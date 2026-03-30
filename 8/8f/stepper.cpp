#include <LPC213X.H>
#include "stepper.h"


enum Step{LEFT,RIGHT};


void Stepper:: SetLed (Led* pNewLed){
	pLed = pNewLed;
}

void Stepper::Step(enum Step eStep){

    if(eStep == LEFT){

        ucLedCtr--;

        ucLedCtr = ucLedCtr % 4;
    }
    else if(eStep == RIGHT){
        ucLedCtr++;
        ucLedCtr = ucLedCtr % 4;

    }
		pLed->On(ucLedCtr);

}





void Stepper::StepLeft(void){

    Step(LEFT);

}

void Stepper::StepRight(void){

    Step(RIGHT);

} 

