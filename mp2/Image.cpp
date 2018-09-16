#include "Image.h"
#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"
using cs225::PNG;
using cs225::HSLAPixel;

void Image::lighten(){
// increase luminance by 0.1
// this = pointer to whatever image lighten got called on by
	int width = this->width();
	int height = this->height();
	for (int i = 0; i < width; i++){
		for (int j = 0; j < height; j++){
			HSLAPixel & pixel = this->getPixel(i, j);
			if (pixel.l <= 0.9)
				pixel.l += 0.1;
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
			if (pixel.l + amount <= 1.0)
				pixel.l += amount;
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
			if (pixel.l >= 0.1)
				pixel.l -= 0.1;
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
			if (pixel.l - amount >= 0)
				pixel.l -= amount;
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
			int current = pixel.h;
			if (current + degrees <= 360)
				current += degrees;
			else {
				current += degrees;
				while (current > 360){
					current -= 360;
				}
			}
		}
	}
}

void virtual Image::illinify(){
}

void Image::scale(double factor){
// scale the image by the given factor

}

void Image::scale(unsigned w, unsigned h){
// scale the image based on given width and height

}


