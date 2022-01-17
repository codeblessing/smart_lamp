#ifndef __SMARTLAMP_LIGHT_CONTROL__
#define __SMARTLAMP_LIGHT_CONTROL__

#include "constants.h"

byte get_current_intensity(byte port);
bool set_intensity(byte port, byte hour, byte minute, byte intensity);

#ifdef SMARTLAMP_IMPLEMENT
byte get_current_intensity(byte port)
{
  byte buffer[] = {GET_INTENSITY, port, NO_OP};
  Serial.write(buffer, 3 * sizeof(byte));
  byte intensity = 0;
  while (Serial.available() < sizeof(byte))
    ;
  //  Serial.readBytes(&intensity, sizeof(byte));
  intensity = (byte)Serial.parseInt();
  return intensity;
}

bool set_intensity(byte port, byte hour, byte minute, byte intensity)
{
  if (hour < 0 || hour > 23 || minute < 0 || minute > 59)
    return false;
  byte buffer[] = {SET_INTENSITY, port, hour, minute, intensity, NO_OP};
  Serial.write(buffer, 6 * sizeof(byte));
  return true;
}

#endif // SMARTLAMP_CONTROL_IMPLEMENT
#endif // __SMARTLAMP_LIGHT_CONTROL__
