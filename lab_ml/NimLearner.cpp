/**
 * @file NimLearner.cpp
 * CS 225: Data Structures
 */

#include "NimLearner.h"
#include <ctime>


/**
 * Constructor to create a game of Nim with `startingTokens` starting tokens.
 *
 * This function creates a graph, `g_` representing all of the states of a
 * game of Nim with vertex labels "p#-X", where:
 * - # is the current player's turn; p1 for Player 1, p2 for Player2
 * - X is the tokens remaining at the start of a player's turn
 *
 * For example:
 *   "p1-4" is Player 1's turn with four (4) tokens remaining
 *   "p2-8" is Player 2's turn with eight (8) tokens remaining
 *
 * All legal moves between states are created as edges with initial weights
 * of 0.
 *
 * @param startingTokens The number of starting tokens in the game of Nim.
 */
NimLearner::NimLearner(unsigned startingTokens) : g_(true, true) {
    /* Your code goes here! */
//	srand(time(NULL));
	for (int i = startingTokens; i > 0; i--){
		string one = "p1-" + to_string(i);
		if (!g_.vertexExists(one)){
			g_.insertVertex(one);
		}

		if (one == "p1-" + to_string(startingTokens)){
			startingVertex_ = one;
		}

		string two = "p2-" + to_string(i);
		if (!g_.vertexExists(two)){
			g_.insertVertex(two);
		}
// for p1
		for (int j = 1; j < 3; j++){
			if (i - j >= 0){
				string next = "p1-" + to_string(i - j);
				if (!g_.vertexExists(next)){
					g_.insertVertex(next);
				}
// insert edge from old to new
				if (!g_.edgeExists(two, next)){
					g_.insertEdge(two, next);
					g_.setEdgeWeight(two, next, 0);
				}
			}
		}

// for p2
		for (int j = 1; j < 3; j++){
			if (i - j >= 0){
				string next = "p2-" + to_string(i - j);
				if (!g_.vertexExists(next)){
					g_.insertVertex(next);
				}
// insert edge from old to new
				if (!g_.edgeExists(one, next)){
					g_.insertEdge(one, next);
					g_.setEdgeWeight(one, next, 0);
				}
			}
		}

	}

}

/**
 * Plays a random game of Nim, returning the path through the state graph
 * as a vector of `Edge` classes.  The `origin` of the first `Edge` must be
 * the vertex with the label "p1-#", where # is the number of starting
 * tokens.  (For example, in a 10 token game, result[0].origin must be the
 * vertex "p1-10".)
 *
 * @returns A random path through the state space graph.
 */
std::vector<Edge> NimLearner::playRandomGame() const {
  vector<Edge> path;
 /* Your code goes here! */
	Vertex current = startingVertex_;
	vector<Vertex> adj = g_.getAdjacent(current);
	while (!adj.empty()){
		int way = (rand() % 2);
		if (adj.size() != 1){
			path.push_back(g_.getEdge(current, adj[way]));
			current = adj[way];
		}
		else {
			path.push_back(g_.getEdge(current, adj[0]));
			current = adj[0];
		}

		adj.clear();
		adj = g_.getAdjacent(current);
	}	
  return path;
}

/*
 * Updates the edge weights on the graph based on a path through the state
 * tree.
 *
 * If the `path` has Player 1 winning (eg: the last vertex in the path goes
 * to Player 2 with no tokens remaining, or "p2-0", meaning that Player 1
 * took the last token), then all choices made by Player 1 (edges where
 * Player 1 is the source vertex) are rewarded by increasing the edge weight
 * by 1 and all choices made by Player 2 are punished by changing the edge
 * weight by -1.
 *
 * Likewise, if the `path` has Player 2 winning, Player 2 choices are
 * rewarded and Player 1 choices are punished.
 *
 * @param path A path through the a game of Nim to learn.
 */
void NimLearner::updateEdgeWeights(const std::vector<Edge> & path) {
 /* Your code goes here! */
	Edge last = path[path.size() - 1];
	Vertex loser = last.dest;
	int count = 0;
	if (loser == "p2-0"){
// p1 won
		count = 1;
	} else {
// p2 won
		count = 0;
	}

	for (Edge it : path){
		Vertex first = it.source;
		Vertex next = it.dest;
//		int weight = g_.getEdgeWeight(first, next);
		int weight = it.getWeight();
		if (count % 2){
			weight++;
		} else {
			weight--;
		}
		g_.setEdgeWeight(first, next, weight);
		count++;
	}

/*
	vector<Edge>::const_iterator it = path.begin();
	for (; it != path.end(); it++){
		Vertex first = it->source;
		Vertex next = it->dest;
//		int weight = g_.getEdgeWeight(first, next);
		int weight = it->getWeight();
		if (count % 2){
			weight++;
		} else {
			weight--;
		}
		g_.setEdgeWeight(first, next, weight);
		count++;
	}
*/
}

/**
 * Label the edges as "WIN" or "LOSE" based on a threshold.
 */
void NimLearner::labelEdgesFromThreshold(int threshold) {
  for (const Vertex & v : g_.getVertices()) {
    for (const Vertex & w : g_.getAdjacent(v)) {
      int weight = g_.getEdgeWeight(v, w);

      // Label all edges with positve weights as "WINPATH"
      if (weight > threshold)           { g_.setEdgeLabel(v, w, "WIN"); }
      else if (weight < -1 * threshold) { g_.setEdgeLabel(v, w, "LOSE"); }
    }
  }
}

/**
 * Returns a constant reference to the state space graph.
 *
 * @returns A constant reference to the state space graph.
 */
const Graph & NimLearner::getGraph() const {
  return g_;
}
