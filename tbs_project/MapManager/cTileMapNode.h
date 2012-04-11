/*
Date: 10/4/2012

Originale code from: http://irrlicht.sourceforge.net/forum/viewtopic.php?t=29947 by
8/11/08
cTileMapNode.h
Dan Bush
*/


#ifndef TILE_MAP_NODE_H
#define TILE_MAP_NODE_H

#include <vector>
#include "TileManager.h"
#include <irrlicht.h>

using namespace irr;
using namespace std;

struct sTile
{
	unsigned char tileset;
	unsigned char id;

	sTile(unsigned char t, unsigned char i){tileset = t; id = i;}
};


class cTileMapNode
{
private:
	vector<sTile> tiles;
	unsigned char bitflags;   //use for whatever you want :) e.g. maybe setting bit 1 means you can't walk there


public:
	cTileMapNode();
	~cTileMapNode();

	bool addTile(sTile t);
	bool removeTile();

	bool free();

	bool draw(IVideoDriver * driver, TileManager * pImages, int x, int y, irr::core::rect<s32> * r = 0);

	unsigned char getFlags();
	void setFlags(const unsigned char c);
	short getNumTiles();
	sTile getTileAt(const unsigned short num);



};



#endif
