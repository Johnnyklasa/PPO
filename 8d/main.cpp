#include "keyboard.h"
#include "stepper.h"

void Delay(int iTimeInMs){
	int iCycle;
	int iNumberOfCycles = 10000 * iTimeInMs;
	
	for (iCycle = 0; iCycle < iNumberOfCycles; iCycle++) {}
}

Stepper MyStepper;


int main(void)
{
	Keyboard MyKeyboard;
	
	if (MyKeyboard.eRead()==BUTTON_4){
		ucInversion=1;
	}
	else {
			ucInversion=0;
	}
	
	while(1){
		switch (MyKeyboard.eRead()){
			case BUTTON_1:
			MyStepper.StepRight();
			break;
			case BUTTON_2:
			MyStepper.StepLeft();
			break;
			default:
			break;
		}
		Delay(100);
		}
	
	
}

