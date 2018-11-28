#include <iostream>
#include "dsets.h"
#include "maze.h"
#include "cs225/PNG.h"

using namespace std;
using cs225::PNG;

int main()
{
    // Write your own main here
//    cout << "Add your own tests here! Modify main.cpp" << endl;
	SquareMaze maze;
	maze.blockI(60, 60);
// make into I shape
	int height = 20;
	for (int i = 0; i < 20; i++){
		maze.setWall(i, height, 3, true);
	}
	for (int i = 40; i < 60; i++){
		maze.setWall(i, height, 3, true);
	}
	height = 40;
	for (int i = 0; i < 20; i++){
		maze.setWall(i, height, 1, true);
	}
	for (int i = 40; i < 60; i++){
		maze.setWall(i, height, 3, true);
	}

	int width = 20;
	for (int i = 0; i < 20; i++){
		maze.setWall(width, 20 + i, 2, true);
	}
	width = 40;
	for (int i = 0; i < 20; i++){
		maze.setWall(width, 20 + i, 0, true);
	}
	maze.solveMaze();
	PNG* output = maze.drawMazeWithSolution();
	output->writeToFile("./creative.png");

    return 0;
}
