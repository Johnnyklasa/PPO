#include "led.h"
#include "stepper.h"

void Delay(int iTimeInMs){

    int iCycle;

    int iNumberOfCycles = 10000 * iTimeInMs;

    

    for (iCycle = 0; iCycle < iNumberOfCycles; iCycle++) {}

}

Led myLed;
Stepper myStepper;


int main(void)

{



    myLed.Init();


    while(1){

        Delay(100);

        myStepper.StepLeft();
			
    }
} 

