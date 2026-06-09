#pragma once
#include <stdint.h>
class Led
{
	public:
		Led(unsigned char ucColumn, unsigned char ucRow);
		void On();
		void Off();
	private:
		unsigned char ucColumn, ucRow;
		void Redraw(uint32_t Color);
};



