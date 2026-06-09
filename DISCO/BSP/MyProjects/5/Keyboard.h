#pragma once
#include <stdint.h>
#include <stm32f429i_discovery_lcd.h>

constexpr unsigned int RectWidth = 80;
constexpr unsigned int RectHigh = 80;
constexpr unsigned int  Number0 = 48;

enum ButtonState {
	BUTTON_0 = 0,
	BUTTON_1 = 1,
	BUTTON_2 = 2,
	BUTTON_3 = 3,
	NONE =4};

class Keyboard{
public:
	Keyboard(unsigned int uiKeyboardPos);
	ButtonState eRead();
private:
	unsigned int uiButtonColumn;
};
