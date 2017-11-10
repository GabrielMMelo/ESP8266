// TODO: atuaalizar o usuario e senha em cloudmqtt.com no mqtt client usado no node-03 (Port:16595)
#ifdef ESP8266
extern "C" {
bool system_update_cpu_freq(int);
}
#endif

#include <ESP8266WiFi.h>
#include <PubSubClient.h> // Biblioteca usada, baixe e instale se não a tiver, link abaixo
                          //https://github.com/knolleary/pubsubclient/blob/master/examples/mqtt_esp8266/mqtt_esp8266.ino
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>

 
#define RELE 4
const char* ssid = "Dougras"; //Aqui o nome da sua rede local wi fi
const char* password =  "eusouodougrasvocenaoehodougras"; // Aqui a senha da sua rede local wi fi
const char* mqttServer = "m11.cloudmqtt.com"; // Aqui o endereço do seu servidor fornecido pelo site 
const int mqttPort =16119; // Aqui mude para sua porta fornecida pelo site
const char* mqttUser = "node01"; //  Aqui o nome de usuario fornecido pelo site
const char* mqttPassword = "node01"; //  Aqui sua senha fornecida pelo site
long contadorAnt, contador;
WiFiClient espClient;
PubSubClient client(espClient);
int stat;

void mqtt_callback(char* topic, byte* payload, unsigned int length);


void setup() {
    ArduinoOTA.setHostname("node-01");
#ifdef ESP8266
system_update_cpu_freq(160);
#endif
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
    contadorAnt=millis();
    pinMode(RELE, OUTPUT);
    digitalWrite(RELE, HIGH); 
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, HIGH);
     
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  //  Serial.println("Connecting to WiFi..");
  }
  //Serial.println("Connected to the WiFi network");
 
  client.setServer(mqttServer, mqttPort);
  client.setCallback(callback);
 
  while (!client.connected()) {
    //Serial.println("Connecting to MQTT...");
 
    if (client.connect("ESP8266Client", mqttUser, mqttPassword )) {
 
      //Serial.println("connected");  
 
    } else {
 
      //Serial.print("failed with state ");
      //Serial.print(client.state());
      delay(2000);
 
    }
  }
  
 
  client.publish("/node01/fromNode","conecao_estabelecida");
  client.subscribe("/node01/toNode");
 
}
 
void callback(char* topic, byte* payload, unsigned int length) {
 
  //Serial.print("Message arrived in topic: ");
  //Serial.println(topic);
 
  Serial.print("Message:");
  for (int i = 0; i < length; i++) {
//    Serial.print((char)payload[i]);

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

    
    

       if (msg.equals("ligar(RELE)"))
    {
        digitalWrite(LED_BUILTIN, LOW);  
        digitalWrite(RELE, LOW);   
            
    }


       else if (msg.equals("desligar(RELE)"))
    {
        digitalWrite(LED_BUILTIN, HIGH);  
        digitalWrite(RELE, HIGH);
    }

     }

}

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
    if (!client.connect("ESP8266Client", mqttUser, mqttPassword )) {   
      delay(100);
    }
 client.publish("/node01/fromNode","conecao_estabelecida");
  client.subscribe("/node01/toNode");
  //}
}

void loop() {
  ArduinoOTA.handle();
  contador = millis();
  client.loop();
  if(contador-contadorAnt >=10000){
    contadorAnt = millis();
     while(contador-contadorAnt <=5000){
            stat = WiFi.status();
            if(stat != 3){ 
              WiFi.disconnect();             
              connectWiFi();
            }

             if(client.state() !=0){
              connectMQTT();
             }
            client.loop();
            yield();
     contador = millis();
     }           
    contadorAnt = millis();
  }
}
