#include <Arduino.h>

int const leds[] ={ 11, 9, 10};
 // if leds[0] is green led then btns[0] must also be green btn
int const btns[] ={ 4, 5, 6};
int const buzz = 7;
int i = 0;
int gamestate = 50;
bool win;
bool lose;
bool playing;

void setup() {
  Serial.begin(9600);
  for(i = 0; i<3; i++){
    pinMode(leds[i], OUTPUT);
    pinMode(btns[i], INPUT_PULLUP);
  }
  pinMode(buzz, OUTPUT);
  randomSeed(analogRead(A0));
  win = false;
  lose = false;
  playing = true;
}

void loop() {
  while(playing ==  true){
    
  }
  
}
