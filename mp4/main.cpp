
#include "cs225/PNG.h"
#include "FloodFilledImage.h"
#include "Animation.h"

#include "imageTraversal/DFS.h"
#include "imageTraversal/BFS.h"

#include "colorPicker/RainbowColorPicker.h"
#include "colorPicker/GradientColorPicker.h"
#include "colorPicker/GridColorPicker.h"
#include "colorPicker/SolidColorPicker.h"
#include "colorPicker/MyColorPicker.h"

using namespace cs225;

int main() {

  // @todo [Part 3]
  // - The code below assumes you have an Animation called `animation`
  // - The code provided below produces the `myFloodFill.png` file you must
  //   submit Part 3 of this assignment -- uncomment it when you're ready.
  
	PNG pic;
 	pic.readFromFile("bread.png");
	FloodFilledImage image(pic);
	DFS dfs(pic, Point(40, 40), 0.05);
	RainbowColorPicker rainbow(0.05);
	image.addFloodFill( dfs, rainbow );
	DFS dfs1(pic, Point(55, 55), 0.1);
	MyColorPicker mine;
	image.addFloodFill(dfs1, mine);

	Animation animation = image.animate(750);

  
  PNG lastFrame = animation.getFrame( animation.frameCount() - 1 );
  lastFrame.writeToFile("myFloodFill.png");
  animation.write("myFloodFill.gif");
  


  return 0;
}
