#ifndef __SMARTLAMP_LIGHT_CONTROL__
#define __SMARTLAMP_LIGHT_CONTROL__

#include "constants.hpp"

char get_current_intensity(char port);
bool set_intensity(char port, char hour, char minute, char intensity);

#endif // __SMARTLAMP_LIGHT_CONTROL__
