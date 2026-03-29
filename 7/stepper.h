
#ifndef STEPPER_H
#define STEPPER_H
#include "led.h"

class Stepper {
	
	private:
	unsigned char ucLedCtr;
	void Step(enum Step eStep);
	Led MyLed;
	
	public:
	Stepper(unsigned char ucStartPos=0);
	void StepRight();
  void StepLeft();
	
};

#endif

