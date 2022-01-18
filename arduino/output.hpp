#ifndef __SMARTLAMP_OUTPUT__
#define __SMARTLAMP_OUTPUT__

#include <Wire.h>
#include <hd44780.h>
#include <hd44780ioClass/hd44780_I2Cexp.h>

#include "constants.hpp"

class Display
{
public:
    Display();
    void begin(unsigned int rows = LCD_ROWS, unsigned int cols = LCD_COLS);
    void display(const char *message);
    void append(const char *message);

private:
    hd44780_I2Cexp __display;
};

#endif // __SMARTLAMP_OUTPUT__
