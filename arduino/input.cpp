#include "input.hpp"

#include "constants.hpp"

char keys[KEYPAD_ROWS][KEYPAD_COLS] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'},
    {'*', '0', '#'}};

byte row_pins[KEYPAD_ROWS] = {13, 12, 11, 10};
byte col_pins[KEYPAD_COLS] = {8, 7, 4};

Keyboard::Keyboard() : __keypad(makeKeymap(keys), row_pins, col_pins, KEYPAD_ROWS, KEYPAD_COLS) {}

void Keyboard::add_listener(void (*listener)(KeypadEvent))
{
    __keypad.addEventListener(listener);
}

void Keyboard::poll()
{
    __keypad.getKeys();
}

KeyState Keyboard::get_state()
{
    return __keypad.getState();
}
