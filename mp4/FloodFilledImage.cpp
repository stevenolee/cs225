#include "cs225/PNG.h"
#include <list>
#include <iostream>

#include "colorPicker/ColorPicker.h"
#include "imageTraversal/ImageTraversal.h"

#include "Point.h"
#include "Animation.h"
#include "FloodFilledImage.h"

using namespace cs225;
using namespace std;

/**
 * Constructs a new instance of a FloodFilledImage with a image `png`.
 * 
 * @param png The starting image of a FloodFilledImage
 */
FloodFilledImage::FloodFilledImage(const PNG & png) {
  /** @todo [Part 2] */
	pic = png;

}

/**
 * Adds a flood fill operation to the FloodFillImage.  This function must store the operation,
 * which will be used by `animate`.
 * 
 * @param traversal ImageTraversal used for this FloodFill operation.
 * @param colorPicker ColorPicker used for this FloodFill operation.
 */
void FloodFilledImage::addFloodFill(ImageTraversal & traversal, ColorPicker & colorPicker) {
  /** @todo [Part 2] */
	color.push_back(&colorPicker);
	traverse.push_back(&traversal);

}

/**
 * Creates an Animation of frames from the FloodFill operations added to this object.
 * 
 * Each FloodFill operation added by `addFloodFill` is executed based on the order
 * the operation was added.  This is done by:
 * 1. Visiting pixels within the image based on the order provided by the ImageTraversal iterator and
 * 2. Updating each pixel to a new color based on the ColorPicker
 * 
 * While applying the FloodFill to the image, an Animation is created by saving the image
 * after every `frameInterval` pixels are filled.  To ensure a smooth Animation, the first
 * frame is always the starting image and the final frame is always the finished image.
 * 
 * (For example, if `frameInterval` is `4` the frames are:
 *   - The initial frame
 *   - Then after the 4th pixel has been filled
 *   - Then after the 8th pixel has been filled
 *   - ...
 *   - The final frame, after all pixels have been filed)
 */ 
Animation FloodFilledImage::animate(unsigned frameInterval) const {
  Animation animation;
  /** @todo [Part 2] */
// add base image
	animation.addFrame(pic);

	vector<ColorPicker*>::const_iterator itColors = color.begin();

	for (ImageTraversal* temp : traverse){
		unsigned count = 0;
		ImageTraversal::Iterator it = temp->begin();

		while (it != temp->end()){
			if (count%frameInterval == 0){
				animation.addFrame(pic);
			}
			Point current = *it;
			HSLAPixel pointer = (*itColors)->getColor(current.x, current.y);
			HSLAPixel& pixel = pic.getPixel(current.x, current.y);
			HSLAPixel* newPixel = new HSLAPixel(pointer.h, pointer.s, pointer.l, pointer.a);
			pixel = *newPixel;
			++it;
			count++;
		}
		
		++itColors;
	}

// add last image
	animation.addFrame(pic);

  return animation;
}
