#include <stm32f4xx_hal.h>

#include "KeyboardLed.h"

int main()
{


	KeyboardLed Keyboard(0);
	LedBoard* pLedBoard = new LedBoard(2);
	ButtonState eState;
	ButtonState ePreviousState= NONE;
	while(true) {
		eState = Keyboard.eRead();
		if(ePreviousState!=eState){
		switch(eState){
		case BUTTON_0:
		pLedBoard->On(3);
		break;
		case BUTTON_1:
		pLedBoard->On(2);
		break;
		case BUTTON_2:
		pLedBoard->On(1);
		break;
		case BUTTON_3:
		pLedBoard->On(0);
		break;
		default : pLedBoard->Off();
		break;
		}
		}
		ePreviousState=eState;




	HAL_Delay(100);
	}
}



