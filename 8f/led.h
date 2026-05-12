#ifndef LED_H
#define LED_H

class Led{
		public:
		virtual void On(unsigned char ucLedIndex)=0;
		Led();
};

enum LedState {STEP_LEFT, STEP_RIGHT, LED_STOP};

#endif 

