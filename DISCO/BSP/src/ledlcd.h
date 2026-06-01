#pragma once
#include <stdint.h>
class LedLcd{
	public:
	LedLcd(unsigned int uiLedColumn);
	void On(unsigned int uiLedCtr);
	private:
	unsigned int uiCurrOn;
	unsigned int uiLedPos;
	void DrawButton(uint32_t FillColor, uint8_t number);
};

