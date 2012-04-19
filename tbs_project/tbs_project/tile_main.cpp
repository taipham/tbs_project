#include "TileManager.h"
#include "cTileMap.h"
#include <irrlicht.h>
#include "driverChoice.h"
#include "MainEventReceiver.h"
#include "test_global.h"

using namespace irr;

using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

#ifdef _IRR_WINDOWS_
#pragma comment(lib, "Irrlicht.lib")
#endif

#define START_X 240
#define START_Y 240


int main()
{
	//TileManager t;

	// ask user for driver
	video::E_DRIVER_TYPE driverType=driverChoiceConsole();
	if (driverType==video::EDT_COUNT)
		return 1;

	// create device

	IrrlichtDevice *device = createDevice(driverType,
		core::dimension2d<u32>(800, 600));

	if (device == 0)
		return 1; // could not create selected driver.

	device->setWindowCaption(L"Irrlicht Engine - 2D Graphics Demo");

	// Event receiver
	MainEventReceiver receiver;
	device->setEventReceiver(&receiver);
	video::IVideoDriver* driver = device->getVideoDriver();

	

	//this will create a map from scratch
	cTileMap map;
	map.createNodes(15,15);
	map.setNodeDimensions(32,32);
	map.setViewPortDimensions(800,600);
	//load texture with 32x32 tiles and 10 collumns
	//pDriver is a pointer to IVideoDriver
	//t.load(driver, "media/dark_forest.png", 32, 32, 8, SColor(SColor(255,255,0,255)));
	map.getTileManager()->load(driver, "../MapImage/test_map.bmp", 32, 32, 15, SColor(255,255,0,255));

	cout << test_map[1][3] << endl;
	int i = 0;
	for(int y = 0; y < 15; y++)
	{
		for(int x = 0; x < 15; x++)
		{   
			map.addTile(sTile(0,i), x, y);
			map.set_tile_info(test_map[y][x], x,y);
			//cout << test_map[x][y];
			i++;
		}
		//cout << endl;
	}

	//save this for later
    map.save("map.txt");


	int current_x = START_X;
	int current_y = START_Y;
	int nodeX = (current_x-16)/32;
	int nodeY = (current_y-16)/32;
	cout << nodeX << endl;
	cout << nodeY << endl;

	while(device->run() && driver)
	{
		if (device->isWindowActive())
		{
			// process key event
			/*
			TODO
				Out fo bound checking
			*/
			
			//cout << nodeY << endl;
			if (receiver.is_key_down(irr::KEY_KEY_W))
			{
				int nodeX = (current_x-16)/32;
				int nodeY = (current_y-32-16)/32;

				if(map.get_tile_info(nodeX, nodeY) == '0')
				{
					current_y -= 32;
				}
				receiver.release_key(irr::KEY_KEY_W);
			}
			else if (receiver.is_key_down(irr::KEY_KEY_S))
			{
				int nodeX = (current_x-16)/32;
				int nodeY = (current_y+32-16)/32;

				if(map.get_tile_info(nodeX, nodeY) == '0')
				{
					current_y += 32;
				}
				receiver.release_key(irr::KEY_KEY_S);
			}
			else if (receiver.is_key_down(irr::KEY_KEY_A))
			{
				int nodeX = (current_x-32-16)/32;
				int nodeY = (current_y-16)/32;

				if(map.get_tile_info(nodeX, nodeY) == '0')
				{
					current_x -= 32;
				}
				receiver.release_key(irr::KEY_KEY_A);
			}
			else if (receiver.is_key_down(irr::KEY_KEY_D))
			{
				int nodeX = (current_x+32-16)/32;
				int nodeY = (current_y-16)/32;

				if(map.get_tile_info(nodeX, nodeY) == '0')
				{
					current_x += 32;
				}
				receiver.release_key(irr::KEY_KEY_D);
			}

			driver->beginScene(true, true, video::SColor(255,120,102,136));
			//this part would go between your beginscene and endscene
			//t.draw(driver, 0, 0, 0, 0); //draws tile #3 coordinates (64,0) from texture at (0,0) on the screen.
			//t.draw(driver, 0, 29, 64, 64); //draws tile #11 coordinates (0,32) from texture at (64,64) on the screen.
			map.draw(driver, 0, 0);

			// draw a transparent rectangle on the current position
			driver->draw2DRectangle(video::SColor(100,255,255,255),
				core::rect<s32>(current_x - 16, current_y - 16, current_x + 16, current_y + 16));

			driver->endScene();
		}
	}

	device->drop();



	return 0;
}