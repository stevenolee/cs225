#include "maze.h"
#include "cs225/HSLAPixel.h"
#include <iostream>
#include <stdlib.h>

using namespace std;
using cs225::PNG;
using cs225::HSLAPixel;

SquareMaze::SquareMaze(){
	width_ = 0;
	height_ = 0;	

/*
	width_ = 0;
	height_ = 0;
	maze.clear();
// initialize all of the maze coordinates
	for (int i = 0; i < width_; i++){
		for (int j = 0; j < height_; j++){
			maze[std::pair<int, int>(i, j)] = false;
		}
	}
	disjoint.addelements(width_*height_);
*/
}

bool SquareMaze::loops(int position, int dir){
	int next = position;
	if (dir == 0){
		next++;
	}
	else if (dir == 1){
		next += height_;
	}
	else if (dir == 2){
		next--;
	}
	else {
		next -= height_;
	}
// if they have the same parents aka are in the same set, there will be a loop
	if (disjoint.find(position) == disjoint.find(next)){
		return true;
	}
	return false;
}

void SquareMaze::makeMaze (int width, int height){
	width_ = width;
	height_ = height;
// set up walls vector
	vector<bool> inner (4, true);
	walls.resize(width_*height_, inner);
// set up dset disjoint
	disjoint.clear();
	disjoint.addelements(height_*width_);

// delete random walls
// stop when the disjoint set tree is a height of 1, aka when size of root == total number of cells
	while (disjoint.size(0) != height_*width_){
		for (int y = 0; y < height_; y++){
			for (int x = 0; x < width_; x++){
				int position = y*height_ + x;
				int next = position;
				int random = rand() % 4;
				while (!canTravel(x, y, random) && loops(position, random)){
					random = rand() % 4;
				}
				int opposite = (random + 2) % 4;
// remove wall at the random direction
				walls[position][random] = false;
// remove wall from the opposite side
				if (random == 0){
					next++;
					walls[position+1][opposite] = false;
					disjoint.setunion(position, next);
				}
				else if (random == 1){
					next += height_;
					walls[position+height_][opposite] = false;
					disjoint.setunion(position, next);
				}
				else if (random == 2){
					next--;
					walls[position-1][opposite] = false;
					disjoint.setunion(position, next);
				}
				else {
					next -= height_;
					walls[position-height_][opposite] = false;
					disjoint.setunion(position, next);
				}
			}
		}
	}
	
/*
	width_ = width;
	height_ = height;
	maze.clear();
// initialize all of the maze coordinates
	for (int i = 0; i < width_; i++){
		for (int j = 0; j < height_; j++){
			maze[std::pair<int, int>(i, j)] = false;
		}
	}
// clear disjoint set
	disjoint.clear();
// add elements to disjoint set
	disjoint.addelements(width_*height_);
*/
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
// check if will hit wall
	if (walls[x+ y*height_][dir]){
		return false;
	}
	return true;

/*
// update the coordinates
	if (dir == 0){
		x++;
	}
	else if (dir == 1){
		y++;
	}
	else if (dir == 2){
		x--;
	}
	else {
		y--;
	}
// if out of x bounds
	if (x < 0 || x >= width_){
		return false;
	}
// if out of y bounds
	if (y < 0 || y >= height_){
		return false;
	}
// if next to a wall
	map<std::pair<int, int>, bool>::const_iterator it;
	it = maze.find(std::pair<int, int>(x, y));
// if the coordinate is not found
	if (it == maze.end()){
		return false;
	}
// cannot travel there if it is a wall
	if (it->second){
		return false;
	}
	return true;
*/
}

void SquareMaze::setWall (int x, int y, int dir, bool exists){
// knock out the walls from both sides
	int position = x + y*height_;
	walls[position][dir] = exists;
/*
// update the coordinates
	if (dir == 0){
		x++;
	}
	else if (dir == 1){
		y++;
	}
	else if (dir == 2){
		x--;
	}
	else {
		y--;
	}
	maze[std::pair<int, int>(x, y)] = exists;
*/
}

vector<int> SquareMaze::solveMaze (){
// 1. 2D vector each stores distance from origin
// 2. check bottom row, which has highest distance 
// 3. trace back (distance--)
// 4. vector.reverse(); ?





	return vector<int>();
}

PNG* SquareMaze::drawMaze () const{
	PNG* pic = new PNG(width_*10 + 1, height_*10 + 1);
// blacken topmost row except entrance
	for (auto i = 0; i < width_; i++){
// continue if entrance
		if (i >= 1 && i <= 9){
			continue;
		}
		HSLAPixel& pixel = pic->getPixel(i, 0);
		pixel.h = 0;
		pixel.s = 0;
		pixel.l = 0;
		pixel.a = 1;
	}
// blacken leftmost column
	for (auto j = 0; j < height_; j++){
		HSLAPixel& pixel = pic->getPixel(0, j);
		pixel.h = 0;
		pixel.s = 0;
		pixel.l = 0;
		pixel.a = 1;
	}

// draw walls
	for (int w = 1; w < width_-1 ; w++){
		for (int h = 1; h < height_-1 ; h++){

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



/*
	PNG* pic = new PNG(width_*10 + 1, height_*10 + 1);
// blacken topmost row except entrance
	for (auto i = 0; i < width_; i++){
// continue if entrance
		if (i >= 1 && i <= 9){
			continue;
		}
		HSLAPixel& pixel = pic->getPixel(i, 0);
		pixel.h = 0;
		pixel.s = 0;
		pixel.l = 0;
		pixel.a = 1;
	}
// blacken leftmost column
	for (auto j = 0; j < height_; j++){
		HSLAPixel& pixel = pic->getPixel(0, j);
		pixel.h = 0;
		pixel.s = 0;
		pixel.l = 0;
		pixel.a = 1;
	}
// draw walls
	for (int w = 1; w < width_-1 ; w++){
		for (int h = 1; h < height_-1 ; h++){

// if right has wall, color black
			if (!canTravel(w, h, 0)){
				for (int k = 0; k <= 10; k++){
					HSLAPixel& curPixel = pic->getPixel((w+1)*10,h*10+k);
					curPixel.h = 0;
					curPixel.s = 0;
					curPixel.l = 0;
					curPixel.a = 1;
				}
			}
// if bottom has wall, color black
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
*/
}

PNG* SquareMaze::drawMazeWithSolution (){
	PNG* picture = drawMaze();
// positions x, y
	int posx = 5;
	int posy = 5;
// solution vector
	vector<int> solution = solveMaze();
// iterate solution vector
	for (int element : solution){
		HSLAPixel& temp = picture->getPixel(posx, posy);
// color path red
		for (int i = 0; i <= 10; i++){
			temp = picture->getPixel(posx, posy);
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
	return picture;


/*
	PNG* picture = drawMaze();
// positions x, y
	int posx = 5;
	int posy = 5;
	
// iterate solution vector
	for (int element : solution){
		HSLAPixel& temp = picture->getPixel(posx, posy);
		for (int i = 0; i <= 10; i++){
// color red
			temp = picture->getPixel(posx, posy);
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
	return picture;
*/
}
