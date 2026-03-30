
#include "stepper.h"
#include "keyboard.h"
#include  "ledpos.h"
void Delay(int iTimeInMs){

    int iCycle;

    int iNumberOfCycles = 10000 * iTimeInMs;

    

    for (iCycle = 0; iCycle < iNumberOfCycles; iCycle++) {}

}

Stepper MyStepper;
Keyboard MyKeyboard;


Led *pLed;

int main(){
	
		if( MyKeyboard.eRead()==BUTTON_4){
			pLed = new LedInv();
			}
		else{
			pLed = new LedPos();
		}
		MyStepper.SetLed(pLed);
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
