#ifndef __SMARTLAMP_OUTPUT__
#define __SMATRLAMP_OUTPUT__

#include <Wire.h>
#include <hd44780.h>
#include <hd44780ioClass/hd44780_I2Cexp.h> // i2c expander i/o class header

#include "constants.h"

using Display = hd44780_I2Cexp;

void setup_display();
void display(const char *message);

#ifdef SMARTLAMP_IMPLEMENT

static Display lcd;

void setup_display()
{
  int failed = lcd.begin(LCD_COLS, LCD_ROWS);
  if (failed)
  {
    exit(failed);
  }
}

void display(const char *message)
{
  lcd.print(message);
}

#endif // SMARTLAMP_IMPLEMENT

#endif // __SMARTLAMP_OUTPUT__
