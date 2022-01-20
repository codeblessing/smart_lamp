#include "constants.hpp"
#include "light_control.hpp"
#include "input.hpp"
#include "output.hpp"
#include "setting.hpp"

enum class Mode
{
    LIGHTS,
    SETTINGS
};

Display display;
Keyboard keyboard;
Mode mode = Mode::LIGHTS;
Setting setting;
unsigned char selected = 255;

void setup()
{
    pinMode(LIGHT_1, OUTPUT);
    pinMode(LIGHT_2, OUTPUT);
    pinMode(LIGHT_3, OUTPUT);
    pinMode(LIGHT_4, OUTPUT);
    digitalWrite(LIGHT_1, LOW);
    digitalWrite(LIGHT_2, LOW);
    digitalWrite(LIGHT_3, LOW);
    digitalWrite(LIGHT_4, LOW);
    Serial.begin(9600);
    display.begin();
    display.display(" _ _ _ _ _ _ _ __ _ _ _ _ _ _ _ ");
    keyboard.add_listener(key_pressed);
}

void key_pressed(KeypadEvent value)
{
    char val[2] = {value, '\0'};
    switch (keyboard.get_state())
    {
    case PRESSED:
        Serial.print("Pressed:");
        Serial.println(val);
        // If we're not in settings mode, then just leave.
        if (mode != Mode::SETTINGS)
        {
            return;
        }

        if (selected == 255)
        {
            switch (value)
            {
            case '0':
                selected = 0;
                break;
            case '1':
                selected = 1;
                break;
            case '2':
                selected = 2;
                break;
            case '3':
                selected = 3;
                break;
            default:
                break;
            }

            Serial.print("Selected: ");
            Serial.println(selected);

            return;
        }

        switch (value)
        {
        case '*':
            // * will be used as backspace.
            setting.remove_prev();
            break;
        case '#':
            // # will be used as accept button.
            set_intensity(selected, setting.__hour, setting.__minute, setting.__intensity);
            setting = Setting();
            selected = 255;
            display.display("Nr lampy: ");
            break;
        case '0':
            setting.insert_next(0);
            break;
        case '1':
            setting.insert_next(1);
            break;
        case '2':
            setting.insert_next(2);
            break;
        case '3':
            setting.insert_next(3);
            break;
        case '4':
            setting.insert_next(4);
            break;
        case '5':
            setting.insert_next(5);
            break;
        case '6':
            setting.insert_next(6);
            break;
        case '7':
            setting.insert_next(7);
            break;
        case '8':
            setting.insert_next(8);
            break;
        case '9':
            setting.insert_next(9);
            break;
        }

        break;

    case HOLD:
        if (value == '*')
        {
            if (mode == Mode::LIGHTS)
            {
                mode = Mode::SETTINGS;
                display.display("Nr lampy: ");
                return;
            }
            else
            {
                mode = Mode::LIGHTS;
            }
        }
        break;
    }
    if (mode == Mode::SETTINGS && selected != 255)
    {
        char buffer[10] = "  :      ";
        setting.to_str(buffer);
        display.display("# to accept     ");
        display.append(buffer);
        Serial.println(buffer);
    }
    else if(mode == Mode::LIGHTS) {
      display.display(" _ _ _ _ _ _ _ __ _ _ _ _ _ _ _ ");
    }
}

char level = 0;
bool increase = true;
float step = 0.01f;
float lamp_0 = 0.0f;
float lamp_1 = 1.5f;
float lamp_2 = 3.0f;
float lamp_3 = 4.5f;

void loop()
{
    keyboard.poll();
    level = (int)((sin(lamp_0) + 1.0f) * 255.0f / 2.0f);
//    level = get_current_intensity(0);
    analogWrite(LIGHT_1, level);
//    level = get_current_intensity(1);
    level = (int)((sin(lamp_1) + 1.0f) * 255.0f / 2.0f);
    analogWrite(LIGHT_2, level);
//    level = get_current_intensity(2);
    level = (int)((sin(lamp_2) + 1.0f) * 255.0f / 2.0f);
    analogWrite(LIGHT_3, level);
//    level = get_current_intensity(3);
    level = (int)((sin(lamp_3) + 1.0f) * 255.0f / 2.0f);
    analogWrite(LIGHT_4, level);
    lamp_0 += step;
    lamp_1 += step;
    lamp_2 += step;
    lamp_3 += step;

    

    delay(10);
}
