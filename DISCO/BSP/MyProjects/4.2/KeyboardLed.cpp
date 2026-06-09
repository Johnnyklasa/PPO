#include "KeyboardLed.h"



KeyboardLed::KeyboardLed(unsigned char ucColumn) {
	pKeyboard = new Keyboard(ucColumn);
	pLed = new LedBoard(ucColumn);
}


ButtonState KeyboardLed::eRead(){
     ButtonState eState = pKeyboard->eRead();
     pLed->On(eState);
     return eState;
}

