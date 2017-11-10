#include <Arduino.h>
#include <IRsend.h>
#include <PubSubClient.h> 
#define SamsungPower        0xE0E040BF  // Panasonic Power button

class Despertador {
private:
  int hour1;                         // transformar em vetor 
  int hour2;
  int minute1;
  int minute2;
  bool flag;
  void alarm(PubSubClient*);

public:
  bool block;
  bool StarWars(PubSubClient*);
  Despertador();
  void setAlarmClock(String);
  void setAlarmOFF();
  void checkAlarm(String,IRsend*, PubSubClient*);
  bool getFlag();
  int getHour1();
  int getMinute1();
  int getHour2();
  int getMinute2();
};

