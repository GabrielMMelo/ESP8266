#ifndef UNIT_TEST2
#include <Arduino.h>
#endif
#ifdef ESP8266
extern "C" {
bool system_update_cpu_freq(int);
}
#endif
//#include "DHT.h"
#include <IRremoteESP8266.h>
#include <IRsend.h>
#include <PubSubClient.h>  //https://github.com/knolleary/pubsubclient/blob/master/examples/mqtt_esp8266/mqtt_esp8266.ino
#include <NTPClient.h>
#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>
#include <LiquidCrystal.h>
//#include <ctype.h>
#define buzzer 15
#include "notas.h"


//#define DHTPIN 2     // what digital pin we're connected to
//#define DHTTYPE DHT11   // DHT 11

#define SamsungPower        0xE0E040BF  // Panasonic Power button
#define SamsungSource        0xE0E0807F  // Panasonic Source button
#define SamsungExit        0xE0E0B44B  // Panasonic Exit button
#define SamsungUp        0xE0E006F9  // Panasonic Up button
#define SamsungDown        0xE0E08679  // Panasonic Down button
#define SamsungRight        0xE0E046B9  // Panasonic Right button
#define SamsungLeft        0xE0E0A659  // Panasonic Left button
#define SamsungSelect        0xE0E016E9  // Panasonic Select button
#define SamsungUpVol        0xE0E0E01F  // Panasonic Up Volume button
#define SamsungDownVol        0xE0E0D02F  // Panasonic Down Volume button
#define SamsungUpCh        0xE0E048B7  // Panasonic Up Channel button
#define SamsungDownCh        0xE0E008F7  // Panasonic Down Channel button
#define SamsungMute        0xE0E0F00F  // Panasonic Mute button


bool block = false;
//ADC_MODE(ADC_VCC);
IRsend irsend(3);  // An IR LED is controlled by GPIO pin 4 (D2)

class Despertador {
private:
  int hour1;                         // transformar em vetor 
  int hour2;
  int minute1;
  int minute2;
  bool flag;
  void alarm();
public:
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

Despertador::Despertador(){
  flag = false;
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
  irsend.sendSAMSUNG(SamsungPower, SAMSUNG_BITS, 0);  // hex value, 16 bits, no repeat
  irsend.sendSAMSUNG(SamsungPower, SAMSUNG_BITS, 1);  // hex value, 16 bits, repeat
  if(!block) {
     //beep();
     StarWars();
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

Despertador despertador;

 /*************************************************************************************************************
*******************************CLASSE LCD BIG NUMBERS*********************************************************
**************************************************************************************************************/
struct LCDNumber {
  byte top1;
  byte top2;
  byte top3;
  byte bottom1;
  byte bottom2;
  byte bottom3;
};
  
class LCDBigNumbers {
  private:
    LiquidCrystal * _lcd;
    int _row;
    int _col;
    long _value; /*0..100*/
      
    void _clear(){
      int cont = 1;
      long x = 9;
      while (_value > x){
        cont++;
        x = x * 10 + 9;
      }
      for (int i=0; i<cont; i++) {
        _lcd->setCursor(_col+i, _row);
        _lcd->print( "    " );
        _lcd->setCursor(_col+i, _row+1);
        _lcd->print( "    " );
      }
    }
  public:
    static byte c0[8];  //bottom
    static byte c1[8];  //top
    static byte c2[8];  //fill
    static byte c3[8];
    static byte c4[8];
    static byte c5[8];  //top-bottom 
    static LCDNumber _lcd_numbers[];
     
    void createChars() {
      _lcd->createChar(0, c0);
      _lcd->createChar(1, c1);
      _lcd->createChar(2, c2);
      _lcd->createChar(3, c3);
      _lcd->createChar(4, c4);
      _lcd->createChar(5, c5);
      //_lcd->createChar(6, c6);
      //_lcd->createChar(7, c7);
    }
      
    LCDBigNumbers(LiquidCrystal * lcd, int row, int col) {
      _lcd = lcd;      _row = row;      _col = col;
    }
      
    void setRow(int row){
      _clear();
      _row = row;
      setValue(_value);
    }
    void setCol(int col){
    //  _clear();
      _col = col;
      setValue(_value);
    }
      
    void setValue(long value){
     // _clear();
      _value = value;
        
      int cont = 1;
      long x = 9;
      while (abs(_value) > x){
        cont++;
        x = x * 10 + 9;
      }
        
      for (int i=0; i<cont; i++) {
        int n = value / pow(10, cont-1-i);
        value = value - pow(10, cont-1-i) * n;
          
        _lcd->setCursor(_col+i*4, _row);
        _lcd_numbers[n].top1 == 9 ? _lcd->print(" ") : _lcd->write( _lcd_numbers[n].top1 );
        _lcd_numbers[n].top2 == 9 ? _lcd->print(" ") : _lcd->write( _lcd_numbers[n].top2 );
        _lcd_numbers[n].top3 == 9 ? _lcd->print(" ") : _lcd->write( _lcd_numbers[n].top3 );
        _lcd->setCursor(_col+i*4, _row+1);
        _lcd_numbers[n].bottom1 == 9 ? _lcd->print(" ") : _lcd->write( _lcd_numbers[n].bottom1 );
        _lcd_numbers[n].bottom2 == 9 ? _lcd->print(" ") : _lcd->write( _lcd_numbers[n].bottom2 );
        _lcd_numbers[n].bottom3 == 9 ? _lcd->print(" ") : _lcd->write( _lcd_numbers[n].bottom3 );
      }
    }
};
 
byte LCDBigNumbers::c0[8] = {B00000, B00000, B00000, B00000, B00000, B11111, B11111, B11111};  //bottom
byte LCDBigNumbers::c1[8] = {B11111, B11111, B11111, B00000, B00000, B00000, B00000, B00000};  //top
byte LCDBigNumbers::c2[8] = {B11111, B11111, B11111, B11111, B11111, B11111, B11111, B11111};  //fill
byte LCDBigNumbers::c3[8] = {B00000, B00000, B00001, B00011, B00011, B00001, B00000, B00000};
byte LCDBigNumbers::c4[8] = {B00000, B00000, B10000, B11000, B11000, B10000, B00000, B00000};
byte LCDBigNumbers::c5[8] = {B11111, B11111, B00000, B00000, B00000, B00000, B11111, B11111};   //top / bottom 
 
LCDNumber LCDBigNumbers::_lcd_numbers[] = { 
      {2, 1, 2, 2, 0, 2}, //0
      {1, 2, 9, 0, 2, 0}, //1
      {1, 5, 2, 2, 0, 0}, //2
      {1, 5, 2, 0, 0, 2}, //3
      {2, 0, 2, 9, 9, 2}, //4
      {2, 5, 1, 0, 0, 2}, //5
      {2, 5, 1, 2, 0, 2}, //6
      {1, 1, 2, 9, 9, 2}, //7
      {2, 5, 2, 2, 0, 2}, //8
      {2, 5, 2, 0, 0, 2} // 9
    };
/*************************************************************************************************************
*******************************FIM CLASSE LCD BIG NUMBERS*****************************************************
**************************************************************************************************************/
    
LiquidCrystal lcd(5, 4, 16, 14, 12, 13); // pinos ESP-12
LCDBigNumbers lcdNum(&lcd, 0,0); //inclui uma barra no lcd, primeira linha, coluna 1

//DHT dht(DHTPIN, DHTTYPE);


const char *ssid     = "Dougras";
const char *password = "eusouodougrasvocenaoehodougras";
const char* mqttServer = "m13.cloudmqtt.com"; // Aqui o endereço do seu servidor fornecido pelo site 
const int mqttPort =16595; // Aqui mude para sua porta fornecida pelo site
const char* mqttUser = "node03"; //  Aqui o nome de usuario fornecido pelo site
const char* mqttPassword = "node03"; //  Aqui sua senha fornecida pelo site
WiFiClient espClient;
PubSubClient client(espClient);

unsigned long initTime;
unsigned long posTime;

bool blink =false;

unsigned int stat;

void mqtt_callback(char* topic, byte* payload, unsigned int length);

WiFiUDP ntpUDP;

int16_t utc = -3; //UTC -3:00 Brazil
uint32_t currentMillis = 0;
uint32_t previousMillis = 0;

NTPClient timeClient(ntpUDP, "a.st1.ntp.br", utc*3600, 60000);

long contador, contadorAnt;

String hora;

void setup(){
#ifdef ESP8266
system_update_cpu_freq(160);
#endif

//dht.begin();
  
contadorAnt=millis();
ArduinoOTA.setHostname("esp-3");

  // No authentication by default
  // ArduinoOTA.setPassword((const char *)"123");

  ArduinoOTA.onStart([]() {
    Serial.println("Start");
  });
  ArduinoOTA.onEnd([]() {
    Serial.println("\nEnd");
  });
  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
    Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
  });
  ArduinoOTA.onError([](ota_error_t error) {
    Serial.printf("Error[%u]: ", error);
    if (error == OTA_AUTH_ERROR) Serial.println("Auth Failed");
    else if (error == OTA_BEGIN_ERROR) Serial.println("Begin Failed");
    else if (error == OTA_CONNECT_ERROR) Serial.println("Connect Failed");
    else if (error == OTA_RECEIVE_ERROR) Serial.println("Receive Failed");
    else if (error == OTA_END_ERROR) Serial.println("End Failed");
  });
  ArduinoOTA.begin();

 lcdNum.createChars();
 lcd.begin(16, 2);
 
 
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(0,HIGH);

  irsend.begin();
  WiFi.begin(ssid, password);

  while ( WiFi.status() != WL_CONNECTED ) {
    delay ( 500 );
    lcd.setCursor(0,0);
   lcd.print("WiFi...");
  }
  lcd.clear();
  lcd.setCursor(0,0);
   lcd.print("WiFi OK!");
   delay(1000);
  timeClient.begin();
  timeClient.update();

  client.setServer(mqttServer, mqttPort);
  client.setCallback(callback);
 
  while (!client.connected()) {
  lcd.clear();
  lcd.setCursor(0,0);
   lcd.print("MQTT...");
   delay(1000);
    if (client.connect("ESP8266Client", mqttUser, mqttPassword )) {
       lcd.clear();
       lcd.setCursor(0,0);
       lcd.print("MQTT OK!");
       delay(1000);
       digitalWrite(LED_BUILTIN, LOW);
    } else {
       lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("MQTT BAD:" +client.state());
      //Serial.print(F("failed with state "));
      //Serial.print(client.state());
      delay(2000);
    }
     lcd.clear();
  }
  
 
  client.publish("/node03","conecao_estabelecida");
  client.subscribe("/node03/tv");
}

void forceUpdate(void) {
  timeClient.forceUpdate();
}

void checkOST(void) {
  currentMillis = millis();//Tempo atual em ms
  //Lógica de verificação do tempo
  if (currentMillis - previousMillis > 1000) {
    previousMillis = currentMillis;    // Salva o tempo atual
    printf("Time Epoch: %d: ", timeClient.getEpochTime());
   // Serial.println(timeClient.getFormattedTime());
   lcd.setCursor(6, 1);
   //lcd.print(timeClient.getFormattedTime());
   imprime();
  }
}


void imprime() {
  String aux = timeClient.getFormattedTime();
  switch(aux[0]) {
    case '1':
    lcdNum.setCol(0);
    lcdNum.setValue(1);
    break;
    case '2':
    lcdNum.setCol(0);
    lcdNum.setValue(2);
    break;
    case '3':
    lcdNum.setCol(0);
    lcdNum.setValue(3);
    break;
    case '4':
    lcdNum.setCol(0);
    lcdNum.setValue(4);
    break;
    case '5':
    lcdNum.setCol(0);
    lcdNum.setValue(5);
    break;
    case '6':
    lcdNum.setCol(0);
    lcdNum.setValue(6);
    break;
    case '7':
    lcdNum.setCol(0);
    lcdNum.setValue(7);
    break;
    case '8':
    lcdNum.setCol(0);
    lcdNum.setValue(8);
    break;
    case '9':
    lcdNum.setCol(0);
    lcdNum.setValue(9);
    break;
    case '0':
    lcdNum.setCol(0);
    lcdNum.setValue(0);
    break;   
  }
  
  switch(aux[1]) {
    case '1':
    lcdNum.setCol(4);
    lcdNum.setValue(1);
    break;
    case '2':
    lcdNum.setCol(4);
    lcdNum.setValue(2);
    break;
    case '3':
    lcdNum.setCol(4);
    lcdNum.setValue(3);
    break;
    case '4':
    lcdNum.setCol(4);
    lcdNum.setValue(4);
    break;
    case '5':
    lcdNum.setCol(4);
    lcdNum.setValue(5);
    break;
    case '6':
    lcdNum.setCol(4);
    lcdNum.setValue(6);
    break;
    case '7':
    lcdNum.setCol(4);
    lcdNum.setValue(7);
    break;
    case '8':
    lcdNum.setCol(4);
    lcdNum.setValue(8);
    break;
    case '9':
    lcdNum.setCol(4);
    lcdNum.setValue(9);
    break;
    case '0':
    lcdNum.setCol(4);
    lcdNum.setValue(0);
    break;   
  }
  if(!blink){
  lcd.setCursor(7,0);
  lcd.print("..");
  lcd.setCursor(7,1);
  lcd.print("..");
  blink=true;}
  else{
    lcd.setCursor(7,0);
  lcd.print("  ");
  lcd.setCursor(7,1);
  lcd.print("  ");
  blink=false;
  }
  
  switch(aux[3]) {
    case '1':
    lcdNum.setCol(9);
    lcdNum.setValue(1);
    break;
    case '2':
    lcdNum.setCol(9);
    lcdNum.setValue(2);
    break;
    case '3':
    lcdNum.setCol(9);
    lcdNum.setValue(3);
    break;
    case '4':
    lcdNum.setCol(9);
    lcdNum.setValue(4);
    break;
    case '5':
    lcdNum.setCol(9);
    lcdNum.setValue(5);
    break;
    case '6':
    lcdNum.setCol(9);
    lcdNum.setValue(6);
    break;
    case '7':
    lcdNum.setCol(9);
    lcdNum.setValue(7);
    break;
    case '8':
    lcdNum.setCol(9);
    lcdNum.setValue(8);
    break;
    case '9':
    lcdNum.setCol(9);
    lcdNum.setValue(9);
    break;
    case '0':
    lcdNum.setCol(9);
    lcdNum.setValue(0);
    break;   
  }
  
  switch(aux[4]) {
    case '1':
    lcdNum.setCol(13);
    lcdNum.setValue(1);
    break;
    case '2':
    lcdNum.setCol(13);
    lcdNum.setValue(2);
    break;
    case '3':
    lcdNum.setCol(13);
    lcdNum.setValue(3);
    break;
    case '4':
    lcdNum.setCol(13);
    lcdNum.setValue(4);
    break;
    case '5':
    lcdNum.setCol(13);
    lcdNum.setValue(5);
    break;
    case '6':
    lcdNum.setCol(13);
    lcdNum.setValue(6);
    break;
    case '7':
    lcdNum.setCol(13);
    lcdNum.setValue(7);
    break;
    case '8':
    lcdNum.setCol(13);
    lcdNum.setValue(8);
    break;
    case '9':
    lcdNum.setCol(13);
    lcdNum.setValue(9);
    break;
    case '0':
    lcdNum.setCol(13);
    lcdNum.setValue(0);
    break;   
  }
}

void callback(char* topic, byte* payload, unsigned int length) {
 
  //Serial.print(F("Message arrived in topic: "));
  //Serial.println(topic);
 
  //Serial.print(F("Message:"));
  for (int i = 0; i < length; i++) {
    //Serial.print((char)payload[i]);
       String msg;
 
    //obtem a string do payload recebido
    for(int i = 0; i < length; i++) 
    {
       char c = (char)payload[i];
       msg += c;
    }
  

    if (msg.equals("power"))
    {
      initTime = millis();
      posTime = initTime;
      while(posTime<= initTime+50){
       irsend.sendSAMSUNG(SamsungPower, SAMSUNG_BITS, 0);  // hex value, 16 bits, no repeat
       irsend.sendSAMSUNG(SamsungPower, SAMSUNG_BITS, 1);  // hex value, 16 bits, repeat
       posTime = millis();
      }
    }
    
    else if (msg.equals("source"))
    {
       irsend.sendSAMSUNG(SamsungSource, SAMSUNG_BITS, 0);  // hex value, 16 bits, no repeat
    }
    
    else if (msg.equals("select"))
    {
       irsend.sendSAMSUNG(SamsungSelect, SAMSUNG_BITS, 0);  // hex value, 16 bits, no repeat
    }

  else if (msg.equals("exit"))
    {
       irsend.sendSAMSUNG(SamsungExit, SAMSUNG_BITS, 0);  // hex value, 16 bits, no repeat
    }
    
    else if (msg.equals("up"))
    {
       irsend.sendSAMSUNG(SamsungUp, SAMSUNG_BITS, 0);  // hex value, 16 bits, no repeat
    }

    else if (msg.equals("down"))
    {
       irsend.sendSAMSUNG(SamsungDown, SAMSUNG_BITS, 0);  // hex value, 16 bits, no repeat
    }

    else if (msg.equals("right"))
    {
      irsend.sendSAMSUNG(SamsungRight, SAMSUNG_BITS, 0);  // hex value, 16 bits, no repeat
    }

    else if (msg.equals("left"))
    {
      irsend.sendSAMSUNG(SamsungLeft, SAMSUNG_BITS, 0);  // hex value, 16 bits, no repeat
    }
    
    else if (msg.equals("volup"))
    {
      irsend.sendSAMSUNG(SamsungUpVol, SAMSUNG_BITS, 0);  // hex value, 16 bits, no repeat     
    }

    else if (msg.equals("voldown"))
    {
       irsend.sendSAMSUNG(SamsungDownVol, SAMSUNG_BITS, 0);  // hex value, 16 bits, no repeat
    }

    else if (msg.equals("chup"))
    {
       irsend.sendSAMSUNG(SamsungUpCh, SAMSUNG_BITS, 0);  // hex value, 16 bits, no repeat
    }

    else if (msg.equals("chdown"))
    {
       irsend.sendSAMSUNG(SamsungDownCh, SAMSUNG_BITS, 0);  // hex value, 16 bits, no repeat
    }

    
    else if (msg.equals("mute"))
    {
       irsend.sendSAMSUNG(SamsungMute, SAMSUNG_BITS, 0);  // hex value, 16 bits, no repeat
    }
    
    else if(msg.equals("oi")){
      initTime = millis();
      posTime = initTime;
      while(posTime<= initTime+1000){
      digitalWrite(LED_BUILTIN, HIGH);
      posTime = millis();
      }
      digitalWrite(LED_BUILTIN, LOW);
    }

    else if(msg.equals("-1")){
      despertador.setAlarmOFF();
    }

    else if(msg.equals("song")){            // FOR DEBUG
     if(!block) {
       //beep();
       StarWars();
       block = true;
     }
    }

    else if(msg.equals("desblock")) {        // FOR DEBUG
        block = false;
    }

    else if((msg.equals("2240")) or (msg.equals("2320")) or (msg.equals("0800"))){
      despertador.setAlarmClock(msg);
    }
    
   /* else if((msg.length() == 4) and (isdigit(msg[0])) and (isdigit(msg[1])) and (isdigit(msg[2])) and (isdigit(msg[3]))) {
      despertador.setAlarmClock(msg);
    }*/
  }
 
}

/*void tempUmi() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
lcd.setCursor(0,1);
lcd.print("t:");
lcd.setCursor(3,1);
lcd.print(t);
lcd.setCursor(8,1);
lcd.print("U:");
lcd.setCursor(10,1);
lcd.print(h);

}*/

void connectWiFi () {
  WiFi.begin(ssid, password);
  int connRes = WiFi.waitForConnectResult();
  if (connRes != WL_CONNECTED) {
    WiFi.disconnect();
    //ESP.restart();
  }
}

void connectMQTT(){ 
  client.setServer(mqttServer, mqttPort);
  client.setCallback(callback);
  //while (!client.connected()) {
  if (!client.connect("ESP8266Client", mqttUser, mqttPassword )) 
      delay(100);
  client.publish("/node03","conecao_estabelecida");
  client.subscribe("/node03/tv");
  //}
}

void greetings() {

    if(hora[0]=='0')
        lcd.print("Bom dia :)");
    else if((hora[0]=='1') and ((hora[1]=='0') or (hora[1] == '1') or (hora[1]=='2')))
          lcd.print("Bom dia :)");
    else if((hora[0] =='1') and ((hora[1]=='8') or (hora[1]=='9')))
          lcd.print("Boa noite :)");
    else if(hora[0]=='1')      
           lcd.print("Boa tarde :)");
    else if(hora[0] =='2')
         lcd.print("Boa noite :)");
}

void loop() {
  ArduinoOTA.handle();
  contador = millis();
  checkOST();                    //Chama a verificacao de tempo
  client.loop();
  hora = timeClient.getFormattedTime();
  despertador.checkAlarm(hora);
  if(contador-contadorAnt >= 10000) {
            lcd.clear();
            lcd.setCursor(0,0);
            
            greetings();
            contadorAnt = millis();
    while(contador-contadorAnt <=5000) {
       lcd.setCursor(0,1);
       stat = WiFi.status();
       if(stat != 3) {            // 3 is WiFi_CONNECTED
            lcd.print("WiFi NO");  
            delay(1000);           
            WiFi.disconnect();    
            connectWiFi();
       }     
       else {
            if(despertador.getFlag()) {
              lcd.print("Alarme: ");
              int hora1 = despertador.getHour1();
              int hora2 = despertador.getHour2();
              int minute1 = despertador.getMinute1();
              int minute2 = despertador.getMinute2();
              lcd.setCursor(8,1);
              lcd.print(hora1);
              lcd.setCursor(9,1);
              lcd.print(hora2);
              lcd.setCursor(10,1);
              lcd.print(":");
              lcd.setCursor(11,1);
              lcd.print(minute1);
              lcd.setCursor(12,1);
              lcd.print(minute2);
            }
            else{
            lcd.setCursor(0,1);
            lcd.print("Alarme OFF");
            }
       }
       if(client.state() !=0) { // 0 is OK
            connectMQTT();
            lcd.setCursor(9,1);
            lcd.print("MQTT NO");  
       }
       //else
            //lcd.print("MQTT OK");
       client.loop();
       yield();
       contador = millis();
    }
    lcd.clear();  
    contadorAnt = millis();
  }
}

