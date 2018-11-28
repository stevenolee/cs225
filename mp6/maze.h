#pragma once
#include <vector>
#include <map>
#include "cs225/PNG.h"
#include "dsets.h"


class SquareMaze{

public:
// constructor 
SquareMaze();

~SquareMaze();

bool isEdge(int x, int y, int dir);



// prepare block I
void blockI(int height, int width);

// bfs search returning the distances vector
std::vector<int> bfs ();

// turns address into coordinate
std::pair<int, int> coordinate (int address);

// check if there are any loops
bool loops (int position, int dir);

// check if going on border
bool isBorder (int position, int dir);

// Makes a new SquareMaze of the given height and width
void makeMaze (int width, int height);

// This uses your representation of the maze to determine whether it is possible to travel in the given direction from the square at coordinates (x,y)
bool canTravel (int x, int y, int dir) const;
 	
// Sets whether or not the specified wall exists
void setWall (int x, int y, int dir, bool exists);
 	
// Solves this SquareMaze
std::vector<int> solveMaze ();
 	
// Draws the maze without the solution
cs225::PNG* drawMaze () const;
 	
// This function calls drawMaze, then solveMaze; it modifies the PNG from drawMaze to show the solution vector and the exit
cs225::PNG* drawMazeWithSolution ();


private:
int width_;
int height_;
//std::map<std::pair<int, int>, bool> maze;
//std::vector<int> solution;
DisjointSets disjoint;
std::vector<std::vector<bool>> walls;
};
