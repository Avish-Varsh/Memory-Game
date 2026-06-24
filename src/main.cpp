#include <Arduino.h>

int const leds[] ={ 11, 9, 10};
int const btns[] ={ 4, 5, 6};
int const buzz = 7;
int i = 0;

void setup() {
  Serial.begin(9600);
  for(i = 0; i<3; i++){
    pinMode(leds[i], OUTPUT);
    pinMode(btns[i], INPUT_PULLUP);
  }
  pinMode(buzz, OUTPUT);
  randomSeed(analogRead(A0));
}

void loop() {
  
}
