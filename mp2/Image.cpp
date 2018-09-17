#include "Image.h"
#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"
#include <iostream>
using cs225::PNG;
using cs225::HSLAPixel;
using namespace std;

void Image::lighten(){
// increase luminance by 0.1
// this = pointer to whatever image lighten got called on by
	int width = this->width();
	int height = this->height();
	for (int i = 0; i < width; i++){
		for (int j = 0; j < height; j++){
			HSLAPixel & pixel = this->getPixel(i, j);
				pixel.l += 0.1;
				if (pixel.l > 1.0)
					pixel.l = 1.0;
		}
	}
}

void Image::lighten(double amount){
// increase luminance by amount
	int width = this->width();
	int height = this->height();
	for (int i = 0; i < width; i++){
		for (int j = 0; j < height; j++){
			HSLAPixel & pixel = this->getPixel(i, j);
				pixel.l += amount;
				if (pixel.l > 1.0)
					pixel.l = 1.0;

		}
	}
}

void Image::darken(){
// decrease luminance by 0.1
	int width = this->width();
	int height = this->height();
	for (int i = 0; i < width; i++){
		for (int j = 0; j < height; j++){
			HSLAPixel & pixel = this->getPixel(i, j);
				pixel.l -= 0.1;
					if (pixel.l < 0.0)
						pixel.l = 0.0;
		}
	}
}

void Image::darken(double amount){
// decrease luminance by amount
	int width = this->width();
	int height = this->height();
	for (int i = 0; i < width; i++){
		for (int j = 0; j < height; j++){
			HSLAPixel & pixel = this->getPixel(i, j);
				pixel.l -= amount;
					if (pixel.l < 0)
						pixel.l = 0.0;
		}
	}
}

void Image::saturate(){
// increase saturation by 0.1
// this = pointer to whatever image lighten got called on by
	int width = this->width();
	int height = this->height();
	for (int i = 0; i < width; i++){
		for (int j = 0; j < height; j++){
			HSLAPixel & pixel = this->getPixel(i, j);
			if (pixel.s <= 0.9)
				pixel.s += 0.1;
		}
	}
}

void Image::saturate(double amount){
// increase saturation by amount
// this = pointer to whatever image lighten got called on by
// this = pointer to whatever image lighten got called on by
	int width = this->width();
	int height = this->height();
	for (int i = 0; i < width; i++){
		for (int j = 0; j < height; j++){
			HSLAPixel & pixel = this->getPixel(i, j);
			if (pixel.s + amount <= 1.0)
				pixel.s += amount;
		}
	}
}

void Image::desaturate(){
// decrease saturation by 0.1
// this = pointer to whatever image lighten got called on by
	int width = this->width();
	int height = this->height();
	for (int i = 0; i < width; i++){
		for (int j = 0; j < height; j++){
			HSLAPixel & pixel = this->getPixel(i, j);
			if (pixel.s >= 0.1)
				pixel.s -= 0.1;
		}
	}
}

void Image::desaturate(double amount){
// decrease saturation by amount
// this = pointer to whatever image lighten got called on by
	int width = this->width();
	int height = this->height();
	for (int i = 0; i < width; i++){
		for (int j = 0; j < height; j++){
			HSLAPixel & pixel = this->getPixel(i, j);
			if (pixel.s - amount >= 0)
				pixel.s -= amount;
		}
	}
}

void Image::grayscale(){
	int width = this->width();
	int height = this->height();
	for (int i = 0; i < width; i++){
		for (int j = 0; j < height; j++){
			HSLAPixel & pixel = this->getPixel(i, j);
			pixel.s = 0;
			pixel.l = 0;
		}
	}
}

void Image::rotateColor(double degrees){
// rotate color wheel by degrees
	int width = this->width();
	int height = this->height();
	for (int i = 0; i < width; i++){
		for (int j = 0; j < height; j++){
			HSLAPixel & pixel = this->getPixel(i, j);
			int hue = pixel.h + degrees;
			if (hue >= 360)
				hue = (double)(hue % 360);
			if (hue <0)
				hue += 360;
			pixel.h = hue;
		}
	}
}


void Image::illinify(){
	unsigned x, y;
	for (x = 0; x < this->width(); x++){
		for (y = 0; y < this->height(); y++){
			HSLAPixel & pixel = this->getPixel(x, y);
			
			if ((pixel.h > 113.5) && (pixel.h < 293.5)){
							pixel.h = 216;
			}
			else {
			pixel.h = 11; }
		}
	}
}

void Image::scale(double factor){
// scale the image by the given factor
/*
make copy of *this
save the original width and height
multiply dimensions by factor and save into new unsigned
resize(newwidth, newheight)
if (new width > original width)
for
	for 
		if (new width < original width)
			// scaling
			for 
				for


// multiply the for loop counters i and j by factor

*/
	
// make a new PNG with new dimensions


	int width = this->width();
	int height = this->height();
	int newWidth = width * factor;
	int newHeight = height * factor;
	PNG newImage = new PNG(this);
	newImage.size(newWidth, newHeight);
	
	






}

void Image::scale(unsigned w, unsigned h){
// scale the image based on given width and height
//	resize(w, h);
}


