#pragma once
#include "KeyboardTs.h"
#include "ledlcd.h"

class KeyboardTsLcd{
	public:
	KeyboardTsLcd(unsigned char ucColumn);
	ButtonState eRead();
	private:
	LedLcd *pLed;
	KeyboardTs *pKeyboard;
};
