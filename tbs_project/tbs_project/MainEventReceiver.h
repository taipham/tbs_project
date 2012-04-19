/***
4/12/2012
Main Event Handler for the project
***/

#ifndef MAINEVENTRECEIVER_H
#define MAINEVENTRECEIVER_H

#include <irrlicht.h>
using namespace irr;

using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

#ifdef _IRR_WINDOWS_
#pragma comment(lib, "Irrlicht.lib")
#endif

class MainEventReceiver : public IEventReceiver
{
public:
	MainEventReceiver();
	virtual bool OnEvent(const SEvent& event);
	virtual bool is_key_down(EKEY_CODE keyCode) const;
	void release_key(EKEY_CODE keyCode);
private:
    bool key_down[KEY_KEY_CODES_COUNT];

};

#endif