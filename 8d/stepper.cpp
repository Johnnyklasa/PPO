#include "stepper.h"


enum Step{LEFT,RIGHT};

void Stepper::SetMode(unsigned char ucMode){
		ucInversion=ucMode;
	}

void Stepper::Step(enum Step eStep){
	if(eStep == LEFT){
		ucLedCtr--;
	}
	else if(eStep == RIGHT){
		ucLedCtr++;
	}
		ucLedCtr = ucLedCtr % 4;
	if (ucInversion==1){
			MyLedInv.On(ucLedCtr);
	}
	else {
			MyLed.On(ucLedCtr);
	}
		
}

void Stepper::StepLeft(void){
	Step(LEFT);
}



void Stepper::StepRight(void){
	Step(RIGHT);
}
