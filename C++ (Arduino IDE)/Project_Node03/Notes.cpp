#include "Notes.h"
#include "Alarm.h"
#include <Arduino.h>
#define buzzer 10

bool milisecond(int tempo, bool flag){
  int anterior = millis();
  int atual = anterior;
  while(atual - anterior <= tempo){
    if(!flag){
      return false;
    }
    atual = millis(); 
    yield();
  }
  return true;
}


bool Alarm::StarWars(PubSubClient* client){
  tone(buzzer,NOTE_G6);
  client->loop();
  client->loop();if(milisecond(500,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(100,getFlag()))
  tone(buzzer,NOTE_G6);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(300,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(100,getFlag()))
  tone(buzzer,NOTE_G6);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(100,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  tone(buzzer,NOTE_G6);
  client->loop();if(milisecond(100,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  tone(buzzer,NOTE_G6);
  client->loop();if(milisecond(100,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  tone(buzzer,NOTE_G6);
  client->loop();if(milisecond(100,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(200,getFlag()))
  tone(buzzer,NOTE_G6);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(100,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(150,getFlag()))
  tone(buzzer,NOTE_DS6);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(100,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  tone(buzzer,NOTE_DS6);
  client->loop();if(milisecond(100,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  tone(buzzer,NOTE_DS6);
  client->loop();if(milisecond(100,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  tone(buzzer,NOTE_DS6);
  client->loop();if(milisecond(100,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  tone(buzzer,NOTE_DS6);
  client->loop();if(milisecond(100,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(160,getFlag()))
  tone(buzzer,NOTE_G6);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(500,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(100,getFlag()))
  tone(buzzer,NOTE_G6);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(300,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(100,getFlag()))
  tone(buzzer,NOTE_G6);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(100,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  tone(buzzer,NOTE_G6);
  client->loop();if(milisecond(100,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  tone(buzzer,NOTE_G6);
  client->loop();if(milisecond(100,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  tone(buzzer,NOTE_G6);
  client->loop();if(milisecond(100,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(200,getFlag()))
  tone(buzzer,NOTE_G6);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(100,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(150,getFlag()))
  tone(buzzer,NOTE_DS6);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(100,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  tone(buzzer,NOTE_DS6);
  client->loop();if(milisecond(100,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  tone(buzzer,NOTE_DS6);
  client->loop();if(milisecond(100,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  tone(buzzer,NOTE_DS6);
  client->loop();if(milisecond(100,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  tone(buzzer,NOTE_DS6);
  client->loop();if(milisecond(100,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(160,getFlag()))

  tone(buzzer,NOTE_G6);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(500,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(100,getFlag()))
  tone(buzzer,NOTE_G6);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(300,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(100,getFlag()))
  tone(buzzer,NOTE_G6);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(100,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  tone(buzzer,NOTE_G6);
  client->loop();if(milisecond(100,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  tone(buzzer,NOTE_G6);
  client->loop();if(milisecond(100,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  tone(buzzer,NOTE_G6);
  client->loop();if(milisecond(100,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(200,getFlag()))
  tone(buzzer,NOTE_G6);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(100,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(150,getFlag()))
  tone(buzzer,NOTE_DS6);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(100,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  tone(buzzer,NOTE_DS6);
  client->loop();if(milisecond(100,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  tone(buzzer,NOTE_DS6);
  client->loop();if(milisecond(100,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  tone(buzzer,NOTE_DS6);
  client->loop();if(milisecond(100,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  tone(buzzer,NOTE_DS6);
  client->loop();if(milisecond(100,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(160,getFlag()))
  
  tone(buzzer,NOTE_G6);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(500,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(100,getFlag()))
  tone(buzzer,NOTE_G6);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(300,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(100,getFlag()))
  tone(buzzer,NOTE_G6);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(100,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  tone(buzzer,NOTE_G6);
  client->loop();if(milisecond(100,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  tone(buzzer,NOTE_G6);
  client->loop();if(milisecond(100,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  tone(buzzer,NOTE_G6);
  client->loop();if(milisecond(100,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(200,getFlag()))
  tone(buzzer,NOTE_G6);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(100,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(150,getFlag()))
  tone(buzzer,NOTE_DS6);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(100,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  tone(buzzer,NOTE_DS6);
  client->loop();if(milisecond(100,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  tone(buzzer,NOTE_DS6);
  client->loop();if(milisecond(100,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  tone(buzzer,NOTE_DS6);
  client->loop();if(milisecond(100,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  tone(buzzer,NOTE_DS6);
  client->loop();if(milisecond(100,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(160,getFlag()))
  

  tone(buzzer,NOTE_G6);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(500,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(100,getFlag()))
  tone(buzzer,NOTE_G6);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(300,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(100,getFlag()))
  tone(buzzer,NOTE_G6);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(200,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(50,getFlag()))
  tone(buzzer,NOTE_G6);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(400,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(150,getFlag()))
  tone(buzzer,NOTE_DS6);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(300,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(50,getFlag()))
  tone(buzzer,NOTE_AS6);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(250,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(50,getFlag()))
  tone(buzzer,NOTE_G6);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(500,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(100,getFlag()))
  tone(buzzer,NOTE_DS6);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(300,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(50,getFlag()))
  tone(buzzer,NOTE_AS6);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(250,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(50,getFlag()))
  tone(buzzer,NOTE_G6);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(500,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(500,getFlag()))
  
  tone(buzzer,NOTE_D7);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(500,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(100,getFlag()))
  tone(buzzer,NOTE_D7);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(250,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(100,getFlag()))
  tone(buzzer,NOTE_D7);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(250,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(50,getFlag()))
  tone(buzzer,NOTE_D7);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(500,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(150,getFlag()))
  tone(buzzer,NOTE_DS7);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(300,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  tone(buzzer,NOTE_AS6);
  client->loop();if(milisecond(250,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(50,getFlag()))
  tone(buzzer,NOTE_G6);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(500,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(200,getFlag()))
  tone(buzzer,NOTE_DS6);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(300,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  tone(buzzer,NOTE_AS6);
  client->loop();if(milisecond(250,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(50,getFlag()))
  tone(buzzer,NOTE_G6);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(500,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(500,getFlag()))
 
  tone(buzzer,NOTE_G7);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(500,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(100,getFlag()))
  tone(buzzer,NOTE_D6);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(300,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(50,getFlag()))
  tone(buzzer,NOTE_D6);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(300,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(50,getFlag()))
  tone(buzzer,NOTE_G7);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(500,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(100,getFlag()))
  tone(buzzer,NOTE_FS7);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(300,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(50,getFlag()))
  tone(buzzer,NOTE_F7);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(300,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(50,getFlag()))
  tone(buzzer,NOTE_E7);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(100,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(50,getFlag()))
  tone(buzzer,NOTE_DS7);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(100,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(50,getFlag()))
  tone(buzzer,NOTE_E7);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(100,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(500,getFlag()))

  tone(buzzer,NOTE_DS6);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(300,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(50,getFlag()))
  tone(buzzer,NOTE_CS7);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(500,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(100,getFlag()))
  tone(buzzer,NOTE_C7);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(300,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(50,getFlag()))
  tone(buzzer,NOTE_B7);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(300,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(50,getFlag()))
  tone(buzzer,NOTE_AS6);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(100,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(50,getFlag()))
  tone(buzzer,NOTE_A6);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(100,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(50,getFlag()))
  tone(buzzer,NOTE_AS6);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(100,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(500,getFlag()))

  tone(buzzer,NOTE_DS6);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(300,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(100,getFlag()))
  tone(buzzer,NOTE_G6);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(500,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(100,getFlag()))
  tone(buzzer,NOTE_DS6);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(250,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(50,getFlag()))
  tone(buzzer,NOTE_G6);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(250,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(50,getFlag()))
  tone(buzzer,NOTE_AS6);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(400,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(250,getFlag()))
  tone(buzzer,NOTE_G6);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(250,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(100,getFlag()))
  tone(buzzer,NOTE_AS6);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(250,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(50,getFlag()))
  tone(buzzer,NOTE_D7);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(500,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(500,getFlag()))

  tone(buzzer,NOTE_G7);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(500,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(100,getFlag()))
  tone(buzzer,NOTE_D6);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(300,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(50,getFlag()))
  tone(buzzer,NOTE_D6);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(300,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(50,getFlag()))
  tone(buzzer,NOTE_G7);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(500,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(100,getFlag()))
  tone(buzzer,NOTE_FS7);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(300,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(50,getFlag()))
  tone(buzzer,NOTE_F7);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(300,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(50,getFlag()))
  tone(buzzer,NOTE_E7);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(100,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(50,getFlag()))
  tone(buzzer,NOTE_DS7);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(100,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(50,getFlag()))
  tone(buzzer,NOTE_E7);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(100,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(500,getFlag()))
  
  tone(buzzer,NOTE_DS6);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(300,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(50,getFlag()))
  tone(buzzer,NOTE_CS7);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(500,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(100,getFlag()))
  tone(buzzer,NOTE_C7);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(300,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(50,getFlag()))
  tone(buzzer,NOTE_B7);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(300,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(50,getFlag()))
  tone(buzzer,NOTE_AS6);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(100,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(50,getFlag()))
  tone(buzzer,NOTE_A6);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(100,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(50,getFlag()))
  tone(buzzer,NOTE_AS6);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(100,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(500,getFlag()))
  
  tone(buzzer,NOTE_DS6);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(300,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(100,getFlag()))
  tone(buzzer,NOTE_G6);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(500,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(100,getFlag()))
  tone(buzzer,NOTE_DS6);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(250,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(50,getFlag()))
  tone(buzzer,NOTE_AS6);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(250,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(50,getFlag()))
  tone(buzzer,NOTE_G6);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(400,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(250,getFlag()))
  tone(buzzer,NOTE_DS6);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(250,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(100,getFlag()))
  tone(buzzer,NOTE_AS6);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(250,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(50,getFlag()))
  tone(buzzer,NOTE_G6);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(700,getFlag()))
  noTone(buzzer);
  else {noTone(buzzer);return false;}
  client->loop();if(milisecond(500,getFlag()))
  return true;
}

/*void beep() {
  tone(buzzer,NOTE_G6);
  client->loop();if(milisecond(700,getFlag()))
  noTone(buzzer);
  client->loop();if(milisecond(500,getFlag()))
  tone(buzzer,NOTE_C6);
  client->loop();if(milisecond(700,getFlag()))
  noTone(buzzer);
  client->loop();if(milisecond(500,getFlag()))
}
*/

