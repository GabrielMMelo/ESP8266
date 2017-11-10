#include <Arduino.h>
class Despertador {
private:
  int hour1;                         // transformar em vetor 
  int hour2;
  int minute1;
  int minute2;
  bool flag;
  void alarm();

public:
  bool block;
  Despertador();
  void setAlarmClock(String);
  void setAlarmOFF();
  void checkAlarm(String);
  bool getFlag();
  int getHour1();
  int getMinute1();
  int getHour2();
  int getMinute2();
};

