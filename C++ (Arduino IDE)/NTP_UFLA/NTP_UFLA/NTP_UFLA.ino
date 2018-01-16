#include <NTPClient.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

const char *ssid     = "UFLA+";
//const char *password = "01234567";
const char *password = "";

WiFiUDP ntpUDP;

int16_t utc = -3; //UTC -3:00 Brasil
uint32_t currentMillis = 0;
uint32_t previousMillis = 0;

NTPClient ntpClient(ntpUDP, "a.st1.ntp.br", utc*3600, 60000);

void setup(){
  Serial.begin(115200);

  WiFi.begin(ssid,password);

  while ( WiFi.status() != WL_CONNECTED ) {
    delay ( 500 );
    Serial.print ( "." );
  }
  
  if(WiFi.status() == 3) 
    Serial.print ( "CONECTADO" );
    Serial.println(WiFi.localIP());
    ntpClient.begin();
    ntpClient.update();
  }

void forcarAtualizacao(void) {
  ntpClient.forceUpdate();
}

void checkHora(void) {
  //Tempo atual em ms
  currentMillis = millis();
  //Lógica de verificação do tempo
  if (currentMillis - previousMillis > 1000) {
    previousMillis = currentMillis;    // Salva o tempo atual
    Serial.println("Time Epoch: " + ntpClient.getFormattedTime());
  }
}

void loop() {
  //Chama a verificacao de tempo
  checkHora();
  forcarAtualizacao();
}
