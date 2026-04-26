#ifndef KEYBOARD_H
#define KEYBOARD_H



class Keyboard{
	public:
	void KeyboardInit(void);
  enum KeyboardState eKeyboardRead(void);
	
};
enum KeyboardState{
	RELASED,
	BUTTON_1,
	BUTTON_2,
	BUTTON_3,
	BUTTON_4};





#endif
