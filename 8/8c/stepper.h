
#ifndef STEPPER_H
#define STEPPER_H
#include "led.h"
#include "ledinv.h"


class Stepper {
	
	private:
	unsigned char ucLedCtr;
	void Step(enum Step eStep);
	Led MyLed;
	LedInv MyLedInv;
	
	public:
	void StepRight();
  void StepLeft();
	
};

#endif
