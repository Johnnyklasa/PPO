#include <LPC213X.H>
#include "stepper.h"
#include "led.h"

enum Step{LEFT,RIGHT};
extern Led myLed;


void Stepper::Step(enum Step eStep){

    if(eStep == LEFT){

        ucLedCtr--;

        ucLedCtr = ucLedCtr % 4;

        myLed.On(ucLedCtr);

    }

    else if(eStep == RIGHT){

        ucLedCtr++;

        ucLedCtr = ucLedCtr % 4;

        myLed.On(ucLedCtr);

    }else{

    }

}

void Stepper::StepLeft(void){

    Step(LEFT);

}

void Stepper::StepRight(void){

    Step(RIGHT);

} 










