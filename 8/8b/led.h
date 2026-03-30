#ifndef LED_H
#define LED_H

class Led{
		public:
		void On(unsigned char ucLedIndex);
		Led();
};

enum LedState {STEP_LEFT, STEP_RIGHT, LED_STOP};

#endif 

