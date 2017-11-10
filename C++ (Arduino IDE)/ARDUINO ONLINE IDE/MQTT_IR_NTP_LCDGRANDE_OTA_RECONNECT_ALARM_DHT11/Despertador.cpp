#include "Despertador.h"
#include "notas.h"

Despertador::Despertador(){
  flag = false;
  block = false;
}

bool Despertador::getFlag(){
  return flag;  
}

int Despertador::getHour1() {
  return hour1;
}


int Despertador::getHour2() {
  return hour2;
}

int Despertador::getMinute1() {
  return minute1;
}

int Despertador::getMinute2() {
  return minute2;
}

void Despertador::checkAlarm(String hora) {
  if(flag){
      if((hour1 == hora[0]) and (hour2 == hora[1]) and (minute1 == hora[3]) and (minute2 == hora[4]))
          alarm();
  }
}

void Despertador::alarm() {
  if(!block) {
    for(int i = 0 ; i < 3 ; i++){
      //beep();
      StarWars();
      delay(50);
    }
    flag = false;
    block = true;
  }
}

void Despertador::setAlarmClock(String msg) {
  hour1 = msg[0];
  hour2 = msg[1];
  minute1 = msg[2];
  minute2 = msg[3];
  flag = true;
  block=false;
}

void Despertador::setAlarmOFF() { 
  flag =  false;
}
