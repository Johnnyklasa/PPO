#include "KeyboardLed.h"



KeyboardLed::KeyboardLed(unsigned char ucColumn) {
	pLed = new LedBoard(ucColumn);
	pKeyboard = new Keyboard(ucColumn);
	ePreviousState=NONE;

}


ButtonState KeyboardLed::eRead(){
    ButtonState eState = pKeyboard->eRead();
    pLed->On(eState);

    return eState;
}
