
#include "stepper.h"
#include "keyboard.h"
void Delay(int iTimeInMs){

    int iCycle;

    int iNumberOfCycles = 10000 * iTimeInMs;

    

    for (iCycle = 0; iCycle < iNumberOfCycles; iCycle++) {}

}

Stepper MyStepper;
Keyboard MyKeyboard;
unsigned char ucInversion=0;


int main(){
		if( MyKeyboard.eRead()==BUTTON_4){
			ucInversion=1;
			}
    while(1){
        Delay(500);
				enum KeyboardState eState = MyKeyboard.eRead();
				if ( eState==BUTTON_1){
					MyStepper.StepLeft();
				}
				else if ( eState==BUTTON_2){
					MyStepper.StepRight();
				}

    }
} 
