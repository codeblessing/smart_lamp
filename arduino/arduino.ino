#include "constants.h"
#define SMARTLAMP_IMPLEMENT
#include "light_control.h"
#include "input.h"
#include "output.h"
#undef SMARTLAMP_IMPLEMENT

void setup() {
  // put your setup code here, to run once:
  pinMode(LIGHT_1, OUTPUT);
  pinMode(LIGHT_2, OUTPUT);
  pinMode(LIGHT_3, OUTPUT);
  pinMode(LIGHT_4, OUTPUT);
  digitalWrite(LIGHT_1, LOW);
  digitalWrite(LIGHT_2, LOW);
  digitalWrite(LIGHT_3, LOW);
  digitalWrite(LIGHT_4, LOW);
  Serial.begin(9600);
}

byte level = 0;
bool increase = true;
float step = 0.01f;
float lamp_0 = 0.0f;
float lamp_1 = 1.5f;
float lamp_2 = 3.0f;
float lamp_3 = 4.5f;

void loop() {
 level = (int)((sin(lamp_0) + 1.0f) * 255.0f / 2.0f);
 analogWrite(LIGHT_1, level);
 level = (int)((sin(lamp_1) + 1.0f) * 255.0f / 2.0f);
 analogWrite(LIGHT_2, level);
 level = (int)((sin(lamp_2) + 1.0f) * 255.0f / 2.0f);
 analogWrite(LIGHT_3, level);
 level = (int)((sin(lamp_3) + 1.0f) * 255.0f / 2.0f);
 analogWrite(LIGHT_4, level);
 lamp_0 += step;
 lamp_1 += step;
 lamp_2 += step;
 lamp_3 += step;

  // level = get_current_intensity(0);
  // analogWrite(LIGHT_1, level);
//  if(increase) {
//    ++level;
//  } else {
//    --level;
//  }

//  if(level == 255) {
//    increase = false;  
//  }
//  if(level == 0) {
//    increase = true;  
//  }
  delay(10);
}
