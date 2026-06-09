#include <stm32f4xx_hal.h>

#include "KeyboardLed.h"

int main()
{

	KeyboardLed Keyboard(0);
	LedBoard Led(2);
	while(true) {
		ButtonState eState = Keyboard.eRead();
		if (eState!=NONE){
			Led.On(3-eState);
		}
		else {
			Led.On(NONE);
		}

	HAL_Delay(100);
	}
}


