#include <queue>
#include <algorithm>
#include <string>
#include <list>
#include <map>

/**
 * Returns an std::list of vertex keys that creates some shortest path between `start` and `end`.
 *
 * This list MUST include the key of the `start` vertex as the first vertex in the list, the key of
 * the `end` vertex as the last element in the list, and an ordered list of all vertices that must
 * be traveled along the shortest path.
 * 
 * For example, the path a -> c -> e returns a list with three elements: "a", "c", "e".
 * 
 * @param start The key for the starting vertex.
 * @param end   The key for the ending vertex.
 */
template <class V, class E>
std::list<std::string> Graph<V,E>::shortestPath(const std::string start, const std::string end) {
  std::list<std::string> path;
// map<key of current vertex, pair<previous vertex, visited>>
	map<string, pair<string, bool>> table;
// priority queue with strings (keys) 
	queue<string> q;
// push start onto queue
	q.push(start);
// intialize the table map
	for (auto it : vertexMap){	
		string temp = it.first;
		table.insert(pair<string, pair<string, bool>>(it.first, pair<string, bool>("none yet", false)));
	}
// update start vertex on table map
	table.at(start) = pair<string, bool>("none", true);
	while(!q.empty()){
		string current = q.front();
		q.pop();
// check if there are adjacent vertices that have not been traversed
// iterate the list from adjList. check if each has been visited
		for (auto it : adjList.at(current)){
			
			string adj = it->get().dest().key();
// check if the edge is directed
			if (!it->get().directed()){
				if (adj == current){
					adj = it->get().source().key();
				}
			}

// if the adjacent vertex has not been visited, then add to queue and update its previous vertex on the table map

// only can traverse this edge if edge source is current vertex

			if (adj == current){
				continue;
			}

			if (!table.at(adj).second){
				q.push(adj);
				table.at(adj) = pair<string, bool>(current, true);
			}
		}
	}
// table should be filled now; get the end vertex from the table map and trace back the previous node
	string trace = end;
	path.emplace_front(trace);
	while(1){
		string previous = table.at(trace).first;
		path.emplace_front(previous);
// break out of loop if the start was found
		if (previous == start){
			break;
		}
		trace = previous;
	}


  return path;
}

