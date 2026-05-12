
#ifndef STEPPER_H
#define STEPPER_H
#include "led.h"
#include "ledinv.h"


class Stepper {
	
	private:
	unsigned char ucLedCtr;
	void Step(enum Step eStep);
	Led* pLed;
	
	public:
	void StepRight();
  void StepLeft();
	void SetLed (Led* pNewLed);
	
};

#endif
