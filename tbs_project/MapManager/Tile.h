/***
Date: 4/4/2012
Tai Pham
Hold description of a single tile, including its stats bonus
Credit: insprired from http://irrlicht.sourceforge.net/forum/viewtopic.php?t=29947
***/

#ifndef TILE_H
#define TILE_H

#include <irrlicht.h>
using namespace irr;
enum e_tile_type
{
	// TODO
};

struct s_stat_bonus
{
	int attack;
	int defense;
	int avoid;
};

struct s_tile
{
	ITexture * texture;
	unsigned short width;
	unsigned short height;
	unsigned short collumns;

	enum e_tile_type type;
	struct s_stat_bonus stat_bonus;
};

#endif