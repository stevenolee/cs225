/**
 * @file kdtree.cpp
 * Implementation of KDTree class.
 */

#include <utility>
#include <algorithm>
#include <cmath>
#include <stdlib.h>
#include <math.h>

using namespace std;

template <int Dim>
bool KDTree<Dim>::smallerDimVal(const Point<Dim>& first,
                                const Point<Dim>& second, int curDim) const
{
    /**
     * @todo Implement this function!
     */
// get first and second points that you are comparing
	int valFirst = first[curDim];
	int valSecond = second[curDim];
// compare the values
	if (valFirst < valSecond){
		return true;
	}
	else if (valFirst > valSecond){
		return false;
	}
// if they're equal, use < operator
	else if (valFirst == valSecond){
		if (first < second){
			return true;
		}
		else {
			return false;
		}
	}
	
    return false;
}

template <int Dim>
bool KDTree<Dim>::shouldReplace(const Point<Dim>& target,
                                const Point<Dim>& currentBest,
                                const Point<Dim>& potential) const
{
    /**
     * @todo Implement this function!
     */
	double currentDistance = 0;
	double potentialDistance = 0;
// calculate currentBest's distance	
	for (int i = 0; i < Dim; i++){
		currentDistance = currentDistance + pow(target[i] - currentBest[i], 2);
		potentialDistance = potentialDistance + pow(target[i] - potential[i], 2);
	}
	currentDistance = sqrt(currentDistance);
	potentialDistance = sqrt(potentialDistance);
// check if distances are equal
// if so, compare the points

// if distances are not equal
	if (potentialDistance < currentDistance){
		return true;
	} 
	else if (currentDistance < potentialDistance){
		return false;
	}
	else if (currentDistance == potentialDistance){
		return potential < currentBest;
	}

	
     return false;
}

template <int Dim>
KDTree<Dim>::KDTree(const vector<Point<Dim>>& newPoints)
{
    /**
     * @todo Implement this function!
     */
	vector<Point<Dim>> sorted = newPoints;
	if (sorted.size() == 0){
		root = NULL;
		size = 0;
		return;
	}
	else {
//		vector<Point<Dim>> sorted = newPoints;
		root = buildTree(sorted, 0, sorted.size()-1, 0);
	}

	

//for (auto i = sorted.begin(); i != sorted.end(); ++i)	
//    std::cout << *i << ' ';

//	KDTreeNode* tree = new KDTreeNode(sorted[rootNode]);
//	tree->point = rootNode;
//	root = tree;

/*	for (int i = 0; i < length; i++){
// skip the Point that is already the root 
		if (i == medianIndex){
			continue;
		}
		KDTreeNode* newNode = new KDTreeNode();
		newNode->point = (sorted[i]);
		insert(tree, newNode, Dim);
	}*/
/*
	vector<Point<Dim>> newPointscp = newPoints;
	int dimension = 0;
	int length = newPointscp.size();
	int medianIndex = (length-1) / 2;
	Point<Dim>* rootNode = quickSelect(newPointscp, 0, length - 1, medianIndex, dimension); 
	KDTreeNode* tree = new KDTreeNode();
	tree->point = *rootNode;
	root = tree;
	tree->right = NULL;
	tree->left = NULL;
	for (int i = 0; i < length; i++){
// skip the Point that is already the root 
		if (i == medianIndex){
			continue;
		}
		KDTreeNode* newNode = new KDTreeNode();
		newNode->point = (newPointscp[i]);
		insert(tree, newNode, dimension);
	}
*/

}
  
template <int Dim>
typename KDTree<Dim>::KDTreeNode* KDTree<Dim>::buildTree(vector<Point<Dim>>& sorted, int start, int end, int counter){
// set the current dimension and increment our counter
	if (start > end){
		return NULL;
	}

	int curDim = counter % Dim;
	counter++;
//cout << "BUILD TREE START AND END: " << start << " " << end << endl;
	int m = (start+end)/2;
	int median = quickSelect(sorted, start, end, m, curDim);
	KDTreeNode* newNode = new KDTreeNode(sorted[median]);
// build left subtree
	newNode->left = buildTree(sorted, start, median-1, counter);
// build right subtree
	newNode->right = buildTree(sorted, median+1, end, counter);
	return newNode;
}
/*
template <int Dim>
typename KDTree<Dim>::KDTreeNode* KDTree<Dim>::buildTree(vector<Point<Dim>>& sorted, int start, int end, KDTreeNode* rootNode, int counter){
// create first node
	int curDim = counter % Dim;
	counter++;
// base case
	if (start == end){
// create KDTreeNode for start aka end
		KDTreeNode* newNode = new KDTreeNode(sorted[start]);
		if (smallerDimVal(newNode->point, rootNode->point, curDim)){
			rootNode->left = newNode;
		}
		else {
			rootNode->right = newNode;
		}

		return rootNode;
	}

	int medianIndex = (start+end)/2;
	int median = quickSelect(sorted, start, end, medianIndex, curDim);

// 	create KDTreeNode for median 
	KDTreeNode* newNode = new KDTreeNode(sorted[median]);
	if (rootNode != NULL){
		if (smallerDimVal(newNode->point, rootNode->point, curDim)){
			rootNode->left = newNode;
		}
		else {
			rootNode->right = newNode;
		}
	}
// rootNode is NULL
	else {
		root = newNode;
		rootNode = newNode;
	}

// unsure about median (+1?)
	buildTree(sorted, start, median-1, newNode, counter);
	buildTree(sorted, median+1, end, rootNode, counter);
	return root;
}
*/

template <int Dim>
int KDTree<Dim>::quickSelect(vector<Point<Dim>>& v, int start, int end, int k, int dimension){

// reached the end
if (start == end){
	return start;
}
	int pivotIndex = end;
	if ((end - start + 1) != 0){
		pivotIndex = start + (int)(rand() % (end - start + 1));
	} 
	pivotIndex = partition(v, start, end, pivotIndex, dimension);
//	int newLength = index - start + 1;
	if (pivotIndex == k){
		return pivotIndex;
	}
	else if (k < pivotIndex){
		return quickSelect(v, start, pivotIndex - 1, k, dimension);
	}
	else {
		return quickSelect(v, pivotIndex + 1, end, k, dimension);
	}
}

template <int Dim>
int KDTree<Dim>::partition(vector<Point<Dim>>& v, int start, int end, int pivotIndex, int dimension){
//cout << pivotIndex << " " << dimension << " " << v.size() << " " << Dim << endl;
	int pivotValue = v[pivotIndex][dimension];
// move pivot to end
	swap(v[pivotIndex], v[end]);
// save the start index as a temp variable
	int storeIndex = start;
	for (int i = start; i < end; i++){
		if (v[i][dimension] < pivotValue){
			swap(v[storeIndex], v[i]);
			storeIndex++;
		}
	}
// finalize pivot
	swap(v[end], v[storeIndex]);
	return storeIndex;
}


template <int Dim>
KDTree<Dim>::KDTree(const KDTree<Dim>& other) {
  /**
   * @todo Implement this function!
   */
}

template <int Dim>
const KDTree<Dim>& KDTree<Dim>::operator=(const KDTree<Dim>& rhs) {
  /**
   * @todo Implement this function!
   */

  return *this;
}

template <int Dim>
KDTree<Dim>::~KDTree() {
  /**
   * @todo Implement this function!
   */
}

template <int Dim>
Point<Dim> KDTree<Dim>::findNearestNeighbor(const Point<Dim>& query) const
{
    /**
     * @todo Implement this function!
     */

    return Point<Dim>();
}

