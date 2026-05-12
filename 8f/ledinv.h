#ifndef LEDINV_H
#define LEDINV_H
#include "led.h"


class LedInv : public Led{
		public:
		void virtual On(unsigned char ucLedIndex);
	
	
};	
#endif
