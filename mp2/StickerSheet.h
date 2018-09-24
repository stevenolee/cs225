/**
 * @file StickerSheet.h
 * Contains your declaration of the interface for the StickerSheet class.
 */
#pragma once
#include "Image.h"
#include <vector>

using namespace std;

class StickerSheet {
	public:
		StickerSheet(const Image &picture, unsigned max);
		StickerSheet(const StickerSheet &other);
		~StickerSheet();
		const StickerSheet &operator=(const StickerSheet &other);
		void changeMaxStickers (unsigned max);
		int addSticker (Image &sticker, unsigned x, unsigned y);
		bool translate (unsigned index, unsigned x, unsigned y);
		void removeSticker (unsigned index);
		Image *	getSticker (unsigned index) const;
		Image render () const;

// my copy function
		Image copy_StickerSheet();

	private:
// delete function
		void _destroy();
// copy function
		void _copy(const StickerSheet &other);
// variables
		unsigned max_stickers;
		unsigned* x_coordinate;
		unsigned* y_coordinate;
		Image** stickers;
		Image myImage;
};
