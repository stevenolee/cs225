#include "dsets.h"
#include <iostream>
#include <cmath>

using namespace std;


void DisjointSets::addelements (int num){
	for (int i = 0; i < num; i++){
		dset.push_back(-1);
	}
}

void DisjointSets::clear (){
		dset.clear();
}

int DisjointSets::find (int elem){
	if (dset[elem] < 0){
		return elem;
	}
	else {
		return find(dset[elem]);
	}
}

// union by size
void DisjointSets::setunion (int a, int b){
	int fa = find(a);
	int fb = find(b);
	if (fa == fb){
		return;
	}
	int newSize = dset[fa] + dset[fb];
	if (dset[fa] < dset[fb]){
		dset[fb] = fa;
		dset[fa] = newSize;
	}
	else {
		dset[fa] = fb;
		dset[fb] = newSize;
	}
}

int DisjointSets::size(int elem){
	if (dset[elem] < 0){
		return abs(dset[elem]);
	}
	else {
		return size(dset[elem]);
	}
}
