#include "cs225/PNG.h"
using cs225::PNG;

#include "cs225/HSLAPixel.h"
using cs225::HSLAPixel;

#include <string>



void rotate(std::string inputFile, std::string outputFile) {
  // TODO: Part 2

	cs225::PNG pngIn;
	pngIn.readFromFile(inputFile);

	unsigned int w = pngIn.width();
	unsigned int h = pngIn.height();
	cs225::PNG pngOut(w, h);
	int i, j;	
	for (i = h - 1; i >= 0; i--){
		for (j = w - 1; j >= 0; j--){
			HSLAPixel & pixel1 = pngIn.getPixel(j, i);
			HSLAPixel & pixel2 = pngOut.getPixel(w - j - 1, h - i - 1);
			pixel2.h = pixel1.h;
			pixel2.s = pixel1.s; 
			pixel2.l = pixel1.l;
			pixel2.a = pixel1.a;
			}
	} 
	pngOut.writeToFile(outputFile);
}

PNG myArt(unsigned int width, unsigned int height) {
  PNG png(width, height);
  // TODO: Part 3
	int hue = 0;
	for (unsigned int i = 0; i < height; i++){
		for (unsigned int j = 0; j < width; j++){
			HSLAPixel & pixel = png.getPixel(j, i);
			pixel.h = hue;
			pixel.s = 1.0;
			pixel.l = 0.5;
			pixel.a = 1;
			hue++;
			if (hue > 360)
				hue = 0;
		}
	}
	
  return png;
}
