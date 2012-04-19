/***
Date: 4/4/2012

Originale code from: http://irrlicht.sourceforge.net/forum/viewtopic.php?t=29947 by
7/31/08
TileManager.cpp
Dan Bush
***/


#ifndef TILE_MANAGER_H
#define TILE_MANAGER_H

#include <irrlicht.h>
#include <string>
#include <vector>

using namespace irr;
using namespace video;
using namespace std;

#include "Tile.h"

class TileManager
{
private:

	vector<s_tile> tile_set;

public:
	TileManager();
	~TileManager();

	bool load(IVideoDriver * p, char * s, const unsigned short w, const unsigned short h, const unsigned short c, SColor key);
	bool free();
	bool draw(IVideoDriver * pDriver, const unsigned short texNum, const unsigned short tileNum, const short x, const short y, irr::core::rect<s32> * r = 0);

	short getNumTileSets();
	s_tile getTileSetAt(const unsigned short i);
};


#endif

