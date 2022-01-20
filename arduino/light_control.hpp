#ifndef __SMARTLAMP_LIGHT_CONTROL__
#define __SMARTLAMP_LIGHT_CONTROL__

#include "constants.hpp"

char get_current_intensity(unsigned char port);
bool set_intensity(unsigned char port, unsigned char hour, unsigned char minute, unsigned char intensity);

#endif // __SMARTLAMP_LIGHT_CONTROL__
