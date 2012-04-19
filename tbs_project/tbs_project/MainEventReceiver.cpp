#include "MainEventReceiver.h"


MainEventReceiver::MainEventReceiver()
{
	for (u32 i=0; i<KEY_KEY_CODES_COUNT; ++i)
		key_down[i] = false;
}

bool MainEventReceiver::OnEvent(const SEvent& event)
{
	// Remember whether each key is down or up
	if (event.EventType == irr::EET_KEY_INPUT_EVENT)
		key_down[event.KeyInput.Key] = event.KeyInput.PressedDown;

	return false;
}

bool MainEventReceiver::is_key_down(EKEY_CODE keyCode) const
{
	return key_down[keyCode];
}

void MainEventReceiver::release_key(EKEY_CODE keyCode)
{
	key_down[keyCode] = false;
}