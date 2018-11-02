/**
 * @file kdtree.cpp
 * Implementation of KDTree class.
 */

#include <utility>
#include <algorithm>
#include <cmath>

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
	int length = newPoints.size();
	int medianIndex = (length-1) / 2;
	
	

}

template <int Dim>
Point<Dim>* KDTree<Dim>::quickSelect(vector<Point<Dim>>& v, int start, int end, int k, int dimension){
// make sure that k is valid
	if (k > 0 && k <= end){
		return NULL;
	}
	int index = partition(v, start, end, k, dimension);

// if k is found, return
	if (index == k){
		return &v[index];
	}
// if index < k
	if (index < k){
		return quickSelect(v, index + 1, end, k - index); 
	}
// if index > k
	if (index > k){
		return quickSelect(v, 1, index - 1, k);
	}

	return NULL;

}
template <int Dim>
int KDTree<Dim>::partition(vector<Point<Dim>>& v, int start, int end, int dimension){
//	Point<Dim> pivot = v[end];
	int piv = end;	
	while (start < end){
//		while (v[start] < pivot){
		while (smallerDimVal(start, piv, dimension)){
			start++;
		}
//		while (pivot < v[end]){
		while(smallerDimVal(piv, end, dimension)){
			end--;
		}
		if (v[start][dimension] == v[end][dimension]){
			start++;
		}
		else if (start < end){
			Point<Dim>* temp = v[start];
			v[start] = v[end];
			v[end] = temp;
		}
	}
	return end;
}

/*
template <int Dim>
int KDTree<Dim>::partition(vector<Point<Dim>>& v, int start, int end, int pivotIndex){
// make pivot last index
	Point<Dim> pivot = v[pivotIndex];
	swap(&v[end], &v[pivotIndex]);
	int temp = start;

	for (int i = start; i < end; i++){
		if (v[i] < pivot){
			swap(v[temp], v[i]);
			temp++;
		}
	}
	swap(v[end], v[temp]);
	return temp;
}
*/
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

