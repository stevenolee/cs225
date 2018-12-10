/**
 * @file NetworkFlow.cpp
 * CS 225: Data Structures
 */

#include <vector>
#include <algorithm>
#include <set>
#include <climits>
#include "graph.h"
#include "edge.h"

#include "NetworkFlow.h"

using std::vector;


int min(int a, int b) {
  if (a<b)
    return a;
  else return b;
}

NetworkFlow::NetworkFlow(Graph & startingGraph, Vertex source, Vertex sink) :
  g_(startingGraph), residual_(Graph(true,true)), flow_(Graph(true,true)), source_(source), sink_(sink) {
  // YOUR CODE HERE
	vector<Vertex> vertices_ = g_.getVertices();
	vector<Edge> edges_ = g_.getEdges();
	if (vertices_.empty()){
		return;
	}	

	for (auto it : vertices_){
		residual_.insertVertex(it);
		flow_.insertVertex(it);
	}	
	for (auto it : edges_){
		residual_.insertEdge(it.source, it.dest);
		residual_.setEdgeWeight(it.source, it.dest, it.getWeight());
		residual_.insertEdge(it.dest, it.source);
		residual_.setEdgeWeight(it.dest, it.source, 0);
		
		flow_.insertEdge(it.source, it.dest);
		flow_.setEdgeWeight(it.source, it.dest, 0);
	}

/*
	vector<Vertex> path;	
	findAugmentingPath(source_, sink_, path);
	if (path.empty()){
		return;
	}
// flow capacity
	int cap = pathCapacity(path);
// if there is a path, get the edge weights and update the flow and residual graph
	for (int unsigned long i = 0; i < path.size() - 2; i++){
// update flow_
		int fWeight = flow_.getEdgeWeight(path[i], path[i+1]);
		flow_.setEdgeWeight(path[i], path[i+1], fWeight+cap);
// update residual_
		int rWeight = residual_.getEdgeWeight(path[i], path[i+1]);
		int oppositeWeight = residual_.getEdgeWeight(path[i+1], path[i]);
// get original graph edge weight
		int weightLimit = g_.getEdgeWeight(path[i], path[i+1]);
		if (weightLimit == Graph::InvalidWeight){
			weightLimit = g_.getEdgeWeight(path[i+1], path[i]);
		}	
// check if new edge weight surpasses the limit
		if (rWeight - cap >= 0){
			residual_.setEdgeWeight(path[i], path[i+1], rWeight - cap);
		}
		else {
			residual_.setEdgeWeight(path[i], path[i+1], 0);
		}

		if (oppositeWeight + cap <= weightLimit){
			residual_.setEdgeWeight(path[i+1], path[i], oppositeWeight + cap);
		}
		else {
			residual_.setEdgeWeight(path[i+1], path[i], weightLimit);
		}
	}
	*/
}

  /**
   * findAugmentingPath - use DFS to find a path in the residual graph with leftover capacity.
   *  This version is the helper function.
   *
   * @@params: source -- The starting (current) vertex
   * @@params: sink   -- The destination vertex
   * @@params: path   -- The vertices in the path
   * @@params: visited -- A set of vertices we have visited
   */

bool NetworkFlow::findAugmentingPath(Vertex source, Vertex sink, 
  std::vector<Vertex> &path, std::set<Vertex> &visited) {

  if (visited.count(source) != 0)
    return false;
  visited.insert(source);

  if (source == sink) {
    return true;
  }

  vector<Vertex> adjs = residual_.getAdjacent(source);
  for(auto it = adjs.begin(); it != adjs.end(); it++) {
    if (visited.count(*it) == 0 && residual_.getEdgeWeight(source,*it) > 0) {
      path.push_back(*it);
      if (findAugmentingPath(*it,sink,path,visited))
        return true;
      else {
        path.pop_back();
      }
    }
  }

  return false;
}

  /**
   * findAugmentingPath - use DFS to find a path in the residual graph with leftover capacity.
   *  This version is the main function.  It initializes a set to keep track of visited vertices.
   *
   * @@params: source -- The starting (current) vertex
   * @@params: sink   -- The destination vertex
   * @@params: path   -- The vertices in the path
   */

bool NetworkFlow::findAugmentingPath(Vertex source, Vertex sink, std::vector<Vertex> &path) {
   std::set<Vertex> visited;
   path.clear();
   path.push_back(source);
   return findAugmentingPath(source,sink,path,visited);
}

  /**
   * pathCapacity - Determine the capacity of a path in the residual graph.
   *
   * @@params: path   -- The vertices in the path
   */

int NetworkFlow::pathCapacity(const std::vector<Vertex> & path) const {
  // YOUR CODE HERE
	
	if (path.size() <= 1){
		return 0;
	}

	int limit = INT_MAX;
	for (unsigned long i = 0; i < path.size() - 1; i++){
		int currWeight = residual_.getEdgeWeight(path[i], path[i+1]);
		if (currWeight < limit){
			limit = currWeight;
		}
	}
	
  return limit;
}

  /**
   * calculuateFlow - Determine the capacity of a path in the residual graph.
   * Sets the member function `maxFlow_` to be the flow, and updates the
   * residual graph and flow graph according to the algorithm.
   *
   * @@outputs: The network flow graph.
   */

const Graph & NetworkFlow::calculateFlow() {
  // YOUR CODE HERE
	vector<Vertex> vertices = g_.getVertices();
	vector<Vertex> path;
// if path is empty
/*	if (path.empty()){
		return ;
	}*/
	bool opposite = false;
	int max = 0;
	while (findAugmentingPath(source_, sink_, path)){
// get pathCap
		int pathCap = pathCapacity(path);
		max += pathCap;
		for (unsigned long i = 0; i < path.size() - 1; i++){
			int currWeight = flow_.getEdgeWeight(path[i], path[i+1]);
// if its the opposite way
			if (currWeight == Graph::InvalidWeight){
				currWeight = flow_.getEdgeWeight(path[i+1], path[i]);
				opposite = true;
			}
			if (opposite){
				flow_.setEdgeWeight(path[i+1], path[i], currWeight - pathCap);
			}
			else {
				flow_.setEdgeWeight(path[i], path[i+1], currWeight + pathCap);
			}
// residual_
			int forward = residual_.getEdgeWeight(path[i], path[i+1]);
			residual_.setEdgeWeight(path[i], path[i+1], forward - pathCap);
			int backward = residual_.getEdgeWeight(path[i+1], path[i]);
			residual_.setEdgeWeight(path[i+1], path[i], backward + pathCap);
		}
	}
	maxFlow_ = max;
  return flow_;
}

int NetworkFlow::getMaxFlow() const {
  return maxFlow_;
}

const Graph & NetworkFlow::getGraph() const {
  return g_;
}

const Graph & NetworkFlow::getFlowGraph() const {
  return flow_;
}

const Graph & NetworkFlow::getResidualGraph() const {
  return residual_;
}

