#ifndef STEPPER_H
#define STEPPER_H
#include "led.h"

class Stepper : public Led {
	
	private:
	unsigned char ucLedCtr;
	void Step(enum Step eStep);
	
	public:
	void StepRight(void);
  void StepLeft(void);
	
};

#endif

