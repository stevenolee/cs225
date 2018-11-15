#include "dsets.h"
#include <iostream>

using namespace std;


void DisjointSets::addelements (int num){
	for (int i = 0; i < num; i++){
		dset.push_back(-1);
		_height.push_back(0);
	}
}

int DisjointSets::find (int elem){
cout << elem << endl;
/*
	if (dset[elem] < 0){
		return elem;
	}
	else {
		int parent = find(elem);
		dset[elem] = parent;
		_height[elem] = 0;
		return parent;
	}
*/
	if (dset[elem] < 0){
		return elem;
	}
	else {
		return find(dset[elem]);
	}
}
	
// union by size
void DisjointSets::setunion (int a, int b){
	int newSize = dset[a] + dset[b];
	
	if (dset[a] < dset[b]){
		dset[b] = a;
		_height[a] = newSize;
	}
	else {
		dset[a] = b;
		_height[b] = newSize;
	}
}

int DisjointSets::size(int elem){
	return _height[elem];
}
