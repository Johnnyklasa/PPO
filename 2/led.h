#ifndef LED_H
#define LED_H

class Led{

    private:
    unsigned char ucLedCtr;
		void Step(enum Step eStep);
		void On(unsigned char ucLedIndex);
		
		public:
    void Init(void);
    void StepRight(void);
    void StepLeft(void);

};

enum LedState {STEP_LEFT, STEP_RIGHT, LED_STOP};

#endif 

