#ifndef STEPPER_H
#define STEPPER_H


class Stepper{
	
	private:
	unsigned char ucLedCtr;
	void Step(enum Step eStep);
	
	public:
	void StepRight(void);
  void StepLeft(void);
	
};

#endif
