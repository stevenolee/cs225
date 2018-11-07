/**
 * @file maptiles.cpp
 * Code for the maptiles function.
 */

#include <iostream>
#include <map>
#include "maptiles.h"

//#include "cs225/RGB_HSL.h"

using namespace std;


Point<3> convertToXYZ(LUVAPixel pixel) {
    return Point<3>( pixel.l, pixel.u, pixel.v );
}

MosaicCanvas* mapTiles(SourceImage const& theSource,
                       vector<TileImage>& theTiles)
{
    /**
     * @todo Implement this function!
     */
// create new MosaicCanvas
	int rows = theSource.getRows();
	int cols = theSource.getColumns();
	MosaicCanvas* canvas = new MosaicCanvas(rows, cols);
// create the KDTree
  vector<Point<3>> points;
//  points.reserve(theTiles.size());
  for (int i = 0; i < (int)theTiles.size(); i++) {
      Point<3> p = convertToXYZ(theTiles[i].getAverageColor());
		points.push_back(p);
  }

	KDTree<3> tree (points);
	

// set each tile
	for (int i = 0; i < rows; i++){
		for (int j = 0; j < cols; j++){
		    LUVAPixel pixel = theSource.getRegionColor(i, j);
			Point<3> close = tree.findNearestNeighbor(convertToXYZ(pixel));
			int index = 0;
			for (int x = 0; x < (int)theTiles.size(); x++){
				if (points[x] == close){
					index = x;
					break;
				}
			}	
			canvas->setTile(i, j, &theTiles[index]);
		}
	}

//	canvas->setTile(row, col, img);
	

    return canvas;
}

