#include <ESP8266WiFi.h>
#include <MFRC522.h>
#include <SPI.h>

#define SS_PIN 4
#define RST_PIN 5
MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance.

String msg = "";
char st[20];

/*
CONFIGURACAO WIFI
*/
const char *ssid     = "ssid_rede";
const char *password = "senha_rede";

/*
 CONFIGURACAO SLACK
 */
// url do webhooks gerado no slack
const String slack_hook_url = "https://hooks.slack.com/services/*****/******/******";
// url do icone usado pelo usuario criado pelo hooks
const String slack_icon_url = "https://pbs.twimg.com/profile_images/1462227900/cda288d94c3e99d0ccc4e8d1c61d7073_normal.jpg";
const String slack_message = "#GoEMakers - mensagem enviada pelo ESP8266 by Arduino Firmware";
const String slack_username = "meu_esp";

void setup() 
{
  Serial.begin(9600); // Inicia a serial
  Serial.println();
    WiFi.begin(ssid, password);

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


bool mensagemParaSlack(String msg) {
  const char* host = "hooks.slack.com";
  Serial.print("Conectando a  ");
  Serial.println(host);

  // Criar conexao TCP
  WiFiClientSecure client;
  const int httpsPort = 443;
  if (!client.connect(host, httpsPort)) {
    Serial.println("Falha na conexao :-(");
    return false;
  }

  //Criacao da URI para requisicao

  Serial.print("Postando em: ");
  Serial.println(slack_hook_url);

  String postData="payload={\"link_names\": 1, \"icon_url\": \"" + slack_icon_url + "\", \"username\": \"" + slack_username + "\", \"text\": \"" + msg + "\"}";

  //Envio da requisicao para o servidor
  client.print(String("POST ") + slack_hook_url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "Content-Type: application/x-www-form-urlencoded\r\n" +
               "Connection: close" + "\r\n" +
               "Content-Length:" + postData.length() + "\r\n" +
               "\r\n" + postData);
  Serial.println("Requisicao enviada");
  String line = client.readStringUntil('\n');
  Serial.printf("Resposta: ");
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
