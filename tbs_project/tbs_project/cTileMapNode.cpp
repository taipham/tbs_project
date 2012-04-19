/*
Date: 4/4/2012

Originale code from: http://irrlicht.sourceforge.net/forum/viewtopic.php?t=29947 by
8/11/08
cTileMapNode.cpp
Dan Bush
*/
#include "cTileMapNode.h"
#include <irrlicht.h>

using namespace irr;
using namespace video;

//cTileMapNode
cTileMapNode::cTileMapNode()
{
	free();
	bitflags = 0;
}

//~cTileMapNode()
cTileMapNode::~cTileMapNode()
{
	free();
}

//free()
bool cTileMapNode::free()
{
	tiles.clear();
	return true;
}

//addTile()
bool cTileMapNode::addTile(sTile t)
{
	tiles.push_back(t);
	return true;
}

//removeTile()
bool cTileMapNode::removeTile()
{
	if(!tiles.empty())
		tiles.erase(tiles.end() - 1);
	return true;
}

//draw()
bool cTileMapNode::draw(IVideoDriver * driver, TileManager * pImages, int x, int y, irr::core::rect<s32> * r)
{

	std::vector<sTile>::iterator itr;
	for ( itr = tiles.begin(); itr != tiles.end(); ++itr )
	{
		pImages->draw(driver, (*itr).tileset, (*itr).id, x, y, r);
	}


	return true;
}


void cTileMapNode::setFlags(const unsigned char c)
{
	bitflags = c;
}

unsigned char cTileMapNode::getFlags()
{
	return bitflags;
}



//getNumTiles()
short cTileMapNode::getNumTiles()
{
	return tiles.size();
}


sTile cTileMapNode::getTileAt(const unsigned short num)
{
	if (num >= tiles.size())
		return tiles[tiles.size()-1];

	return tiles[num];
}
