/***
Date: 4/4/2012

Originale code from: http://irrlicht.sourceforge.net/forum/viewtopic.php?t=29947 by
7/31/08
TileManager.cpp
Dan Bush
***/

#include "TileManager.h"
#include <string>
#include <iostream>
#include <vector>

using namespace irr;
using namespace video;
using namespace std;
using namespace core;

//TileManager()
TileManager::TileManager()
{
	free();
}

//~TileManager()
TileManager::~TileManager()
{
	free();
}

//load()
//loads a tileset given a texture, the width and hieght of the tiles, the number of collumns
//and the transparent color key
bool TileManager::load(IVideoDriver * p, char * s, const unsigned short w, const unsigned short h, const unsigned short c, SColor key)
{   
	s_tile set;

	set.texture = p->getTexture(s);
	set.width = w;
	set.height = h;
	set.collumns = c;
	tile_set.push_back(set);


	p->makeColorKeyTexture(tile_set[tile_set.size() - 1].texture, key);


	return true;
}

//free()
bool TileManager::free()
{
	//dealloc the vector
	tile_set.clear();
	return true;
}



//draw()
//draws a tile at x, y
//you probably wont call this directly very often (unless maybe you're writing an editor)
bool TileManager::draw(IVideoDriver * pDriver, const unsigned short texNum, const unsigned short tileNum, const short x, const short y, irr::core::rect<s32> * r)
{

	// get the source coordinates
	int sx = (tileNum % tile_set.at(texNum).collumns) * tile_set.at(texNum).width;
	int sy = (tileNum / tile_set.at(texNum).collumns) * tile_set.at(texNum).height;


	pDriver->draw2DImage(tile_set.at(texNum).texture,position2d<s32>(x,y), rect<s32>(sx, sy, sx + tile_set.at(texNum).width, sy + tile_set.at(texNum).height),
		r, SColor(255,255,255,255), true);

	return true;
}

//getNumTileSets()
short TileManager::getNumTileSets()
{
	return tile_set.size();
}

//getTileSetAt()
s_tile TileManager::getTileSetAt(const unsigned short i)
{
	if(i >= tile_set.size())
		return tile_set[tile_set.size()-1];

	else
		return tile_set[i];
}