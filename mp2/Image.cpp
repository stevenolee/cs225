#include "Image.h"
#include "cs225/PNG.h"
using cs225::PNG;

// how to get the PNG
void lighten(){
// increase luminance by 0.1
// this, pointer to whatever image lighten got called on by
	for (int i = 0; i < width_; i++){
		for (int j = 0; j < height_; j++){
			pixel = HSLA & getPixel(i, j);
		}
	}
}

void lighten(double amount){
// increase luminance by amount
	for (int i = 0; i < width_; i++){
		for (int j = 0; j < height_; j++){
			pixel = HSLA & getPixel(i, j);
		}
	}
}

void darken(){
// decrease luminance by 0.1
	for (int i = 0; i < width_; i++){
		for (int j = 0; j < height_; j++){
			pixel = HSLA & getPixel(i, j);
		}
	}
}

void darken(double amount){
// decrease luminance by amount
	for (int i = 0; i < width_; i++){
		for (int j = 0; j < height_; j++){
			pixel = HSLA & getPixel(i, j);
		}
	}
}

void saturate(){
// increase saturation by 0.1
	for (int i = 0; i < width_; i++){
		for (int j = 0; j < height_; j++){
			pixel = HSLA & getPixel(i, j);
		}
	}
}

void saturate(double amount{
// increase saturation by amount
	for (int i = 0; i < width_; i++){
		for (int j = 0; j < height_; j++){
			pixel = HSLA & getPixel(i, j);
		}
	}
}

void desaturate(){
// decrease saturation by 0.1
	for (int i = 0; i < width_; i++){
		for (int j = 0; j < height_; j++){
			pixel = HSLA & getPixel(i, j);
		}
	}
}

void desaturate(double amount){
// decrease saturation by amount
	for (int i = 0; i < width_; i++){
		for (int j = 0; j < height_; j++){
			pixel = HSLA & getPixel(i, j);
		}
	}
}

void grayscale(){
	for (int i = 0; i < width_; i++){
		for (int j = 0; j < height_; j++){
			pixel = HSLA & getPixel(i, j);
		}
	}
}

void rotateColor(double degrees){
// rotate color wheel by degrees
}

void illinify(){
}

void scale(double factor){
// scale the image by the given factor
}

void scale(unsigned w, unsigned h){
// scale the image based on given width and height

}


