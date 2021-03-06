//                            by GabrielMMelo

#include <Arduino.h>
#ifdef ESP8266
extern "C" {
bool system_update_cpu_freq(int);
}
#endif

#include <IRremoteESP8266.h>
#include <PubSubClient.h>  //https://github.com/knolleary/pubsubclient/blob/master/examples/mqtt_esp8266/mqtt_esp8266.ino
#include <NTPClient.h>
#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>
#include <LiquidCrystal_I2C.h>
#include "Notes.h"
//#include "Lcd.h"
#include "Alarm.h"
#include "DHT.h"

/* ###################################      DEBUG    ################################### */
#define LED1 15

/* ###################################      DHT11     ################################### */
#define DHTPIN 12     // what digital pin we're connected to
#define DHTTYPE DHT11   // DHT 11

DHT dht(DHTPIN, DHTTYPE);

String tempUmi() {
  String message = "Temperatura: ";
  message += (String)dht.readTemperature();
  message += "C Umidade: ";
  message += (String)dht.readHumidity();
  message += "UR ";
  return message;
}


/* ###################################      IR     ################################### */
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

IRsend irsend(14);  // LED no pino 3


/* ###################################      Alarm     ################################### */
Alarm Alarm;


/* ###################################      LCD     ################################### */    
//LiquidCrystal lcd(5, 4, 16, 14, 12, 13); // pinos ESP-12
LiquidCrystal_I2C lcd(0x3F, 16, 2);
//LCDBigNumbers lcdNum(&lcd, 0,0); //inclui uma barra no lcd, primeira linha, coluna 1
String message;

void printMove(String message, unsigned short int row, PubSubClient* client) {
  int sized = message.length();
  if (sized>16) {
    int aus = millis();
    int aus2 = aus;
    
    for(int i=0;i<(message.length()-16);i++) {
      for(int j=0; j <16; j++) {
        
        lcd.setCursor(j,row);
        lcd.print(message[i+j]);
        if((!i) and (j == 15)) {
          aus = millis();
          aus2 = aus;
          while(aus2-aus <=1500) {
             client->loop();
             yield();
             aus2 = millis();
          }
        }
      }
      aus = millis();
      aus2 = aus;
      while(aus2-aus <=300) {
        client->loop();
        yield();
        aus2 = millis();
      }
    }
    aus = millis();
    aus2 = aus;
    while(aus2-aus <=1500) {
      client->loop();
      yield();
      aus2 = millis();
    }
  }
  else{
        lcd.setCursor(0,row);
        lcd.print(message);
  }
}

/* ###################################      WiFi     ################################### */
const char *ssid     = "Dougras";
const char *password = "eusouodougrasvocenaoehodougras";
char*       AP_ssid;              // SERVER WIFI NAME
char*       AP_password;          // SERVER PASSWORD
WiFiClient espClient;

void connectWiFi () {
  WiFi.begin(ssid, password);
  int connRes = WiFi.waitForConnectResult();
  if (connRes != WL_CONNECTED) {
    WiFi.disconnect();
    //ESP.restart();
  }
}



/* ###################################      MQTT     ################################### */
const char* mqttServer = "m13.cloudmqtt.com"; // Aqui o endereço do seu servidor fornecido pelo site 
const int mqttPort =16595; // Aqui mude para sua porta fornecida pelo site
const char* mqttUser = "node03"; //  Aqui o nome de usuario fornecido pelo site
const char* mqttPassword = "node03"; //  Aqui sua senha fornecida pelo site
PubSubClient client(espClient);
unsigned int stat;
void mqtt_callback(char* topic, byte* payload, unsigned int length);

unsigned long initTime;
unsigned long posTime;

void connectMQTT(){ 
  client.setServer(mqttServer, mqttPort);
  client.setCallback(callback);
  //while (!client.connected()) {
  if (!client.connect("ESP8266Client", mqttUser, mqttPassword )) 
      delay(100);
  client.publish("/node03/fromNode","conecao_estabelecida");
  client.subscribe("/node03/toNode");
  //}
}


/* ###################################      NTP     ################################### */
WiFiUDP ntpUDP;
int16_t utc = -2; //UTC -3:00 Brazil
uint32_t currentMillis = 0;
uint32_t previousMillis = 0;
String hora;

NTPClient timeClient(ntpUDP, "a.st1.ntp.br", utc*3600, 60000);

void checkOST(void) {
  currentMillis = millis();                         //Tempo atual em ms
  
  if (currentMillis - previousMillis > 1000) {          //Lógica de verificação do tempo
    previousMillis = currentMillis;    // Salva o tempo atual
    //printf("Time Epoch: %d: ", timeClient.getEpochTime());
    //lcd.setCursor(6, 1);
    String aux = timeClient.getFormattedTime();
//    lcdNum.imprime(aux);
    lcd.setCursor(4,0);
    lcd.print(aux);
  }
}

void forceUpdate(void) {
  timeClient.forceUpdate();
}

#define LED_CASTLE 0 
long contador, contadorAnt;

/* ###################################################################################### *//* ###################################################################################### */
/* ###################################      SETUP     ################################### *//* ###################################      SETUP     ################################### */
/* ###################################################################################### *//* ###################################################################################### */
void setup(){
#ifdef ESP8266
system_update_cpu_freq(160);
#endif
  //dht.begin();
  contadorAnt=millis();
  ArduinoOTA.setHostname("node-03");
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

  
  //lcdNum.createChars();
  lcd.begin(16, 2);
  lcd.init();
  lcd.backlight();
  lcd.setBacklight(100);
  lcd.setCursor(0,0);

  pinMode(LED1, OUTPUT);
  digitalWrite(LED1, LOW);
  
  
  //pinMode(LED_CASTLE, OUTPUT);
  //digitalWrite(LED_CASTLE, LOW);

  irsend.begin();
  //SetWifi("node03", "nodenodenode");
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
    } 
    else {
       lcd.clear();
       lcd.setCursor(0,0);
       lcd.print("MQTT BAD:" + client.state());
       //Serial.print(F("failed with state "));
       //Serial.print(client.state());
       delay(2000);
    }
    lcd.clear();
  } 
  client.publish("/node03/fromNode","conecao_estabelecida");
  client.subscribe("/node03/toNode");
}

void callback(char* topic, byte* payload, unsigned int length) {
  for (int i = 0; i < length; i++) {
    String msg;
    for(int i = 0; i < length; i++) {
       char c = (char)payload[i];
       msg += c;
    }

/* ##############################################      MENSAGENS MQTT     ############################################## */
    if (msg.equals("power")) {
      initTime = millis();
      posTime = initTime;
      while(posTime<= initTime+50) {
        irsend.sendSAMSUNG(SamsungPower, SAMSUNG_BITS, 0);  // hex value, 16 bits, no repeat
        irsend.sendSAMSUNG(SamsungPower, SAMSUNG_BITS, 1);  // hex value, 16 bits, repeat
        posTime = millis();
      }
    }
    
    else if (msg.equals("source")) 
       irsend.sendSAMSUNG(SamsungSource, SAMSUNG_BITS, 0);  // hex value, 16 bits, no repeat
    
    else if (msg.equals("select")) 
       irsend.sendSAMSUNG(SamsungSelect, SAMSUNG_BITS, 0);  // hex value, 16 bits, no repeat

    else if (msg.equals("exit")) 
       irsend.sendSAMSUNG(SamsungExit, SAMSUNG_BITS, 0);  // hex value, 16 bits, no repeat
    
    else if (msg.equals("up")) 
       irsend.sendSAMSUNG(SamsungUp, SAMSUNG_BITS, 0);  // hex value, 16 bits, no repeat

    else if (msg.equals("down")) 
       irsend.sendSAMSUNG(SamsungDown, SAMSUNG_BITS, 0);  // hex value, 16 bits, no repeat

    else if (msg.equals("right")) 
      irsend.sendSAMSUNG(SamsungRight, SAMSUNG_BITS, 0);  // hex value, 16 bits, no repeat

    else if (msg.equals("left")) 
      irsend.sendSAMSUNG(SamsungLeft, SAMSUNG_BITS, 0);  // hex value, 16 bits, no repeat
   
    else if (msg.equals("volup")) 
      irsend.sendSAMSUNG(SamsungUpVol, SAMSUNG_BITS, 0);  // hex value, 16 bits, no repeat     

    else if (msg.equals("voldown")) 
       irsend.sendSAMSUNG(SamsungDownVol, SAMSUNG_BITS, 0);  // hex value, 16 bits, no repeat

    else if (msg.equals("chup")) 
       irsend.sendSAMSUNG(SamsungUpCh, SAMSUNG_BITS, 0);  // hex value, 16 bits, no repeat

    else if (msg.equals("chdown")) 
       irsend.sendSAMSUNG(SamsungDownCh, SAMSUNG_BITS, 0);  // hex value, 16 bits, no repeat
    
    else if (msg.equals("mute")) 
       irsend.sendSAMSUNG(SamsungMute, SAMSUNG_BITS, 0);  // hex value, 16 bits, no repeat
       
    else if (msg.equals("lightON")) {
      long aus = millis();
      long aus2 = aus;
      bool aus3 = false;
      while(aus2-aus <=1500) {
        if(!aus3){
        //  sendMessage("relay_1_ON");
          aus3 = true;
        }
        yield();
        aus2 = millis();
      }
      
    }

    else if (msg.equals("lightOFF")) {
      long aus = millis();
      long aus2 = aus;
      bool aus3 = false;
      while(aus2-aus <=1500) {
        if(!aus3){
       //   sendMessage("relay_1_OFF");
          aus3 = true;
        }
        yield();
        aus2 = millis();
      }
    }
    
    else if (msg.equals("fanON")) {
      long aus = millis();
      long aus2 = aus;
      bool aus3 = false;
      while(aus2-aus <=1500) {
        if(!aus3){
      //    sendMessage("relay_2_ON");
          aus3 = true;
        }
        yield();
        aus2 = millis();
      }
    }

    else if (msg.equals("fanOFF")) {
      long aus = millis();
      long aus2 = aus;
      bool aus3 = false;
      while(aus2-aus <=1500) {
        if(!aus3){
      //    sendMessage("relay_2_OFF");
          aus3 = true;
        }
        yield();
        aus2 = millis();
      }
    }

     else if(msg.equals("LED")){
      bool stat = digitalRead(LED1);  
      digitalWrite(LED1, !stat);
     }

    else if(msg.equals("-1")) 
      Alarm.setAlarmOFF();
    
    else if(msg.equals("song")) {            // FOR DEBUG
      if(!Alarm.block) {
       // beep();
        //StarWars();
        Alarm.block = true;
      }
    }
    
    else if(msg.equals("desblock"))         // FOR DEBUG
        Alarm.block = false;

    else if(msg.equals("castleON")) {
        digitalWrite(LED_CASTLE, HIGH);
    }

    else if(msg.equals("castleOFF")) {
        digitalWrite(LED_CASTLE, LOW);
    }
    
    else if((msg.length() == 4) and (isdigit(msg[0])) and (isdigit(msg[1])) and (isdigit(msg[2])) and (isdigit(msg[3])))
      Alarm.setAlarmClock(msg);
    
    else if((msg.length() == 1) and (isdigit(msg[0]))){
    //  lcdNum.setBrightness(((unsigned short int)msg[0])-48);
    }
      
  }
}

void greetings(unsigned short int row,String hora) {
  lcd.clear();
  lcd.setCursor(0,row);
  if((hora[0]=='0') and ((hora[1]=='6') or (hora[1]=='7') or (hora[1]=='8') or (hora[1]=='9')))
      lcd.print("Bom dia :)");
  else if((hora[0]=='1') and ((hora[1]=='0') or (hora[1] == '1') or (hora[1]=='2')))
        lcd.print("Bom dia :)");
  else if(((hora[0] =='1') and ((hora[1]=='8') or (hora[1]=='9'))) or (hora[0] == '0'))
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
  //AvailableClients();
  client.loop();
  hora = timeClient.getFormattedTime();
  Alarm.checkAlarm(hora,&irsend, &client);
  if(contador-contadorAnt >= 15000) {
     greetings(0,hora);
     stat = WiFi.status();
     if(stat != 3) {            // 3 is WL_CONNECTED
        message = "WiFi NO :/";
        message += " Stat: ";
        message += stat;
        printMove(message,1,&client);
        delay(2000);           
        WiFi.disconnect();    
        connectWiFi();
     }     
     else {
        message = "Alarme: ";
        if(Alarm.getFlag()) {
           message += (Alarm.getHour1()-48);
           message += (Alarm.getHour2()-48);
           message += ":";
           message += (Alarm.getMinute1()-48);
           message += (Alarm.getMinute2()-48);
           message += " ";
        }
        else
           message += "OFF ";
        message += tempUmi();
        printMove(message,1, &client);
    }
    yield();
    lcd.clear();
    contadorAnt = millis();
  }
}
