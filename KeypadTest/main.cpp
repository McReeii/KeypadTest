#include <Arduino.h>

const int pinCols[4]={2,3,4,5};
const int pinRows[5]={6,7,8,9,10};

#define OKled 13                                                   
#define Buzzer 12
#define Led1 A4
#define Led2 A5

//int KeyResis = 0;
//bool KeyPress = false;

//unsigned long time_now = 0;

//int reading;

//const int ReadPin[4]={A0,A1,A2,A3};


char keys[5][4]={
  {'T','t','>','+'},
  {'G','g','<','-'},
  {'S','A','C','E'},
  {'D','U','W','L'},
  {'Z','H','f','F'},
};

void readKey(){
  for (int c=0; c<4; c++) {
    digitalWrite(pinCols[c], HIGH);
    for(int r=0; r<5; r++){
      if (digitalRead(pinRows[r]) == HIGH) {
        Serial.println(keys[r][c]); //we dispalay the right symbol
        digitalWrite(Buzzer, HIGH);
        digitalWrite(OKled, HIGH);
        delay(200);

      }
    }
    digitalWrite(pinCols[c], LOW);
    digitalWrite(Buzzer, LOW);
    digitalWrite(OKled, LOW);
  }
}


void setup() {
  Serial.begin(9600);
  
  for(int i=0; i<4; i++) {
    pinMode(pinCols[i], OUTPUT);
    digitalWrite(pinCols[i], HIGH);
  }

   for(int j=0; j<5; j++) {
    pinMode(pinRows[j], INPUT);
    //pinMode(ReadPin[j], INPUT);
  }

  pinMode(OKled, OUTPUT);
  pinMode(Buzzer, OUTPUT);
  pinMode(Led1, OUTPUT);
  pinMode(Led2, OUTPUT);
 

} 

void loop() {

  readKey();
  delay(100);
}
