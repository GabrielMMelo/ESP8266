#include "notas.h"
#include <Arduino.h>
#define buzzer 15

void milisecond(int tempo){
  int anterior = millis();
  int atual = anterior;
  while(atual - anterior <= tempo){
    atual = millis(); 
    yield();
  }
}


void StarWars(){
  tone(buzzer,NOTE_G6);
  milisecond(500);
  noTone(buzzer);
  milisecond(100);
  tone(buzzer,NOTE_G6);
  milisecond(300);
  noTone(buzzer);
  milisecond(100);
  tone(buzzer,NOTE_G6);
  milisecond(100);
  noTone(buzzer);
  tone(buzzer,NOTE_G6);
  milisecond(100);
  noTone(buzzer);
  tone(buzzer,NOTE_G6);
  milisecond(100);
  noTone(buzzer);
  tone(buzzer,NOTE_G6);
  milisecond(100);
  noTone(buzzer);
  milisecond(200);
  tone(buzzer,NOTE_G6);
  milisecond(100);
  noTone(buzzer);
  milisecond(150);
  tone(buzzer,NOTE_DS6);
  milisecond(100);
  noTone(buzzer);
  tone(buzzer,NOTE_DS6);
  milisecond(100);
  noTone(buzzer);
  tone(buzzer,NOTE_DS6);
  milisecond(100);
  noTone(buzzer);
  tone(buzzer,NOTE_DS6);
  milisecond(100);
  noTone(buzzer);
  tone(buzzer,NOTE_DS6);
  milisecond(100);
  noTone(buzzer);
  milisecond(160);
  
  tone(buzzer,NOTE_G6);
  milisecond(500);
  noTone(buzzer);
  milisecond(100);
  tone(buzzer,NOTE_G6);
  milisecond(300);
  noTone(buzzer);
  milisecond(100);
  tone(buzzer,NOTE_G6);
  milisecond(100);
  noTone(buzzer);
  tone(buzzer,NOTE_G6);
  milisecond(100);
  noTone(buzzer);
  tone(buzzer,NOTE_G6);
  milisecond(100);
  noTone(buzzer);
  tone(buzzer,NOTE_G6);
  milisecond(100);
  noTone(buzzer);
  milisecond(200);
  tone(buzzer,NOTE_G6);
  milisecond(100);
  noTone(buzzer);
  milisecond(150);
  tone(buzzer,NOTE_DS6);
  milisecond(100);
  noTone(buzzer);
  tone(buzzer,NOTE_DS6);
  milisecond(100);
  noTone(buzzer);
  tone(buzzer,NOTE_DS6);
  milisecond(100);
  noTone(buzzer);
  tone(buzzer,NOTE_DS6);
  milisecond(100);
  noTone(buzzer);
  tone(buzzer,NOTE_DS6);
  milisecond(100);
  noTone(buzzer);
  milisecond(160);

  tone(buzzer,NOTE_G6);
  milisecond(500);
  noTone(buzzer);
  milisecond(100);
  tone(buzzer,NOTE_G6);
  milisecond(300);
  noTone(buzzer);
  milisecond(100);
  tone(buzzer,NOTE_G6);
  milisecond(100);
  noTone(buzzer);
  tone(buzzer,NOTE_G6);
  milisecond(100);
  noTone(buzzer);
  tone(buzzer,NOTE_G6);
  milisecond(100);
  noTone(buzzer);
  tone(buzzer,NOTE_G6);
  milisecond(100);
  noTone(buzzer);
  milisecond(200);
  tone(buzzer,NOTE_G6);
  milisecond(100);
  noTone(buzzer);
  milisecond(150);
  tone(buzzer,NOTE_DS6);
  milisecond(100);
  noTone(buzzer);
  tone(buzzer,NOTE_DS6);
  milisecond(100);
  noTone(buzzer);
  tone(buzzer,NOTE_DS6);
  milisecond(100);
  noTone(buzzer);
  tone(buzzer,NOTE_DS6);
  milisecond(100);
  noTone(buzzer);
  tone(buzzer,NOTE_DS6);
  milisecond(100);
  noTone(buzzer);
  milisecond(160);
  
  tone(buzzer,NOTE_G6);
  milisecond(500);
  noTone(buzzer);
  milisecond(100);
  tone(buzzer,NOTE_G6);
  milisecond(300);
  noTone(buzzer);
  milisecond(100);
  tone(buzzer,NOTE_G6);
  milisecond(100);
  noTone(buzzer);
  tone(buzzer,NOTE_G6);
  milisecond(100);
  noTone(buzzer);
  tone(buzzer,NOTE_G6);
  milisecond(100);
  noTone(buzzer);
  tone(buzzer,NOTE_G6);
  milisecond(100);
  noTone(buzzer);
  milisecond(200);
  tone(buzzer,NOTE_G6);
  milisecond(100);
  noTone(buzzer);
  milisecond(150);
  tone(buzzer,NOTE_DS6);
  milisecond(100);
  noTone(buzzer);
  tone(buzzer,NOTE_DS6);
  milisecond(100);
  noTone(buzzer);
  tone(buzzer,NOTE_DS6);
  milisecond(100);
  noTone(buzzer);
  tone(buzzer,NOTE_DS6);
  milisecond(100);
  noTone(buzzer);
  tone(buzzer,NOTE_DS6);
  milisecond(100);
  noTone(buzzer);
  milisecond(160);
  

  tone(buzzer,NOTE_G6);
  milisecond(500);
  noTone(buzzer);
  milisecond(100);
  tone(buzzer,NOTE_G6);
  milisecond(300);
  noTone(buzzer);
  milisecond(100);
  tone(buzzer,NOTE_G6);
  milisecond(200);
  noTone(buzzer);
  milisecond(50);
  tone(buzzer,NOTE_G6);
  milisecond(400);
  noTone(buzzer);
  milisecond(150);
  tone(buzzer,NOTE_DS6);
  milisecond(300);
  noTone(buzzer);
  milisecond(50);
  tone(buzzer,NOTE_AS6);
  milisecond(250);
  noTone(buzzer);
  milisecond(50);
  tone(buzzer,NOTE_G6);
  milisecond(500);
  noTone(buzzer);
  milisecond(100);
  tone(buzzer,NOTE_DS6);
  milisecond(300);
  noTone(buzzer);
  milisecond(50);
  tone(buzzer,NOTE_AS6);
  milisecond(250);
  noTone(buzzer);
  milisecond(50);
  tone(buzzer,NOTE_G6);
  milisecond(500);
  noTone(buzzer);
  milisecond(500);
  
  tone(buzzer,NOTE_D7);
  milisecond(500);
  noTone(buzzer);
  milisecond(100);
  tone(buzzer,NOTE_D7);
  milisecond(250);
  noTone(buzzer);
  milisecond(100);
  tone(buzzer,NOTE_D7);
  milisecond(250);
  noTone(buzzer);
  milisecond(50);
  tone(buzzer,NOTE_D7);
  milisecond(500);
  noTone(buzzer);
  milisecond(150);
  tone(buzzer,NOTE_DS7);
  milisecond(300);
  noTone(buzzer);
  tone(buzzer,NOTE_AS6);
  milisecond(250);
  noTone(buzzer);
  milisecond(50);
  tone(buzzer,NOTE_G6);
  milisecond(500);
  noTone(buzzer);
  milisecond(200);
  tone(buzzer,NOTE_DS6);
  milisecond(300);
  noTone(buzzer);
  tone(buzzer,NOTE_AS6);
  milisecond(250);
  noTone(buzzer);
  milisecond(50);
  tone(buzzer,NOTE_G6);
  milisecond(500);
  noTone(buzzer);
  milisecond(500);
 
  tone(buzzer,NOTE_G7);
  milisecond(500);
  noTone(buzzer);
  milisecond(100);
  tone(buzzer,NOTE_D6);
  milisecond(300);
  noTone(buzzer);
  milisecond(50);
  tone(buzzer,NOTE_D6);
  milisecond(300);
  noTone(buzzer);
  milisecond(50);
  tone(buzzer,NOTE_G7);
  milisecond(500);
  noTone(buzzer);
  milisecond(100);
  tone(buzzer,NOTE_FS7);
  milisecond(300);
  noTone(buzzer);
  milisecond(50);
  tone(buzzer,NOTE_F7);
  milisecond(300);
  noTone(buzzer);
  milisecond(50);
  tone(buzzer,NOTE_E7);
  milisecond(100);
  noTone(buzzer);
  milisecond(50);
  tone(buzzer,NOTE_DS7);
  milisecond(100);
  noTone(buzzer);
  milisecond(50);
  tone(buzzer,NOTE_E7);
  milisecond(100);
  noTone(buzzer);
  milisecond(500);

  tone(buzzer,NOTE_DS6);
  milisecond(300);
  noTone(buzzer);
  milisecond(50);
  tone(buzzer,NOTE_CS7);
  milisecond(500);
  noTone(buzzer);
  milisecond(100);
  tone(buzzer,NOTE_C7);
  milisecond(300);
  noTone(buzzer);
  milisecond(50);
  tone(buzzer,NOTE_B7);
  milisecond(300);
  noTone(buzzer);
  milisecond(50);
  tone(buzzer,NOTE_AS6);
  milisecond(100);
  noTone(buzzer);
  milisecond(50);
  tone(buzzer,NOTE_A6);
  milisecond(100);
  noTone(buzzer);
  milisecond(50);
  tone(buzzer,NOTE_AS6);
  milisecond(100);
  noTone(buzzer);
  milisecond(500);

  tone(buzzer,NOTE_DS6);
  milisecond(300);
  noTone(buzzer);
  milisecond(100);
  tone(buzzer,NOTE_G6);
  milisecond(500);
  noTone(buzzer);
  milisecond(100);
  tone(buzzer,NOTE_DS6);
  milisecond(250);
  noTone(buzzer);
  milisecond(50);
  tone(buzzer,NOTE_G6);
  milisecond(250);
  noTone(buzzer);
  milisecond(50);
  tone(buzzer,NOTE_AS6);
  milisecond(400);
  noTone(buzzer);
  milisecond(250);
  tone(buzzer,NOTE_G6);
  milisecond(250);
  noTone(buzzer);
  milisecond(100);
  tone(buzzer,NOTE_AS6);
  milisecond(250);
  noTone(buzzer);
  milisecond(50);
  tone(buzzer,NOTE_D7);
  milisecond(500);
  noTone(buzzer);
  milisecond(500);

  tone(buzzer,NOTE_G7);
  milisecond(500);
  noTone(buzzer);
  milisecond(100);
  tone(buzzer,NOTE_D6);
  milisecond(300);
  noTone(buzzer);
  milisecond(50);
  tone(buzzer,NOTE_D6);
  milisecond(300);
  noTone(buzzer);
  milisecond(50);
  tone(buzzer,NOTE_G7);
  milisecond(500);
  noTone(buzzer);
  milisecond(100);
  tone(buzzer,NOTE_FS7);
  milisecond(300);
  noTone(buzzer);
  milisecond(50);
  tone(buzzer,NOTE_F7);
  milisecond(300);
  noTone(buzzer);
  milisecond(50);
  tone(buzzer,NOTE_E7);
  milisecond(100);
  noTone(buzzer);
  milisecond(50);
  tone(buzzer,NOTE_DS7);
  milisecond(100);
  noTone(buzzer);
  milisecond(50);
  tone(buzzer,NOTE_E7);
  milisecond(100);
  noTone(buzzer);
  milisecond(500);
  
  tone(buzzer,NOTE_DS6);
  milisecond(300);
  noTone(buzzer);
  milisecond(50);
  tone(buzzer,NOTE_CS7);
  milisecond(500);
  noTone(buzzer);
  milisecond(100);
  tone(buzzer,NOTE_C7);
  milisecond(300);
  noTone(buzzer);
  milisecond(50);
  tone(buzzer,NOTE_B7);
  milisecond(300);
  noTone(buzzer);
  milisecond(50);
  tone(buzzer,NOTE_AS6);
  milisecond(100);
  noTone(buzzer);
  milisecond(50);
  tone(buzzer,NOTE_A6);
  milisecond(100);
  noTone(buzzer);
  milisecond(50);
  tone(buzzer,NOTE_AS6);
  milisecond(100);
  noTone(buzzer);
  milisecond(500);
  
  tone(buzzer,NOTE_DS6);
  milisecond(300);
  noTone(buzzer);
  milisecond(100);
  tone(buzzer,NOTE_G6);
  milisecond(500);
  noTone(buzzer);
  milisecond(100);
  tone(buzzer,NOTE_DS6);
  milisecond(250);
  noTone(buzzer);
  milisecond(50);
  tone(buzzer,NOTE_AS6);
  milisecond(250);
  noTone(buzzer);
  milisecond(50);
  tone(buzzer,NOTE_G6);
  milisecond(400);
  noTone(buzzer);
  milisecond(250);
  tone(buzzer,NOTE_DS6);
  milisecond(250);
  noTone(buzzer);
  milisecond(100);
  tone(buzzer,NOTE_AS6);
  milisecond(250);
  noTone(buzzer);
  milisecond(50);
  tone(buzzer,NOTE_G6);
  milisecond(700);
  noTone(buzzer);
  milisecond(500);
}

void beep() {
  tone(buzzer,NOTE_G6);
  milisecond(700);
  noTone(buzzer);
  milisecond(500);
  tone(buzzer,NOTE_C6);
  milisecond(700);
  noTone(buzzer);
  milisecond(500);
}

