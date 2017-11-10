#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>

const char* ssid     = "Dougras";
const char* password = "eusouodougrasvocenaoehodougras";

const char* host = "maker.ifttt.com";
const char* eventName   = "test";
const char* privateKey = "n91jfpxpOs_k0qhQ4N_vnB2VJ6tFkKdzODzyRf4WZkD";

void setup() {
    // Port defaults to 8266
  // ArduinoOTA.setPort(8266);

  // Hostname defaults to esp8266-[ChipID]
   ArduinoOTA.setHostname("esp-4");

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
  delay(10);

  pinMode(2, OUTPUT);     // Define GPIO2 como saída
  digitalWrite(2, HIGH);  // Coloca a saída em nível alto para manter chip ligado

  Serial.print("Conectando em ");
    Serial.println(ssid);

  WiFi.begin(ssid, password);

  // Aguarda conexão
  while (WiFi.status() != WL_CONNECTED) {
    delay(500); // Tempo para aguardar conexão, pode ser diminuido para melhorar tempo de resposta
    Serial.print(".");
  }

  /*Serial.println("");
    Serial.println("WiFi conectado");
    Serial.println("Endereço de IP: ");
    Serial.println(WiFi.localIP());*/
}
 bool teste = true;
 String payload, lastPayload;
 
void loop() {
  ArduinoOTA.handle();
  
  Serial.print("Conectando em ");
  Serial.println(host);
   
  HTTPClient http;

   Serial.print("[HTTP] início...\n");

  // Configuração de servidor e url
  // http.begin(host, 443,  String("/trigger/") + eventName + "/with/key/" + privateKey, true, "‎a9 81 e1 35 b3 7f 81 b9 87 9d 11 dd 48 55 43 2c 8f c3 ec 87"); //HTTPS
  http.begin(host, 80, String("/trigger/") + eventName + "/with/key/" + privateKey + "?value1"); //HTTP

   Serial.print("[HTTP] GET...\n");
  // inicia conexão e envia header HTTP
  //if(teste) {
  int httpCode = http.GET();
 // teste = false;
 // }
  
  if (httpCode) {
      // Header HTTP foi enviado e resposta do servidor foi processada
      Serial.printf("[HTTP] GET... código: %d\n", httpCode);

      // Arquivo encontrado no servidor
      if(teste){
        payload = http.getString();
        lastPayload = payload;
        teste = false;
        Serial.println(payload);
      }
      if(lastPayload!=payload){
        Serial.println(payload);
        lastPayload = payload;
      }
      
    } else {
      Serial.print("[HTTP] GET... falha, nenhuma conexão ou nenhum servidor http\n");
    }
  digitalWrite(2, LOW); // Coloca saída em nível baixo para deligar chip
  delay(100);
  
}
