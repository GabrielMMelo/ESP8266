#include <ESP8266WiFi.h>
#include <deprecated.h>
#include <MFRC522.h>
#include <MFRC522Debug.h>
#include <MFRC522Extended.h>
#include <MFRC522Hack.h>
#include <require_cpp11.h>
#include <SPI.h>

#define SS_PIN 4
#define RST_PIN 5
MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance.

String msg = "";
char st[20];

/*
 WIFI CONFIGURATION
 */
char SSID[] = "Dougras";
char pwd[] = "eusouodougrasvocenaoehodougras";

/*
 SLACK CONFIGURATION
 */
const String slack_hook_url = "https://hooks.slack.com/services/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";
const String slack_icon_url = "https://pbs.twimg.com/profile_images/1462227900/cda288d94c3e99d0ccc4e8d1c61d7073_normal.jpg";
const String slack_message = "#GoEMakers - mensagem enviada pelo ESP8266 by Arduino Firmware";
const String slack_username = "esp_milgrau";

void setup() 
{
  Serial.begin(9600); // Inicia a serial
  Serial.println();
    WiFi.begin(SSID, pwd);

  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println();

  Serial.print("Connected, IP address: ");
  Serial.println(WiFi.localIP());

  SPI.begin();    // Inicia  SPI bus
  mfrc522.PCD_Init(); // Inicia MFRC522
  Serial.println("Aproxime o seu cartao do leitor...");

}


bool mensagemParaSlack(String msg)
{
  const char* host = "hooks.slack.com";
  Serial.print("Connecting to ");
  Serial.println(host);

  // Use WiFiClient class to create TCP connections
  WiFiClientSecure client;
  const int httpsPort = 443;
  if (!client.connect(host, httpsPort)) {
    Serial.println("Connection failed :-(");
    return false;
  }

  // We now create a URI for the request

  Serial.print("Posting to URL: ");
  Serial.println(slack_hook_url);

  String postData="payload={\"link_names\": 1, \"icon_url\": \"" + slack_icon_url + "\", \"username\": \"" + slack_username + "\", \"text\": \"" + msg + "\"}";

  // This will send the request to the server
  client.print(String("POST ") + slack_hook_url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "Content-Type: application/x-www-form-urlencoded\r\n" +
               "Connection: close" + "\r\n" +
               "Content-Length:" + postData.length() + "\r\n" +
               "\r\n" + postData);
  Serial.println("Request sent");
  String line = client.readStringUntil('\n');
  Serial.printf("Response code was: ");
  Serial.println(line);
  if (line.startsWith("HTTP/1.1 200 OK")) {
    return true;
  } else {
    return false;
  }
}


void loop() 
{
  //Procura novos cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  //Seleciona um card
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Mostra UID na serial
  Serial.print("UID da tag :");
  String conteudo= "";
  byte letra;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     conteudo.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     conteudo.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Mensagem : ");
  conteudo.toUpperCase();

  if (conteudo.substring(1) == "64 96 35 24") //UID 2 - Cartao
  {
    msg = "Gabriel Marques de Melo - Chegou na sala!";
    mensagemParaSlack(msg);
    Serial.println(msg);
    Serial.println();
    delay(2000);
  }
} 
