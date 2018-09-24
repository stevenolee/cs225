#include "Image.h"
#include "StickerSheet.h"

int main() {

  //
  // Reminder:
  //   Before exiting main, save your creation to disk as myImage.png
  //
	Image meme;
	meme.readFromFile("meme.png");
	Image statement;
	statement.readFromFile("statement.png");
	Image valgrind;
	valgrind.readFromFile("valgrind.png");
	Image gdb;
	gdb.readFromFile("gdb.png");

	StickerSheet my_stickers(meme, 3);
	my_stickers.addSticker(statement, 80, 400);
	my_stickers.addSticker(valgrind, 500, 500);
	my_stickers.addSticker(gdb, 500, 350);

	my_stickers.render().writeToFile("myImage.png");

  return 0;
}
