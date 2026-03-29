#ifndef LED_H
#define LED_H

class Led{
		protected: 
		void On(unsigned char ucLedIndex);
		public:
		Led();

};

enum LedState {STEP_LEFT, STEP_RIGHT, LED_STOP};

#endif 
