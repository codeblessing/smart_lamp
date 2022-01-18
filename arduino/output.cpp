#include "output.hpp"

Display::Display() {}

void Display::begin(unsigned int rows, unsigned int cols)
{
    int failed = __display.begin(cols, rows);
    if (failed)
    {
        Serial.print("Cannot initialize LCD display.\n");
        exit(failed);
    }
    __display.lineWrap();
    __display.clear();
}

void Display::display(const char *message)
{
    __display.clear();
    __display.print(message);
}

void Display::append(const char *message)
{
    __display.print(message);
}
