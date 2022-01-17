#ifndef __SMARTLAMP_INPUT__
#define __SMARTLAMP_INPUT__

#include <Keypad.h>
#include "constants.h"

void setup_keyboard();
void add_listener(void (*listener)(char));

#ifdef SMARTLAMP_IMPLEMENT

static Keypad keypad(nullptr, nullptr, nullptr, 0, 0);

void setup_keyboard() {
  char keys[KEYPAD_ROWS][KEYPAD_COLS] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'},
    {'*', '0', '#'}
  };

  byte row_pins[KEYPAD_ROWS] = {5, 4, 3, 2};
  byte col_pins[KEYPAD_COLS] = {8, 7, 6};

  keypad = Keypad( makeKeymap(keys), row_pins, col_pins, KEYPAD_ROWS, KEYPAD_COLS );
}


#endif // SMARTLAMP_IMPLEMENT

#endif // __SMARTLAMP_INPUT__
