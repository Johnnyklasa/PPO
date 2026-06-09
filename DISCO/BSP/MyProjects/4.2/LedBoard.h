#pragma once
#include <stdint.h>
class LedBoard{
	public:
	LedBoard(unsigned int uiLedColumn);
	void On(unsigned int uiLedCtr);
	void Off();
	private:
	unsigned int uiCurrOn;
	unsigned int uiLedPos;
	void DrawButton(uint32_t FillColor, uint8_t number);
};

