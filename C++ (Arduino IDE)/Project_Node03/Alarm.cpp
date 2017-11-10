#include "Alarm.h"
#include "Notes.h"

Alarm::Alarm(){
  flag = false;
  block = false;
}

bool Alarm::getFlag(){
  return flag;  
}

int Alarm::getHour1() {
  return hour1;
}


int Alarm::getHour2() {
  return hour2;
}

int Alarm::getMinute1() {
  return minute1;
}

int Alarm::getMinute2() {
  return minute2;
}

void Alarm::checkAlarm(String hora, IRsend* IR, PubSubClient* client) {
  if(flag){
      if((hour1 == hora[0]) and (hour2 == hora[1]) and (minute1 == hora[3]) and (minute2 == hora[4])) {
          IR->sendSAMSUNG(SamsungPower, SAMSUNG_BITS, 0);  // hex value, 16 bits, no repeat
          IR->sendSAMSUNG(SamsungPower, SAMSUNG_BITS, 1);  // hex value, 16 bits, repeat
          client->publish("/node03/fromNode","conecao_estabelecida");
          alarm(client);
      }
  }
}

void Alarm::alarm(PubSubClient* client) {
  if(!block) {
    for(int i = 0 ; i < _repeat ; i++){
      //beep();
      if(StarWars(client))
      delay(50);
      else break;
    }
    
    flag = false;
    block = true;
  }
}

void Alarm::setAlarmClock(String msg) {
  hour1 = msg[0];
  hour2 = msg[1];
  minute1 = msg[2];
  minute2 = msg[3];
  flag = true;
  block=false;
}

void Alarm::setAlarmOFF() { 
  flag =  false;
}
