#include "light_control.hpp"
#include <Arduino.h>

char get_current_intensity(char port)
{
    char buffer[] = {GET_INTENSITY, port, NO_OP};
    Serial.write(buffer, 3 * sizeof(char));
    char intensity = 0;
    while (Serial.available() < sizeof(char))
        ;
    intensity = (char)Serial.parseInt();
    return intensity;
}

bool set_intensity(char port, char hour, char minute, char intensity)
{
    if (hour < 0 || hour > 23 || minute < 0 || minute > 59)
        return false;
    char buffer[] = {SET_INTENSITY, port, hour, minute, intensity, NO_OP};
    Serial.write(buffer, 6 * sizeof(char));
    return true;
}
