#include "light_control.hpp"
#include <Arduino.h>

char get_current_intensity(unsigned char port)
{
//    Serial.print("Port: ");
//    Serial.println((int)port);
    unsigned char buffer[] = {GET_INTENSITY, port, NO_OP};
    Serial.write(buffer, 3 * sizeof(unsigned char));
//    Serial.println("");
    unsigned char intensity = 0;
    while (Serial.available() < sizeof(unsigned char))
        ;
    intensity = (unsigned char)Serial.read();
//    Serial.read();
//    Serial.println((int)intensity);
    return intensity;
}

bool set_intensity(unsigned char port, unsigned char hour, unsigned char minute, unsigned char intensity)
{
    if (hour < 0 || hour > 23 || minute < 0 || minute > 59)
        return false;
    unsigned char buffer[] = {SET_INTENSITY, port, hour, minute, intensity, NO_OP};
    int buffer_2[] = {SET_INTENSITY, (int)port, (int)hour, (int)minute, (int)intensity, NO_OP};
    Serial.write(buffer, 6 * sizeof(unsigned char));
//    Serial.println("");
//    for(auto i : buffer_2) {
//      Serial.print(i);  
//    }
//    Serial.println("");
    
    return true;
}
