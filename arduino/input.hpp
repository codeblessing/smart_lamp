#ifndef __SMARTLAMP_INPUT__
#define __SMARTLAMP_INPUT__

#include <Keypad.h>

class Keyboard
{
public:
	Keyboard();
	void add_listener(void (*listener)(KeypadEvent));
	void poll();
	KeyState get_state();

private:
	Keypad __keypad;
};

#endif // __SMARTLAMP_INPUT__
