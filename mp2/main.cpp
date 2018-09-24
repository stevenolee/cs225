#include "Image.h"
#include "StickerSheet.h"
#include <iostream>
int main() {

  //
  // Reminder:
  //   Before exiting main, save your creation to disk as myImage.png
  //

	Image meme;
	meme.readFromFile("meme1.resized.png");
//	meme.readFromFile("meme.png");
	Image statement;
	statement.readFromFile("statement.png");
	Image valgrind;
	valgrind.readFromFile("valgrind.png");
	Image gdb;
	gdb.readFromFile("gdb.png");

	StickerSheet my_stickers(meme, 3);
	my_stickers.addSticker(statement, 200, 600);
	my_stickers.addSticker(valgrind, 830, 700);
	my_stickers.addSticker(gdb, 845, 400);
//	my_stickers.addSticker(statement, 20, 250);
//	my_stickers.addSticker(valgrind, 250, 250);
//	my_stickers.addSticker(gdb, 250, 250);
	my_stickers.render().writeToFile("myImage.png");

  return 0;
}
