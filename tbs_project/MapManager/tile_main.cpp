#include "TileManager.h"
#include "cTileMap.h"
#include <irrlicht.h>
#include "driverChoice.h"

using namespace irr;

using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

#ifdef _IRR_WINDOWS_
#pragma comment(lib, "Irrlicht.lib")
#endif

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

	video::IVideoDriver* driver = device->getVideoDriver();


	//this will create a map from scratch
	cTileMap map;
	map.createNodes(8,20);
	map.setNodeDimensions(32,32);
	map.setViewPortDimensions(800,600);
	//load texture with 32x32 tiles and 10 collumns
	//pDriver is a pointer to IVideoDriver
	//t.load(driver, "media/dark_forest.png", 32, 32, 8, SColor(SColor(255,255,0,255)));
	map.getTileManager()->load(driver, "../MapImage/dark_forest.png", 32, 32, 8, SColor(255,255,0,255));

	int i = 0;
	for(int y = 0; y < 20; y++)
	{
		for(int x = 0; x < 8; x++)
		{   
			map.addTile(sTile(0,i), x, y);
			i++;
		}
	}

	//save this for later
    map.save("map.txt");


	while(device->run() && driver)
	{
		if (device->isWindowActive())
		{
			driver->beginScene(true, true, video::SColor(255,120,102,136));
			//this part would go between your beginscene and endscene
			//t.draw(driver, 0, 0, 0, 0); //draws tile #3 coordinates (64,0) from texture at (0,0) on the screen.
			//t.draw(driver, 0, 29, 64, 64); //draws tile #11 coordinates (0,32) from texture at (64,64) on the screen.
			map.draw(driver, 0, 0);
			driver->endScene();
		}
	}

	device->drop();



	return 0;
}