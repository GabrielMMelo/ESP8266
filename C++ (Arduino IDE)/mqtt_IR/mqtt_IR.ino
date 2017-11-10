#ifndef UNIT_TEST
#include <Arduino.h>
#endif
#include <IRremoteESP8266.h>
#include <IRsend.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>  //https://github.com/knolleary/pubsubclient/blob/master/examples/mqtt_esp8266/mqtt_esp8266.ino

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


IRsend irsend(12);  // An IR LED is controlled by GPIO pin 4 (D2)
 
const char* ssid = "Dougras"; //Aqui o nome da sua rede local wi fi
const char* password =  "eusouodougrasvocenaoehodougras"; // Aqui a senha da sua rede local wi fi
const char* mqttServer = "m13.cloudmqtt.com"; // Aqui o endereço do seu servidor fornecido pelo site 
const int mqttPort =16595; // Aqui mude para sua porta fornecida pelo site
const char* mqttUser = "node03"; //  Aqui o nome de usuario fornecido pelo site
const char* mqttPassword = "node03"; //  Aqui sua senha fornecida pelo site
WiFiClient espClient;
PubSubClient client(espClient);

unsigned long initTime;
unsigned long posTime;

void mqtt_callback(char* topic, byte* payload, unsigned int length);


void setup() {
  irsend.begin();

  pinMode(0, OUTPUT);
  digitalWrite(0,LOW);
  Serial.begin(115200);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    //Serial.println(F("Connecting to WiFi.."));
  }
//  Serial.println(F("Connected to the WiFi network"));
 
  client.setServer(mqttServer, mqttPort);
  client.setCallback(callback);
 
  while (!client.connected()) {
  //  Serial.println(F("Connecting to MQTT..."));
 
    if (client.connect("ESP8266Client", mqttUser, mqttPassword )) {
 
    //  Serial.println(F("connected"));  
 
    } else {
 
      //Serial.print(F("failed with state "));
      //Serial.print(client.state());
      delay(2000);
 
    }
  }
  
 
  client.publish("/node03","conecao_estabelecida");
  client.subscribe("/node03/tv");
 
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
  

        
    //toma ação dependendo da string recebida:
    //verifica se deve colocar nivel alto de tensão na saída.
    //IMPORTANTE: o Led já contido na placa é acionado com lógica invertida (ou seja,
    //enviar HIGH para o output faz o Led apagar / enviar LOW faz o Led acender)
 
 
    //verifica se deve colocar nivel alto de tensão na saída se enviar L e digito, ou nivel baixo se enviar D e digito no topíco LED

    
    

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
      initTime = millis();
      posTime = initTime;
      while(posTime<= initTime+50){
       irsend.sendSAMSUNG(SamsungSource, SAMSUNG_BITS, 0);  // hex value, 16 bits, no repeat
       irsend.sendSAMSUNG(SamsungSource, SAMSUNG_BITS, 1);  // hex value, 16 bits, repeat
       posTime = millis();
      }
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
      digitalWrite(4, HIGH);
      posTime = millis();
      }
      digitalWrite(4, LOW);
    }

    
  }
   
 
  //Serial.println();
  //Serial.println(F("-----------------------"));
 
}
 
void loop() {
  client.loop();
}
