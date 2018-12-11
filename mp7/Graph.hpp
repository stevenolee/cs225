#include "Graph.h"
#include "Edge.h"
#include "Vertex.h"

#include <string>
#include <iostream>
using namespace std;
/**
* @return The number of vertices in the Graph
*/
template <class V, class E>
unsigned int Graph<V,E>::size() const {
  // TODO: Part 2
  return vertexMap.size();
}


/**
* @return Returns the degree of a given vertex.
* @param v Given vertex to return degree.
*/
template <class V, class E>
unsigned int Graph<V,E>::degree(const V & v) const {
  // TODO: Part 2
	string str;
	for (auto it : vertexMap){
		if (it->second == v){
			string str = it->second;
		}
	}
	typename std::unordered_map<string, list<edgeListIter>>::iterator edgeIterator = adjList.find(str);
	if (edgeIterator == adjList.end()){
		return 0;
	}	
	return edgeIterator->second.size();
}


/**
* Inserts a Vertex into the Graph by adding it to the Vertex map and adjacency list
* @param key The key of the Vertex to insert
* @return The inserted Vertex
*/
template <class V, class E>
V & Graph<V,E>::insertVertex(std::string key) {
  // TODO: Part 2
//  V & v = *(new V(key));
	V& newV = *(new V (key));
	vertexMap.insert(pair<string, V &>(key, newV));
	list<edgeListIter> newList;
	adjList.insert(pair<string, list<edgeListIter>>(key, newList));

  return newV;
}


/**
* Removes a given Vertex
* @param v The Vertex to remove
*/
template <class V, class E>
void Graph<V,E>::removeVertex(const std::string & key) {
  // TODO: Part 2
cout << "edgeList: " << endl;
	for (auto it = edgeList.begin(); it != edgeList.end(); it++){
cout << it->get().source() << " -> " << it->get().dest() << endl;
	}

cout << "adjList:" << endl;
	for (auto it : adjList.at(key)){
		cout << it->get().source().key() << " -> " << it->get().dest().key() << endl;
	}


// remove from vertexMap
	vertexMap.erase(key);

// remove from edgeList
/*
	for (auto it : edgeList){
		if (it.get().source().key() == key || it.get().dest().key() == key){
			edgeList.remove(it);
		}
	}
*/

	for (auto it = edgeList.begin(); it != edgeList.end(); it++){
		string begin = it->get().source().key();
		string end = it->get().dest().key();
		if (key == begin || key == end){
			edgeList.erase(it);
//			break;
		}
	}



// remove from adjList
/*
	for (auto it : adjList.at(key)){
		if (it->get().source().key() == key || it->get().dest().key() == key){
			adjList.at(key).remove(it);
		}
	}
*/
	for (auto iter : adjList.at(key)){
		if (iter->get().source().key() == key || iter->get().dest().key() == key){
//			iter.clear();
			adjList.at(key).remove(iter);
//			break;
		}
	}


cout << "____________________________________" << endl;
cout << "edgeList:" << endl;
	for (auto it = edgeList.begin(); it != edgeList.end(); it++){
cout << it->get().source() << " -> " << it->get().dest() << endl;
	}
cout << "adjList:" << endl;
	for (auto it : adjList.at(key)){
		cout << it->get().source().key() << " -> " << it->get().dest().key() << endl;
	}

}


/**
* Inserts an Edge into the adjacency list
* @param v1 The source Vertex
* @param v2 The destination Vertex
* @return The inserted Edge
*/
template <class V, class E>
E & Graph<V,E>::insertEdge(const V & v1, const V & v2) {
  // TODO: Part 2
	E & newEdge = *(new E(v1, v2));
	edgeList.push_front(newEdge);
	adjList.at(v1.key()).push_front(edgeList.begin());
	adjList.at(v2.key()).push_front(edgeList.begin());

  return newEdge;
}


/**
* Removes an Edge from the Graph
* @param key1 The key of the ource Vertex
* @param key2 The key of the destination Vertex
*/
template <class V, class E>
void Graph<V,E>::removeEdge(const std::string key1, const std::string key2) {  
  // TODO: Part 2

/*
	for (auto it = edgeList.begin(); it != edgeList.end(); it++){
cout << it->get().source() << " -> " << it->get().dest() << endl;
	}
*/
/*
	for (auto it : adjList.at(key1)){
		cout << it->get().source().key() << " -> " << it->get().dest().key() << endl;
	}
*/


	V v1 (key1);
	V v2 (key2);
	E edge (v1, v2);
	for (auto it = edgeList.begin(); it != edgeList.end(); it++){
		V begin = it->get().source();
		V end = it->get().dest();
		if (v1 == begin && v2 == end){
			edgeList.erase(it);
//			break;
		}
	}
//	for (auto iter = adjList.at(key1).begin(); iter != adjList.at(key1).end(); iter++){
	for (auto iter : adjList.at(key1)){
		if (iter->get().source().key() == key1 && iter->get().dest().key() == key2){
//			iter.clear();
			adjList.at(key1).remove(iter);
//			break;
		}
	}

/*
cout << "fucking shit" << endl;
	for (auto it : adjList.at(key1)){
		cout << it->get().source().key() << " -> " << it->get().dest().key() << endl;
	}
*/
/*
	for (auto it = edgeList.begin(); it != edgeList.end(); it++){
cout << it->get().source() << " -> " << it->get().dest() << endl;
	}
*/
}


/**
* Removes an Edge from the adjacency list at the location of the given iterator
* @param it An iterator at the location of the Edge that
* you would like to remove
*/
template <class V, class E>
void Graph<V,E>::removeEdge(const edgeListIter & it) {
  // TODO: Part 2
	string key1 = it->get().source().key();
	
	for (auto it : adjList.at(key1)){
		cout << it->get().source().key() << " -> " << it->get().dest().key() << endl;
	}

	adjList.at(key1).clear();

	for (auto it = edgeList.begin(); it != edgeList.end(); it++){
		string begin = it->get().source().key();
		if (key1 == begin){
			edgeList.erase(it);
		}
	}




cout << "fucking shit" << endl;
	for (auto it : adjList.at(key1)){
		cout << it->get().source().key() << " -> " << it->get().dest().key() << endl;
	}
}


/**
* @param key The key of an arbitrary Vertex "v"
* @return The list edges (by reference) that are adjacent to "v"
*/
template <class V, class E>  
const std::list<std::reference_wrapper<E>> Graph<V,E>::incidentEdges(const std::string key) const {
  // TODO: Part 2
  std::list<std::reference_wrapper<E>> edges;
	typename unordered_map<string, list<edgeListIter>>::const_iterator it = adjList.find(key);
	for (auto iter : it->second){
		edges.push_back(*iter);
	}

  return edges;
}


/**
* Return whether the two vertices are adjacent to one another
* @param key1 The key of the source Vertex
* @param key2 The key of the destination Vertex
* @return True if v1 is adjacent to v2, False otherwise
*/
template <class V, class E>
bool Graph<V,E>::isAdjacent(const std::string key1, const std::string key2) const {
  // TODO: Part 2
	for (auto & iter : adjList.at(key1)){
// if they are adjacent
		if (iter->get().dest().key() == key2){
			return true;
		}
	}

  return false;
}
