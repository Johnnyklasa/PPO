#ifndef STEPPER_H
#define STEPPER_H 
#include "led.h"
class Stepper : private Led{
	public:
	void StepRight(void);
	void StepLeft(void);
	Stepper(unsigned char ucStartPos=0);
	private:
	void Step(enum Step eStep);
	unsigned char ucLedCtr;
}; 
#endif
