#include "StickerSheet.h"

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
/*	for (unsigned i = 0; i < max_stickers; i++){
		delete stickers[i];

	}*/
	delete[] x_coordinate;
	delete[] y_coordinate;
	delete[] stickers;
}

void StickerSheet::_copy(const StickerSheet &other){
// copy the Image: myImage
	myImage = other.myImage;
	max_stickers = other.max_stickers;
// copy x and y coordinate arrays
	x_coordinate = new unsigned [other.max_stickers];
	y_coordinate = new unsigned [other.max_stickers];
	stickers = new Image* [max_stickers];
	for (unsigned i = 0; i < max_stickers; i++){
		x_coordinate[i] = other.x_coordinate[i];
		y_coordinate[i] = other.y_coordinate[i];
		stickers[i] = other.stickers[i];
	}
}


StickerSheet::StickerSheet(const StickerSheet &other){
	_copy(other);
}

StickerSheet::~StickerSheet(){
	_destroy();
}

const StickerSheet& StickerSheet::operator=(const StickerSheet &other){
	if (this != &other){
		_copy(other);
	}
	return *this;
}


void StickerSheet::changeMaxStickers(unsigned max){
	unsigned previous_max = max_stickers;
	max_stickers = max;
	Image** new_sheet = new Image* [max_stickers];
	for (unsigned i = 0; i < max_stickers; i++){
		if ((i >= previous_max) || (stickers[i] = NULL)){
			new_sheet[i] = NULL;
		} else {
			new_sheet[i] = stickers[i];
		}
	}
	stickers = new_sheet;
}

int StickerSheet::addSticker(Image &sticker, unsigned x, unsigned y){
	if (stickers[max_stickers - 1] != NULL){return -1;}
	unsigned count = 0;
// find where the most recent sticker is
	while (stickers[count] != NULL){count++;}
	stickers[count] = &sticker;
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
// DO I NEED A "DELETE"
	while (index < max_stickers - 1){
		if (stickers[index + 1] != NULL){
			stickers[index] = stickers[index + 1];
		} else {
			stickers[index] = NULL;
		}
		index++;
	}
// set the last layer to NULL
	stickers[max_stickers - 1] = NULL;	
}

Image *StickerSheet::getSticker(unsigned index) const{
	if ((index >= max_stickers) || (stickers[index] == NULL)){return NULL;}
	Image *pointer = stickers[index];
	return pointer;
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
