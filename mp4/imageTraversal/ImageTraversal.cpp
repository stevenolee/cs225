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
}

// custom constructor
ImageTraversal::Iterator::Iterator(ImageTraversal* trav, const PNG & png, Point startPoint, double t) 
	:traversal(trav), pic(png), start(startPoint), tol(t)
{
	current = start;
	
}
/*
// custom constructor 2
ImageTraversal::Iterator::Iterator(BFS & traversal, Point startPoint, double t) 
	:traversalBFS(&traversal), start(startPoint), tol(t)
{
	current = traversal.peek();
	
}
*/
/**
 * Iterator increment opreator.
 *
 * Advances the traversal of the image.
 */
ImageTraversal::Iterator & ImageTraversal::Iterator::operator++() {
  /** @todo [Part 1] */
	unsigned x = current.x;
	unsigned y = current.y;
	double delta;
	Point temp;
// check right
	delta = calculateDelta(pic.getPixel(x + 1, y), pic.getPixel(x, y));
	if (delta < tol){
		temp = Point(x + 1, y);
		add(temp);
		current = temp;
		return *this;
	} 
// check bottom
	delta = calculateDelta(pic.getPixel(x, y + 1), pic.getPixel(x, y));
	if (delta < tol){
		temp = Point(x, y + 1);
		add(temp);
		current = temp;
		return *this;
	} 
// check left
	delta = calculateDelta(pic.getPixel(x - 1, y), pic.getPixel(x, y));
	if (delta < tol){
		temp = Point(x - 1, y);
		add(temp);
		current = temp;
		return *this;
	} 
// check above
	delta = calculateDelta(pic.getPixel(x, y - 1), pic.getPixel(x, y));
	if (delta < tol){
		temp = Point(x, y - 1);
		add(temp);
		current = temp;
		return *this;
	} 








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
  return false;
}

