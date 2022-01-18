#include "setting.hpp"

Setting::Setting() : __hour(0), __minute(0), __intensity(0), __property('h'), __index(0) {}

void Setting::insert_next(char value)
{
    if (__property == 'h')
    {
        if (__index == 0 && value < 3)
        {
            __hour = 10 * value;
            __index = 1;
        }
        else if (__index == 1)
        {
            if (__hour != 20 || (__hour == 20 && value < 4))
            {
                __hour += value;
                __property = 'm';
                __index = 0;
            }
        }
    }
    else if (__property == 'm')
    {
        // Minutes can be in range [0; 59]
        if (__index == 0 && value < 6)
        {
            __minute = 10 * value;
            __index = 1;
        }
        else if (__index == 1)
        {
            __minute += value;
            __property = 'i';
            __index = 0;
        }
    }
    else if (__property == 'i')
    {
        if (__index == 0)
        {
            __intensity = 10 * value;
            __index = 1;
        }
        else if (__index == 1)
        {
            __intensity += value;
            __index = 2;
        }
        else if (__index == 2 && __intensity < 26 && value < 6)
        {
            __intensity = __intensity * 10 + value;
            __index = 3;
        }
    }
}

void Setting::remove_prev()
{
    if (__index == 0)
    {
        switch (__property)
        {
        case 'i':
            __property = 'm';
            __index = 2;
            break;
        case 'm':
            __property = 'h';
            __index = 2;
        default:
            __index = 1;
            break;
        }
    }

    --__index;

    if (__property == 'i')
    {
        if (__index == 2)
        {
            __intensity /= 10;
        }
        else if (__index == 1)
        {
            // Dividing by 10 and then multiplying by 10 gives us truncation of unit value.
            __intensity /= 10;
            __intensity *= 10;
        }
        else if (__index == 0)
        {
            __intensity = 0;
        }
    }
    else if (__property == 'm')
    {
        if (__index == 1)
        {
            // Dividing by 10 and then multiplying by 10 gives us truncation of unit value.
            __minute /= 10;
            __minute *= 10;
        }
        else if (__index == 0)
        {
            __minute = 0;
        }
    }
    else if (__property == 'h')
    {
        if (__hour > 19)
            __hour = 20;
        else if (__hour > 9)
            __hour = 10;
        else
            __hour = 0;
    }
}

void Setting::to_str(char *buffer)
{
    // Naive, but working implementation.
    switch (__hour)
    {
    case 0:
        buffer[0] = '0';
        buffer[1] = '0';
        break;
    case 1:
        buffer[0] = '0';
        buffer[1] = '1';
        break;
    case 2:
        buffer[0] = '0';
        buffer[1] = '2';
        break;
    case 3:
        buffer[0] = '0';
        buffer[1] = '3';
        break;
    case 4:
        buffer[0] = '0';
        buffer[1] = '4';
        break;
    case 5:
        buffer[0] = '0';
        buffer[1] = '5';
        break;
    case 6:
        buffer[0] = '0';
        buffer[1] = '6';
        break;
    case 7:
        buffer[0] = '0';
        buffer[1] = '7';
        break;
    case 8:
        buffer[0] = '0';
        buffer[1] = '8';
        break;
    case 9:
        buffer[0] = '0';
        buffer[1] = '9';
        break;
    case 10:
        buffer[0] = '1';
        buffer[1] = '0';
        break;
    case 11:
        buffer[0] = '1';
        buffer[1] = '1';
        break;
    case 12:
        buffer[0] = '1';
        buffer[1] = '2';
        break;
    case 13:
        buffer[0] = '1';
        buffer[1] = '3';
        break;
    case 14:
        buffer[0] = '1';
        buffer[1] = '4';
        break;
    case 15:
        buffer[0] = '1';
        buffer[1] = '5';
        break;
    case 16:
        buffer[0] = '1';
        buffer[1] = '6';
        break;
    case 17:
        buffer[0] = '1';
        buffer[1] = '7';
        break;
    case 18:
        buffer[0] = '1';
        buffer[1] = '8';
        break;
    case 19:
        buffer[0] = '1';
        buffer[1] = '9';
        break;
    case 20:
        buffer[0] = '2';
        buffer[1] = '0';
        break;
    case 21:
        buffer[0] = '2';
        buffer[1] = '1';
        break;
    case 22:
        buffer[0] = '2';
        buffer[1] = '2';
        break;
    case 23:
        buffer[0] = '2';
        buffer[1] = '3';
    default:
        break;
    }

    switch (__minute)
    {
    case 0:
        buffer[3] = '0';
        buffer[4] = '0';
        break;

    case 1:
        buffer[3] = '0';
        buffer[4] = '1';
        break;

    case 2:
        buffer[3] = '0';
        buffer[4] = '2';
        break;

    case 3:
        buffer[3] = '0';
        buffer[4] = '3';
        break;

    case 4:
        buffer[3] = '0';
        buffer[4] = '4';
        break;

    case 5:
        buffer[3] = '0';
        buffer[4] = '5';
        break;

    case 6:
        buffer[3] = '0';
        buffer[4] = '6';
        break;

    case 7:
        buffer[3] = '0';
        buffer[4] = '7';
        break;

    case 8:
        buffer[3] = '0';
        buffer[4] = '8';
        break;

    case 9:
        buffer[3] = '0';
        buffer[4] = '9';
        break;

    case 10:
        buffer[3] = '1';
        buffer[4] = '0';
        break;

    case 11:
        buffer[3] = '1';
        buffer[4] = '1';
        break;

    case 12:
        buffer[3] = '1';
        buffer[4] = '2';
        break;

    case 13:
        buffer[3] = '1';
        buffer[4] = '3';
        break;

    case 14:
        buffer[3] = '1';
        buffer[4] = '4';
        break;

    case 15:
        buffer[3] = '1';
        buffer[4] = '5';
        break;

    case 16:
        buffer[3] = '1';
        buffer[4] = '6';
        break;

    case 17:
        buffer[3] = '1';
        buffer[4] = '7';
        break;

    case 18:
        buffer[3] = '1';
        buffer[4] = '8';
        break;

    case 19:
        buffer[3] = '1';
        buffer[4] = '9';
        break;

    case 20:
        buffer[3] = '2';
        buffer[4] = '0';
        break;

    case 21:
        buffer[3] = '2';
        buffer[4] = '1';
        break;

    case 22:
        buffer[3] = '2';
        buffer[4] = '2';
        break;

    case 23:
        buffer[3] = '2';
        buffer[4] = '3';
        break;

    case 24:
        buffer[3] = '2';
        buffer[4] = '4';
        break;

    case 25:
        buffer[3] = '2';
        buffer[4] = '5';
        break;

    case 26:
        buffer[3] = '2';
        buffer[4] = '6';
        break;

    case 27:
        buffer[3] = '2';
        buffer[4] = '7';
        break;

    case 28:
        buffer[3] = '2';
        buffer[4] = '8';
        break;

    case 29:
        buffer[3] = '2';
        buffer[4] = '9';
        break;

    case 30:
        buffer[3] = '3';
        buffer[4] = '0';
        break;

    case 31:
        buffer[3] = '3';
        buffer[4] = '1';
        break;

    case 32:
        buffer[3] = '3';
        buffer[4] = '2';
        break;

    case 33:
        buffer[3] = '3';
        buffer[4] = '3';
        break;

    case 34:
        buffer[3] = '3';
        buffer[4] = '4';
        break;

    case 35:
        buffer[3] = '3';
        buffer[4] = '5';
        break;

    case 36:
        buffer[3] = '3';
        buffer[4] = '6';
        break;

    case 37:
        buffer[3] = '3';
        buffer[4] = '7';
        break;

    case 38:
        buffer[3] = '3';
        buffer[4] = '8';
        break;

    case 39:
        buffer[3] = '3';
        buffer[4] = '9';
        break;

    case 40:
        buffer[3] = '4';
        buffer[4] = '0';
        break;

    case 41:
        buffer[3] = '4';
        buffer[4] = '1';
        break;

    case 42:
        buffer[3] = '4';
        buffer[4] = '2';
        break;

    case 43:
        buffer[3] = '4';
        buffer[4] = '3';
        break;

    case 44:
        buffer[3] = '4';
        buffer[4] = '4';
        break;

    case 45:
        buffer[3] = '4';
        buffer[4] = '5';
        break;

    case 46:
        buffer[3] = '4';
        buffer[4] = '6';
        break;

    case 47:
        buffer[3] = '4';
        buffer[4] = '7';
        break;

    case 48:
        buffer[3] = '4';
        buffer[4] = '8';
        break;

    case 49:
        buffer[3] = '4';
        buffer[4] = '9';
        break;

    case 50:
        buffer[3] = '5';
        buffer[4] = '0';
        break;

    case 51:
        buffer[3] = '5';
        buffer[4] = '1';
        break;

    case 52:
        buffer[3] = '5';
        buffer[4] = '2';
        break;

    case 53:
        buffer[3] = '5';
        buffer[4] = '3';
        break;

    case 54:
        buffer[3] = '5';
        buffer[4] = '4';
        break;

    case 55:
        buffer[3] = '5';
        buffer[4] = '5';
        break;

    case 56:
        buffer[3] = '5';
        buffer[4] = '6';
        break;

    case 57:
        buffer[3] = '5';
        buffer[4] = '7';
        break;

    case 58:
        buffer[3] = '5';
        buffer[4] = '8';
        break;

    case 59:
        buffer[3] = '5';
        buffer[4] = '9';
        break;
    }

    switch (__intensity)
    {
    case 0:
        buffer[6] = ' ';
        buffer[7] = ' ';
        buffer[8] = '0';
        break;

    case 1:
        buffer[6] = ' ';
        buffer[7] = ' ';
        buffer[8] = '1';
        break;

    case 2:
        buffer[6] = ' ';
        buffer[7] = ' ';
        buffer[8] = '2';
        break;

    case 3:
        buffer[6] = ' ';
        buffer[7] = ' ';
        buffer[8] = '3';
        break;

    case 4:
        buffer[6] = ' ';
        buffer[7] = ' ';
        buffer[8] = '4';
        break;

    case 5:
        buffer[6] = ' ';
        buffer[7] = ' ';
        buffer[8] = '5';
        break;

    case 6:
        buffer[6] = ' ';
        buffer[7] = ' ';
        buffer[8] = '6';
        break;

    case 7:
        buffer[6] = ' ';
        buffer[7] = ' ';
        buffer[8] = '7';
        break;

    case 8:
        buffer[6] = ' ';
        buffer[7] = ' ';
        buffer[8] = '8';
        break;

    case 9:
        buffer[6] = ' ';
        buffer[7] = ' ';
        buffer[8] = '9';
        break;

    case 10:
        buffer[6] = ' ';
        buffer[7] = '1';
        buffer[8] = '0';
        break;

    case 11:
        buffer[6] = ' ';
        buffer[7] = '1';
        buffer[8] = '1';
        break;

    case 12:
        buffer[6] = ' ';
        buffer[7] = '1';
        buffer[8] = '2';
        break;

    case 13:
        buffer[6] = ' ';
        buffer[7] = '1';
        buffer[8] = '3';
        break;

    case 14:
        buffer[6] = ' ';
        buffer[7] = '1';
        buffer[8] = '4';
        break;

    case 15:
        buffer[6] = ' ';
        buffer[7] = '1';
        buffer[8] = '5';
        break;

    case 16:
        buffer[6] = ' ';
        buffer[7] = '1';
        buffer[8] = '6';
        break;

    case 17:
        buffer[6] = ' ';
        buffer[7] = '1';
        buffer[8] = '7';
        break;

    case 18:
        buffer[6] = ' ';
        buffer[7] = '1';
        buffer[8] = '8';
        break;

    case 19:
        buffer[6] = ' ';
        buffer[7] = '1';
        buffer[8] = '9';
        break;

    case 20:
        buffer[6] = ' ';
        buffer[7] = '2';
        buffer[8] = '0';
        break;

    case 21:
        buffer[6] = ' ';
        buffer[7] = '2';
        buffer[8] = '1';
        break;

    case 22:
        buffer[6] = ' ';
        buffer[7] = '2';
        buffer[8] = '2';
        break;

    case 23:
        buffer[6] = ' ';
        buffer[7] = '2';
        buffer[8] = '3';
        break;

    case 24:
        buffer[6] = ' ';
        buffer[7] = '2';
        buffer[8] = '4';
        break;

    case 25:
        buffer[6] = ' ';
        buffer[7] = '2';
        buffer[8] = '5';
        break;

    case 26:
        buffer[6] = ' ';
        buffer[7] = '2';
        buffer[8] = '6';
        break;

    case 27:
        buffer[6] = ' ';
        buffer[7] = '2';
        buffer[8] = '7';
        break;

    case 28:
        buffer[6] = ' ';
        buffer[7] = '2';
        buffer[8] = '8';
        break;

    case 29:
        buffer[6] = ' ';
        buffer[7] = '2';
        buffer[8] = '9';
        break;

    case 30:
        buffer[6] = ' ';
        buffer[7] = '3';
        buffer[8] = '0';
        break;

    case 31:
        buffer[6] = ' ';
        buffer[7] = '3';
        buffer[8] = '1';
        break;

    case 32:
        buffer[6] = ' ';
        buffer[7] = '3';
        buffer[8] = '2';
        break;

    case 33:
        buffer[6] = ' ';
        buffer[7] = '3';
        buffer[8] = '3';
        break;

    case 34:
        buffer[6] = ' ';
        buffer[7] = '3';
        buffer[8] = '4';
        break;

    case 35:
        buffer[6] = ' ';
        buffer[7] = '3';
        buffer[8] = '5';
        break;

    case 36:
        buffer[6] = ' ';
        buffer[7] = '3';
        buffer[8] = '6';
        break;

    case 37:
        buffer[6] = ' ';
        buffer[7] = '3';
        buffer[8] = '7';
        break;

    case 38:
        buffer[6] = ' ';
        buffer[7] = '3';
        buffer[8] = '8';
        break;

    case 39:
        buffer[6] = ' ';
        buffer[7] = '3';
        buffer[8] = '9';
        break;

    case 40:
        buffer[6] = ' ';
        buffer[7] = '4';
        buffer[8] = '0';
        break;

    case 41:
        buffer[6] = ' ';
        buffer[7] = '4';
        buffer[8] = '1';
        break;

    case 42:
        buffer[6] = ' ';
        buffer[7] = '4';
        buffer[8] = '2';
        break;

    case 43:
        buffer[6] = ' ';
        buffer[7] = '4';
        buffer[8] = '3';
        break;

    case 44:
        buffer[6] = ' ';
        buffer[7] = '4';
        buffer[8] = '4';
        break;

    case 45:
        buffer[6] = ' ';
        buffer[7] = '4';
        buffer[8] = '5';
        break;

    case 46:
        buffer[6] = ' ';
        buffer[7] = '4';
        buffer[8] = '6';
        break;

    case 47:
        buffer[6] = ' ';
        buffer[7] = '4';
        buffer[8] = '7';
        break;

    case 48:
        buffer[6] = ' ';
        buffer[7] = '4';
        buffer[8] = '8';
        break;

    case 49:
        buffer[6] = ' ';
        buffer[7] = '4';
        buffer[8] = '9';
        break;

    case 50:
        buffer[6] = ' ';
        buffer[7] = '5';
        buffer[8] = '0';
        break;

    case 51:
        buffer[6] = ' ';
        buffer[7] = '5';
        buffer[8] = '1';
        break;

    case 52:
        buffer[6] = ' ';
        buffer[7] = '5';
        buffer[8] = '2';
        break;

    case 53:
        buffer[6] = ' ';
        buffer[7] = '5';
        buffer[8] = '3';
        break;

    case 54:
        buffer[6] = ' ';
        buffer[7] = '5';
        buffer[8] = '4';
        break;

    case 55:
        buffer[6] = ' ';
        buffer[7] = '5';
        buffer[8] = '5';
        break;

    case 56:
        buffer[6] = ' ';
        buffer[7] = '5';
        buffer[8] = '6';
        break;

    case 57:
        buffer[6] = ' ';
        buffer[7] = '5';
        buffer[8] = '7';
        break;

    case 58:
        buffer[6] = ' ';
        buffer[7] = '5';
        buffer[8] = '8';
        break;

    case 59:
        buffer[6] = ' ';
        buffer[7] = '5';
        buffer[8] = '9';
        break;

    case 60:
        buffer[6] = ' ';
        buffer[7] = '6';
        buffer[8] = '0';
        break;

    case 61:
        buffer[6] = ' ';
        buffer[7] = '6';
        buffer[8] = '1';
        break;

    case 62:
        buffer[6] = ' ';
        buffer[7] = '6';
        buffer[8] = '2';
        break;

    case 63:
        buffer[6] = ' ';
        buffer[7] = '6';
        buffer[8] = '3';
        break;

    case 64:
        buffer[6] = ' ';
        buffer[7] = '6';
        buffer[8] = '4';
        break;

    case 65:
        buffer[6] = ' ';
        buffer[7] = '6';
        buffer[8] = '5';
        break;

    case 66:
        buffer[6] = ' ';
        buffer[7] = '6';
        buffer[8] = '6';
        break;

    case 67:
        buffer[6] = ' ';
        buffer[7] = '6';
        buffer[8] = '7';
        break;

    case 68:
        buffer[6] = ' ';
        buffer[7] = '6';
        buffer[8] = '8';
        break;

    case 69:
        buffer[6] = ' ';
        buffer[7] = '6';
        buffer[8] = '9';
        break;

    case 70:
        buffer[6] = ' ';
        buffer[7] = '7';
        buffer[8] = '0';
        break;

    case 71:
        buffer[6] = ' ';
        buffer[7] = '7';
        buffer[8] = '1';
        break;

    case 72:
        buffer[6] = ' ';
        buffer[7] = '7';
        buffer[8] = '2';
        break;

    case 73:
        buffer[6] = ' ';
        buffer[7] = '7';
        buffer[8] = '3';
        break;

    case 74:
        buffer[6] = ' ';
        buffer[7] = '7';
        buffer[8] = '4';
        break;

    case 75:
        buffer[6] = ' ';
        buffer[7] = '7';
        buffer[8] = '5';
        break;

    case 76:
        buffer[6] = ' ';
        buffer[7] = '7';
        buffer[8] = '6';
        break;

    case 77:
        buffer[6] = ' ';
        buffer[7] = '7';
        buffer[8] = '7';
        break;

    case 78:
        buffer[6] = ' ';
        buffer[7] = '7';
        buffer[8] = '8';
        break;

    case 79:
        buffer[6] = ' ';
        buffer[7] = '7';
        buffer[8] = '9';
        break;

    case 80:
        buffer[6] = ' ';
        buffer[7] = '8';
        buffer[8] = '0';
        break;

    case 81:
        buffer[6] = ' ';
        buffer[7] = '8';
        buffer[8] = '1';
        break;

    case 82:
        buffer[6] = ' ';
        buffer[7] = '8';
        buffer[8] = '2';
        break;

    case 83:
        buffer[6] = ' ';
        buffer[7] = '8';
        buffer[8] = '3';
        break;

    case 84:
        buffer[6] = ' ';
        buffer[7] = '8';
        buffer[8] = '4';
        break;

    case 85:
        buffer[6] = ' ';
        buffer[7] = '8';
        buffer[8] = '5';
        break;

    case 86:
        buffer[6] = ' ';
        buffer[7] = '8';
        buffer[8] = '6';
        break;

    case 87:
        buffer[6] = ' ';
        buffer[7] = '8';
        buffer[8] = '7';
        break;

    case 88:
        buffer[6] = ' ';
        buffer[7] = '8';
        buffer[8] = '8';
        break;

    case 89:
        buffer[6] = ' ';
        buffer[7] = '8';
        buffer[8] = '9';
        break;

    case 90:
        buffer[6] = ' ';
        buffer[7] = '9';
        buffer[8] = '0';
        break;

    case 91:
        buffer[6] = ' ';
        buffer[7] = '9';
        buffer[8] = '1';
        break;

    case 92:
        buffer[6] = ' ';
        buffer[7] = '9';
        buffer[8] = '2';
        break;

    case 93:
        buffer[6] = ' ';
        buffer[7] = '9';
        buffer[8] = '3';
        break;

    case 94:
        buffer[6] = ' ';
        buffer[7] = '9';
        buffer[8] = '4';
        break;

    case 95:
        buffer[6] = ' ';
        buffer[7] = '9';
        buffer[8] = '5';
        break;

    case 96:
        buffer[6] = ' ';
        buffer[7] = '9';
        buffer[8] = '6';
        break;

    case 97:
        buffer[6] = ' ';
        buffer[7] = '9';
        buffer[8] = '7';
        break;

    case 98:
        buffer[6] = ' ';
        buffer[7] = '9';
        buffer[8] = '8';
        break;

    case 99:
        buffer[6] = ' ';
        buffer[7] = '9';
        buffer[8] = '9';
        break;

    case 100:
        buffer[6] = '1';
        buffer[7] = '0';
        buffer[8] = '0';
        break;

    case 101:
        buffer[6] = '1';
        buffer[7] = '0';
        buffer[8] = '1';
        break;

    case 102:
        buffer[6] = '1';
        buffer[7] = '0';
        buffer[8] = '2';
        break;

    case 103:
        buffer[6] = '1';
        buffer[7] = '0';
        buffer[8] = '3';
        break;

    case 104:
        buffer[6] = '1';
        buffer[7] = '0';
        buffer[8] = '4';
        break;

    case 105:
        buffer[6] = '1';
        buffer[7] = '0';
        buffer[8] = '5';
        break;

    case 106:
        buffer[6] = '1';
        buffer[7] = '0';
        buffer[8] = '6';
        break;

    case 107:
        buffer[6] = '1';
        buffer[7] = '0';
        buffer[8] = '7';
        break;

    case 108:
        buffer[6] = '1';
        buffer[7] = '0';
        buffer[8] = '8';
        break;

    case 109:
        buffer[6] = '1';
        buffer[7] = '0';
        buffer[8] = '9';
        break;

    case 110:
        buffer[6] = '1';
        buffer[7] = '1';
        buffer[8] = '0';
        break;

    case 111:
        buffer[6] = '1';
        buffer[7] = '1';
        buffer[8] = '1';
        break;

    case 112:
        buffer[6] = '1';
        buffer[7] = '1';
        buffer[8] = '2';
        break;

    case 113:
        buffer[6] = '1';
        buffer[7] = '1';
        buffer[8] = '3';
        break;

    case 114:
        buffer[6] = '1';
        buffer[7] = '1';
        buffer[8] = '4';
        break;

    case 115:
        buffer[6] = '1';
        buffer[7] = '1';
        buffer[8] = '5';
        break;

    case 116:
        buffer[6] = '1';
        buffer[7] = '1';
        buffer[8] = '6';
        break;

    case 117:
        buffer[6] = '1';
        buffer[7] = '1';
        buffer[8] = '7';
        break;

    case 118:
        buffer[6] = '1';
        buffer[7] = '1';
        buffer[8] = '8';
        break;

    case 119:
        buffer[6] = '1';
        buffer[7] = '1';
        buffer[8] = '9';
        break;

    case 120:
        buffer[6] = '1';
        buffer[7] = '2';
        buffer[8] = '0';
        break;

    case 121:
        buffer[6] = '1';
        buffer[7] = '2';
        buffer[8] = '1';
        break;

    case 122:
        buffer[6] = '1';
        buffer[7] = '2';
        buffer[8] = '2';
        break;

    case 123:
        buffer[6] = '1';
        buffer[7] = '2';
        buffer[8] = '3';
        break;

    case 124:
        buffer[6] = '1';
        buffer[7] = '2';
        buffer[8] = '4';
        break;

    case 125:
        buffer[6] = '1';
        buffer[7] = '2';
        buffer[8] = '5';
        break;

    case 126:
        buffer[6] = '1';
        buffer[7] = '2';
        buffer[8] = '6';
        break;

    case 127:
        buffer[6] = '1';
        buffer[7] = '2';
        buffer[8] = '7';
        break;

    case 128:
        buffer[6] = '1';
        buffer[7] = '2';
        buffer[8] = '8';
        break;

    case 129:
        buffer[6] = '1';
        buffer[7] = '2';
        buffer[8] = '9';
        break;

    case 130:
        buffer[6] = '1';
        buffer[7] = '3';
        buffer[8] = '0';
        break;

    case 131:
        buffer[6] = '1';
        buffer[7] = '3';
        buffer[8] = '1';
        break;

    case 132:
        buffer[6] = '1';
        buffer[7] = '3';
        buffer[8] = '2';
        break;

    case 133:
        buffer[6] = '1';
        buffer[7] = '3';
        buffer[8] = '3';
        break;

    case 134:
        buffer[6] = '1';
        buffer[7] = '3';
        buffer[8] = '4';
        break;

    case 135:
        buffer[6] = '1';
        buffer[7] = '3';
        buffer[8] = '5';
        break;

    case 136:
        buffer[6] = '1';
        buffer[7] = '3';
        buffer[8] = '6';
        break;

    case 137:
        buffer[6] = '1';
        buffer[7] = '3';
        buffer[8] = '7';
        break;

    case 138:
        buffer[6] = '1';
        buffer[7] = '3';
        buffer[8] = '8';
        break;

    case 139:
        buffer[6] = '1';
        buffer[7] = '3';
        buffer[8] = '9';
        break;

    case 140:
        buffer[6] = '1';
        buffer[7] = '4';
        buffer[8] = '0';
        break;

    case 141:
        buffer[6] = '1';
        buffer[7] = '4';
        buffer[8] = '1';
        break;

    case 142:
        buffer[6] = '1';
        buffer[7] = '4';
        buffer[8] = '2';
        break;

    case 143:
        buffer[6] = '1';
        buffer[7] = '4';
        buffer[8] = '3';
        break;

    case 144:
        buffer[6] = '1';
        buffer[7] = '4';
        buffer[8] = '4';
        break;

    case 145:
        buffer[6] = '1';
        buffer[7] = '4';
        buffer[8] = '5';
        break;

    case 146:
        buffer[6] = '1';
        buffer[7] = '4';
        buffer[8] = '6';
        break;

    case 147:
        buffer[6] = '1';
        buffer[7] = '4';
        buffer[8] = '7';
        break;

    case 148:
        buffer[6] = '1';
        buffer[7] = '4';
        buffer[8] = '8';
        break;

    case 149:
        buffer[6] = '1';
        buffer[7] = '4';
        buffer[8] = '9';
        break;

    case 150:
        buffer[6] = '1';
        buffer[7] = '5';
        buffer[8] = '0';
        break;

    case 151:
        buffer[6] = '1';
        buffer[7] = '5';
        buffer[8] = '1';
        break;

    case 152:
        buffer[6] = '1';
        buffer[7] = '5';
        buffer[8] = '2';
        break;

    case 153:
        buffer[6] = '1';
        buffer[7] = '5';
        buffer[8] = '3';
        break;

    case 154:
        buffer[6] = '1';
        buffer[7] = '5';
        buffer[8] = '4';
        break;

    case 155:
        buffer[6] = '1';
        buffer[7] = '5';
        buffer[8] = '5';
        break;

    case 156:
        buffer[6] = '1';
        buffer[7] = '5';
        buffer[8] = '6';
        break;

    case 157:
        buffer[6] = '1';
        buffer[7] = '5';
        buffer[8] = '7';
        break;

    case 158:
        buffer[6] = '1';
        buffer[7] = '5';
        buffer[8] = '8';
        break;

    case 159:
        buffer[6] = '1';
        buffer[7] = '5';
        buffer[8] = '9';
        break;

    case 160:
        buffer[6] = '1';
        buffer[7] = '6';
        buffer[8] = '0';
        break;

    case 161:
        buffer[6] = '1';
        buffer[7] = '6';
        buffer[8] = '1';
        break;

    case 162:
        buffer[6] = '1';
        buffer[7] = '6';
        buffer[8] = '2';
        break;

    case 163:
        buffer[6] = '1';
        buffer[7] = '6';
        buffer[8] = '3';
        break;

    case 164:
        buffer[6] = '1';
        buffer[7] = '6';
        buffer[8] = '4';
        break;

    case 165:
        buffer[6] = '1';
        buffer[7] = '6';
        buffer[8] = '5';
        break;

    case 166:
        buffer[6] = '1';
        buffer[7] = '6';
        buffer[8] = '6';
        break;

    case 167:
        buffer[6] = '1';
        buffer[7] = '6';
        buffer[8] = '7';
        break;

    case 168:
        buffer[6] = '1';
        buffer[7] = '6';
        buffer[8] = '8';
        break;

    case 169:
        buffer[6] = '1';
        buffer[7] = '6';
        buffer[8] = '9';
        break;

    case 170:
        buffer[6] = '1';
        buffer[7] = '7';
        buffer[8] = '0';
        break;

    case 171:
        buffer[6] = '1';
        buffer[7] = '7';
        buffer[8] = '1';
        break;

    case 172:
        buffer[6] = '1';
        buffer[7] = '7';
        buffer[8] = '2';
        break;

    case 173:
        buffer[6] = '1';
        buffer[7] = '7';
        buffer[8] = '3';
        break;

    case 174:
        buffer[6] = '1';
        buffer[7] = '7';
        buffer[8] = '4';
        break;

    case 175:
        buffer[6] = '1';
        buffer[7] = '7';
        buffer[8] = '5';
        break;

    case 176:
        buffer[6] = '1';
        buffer[7] = '7';
        buffer[8] = '6';
        break;

    case 177:
        buffer[6] = '1';
        buffer[7] = '7';
        buffer[8] = '7';
        break;

    case 178:
        buffer[6] = '1';
        buffer[7] = '7';
        buffer[8] = '8';
        break;

    case 179:
        buffer[6] = '1';
        buffer[7] = '7';
        buffer[8] = '9';
        break;

    case 180:
        buffer[6] = '1';
        buffer[7] = '8';
        buffer[8] = '0';
        break;

    case 181:
        buffer[6] = '1';
        buffer[7] = '8';
        buffer[8] = '1';
        break;

    case 182:
        buffer[6] = '1';
        buffer[7] = '8';
        buffer[8] = '2';
        break;

    case 183:
        buffer[6] = '1';
        buffer[7] = '8';
        buffer[8] = '3';
        break;

    case 184:
        buffer[6] = '1';
        buffer[7] = '8';
        buffer[8] = '4';
        break;

    case 185:
        buffer[6] = '1';
        buffer[7] = '8';
        buffer[8] = '5';
        break;

    case 186:
        buffer[6] = '1';
        buffer[7] = '8';
        buffer[8] = '6';
        break;

    case 187:
        buffer[6] = '1';
        buffer[7] = '8';
        buffer[8] = '7';
        break;

    case 188:
        buffer[6] = '1';
        buffer[7] = '8';
        buffer[8] = '8';
        break;

    case 189:
        buffer[6] = '1';
        buffer[7] = '8';
        buffer[8] = '9';
        break;

    case 190:
        buffer[6] = '1';
        buffer[7] = '9';
        buffer[8] = '0';
        break;

    case 191:
        buffer[6] = '1';
        buffer[7] = '9';
        buffer[8] = '1';
        break;

    case 192:
        buffer[6] = '1';
        buffer[7] = '9';
        buffer[8] = '2';
        break;

    case 193:
        buffer[6] = '1';
        buffer[7] = '9';
        buffer[8] = '3';
        break;

    case 194:
        buffer[6] = '1';
        buffer[7] = '9';
        buffer[8] = '4';
        break;

    case 195:
        buffer[6] = '1';
        buffer[7] = '9';
        buffer[8] = '5';
        break;

    case 196:
        buffer[6] = '1';
        buffer[7] = '9';
        buffer[8] = '6';
        break;

    case 197:
        buffer[6] = '1';
        buffer[7] = '9';
        buffer[8] = '7';
        break;

    case 198:
        buffer[6] = '1';
        buffer[7] = '9';
        buffer[8] = '8';
        break;

    case 199:
        buffer[6] = '1';
        buffer[7] = '9';
        buffer[8] = '9';
        break;

    case 200:
        buffer[6] = '2';
        buffer[7] = '0';
        buffer[8] = '0';
        break;

    case 201:
        buffer[6] = '2';
        buffer[7] = '0';
        buffer[8] = '1';
        break;

    case 202:
        buffer[6] = '2';
        buffer[7] = '0';
        buffer[8] = '2';
        break;

    case 203:
        buffer[6] = '2';
        buffer[7] = '0';
        buffer[8] = '3';
        break;

    case 204:
        buffer[6] = '2';
        buffer[7] = '0';
        buffer[8] = '4';
        break;

    case 205:
        buffer[6] = '2';
        buffer[7] = '0';
        buffer[8] = '5';
        break;

    case 206:
        buffer[6] = '2';
        buffer[7] = '0';
        buffer[8] = '6';
        break;

    case 207:
        buffer[6] = '2';
        buffer[7] = '0';
        buffer[8] = '7';
        break;

    case 208:
        buffer[6] = '2';
        buffer[7] = '0';
        buffer[8] = '8';
        break;

    case 209:
        buffer[6] = '2';
        buffer[7] = '0';
        buffer[8] = '9';
        break;

    case 210:
        buffer[6] = '2';
        buffer[7] = '1';
        buffer[8] = '0';
        break;

    case 211:
        buffer[6] = '2';
        buffer[7] = '1';
        buffer[8] = '1';
        break;

    case 212:
        buffer[6] = '2';
        buffer[7] = '1';
        buffer[8] = '2';
        break;

    case 213:
        buffer[6] = '2';
        buffer[7] = '1';
        buffer[8] = '3';
        break;

    case 214:
        buffer[6] = '2';
        buffer[7] = '1';
        buffer[8] = '4';
        break;

    case 215:
        buffer[6] = '2';
        buffer[7] = '1';
        buffer[8] = '5';
        break;

    case 216:
        buffer[6] = '2';
        buffer[7] = '1';
        buffer[8] = '6';
        break;

    case 217:
        buffer[6] = '2';
        buffer[7] = '1';
        buffer[8] = '7';
        break;

    case 218:
        buffer[6] = '2';
        buffer[7] = '1';
        buffer[8] = '8';
        break;

    case 219:
        buffer[6] = '2';
        buffer[7] = '1';
        buffer[8] = '9';
        break;

    case 220:
        buffer[6] = '2';
        buffer[7] = '2';
        buffer[8] = '0';
        break;

    case 221:
        buffer[6] = '2';
        buffer[7] = '2';
        buffer[8] = '1';
        break;

    case 222:
        buffer[6] = '2';
        buffer[7] = '2';
        buffer[8] = '2';
        break;

    case 223:
        buffer[6] = '2';
        buffer[7] = '2';
        buffer[8] = '3';
        break;

    case 224:
        buffer[6] = '2';
        buffer[7] = '2';
        buffer[8] = '4';
        break;

    case 225:
        buffer[6] = '2';
        buffer[7] = '2';
        buffer[8] = '5';
        break;

    case 226:
        buffer[6] = '2';
        buffer[7] = '2';
        buffer[8] = '6';
        break;

    case 227:
        buffer[6] = '2';
        buffer[7] = '2';
        buffer[8] = '7';
        break;

    case 228:
        buffer[6] = '2';
        buffer[7] = '2';
        buffer[8] = '8';
        break;

    case 229:
        buffer[6] = '2';
        buffer[7] = '2';
        buffer[8] = '9';
        break;

    case 230:
        buffer[6] = '2';
        buffer[7] = '3';
        buffer[8] = '0';
        break;

    case 231:
        buffer[6] = '2';
        buffer[7] = '3';
        buffer[8] = '1';
        break;

    case 232:
        buffer[6] = '2';
        buffer[7] = '3';
        buffer[8] = '2';
        break;

    case 233:
        buffer[6] = '2';
        buffer[7] = '3';
        buffer[8] = '3';
        break;

    case 234:
        buffer[6] = '2';
        buffer[7] = '3';
        buffer[8] = '4';
        break;

    case 235:
        buffer[6] = '2';
        buffer[7] = '3';
        buffer[8] = '5';
        break;

    case 236:
        buffer[6] = '2';
        buffer[7] = '3';
        buffer[8] = '6';
        break;

    case 237:
        buffer[6] = '2';
        buffer[7] = '3';
        buffer[8] = '7';
        break;

    case 238:
        buffer[6] = '2';
        buffer[7] = '3';
        buffer[8] = '8';
        break;

    case 239:
        buffer[6] = '2';
        buffer[7] = '3';
        buffer[8] = '9';
        break;

    case 240:
        buffer[6] = '2';
        buffer[7] = '4';
        buffer[8] = '0';
        break;

    case 241:
        buffer[6] = '2';
        buffer[7] = '4';
        buffer[8] = '1';
        break;

    case 242:
        buffer[6] = '2';
        buffer[7] = '4';
        buffer[8] = '2';
        break;

    case 243:
        buffer[6] = '2';
        buffer[7] = '4';
        buffer[8] = '3';
        break;

    case 244:
        buffer[6] = '2';
        buffer[7] = '4';
        buffer[8] = '4';
        break;

    case 245:
        buffer[6] = '2';
        buffer[7] = '4';
        buffer[8] = '5';
        break;

    case 246:
        buffer[6] = '2';
        buffer[7] = '4';
        buffer[8] = '6';
        break;

    case 247:
        buffer[6] = '2';
        buffer[7] = '4';
        buffer[8] = '7';
        break;

    case 248:
        buffer[6] = '2';
        buffer[7] = '4';
        buffer[8] = '8';
        break;

    case 249:
        buffer[6] = '2';
        buffer[7] = '4';
        buffer[8] = '9';
        break;

    case 250:
        buffer[6] = '2';
        buffer[7] = '5';
        buffer[8] = '0';
        break;

    case 251:
        buffer[6] = '2';
        buffer[7] = '5';
        buffer[8] = '1';
        break;

    case 252:
        buffer[6] = '2';
        buffer[7] = '5';
        buffer[8] = '2';
        break;

    case 253:
        buffer[6] = '2';
        buffer[7] = '5';
        buffer[8] = '3';
        break;

    case 254:
        buffer[6] = '2';
        buffer[7] = '5';
        buffer[8] = '4';
        break;

    case 255:
        buffer[6] = '2';
        buffer[7] = '5';
        buffer[8] = '5';
        break;
    }

    buffer[2] = ':';
    buffer[5] = ' ';
}
