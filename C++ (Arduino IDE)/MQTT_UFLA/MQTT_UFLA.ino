#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <ESP8266mDNS.h>
#include <ArduinoOTA.h>
#include <PubSubClient.h> // Biblioteca usada, baixe e instale se não a tiver, link abaixo

#define LED 2
const char *ssid     = "UFLA+";
//const char *ssid     = "Dougras";
//const char *password     = "eusouodougrasvocenaoehodougras";
const char* mqttServer = "m12.cloudmqtt.com"; // Aqui o endereço do seu servidor fornecido pelo site 
const int mqttPort =17226; // Aqui mude para sua porta fornecida pelo site
const char* mqttUser = "ufla_esp"; //  Aqui o nome de usuario fornecido pelo site
const char* mqttPassword = "ufla_esp"; //  Aqui sua senha fornecida pelo site
WiFiClient espClient;
PubSubClient client(espClient);
int stat;
int ip[4];
ip[0]=172;
ip[1]=16;
ip[2] = 0;
ip[3] = 170;

void mqtt_callback(char* topic, byte* payload, unsigned int length);

void setup(){
  // Hostname defaults to esp8266-[ChipID]
   ArduinoOTA.setHostname("esp_MAC_UFLA+");

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

  Serial.begin(115200);

WiFi.config(ip);

 WiFi.begin(ssid);
 //WiFi.begin(ssid,password);

  while ( WiFi.status() != WL_CONNECTED ) {
    delay ( 500 );
    Serial.print ( "." );
  }

  Serial.println("Conectado!");

client.setServer(mqttServer, mqttPort);
  client.setCallback(callback);
 
  while (!client.connected()) {
    Serial.println("Connecting to MQTT...");
 
    if (client.connect("ESP8266Client", mqttUser, mqttPassword )) {
 
      Serial.println("connected");  
 
    } else {
 
      Serial.print("failed with state ");
      Serial.print(client.state());
      delay(2000);
 
    }
  }
  
 
  client.publish("/ufla/LED/fromnode","conecao_estabelecida");
  client.subscribe("/ufla/LED/tonode");

 pinMode(LED,OUTPUT);
}

void callback(char* topic, byte* payload, unsigned int length) {
 
  Serial.print("Message arrived in topic: ");
  Serial.println(topic);
 
  Serial.print("Message:");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);

       String msg;
    
 
    //obtem a string do payload recebido
    for(int i = 0; i < length; i++) 
    {
       char c = (char)payload[i];
       msg += c;
    }
    
    
       if (msg.equals("liga"))
    {
        digitalWrite(LED, HIGH);   
            
    }


       else if (msg.equals("desliga"))
    {
        digitalWrite(LED, LOW);
    }

     }

}

void loop() {
  ArduinoOTA.handle();
    client.loop();
}
