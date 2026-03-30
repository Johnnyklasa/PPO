
#include "stepper.h"
#include "keyboard.h"
void Delay(int iTimeInMs){

    int iCycle;

    int iNumberOfCycles = 10000 * iTimeInMs;

    

    for (iCycle = 0; iCycle < iNumberOfCycles; iCycle++) {}

}

Stepper myStepper;
Keyboard myKeyboard;

int main(){
	
    while(1){
        Delay(500);
				enum KeyboardState eState = myKeyboard.eRead();
				if ( eState==BUTTON_1){
					myStepper.StepLeft();
				}
				else if ( eState==BUTTON_2){
					myStepper.StepRight();
				}
    }
} 
