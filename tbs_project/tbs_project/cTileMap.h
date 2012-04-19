/*
Originale code from: http://irrlicht.sourceforge.net/forum/viewtopic.php?t=29947 by
8/11/08
cTileMap.h
Dan Bush

Modified: Tai Pham
4/18/2012
*/
#ifndef TILE_MAP_H
#define TILE_MAP_H

#include"TileManager.h"
#include"cTileMapNode.h"

using namespace std;

struct sMapHeader {

	unsigned short width;
	unsigned short height;
	unsigned short nWidth;
	unsigned short nHeight;
}; 

class cTileMap
{
private:
	ITexture * map;
	TileManager manager;
	vector<vector<cTileMapNode>> nodes;

	unsigned short maxNodeX;
	unsigned short maxNodeY;
	unsigned short nodeWidth;
	unsigned short nodeHeight;

	unsigned short cameraX;
	unsigned short cameraY;
	unsigned short viewPortWidth;
	unsigned short viewPortHeight;

public:
	cTileMap();
	~cTileMap();

	bool freeNodes();

	bool draw(IVideoDriver * driver, const short drawX, const short drawY);

	bool load(IVideoDriver * driver, const std::string s);
	bool save(const std::string s);

	bool setNodeDimensions(const unsigned short w,const  unsigned short h);

	bool createNodes(const unsigned short x, const unsigned y);


	bool setViewPortDimensions(const unsigned short w, const unsigned short h);
	bool setCamera(const short x, const short y);


	unsigned short getCameraX();
	unsigned short getCameraY();
	TileManager * getTileManager();
	vector<vector<cTileMapNode>> * getNodes();

	bool addTile(sTile t, unsigned int nodeX, unsigned int nodeY);
	bool set_tile_info(unsigned char c, unsigned int nodeX, unsigned int nodeY);

	unsigned char get_tile_info(unsigned int nodeX, unsigned int nodeY);
};



#endif