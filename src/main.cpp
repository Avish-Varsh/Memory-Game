#include <Arduino.h>
int const potenti = A5;
int const leds[3] ={ 9, 10, 11};
 // if leds[0] is green led then btns[0] must also be green btn
int const btns[3] ={ 4, 5, 6};
int const btnnumber = 3; 
int sequence[50]={}; 
int const buzz = 7;
int level;
long m1 = 0; // previous millis
unsigned long m2[btnnumber] = {0,0,0}; //millis for button debounce
unsigned long tonemillis[5] = {0,0,0,0,0}; // stores time for which each tone must play till they change.  
unsigned int debounce = 50;
bool inputflag[btnnumber] = {false, false, false}; // flags to store button state data
bool waspressed[btnnumber] = {false, false, false}; // notes whether btn was pressed before or not
float interval;
bool on; // determines whether led should be on or off
int currentstate;
enum gamestate {store, pattern, user, lose, win}; // possible states for the game
int j; // for leds
int counter; // input counter
bool timer = false;// used to note when the timer is on or off;
bool startup;
bool lost = false;
bool won = false;
void setup() {
  Serial.begin(9600);
  for(int p = 0; p < 3; p++){
    pinMode(leds[p], OUTPUT);
    pinMode(btns[p], INPUT);
    digitalWrite(btns[p],HIGH);
  }
  pinMode(potenti,INPUT);
  pinMode(buzz, OUTPUT);
  level = 0;
  on = true; 
  currentstate = store;
  j =  0;
  counter = 0;
  randomSeed(analogRead(A0));
  startup = true; 
}

void userflag() {
for(int i = 0; i < btnnumber; i++){
 int reading  =  digitalRead(btns[i]);
 if(reading == LOW){
  waspressed[i] = true; 
 }
 if(reading == HIGH && waspressed[i] == true){
  if(timer ==  false){
    m2[i] = millis();
    timer = true; 
  }
 if((millis() - m2[i]) >= debounce && waspressed[i] == true){
  inputflag[i] = true;
  waspressed[i] = false;
  timer = false;
 }
}
}
}

void validateinput(int userinput){
if(userinput == sequence[counter]){
  counter = counter + 1;
  if(userinput == 0){
  tone(buzz,262,10);
  }
  if(userinput == 1){
    tone(buzz,5000,20);
  }
  if(userinput == 2){
    tone(buzz,2000,15);
  }
}else{
  lost = true; 
  currentstate = lose;
}
}

void checkwin(){
  if(counter == (level + 1)){
    won = true; 
    currentstate = win;
  }
}


void flagaction() {
for(int i = 0; i < btnnumber; i++){
  if(inputflag[i] == true){ 
    validateinput(i);
    inputflag[i] = false;
  }
}
}


int picked() {
 return random(3);
}


void loop() {
  if(startup == true){
    tone(buzz,262,180);
    delay(200);
    tone(buzz,392,180);
    delay(200);
    tone(buzz, 523, 180);
    delay(200);
    startup = false; 
  }
  counter = constrain(counter, 0, 51); 
  j = constrain(j, 0, 51);
  level = constrain(level, 0, 50); // max 50 levels;
  interval = (600 + (analogRead(potenti)/2));
  switch(currentstate){
    case store:
     sequence[level] = constrain(picked(), 0 , 2); 
     currentstate = pattern;
     break;
    case pattern:
     if(on == true){
       digitalWrite(leds[sequence[j]],HIGH);
       if(millis() - m1 >= interval){
         m1 = millis();
         digitalWrite(leds[sequence[j]],LOW);
         on = false;
        }
      }
      if(on == false && (millis() - m1 >= 500)){
          on = true;
          j = j + 1;
        }
      if( j == (level+1)){
        currentstate = user;
      }
      break;
    case user:
    userflag();
    flagaction();
    checkwin();
    break;
    case lose: 
    if(lost == true){
      tone(buzz,5000,60);
      tonemillis[0] = millis() + 80;
      lost = false;
    }
    if(millis() == tonemillis[0]){
      tone(buzz,1800,80);
      tonemillis[1] = millis() + 100;
    }
    if(millis() == tonemillis[1]){
      tone(buzz,800,80);
      tonemillis[2] = millis() + 100;
    }
    if(millis() == tonemillis[2]){
      tone(buzz,350,60);
      tonemillis[3] = millis() + 80;
    }
    if(millis() == tonemillis[3]){
      tone(buzz,180,80);
      tonemillis[4] = millis() + 80;
    }
    if(millis() == tonemillis[4]){
      Serial.print("You lose start from begining. Score:");
      Serial.println(level);
      level = 0;
      counter = 0;
      j = 0;
      m1 = millis();
      currentstate = pattern;
      break; 
    }
    break;
    case win:
    if(won == true){
      tone(buzz,523,60);
      tonemillis[0] =  millis() + 80;
      won = false;
    }
    if(millis() == tonemillis[0]){
      tone(buzz,1000,80);
      tonemillis[1] = millis() + 100;
    }
    if(millis() == tonemillis[1]){
      tone(buzz,2000,80);
      tonemillis[2] = millis() + 100;
    }
    if(millis() == tonemillis[2]){
      tone(buzz,3500,80);
      tonemillis[3] = millis() + 100;
    }
    if(millis() == tonemillis[3]){
      tone(buzz,5000,80);
      tonemillis[4] = millis() + 80;
    }
    if(millis() == tonemillis[4]){
      Serial.println("You win entering new level");
      j = 0;
      counter = 0;
      level = level + 1;
      Serial.print("level:");  
      Serial.println(level);
      m1 = millis();
      currentstate = store; 
      break;
    }
    break;
  }
}