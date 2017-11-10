#ifndef ALARM_H
#define ALARM_H
#include <Arduino.h>
#include <IRsend.h>
#include <PubSubClient.h> 
#include <LiquidCrystal.h>
#define SamsungPower        0xE0E040BF  // Panasonic Power button
#define _repeat 5

class Alarm {
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
  Alarm();
  void setAlarmClock(String);
  void setAlarmOFF();
  void checkAlarm(String,IRsend*, PubSubClient*);
  bool getFlag();
  int getHour1();
  int getMinute1();
  int getHour2();
  int getMinute2();
};
#endif
