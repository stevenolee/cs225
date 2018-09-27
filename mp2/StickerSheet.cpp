#include "StickerSheet.h"
#include <iostream>

using namespace std;

StickerSheet::StickerSheet(const Image &picture, unsigned max){
	myImage = picture;
	max_stickers = max;
	x_coordinate = new unsigned [max_stickers];
	y_coordinate = new unsigned [max_stickers];
	stickers = new Image* [max_stickers];
	for (unsigned i = 0; i < max_stickers; i++){
		x_coordinate[i] = 0;
		y_coordinate[i] = 0;
		stickers[i] = NULL;
	}
}

void StickerSheet::_destroy(){
	for (unsigned i = 0; i < max_stickers; i++){
		if (stickers[i] != NULL){
			delete stickers[i];
		}
	}
	delete[] x_coordinate;
//	x_coordinate = NULL;
	delete[] y_coordinate;
//	y_coordinate = NULL;
	delete[] stickers;
//	stickers = NULL;
}

void StickerSheet::_copy(const StickerSheet &other){
// copy the Image: myImage
	this->myImage = other.myImage;
	this->max_stickers = other.max_stickers;
// copy x and y coordinate arrays
	this->stickers = new Image*[max_stickers];
	this->x_coordinate = new unsigned [max_stickers];
	this->y_coordinate = new unsigned [max_stickers];
	for (unsigned i = 0; i < max_stickers; i++) {
		x_coordinate[i] = 0;
		y_coordinate[i] = 0;
		stickers[i] = NULL;
	}
	for (unsigned i = 0; i < max_stickers; i++){
		if (other.stickers[i] != NULL) {
			this->stickers[i] = new Image(*(other.stickers[i]));
		}
		x_coordinate[i] = other.x_coordinate[i];
		y_coordinate[i] = other.y_coordinate[i];
	}
}


StickerSheet::StickerSheet(const StickerSheet &other){
	_copy(other);
}

StickerSheet::~StickerSheet(){
	_destroy();
}

const StickerSheet& StickerSheet::operator=(const StickerSheet &other){

	this->_destroy();
	this->_copy(other);
	
	return *this;
}

void StickerSheet::changeMaxStickers(unsigned max){

	unsigned previous_max = max_stickers;
	max_stickers = max;
	Image** new_stickers = new Image* [max_stickers];
	unsigned* new_x = new unsigned [max_stickers];
	unsigned* new_y = new unsigned [max_stickers];
	unsigned smaller = (previous_max < max_stickers) ? previous_max : max_stickers;

// DEEP copy what you can
	for (unsigned i = 0; i < smaller; i++){
		new_stickers[i] = stickers[i];
		new_x[i] = x_coordinate[i];
		new_y[i]  = y_coordinate[i];
	}

// if longer
	if (max_stickers > previous_max) {
		for (unsigned i = smaller; i < max_stickers; i++){
			new_stickers[i] = NULL;
			new_x[i] = 0;
			new_y[i] = 0;
		}
	}

// if shorter
	if (max_stickers < previous_max) {
		for (unsigned i = smaller; i < previous_max; i++){
				delete stickers[i];
				stickers[i] = NULL;
		}
	}

// route the pointers
	Image** pointer = stickers;
	unsigned* x_point = x_coordinate;
	unsigned* y_point = y_coordinate;
	stickers = new_stickers;
	x_coordinate = new_x;
	y_coordinate = new_y;
	new_stickers = NULL;
	new_x = NULL;
	new_y = NULL;
	delete[] pointer;
	delete[] x_point;
	delete[] y_point;

}

int StickerSheet::addSticker(Image &sticker, unsigned x, unsigned y){
	if (stickers[max_stickers - 1] != NULL){return -1;}
	unsigned count = 0;
// find where the most recent sticker is
	while (stickers[count] != NULL){count++;}
	stickers[count] = new Image(sticker);
	x_coordinate[count] = x;
	y_coordinate[count] = y;
	return count;
}

bool StickerSheet::translate(unsigned index, unsigned x, unsigned y){
// check if layer exists
	if ((index > max_stickers) || (stickers[index] == NULL)){return false;}
// change the coordinates
	x_coordinate[index] = x;
	y_coordinate[index] = y;
	return true;
}

void StickerSheet::removeSticker(unsigned index){
	Image* insert_pointer = stickers[index];
// DO I NEED A "DELETE"
	for (unsigned i = index; i < max_stickers - 1; i++){
// iterate through the stickers array
		if (stickers[index + 1] != NULL){
			stickers[index] = stickers[index + 1];
			x_coordinate[index] = x_coordinate[index+1];
			y_coordinate[index] = y_coordinate[index+1];
		} else {
			if (stickers[index] != NULL){
				x_coordinate[index] = 0;
				y_coordinate[index] = 0;
				stickers[index] = NULL;
			}
		}
	}
	delete insert_pointer;
	insert_pointer = NULL;
// set the last layer to NULL
	stickers[max_stickers - 1] = NULL;	
	x_coordinate[max_stickers - 1] = 0;
	y_coordinate[max_stickers - 1] = 0;

}

Image *StickerSheet::getSticker(unsigned index) const{
	if ((index >= max_stickers) || (stickers[index] == NULL)){return NULL;}
	return stickers[index];
}

Image StickerSheet::render() const{
// draw the base image
	Image finalImage = myImage;
// add the stickers
	for (unsigned i = 0; i < max_stickers; i++){
		if (stickers[i] == NULL){break;}
// x and y coordinates of sticker
		unsigned x = x_coordinate[i];
		unsigned y = y_coordinate[i];
// pointer to the sticker
		Image* stick = stickers[i];
// width and height of the sticker
		unsigned width = stick->width();
		unsigned height = stick->height();
// check if stickers exceed current width and height
		if (x + width > finalImage.width()){
			finalImage.resize(x + width, y);
		}
		if (y + height > finalImage.height()){
			finalImage.resize(x, y + height);
		}
		for (unsigned counter1 = 0; counter1 < width; counter1++){
			for (unsigned counter2 = 0; counter2 < height; counter2++){
// pixel at the x, y coordinates for base image and sticker
				HSLAPixel& image_pixel = finalImage.getPixel(x + counter1, y + counter2);
				HSLAPixel& sticker_pixel = stick->getPixel(counter1, counter2);
				if (sticker_pixel.a == 0){continue;}
				image_pixel.h = sticker_pixel.h;
				image_pixel.s = sticker_pixel.s;
				image_pixel.l = sticker_pixel.l;
				image_pixel.a = sticker_pixel.a;
			}
		}
	}
	return finalImage;
}

/*
Image StickerSheet::copy_Image(StickerSheet){
	for (int i = 0; i < max - 1; i++){
		*(this->stickers[i]) = 
	}
}
*/
