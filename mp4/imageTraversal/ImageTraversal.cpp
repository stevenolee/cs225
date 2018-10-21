#include <cmath>
#include <iterator>
#include <iostream>

#include "../cs225/HSLAPixel.h"
#include "../cs225/PNG.h"
#include "../Point.h"

#include "ImageTraversal.h"
#include <stack>

using namespace std;

/**
 * Calculates a metric for the difference between two pixels, used to
 * calculate if a pixel is within a tolerance.
 * 
 * @param p1 First pixel
 * @param p2 Second pixel
 * @return the difference between two HSLAPixels
 */
double ImageTraversal::calculateDelta(const HSLAPixel & p1, const HSLAPixel & p2) {
  double h = fabs(p1.h - p2.h);
  double s = p1.s - p2.s;
  double l = p1.l - p2.l;

  // Handle the case where we found the bigger angle between two hues:
  if (h > 180) { h = 360 - h; }
  h /= 360;

  return sqrt( (h*h) + (s*s) + (l*l) );    
}

/**
 * Default iterator constructor.
 */
ImageTraversal::Iterator::Iterator(){
  /** @todo [Part 1] */
	// IDK WHAT TO DOOOOOOOOOOOOOOOOOO
	traversal = NULL;
}

// custom constructor
ImageTraversal::Iterator::Iterator(ImageTraversal* trav, const PNG & png, Point startPoint, double t) 
	:traversal(trav), pic(png), start(startPoint), tol(t)
{
	current = start;
	visit = new bool*[png.width()];
	for (unsigned int i = 0; i < png.width(); i++){
		visit[i] = new bool[png.height()];
		for (unsigned int j = 0; j < png.height(); j++){
			visit[i][j] = false;
		}
	}

}

/**
 * Iterator increment opreator.
 *
 * Advances the traversal of the image.
 */
ImageTraversal::Iterator & ImageTraversal::Iterator::operator++() {
  /** @todo [Part 1] */

	current = traversal->pop();
	unsigned x = current.x;
	unsigned y = current.y;
//	if (visit[x][y]){
//		return *this;
//	}
	double delta;
	Point temp;

// check right
	if (x + 1 < pic.width()){
		delta = calculateDelta(pic.getPixel(x + 1, y), pic.getPixel(start.x, start.y));
		if (delta <= tol){
			if (!visit[x+1][y]){
				temp = Point(x + 1, y);
				traversal->add(temp);
				current = temp;
			}
		} 
	}
// check bottom
	if (y + 1 < pic.height()){
		delta = calculateDelta(pic.getPixel(x, y + 1), pic.getPixel(start.x, start.y));
		if (delta <= tol){
			if (!visit[x][y+1]){
				temp = Point(x, y + 1);
				traversal->add(temp);
				current = temp;
			}
		} 
	}
// check left
	if (x >= 1){
		delta = calculateDelta(pic.getPixel(x - 1, y), pic.getPixel(start.x, start.y));
		if (delta <= tol){
			if (!visit[x-1][y]){
				temp = Point(x - 1, y);
				traversal->add(temp);
				current = temp;
			}
		} 
	}
// check above
	if (y >= 1){
		delta = calculateDelta(pic.getPixel(x, y - 1), pic.getPixel(start.x, start.y));
		if (delta <= tol){
			if (!visit[x][y-1]){
				temp = Point(x, y - 1);
				traversal->add(temp);
				current = temp;
			}
		} 
	}
	current = traversal->peek();
	visit[x][y] = true;
/*
	while (visit[traversal->peek().x][traversal->peek().y] && !traversal->empty()){
		traversal->pop();
	}	
*/
	return *this;
}

/**
 * Iterator accessor opreator.
 * 
 * Accesses the current Point in the ImageTraversal.
 */
Point ImageTraversal::Iterator::operator*() {
  /** @todo [Part 1] */
  return current;
}

/**
 * Iterator inequality operator.
 * 
 * Determines if two iterators are not equal.
 */
bool ImageTraversal::Iterator::operator!=(const ImageTraversal::Iterator &other) {
  /** @todo [Part 1] */
/*
    bool thisEmpty = false; 
    bool otherEmpty = false;

	if (traversal == NULL){
		thisEmpty = true;
	} else {
		thisEmpty = traversal->empty();
	}
    if (other.traversal == NULL){
		otherEmpty = true;
	} else {
		otherEmpty = other.traversal->empty(); 
	}

    if (thisEmpty && otherEmpty){
		return false; 
	}
    else if ((!thisEmpty)&&(!otherEmpty)){
		return !(traversal->peek() == other.traversal->peek());
	}
    else {
		return true;
	}
*/
  return false;

}

