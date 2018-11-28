#include "maze.h"
#include "cs225/HSLAPixel.h"
#include <iostream>
#include <stdlib.h>
#include <queue>
#include <algorithm>

using namespace std;
using cs225::PNG;
using cs225::HSLAPixel;

SquareMaze::SquareMaze(){
	width_ = 0;
	height_ = 0;	
}

SquareMaze::~SquareMaze(){
	disjoint.clear();
}

void SquareMaze::blockI(int height, int width){
	width_ = width;
	height_ = height;
// set up walls vector
	vector<bool> inner (4, true);
	walls.clear();
	walls.resize(width_*height_, inner);
// set up dset disjoint
	disjoint.clear();
	disjoint.addelements(height_*width_);



	for (int h = 20; h <= 40; h++){
		for (int w = 0; w <= 20; w++){
			int position = h*width_ + w;
			disjoint.setunion(0, position);
		}
	}
	for (int h = 20; h <= 40; h++){
		for (int w = 40; w <= 60; w++){
			int position = h*width_ + w;
			disjoint.setunion(0, position);
		}
	}



// delete random walls
// stop when the disjoint set tree is a height of 1, aka when size of root == total number of cells
	while (disjoint.size(0) != height_*width_){
		for (int y = 0; y < height_; y++){
			for (int x = 0; x < width_; x++){
				int position = y*width_ + x;
				if (disjoint.find(position) == 0){continue;}
				if (position == height_*width_ - 1){
					break;
				}
				int next = position;
				int random = rand() % 4;
				int count = 0;
				int flag = false;
				while (isBorder(position, random) || loops(position, random)){
					random = (random + 1)%4;
					count++;
					if (count == 4){
						flag = true;
						break;
					}
				}
				if (flag){
cout << "X . Y " << x << " " << y << endl;
					continue;
				}
//				int opposite = (random + 2) % 4;
// remove wall at the random direction
				walls[position][random] = false;
// remove wall from the opposite side
				if (random == 0){
					next++;
					walls[next][2] = false;
					disjoint.setunion(position, next);
				}
				else if (random == 1){
					next += width_;
					walls[next][3] = false;
					disjoint.setunion(position, next);
				}
				else if (random == 2){
					next--;
					walls[next][0] = false;
					disjoint.setunion(position, next);
				}
				else if (random == 3){
					next -= width_;
					walls[next][1] = false;
					disjoint.setunion(position, next);
				}

			}
		}
	}


}

bool SquareMaze::loops(int position, int dir){
	int next = position;
	std::pair<int, int> coor = coordinate(position);
	if (dir == 0 && !isBorder(position, 0)){
		next++;
	}
	else if (dir == 1 && !isBorder(position, 1)){
		next += height_;
	}
	else if (dir == 2 && !isBorder(position, 2)){
		next--;
	}
	else if (dir == 3 && !isBorder(position, 3)){
		next -= height_;
	}
// if they have the same parents aka are in the same set, there will be a loop
	if (disjoint.find(position) == disjoint.find(next)){
		return true;
	}
	return false;
}

bool SquareMaze::isBorder(int position, int dir){
// check right border
	if ((position + 1) % width_ == 0 && dir == 0){
		return true;
	}

// check bottom border 
	if (position + width_ >= height_*width_ && dir == 1){
		return true;
	}

// check left border
	if (position % width_ == 0 && dir == 2){
		return true;
	}

// check top border
	if (position < width_ && dir == 3){
		return true;
	}
	return false;

}


void SquareMaze::makeMaze (int width, int height){
	width_ = width;
	height_ = height;
// set up walls vector
	vector<bool> inner (4, true);
	walls.clear();
	walls.resize(width_*height_, inner);
// set up dset disjoint
	disjoint.clear();
	disjoint.addelements(height_*width_);

// delete random walls
// stop when the disjoint set tree is a height of 1, aka when size of root == total number of cells
	while (disjoint.size(0) != height_*width_){
		for (int y = 0; y < height_; y++){
			for (int x = 0; x < width_; x++){
				int position = y*width_ + x;
				if (position == height_*width_ - 1){
					break;
				}
				int next = position;
				int random = rand() % 4;
				int count = 0;
				bool flag = false;
				while (isBorder(position, random) || loops(position, random)){
					random = (random+1)%4;
					count++;
					if (count == 4){
						flag = true;
						break;
					}
				}
				if (flag){continue;}
//				int opposite = (random + 2) % 4;
// remove wall at the random direction
				walls[position][random] = false;
// remove wall from the opposite side
				if (random == 0){
					next++;
					walls[next][2] = false;
					disjoint.setunion(position, next);
				}
				else if (random == 1){
					next += width_;
					walls[next][3] = false;
					disjoint.setunion(position, next);
				}
				else if (random == 2){
					next--;
					walls[next][0] = false;
					disjoint.setunion(position, next);
				}
				else if (random == 3){
					next -= width_;
					walls[next][1] = false;
					disjoint.setunion(position, next);
				}

			}
		}
	}

}

bool SquareMaze::canTravel (int x, int y, int dir) const{
// check if going out of bounds
	if (x == 0 && dir == 2){
		return false;
	}
	if (x == width_-1 && dir == 0){
		return false;
	}
	if (y == 0 && dir == 3){
		return false;
	}
	if (y == height_-1 && dir == 1){
		return false;
	}
	int position = x + y*width_;
// check if will hit wall
	if (walls[position][dir]){
		return false;
	}
// check if will hit wall from the other side too in case
	if (dir == 0 && walls[position + 1][2]){
		return false;
	}
	if (dir == 1 && walls[position + width_][3]){
		return false;
	}
	if (dir == 2 && walls[position - 1][0]){
		return false;
	}
	if (dir == 3 && walls[position - width_][1]){
		return false;
	}
	return true;
}

void SquareMaze::setWall (int x, int y, int dir, bool exists){
	int position = x + y*width_;
	walls[position][dir] = exists;
// maybe try setting on other side as well
	if (!isBorder(position, dir)){
		if (dir == 0){
			walls[position + 1][2] = false;
		}
		if (dir == 1){
			walls[position + width_][3] = false;
		}
		if (dir == 2){
			walls[position - 1][0] = false;
		}
		if (dir == 3){
			walls[position - width_][1] = false;
		}
	}

}

std::pair<int, int> SquareMaze::coordinate(int address){
/*	int count = 0;
	while (address >= width_){
		address -= width_;
		count++; 
	}
	return std::pair<int, int> (address, count);
*/
	return std::pair<int, int> (address%width_, address/width_);
}

vector<int> SquareMaze::bfs(){
	vector<int> distances(height_*width_);
	distances[0] = 0;
	queue<int> q;
	vector<bool> visited(height_*width_, false);
	visited[0] = true;
	q.push(0);
	while (!q.empty()){
		int address = q.front();
		q.pop();
		std::pair<int, int> coor = coordinate(address);

//cout << "current coordinate in bfs: " << coor.first << " " << coor.second << endl;
//cout << "wall info at coordinate: ";
//for (vector<bool>::iterator it = walls[address].begin(); it != walls[address].end(); it++){
//	cout << *it << " ";
//}
//cout << endl;

// if can travel right
		if (canTravel(coor.first, coor.second, 0) && !visited[address + 1]){
//cout << "can travel right" << endl;
			q.push(address + 1);
			distances[address + 1] = distances[address] + 1; 
			visited[address + 1] = true;
		}
// if can travel down
		if (canTravel(coor.first, coor.second, 1) && !visited[address + width_]){
//cout << "can travel down" << endl;
			q.push(address + width_);
			distances[address + width_] = distances[address] + 1;
			visited[address + width_] = true;
		}
// if can travel left
		if (canTravel(coor.first, coor.second, 2) && !visited[address - 1]){
//cout << "can travel left" << endl;
			q.push(address - 1);
			distances[address - 1] = distances[address] + 1;
			visited[address - 1] = true;
		}
// if can travel up
		if (canTravel(coor.first, coor.second, 3) && !visited[address - width_]){
//cout << "can travel up" << endl;
			q.push(address - width_);
			distances[address - width_] = distances[address] + 1;
			visited[address - width_] = true;
		}
	}
	return distances;
}

vector<int> SquareMaze::solveMaze (){
// 1. 2D vector each stores distance from origin
// 2. check bottom row, which has highest distance 
// 3. trace back (distance--)
// 4. vector.reverse(); ?
	vector<int> solution;
	vector<int> distances = bfs();
//cout << "bfs:" << endl;
//for (vector<int>::iterator it = distances.begin(); it != distances.end(); it++){
//	cout << *it << " ";
//}
//cout << endl;
// exit is the location of the exit in the array
	int exit = (height_-1) * width_;
	for (int i = 0; i < width_; i++){
		int offset = (height_-1) * width_;
		if (distances[offset + i] > distances[exit]){
			exit = offset + i;
		}
	}
//cout << "height and width: " << height_ << " " << width_ << endl;
//cout << "exit: " << exit << endl;
//cout << "distances[exit] " << distances[exit] << endl;
// use start and endpoints to find the path
	int curDistance = distances[exit];
	while (exit > 0){
//cout << "solution.size()" << solution.size() << endl;
		std::pair<int, int> location = coordinate(exit);
// check adjacent cells to backtrack
// check right
//cout << "curDis and exit: " << curDistance << " " << exit << endl;
//cout << location.first << " " << location.second << " width: " << width_<< endl;

		if (canTravel(location.first, location.second, 0) && distances[exit + 1] == curDistance - 1){
			solution.push_back(2);
			exit++;
			curDistance--;
		}
// check bottom
		else if (canTravel(location.first, location.second, 1) && distances[exit + width_] == curDistance - 1){
			solution.push_back(3);
			exit += width_;
			curDistance--;
		}
// check left
		else if (canTravel(location.first, location.second, 2) && distances[exit - 1] == curDistance - 1){
			solution.push_back(0);
			exit--;
			curDistance--;
		}
// above
		else {
			solution.push_back(1);
			exit -= width_;
			curDistance--;
		}
	}


	reverse(solution.begin(), solution.end());
//cout << "solution: size  " << solution.size() << endl;
//for (vector<int>::iterator it = solution.begin(); it != solution.end(); it++)
//	cout << *it << " ";
//cout << endl;
	return solution;
}


PNG* SquareMaze::drawMaze () const{
	PNG* pic = new PNG(width_*10 + 1, height_*10 + 1);
// blacken topmost row except entrance
	for (auto i = 0; i < width_; i++){
		for (int k = 0; k <= 10; k++){
// continue if entrance
			if (i == 0 && k >= 1 && k <= 9){
				continue;
			}
			HSLAPixel& pixel = pic->getPixel(i*10 + k, 0);
			pixel.h = 0;
			pixel.s = 0;
			pixel.l = 0;
			pixel.a = 1;
		}
	}
// blacken leftmost column
	for (auto j = 0; j < height_; j++){
		for (int k = 0; k <= 10; k++){
			HSLAPixel& pixel = pic->getPixel(0, j*10 + k);
			pixel.h = 0;
			pixel.s = 0;
			pixel.l = 0;
			pixel.a = 1;
		}
	}

// draw walls
	for (int w = 0; w < width_ ; w++){
		for (int h = 0; h < height_ ; h++){

// if cannot travel right, color black
			if (!canTravel(w, h, 0)){
				for (int k = 0; k <= 10; k++){
					HSLAPixel& curPixel = pic->getPixel((w+1)*10,h*10+k);
					curPixel.h = 0;
					curPixel.s = 0;
					curPixel.l = 0;
					curPixel.a = 1;
				}
			}
// if cannot travel down, color black
			if (!canTravel(w, h, 1)){
				for (int k = 0; k <= 10; k++){
					HSLAPixel& curPixel = pic->getPixel(w*10+k, (h+1)*10);
					curPixel.h = 0;
					curPixel.s = 0;
					curPixel.l = 0;
					curPixel.a = 1;
				}
			}
		}
	}

	return pic;
}

PNG* SquareMaze::drawMazeWithSolution (){
	PNG* picture = drawMaze();
// positions x, y
	int posx = 5;
	int posy = 5;
// solution vector
	vector<int> solution = solveMaze();

//for (vector<int>::iterator it = solution.begin(); it != solution.end(); it++){
//}

// iterate solution vector
	for (int element : solution){
//		HSLAPixel& temp = picture->getPixel(posx, posy);
// color path red
		for (int i = 0; i < 10; i++){
				HSLAPixel& temp = picture->getPixel(posx, posy);
				temp.h = 0;
				temp.s = 1;
				temp.l = 0.5;
				temp.a = 1;
			if (element == 0){
				posx++;
			}
			else if (element == 1){
				posy++;
			}
			else if (element == 2){
				posx--;
			}
			else {
				posy--;
			}
		}
	}
	HSLAPixel& temp = picture->getPixel(posx, posy);
	temp.h = 0;
	temp.s = 1;
	temp.l = 0.5;
	temp.a = 1;
	posy = posy+5;
	posx = posx - 4;
// draw the exit
//cout << "height_: " << height_ << endl;
	for (int k = 0; k < 9; k++){	
//cout << posx + k << " " << posy << endl;
		HSLAPixel& ending = picture->getPixel(posx + k, posy);
		ending.h = 0;
		ending.s = 0;
		ending.l = 1;
		ending.a = 1;
	}
	return picture;

}
