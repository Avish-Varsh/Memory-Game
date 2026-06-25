#include <Arduino.h>
int const potenti = A5;
int const leds[] ={ 11, 9, 10};
 // if leds[0] is green led then btns[0] must also be green btn
int const btns[] ={ 4, 5, 6};
int sequence[50]={}; 
int input[50]={};
// maximum 50 levels
int const buzz = 7;
int level;
long m1 = 0;
// previous millis
float interval;
bool on;
// determines whether led should be on or off
int currentstate;
enum gamestate {store, pattern, user, outcome};
// possible states for the game
void setup() {
  Serial.begin(9600);
  for(int i = 0; i<3; i++){
    pinMode(leds[i], OUTPUT);
    pinMode(btns[i], INPUT_PULLUP);
  }
  pinMode(A5,INPUT);
  pinMode(buzz, OUTPUT);
  randomSeed(analogRead(A0));
  level = 0;
  on = true; 
  currentstate = store; 
}

int picked() {
  return random(3);
}

void loop() {
  interval = (600 + (analogRead(potenti)/2));
  switch(currentstate){
    case store:
     sequence[level] = picked(); 
     currentstate = pattern;
    case pattern:
     if(on == true){
       digitalWrite(leds[sequence[level]],HIGH);
       if(millis() - m1 >= interval){
         m1 = millis();
         digitalWrite(leds[sequence[level]],LOW);
         on = false;
        }
      }
      if(on == false && (millis() - m1 >= 500)){
          on = true;
          level = level + 1;
          currentstate = store;
        }
        break;
  }
}
