//------------------------------------------------------------------------------------
// Libraries Needed For This Project
//------------------------------------------------------------------------------------
  #include <Wire.h>           // To Be Able To Use Sensors Like IMU9050
  #include <EEPROM.h>         // To Be Able To Store & Read Data Between Power Off
  #include <ESP8266WiFi.h>    // The Basic Function Of The ESP NOD MCU
  #include <WiFiUdp.h>
  #include <NTPClient.h>
//------------------------------------------------------------------------------------
// Defining I/O Pins
//------------------------------------------------------------------------------------
  #define       LED0      2         // WIFI Module LED
  #define RELE_1 4
  #define RELE_2 5
  unsigned short int stat;
  long contador, contadorAnt;
//------------------------------------------------------------------------------------
// Node Variables
//------------------------------------------------------------------------------------
  const String  ESP_ID       = "node_02";
//------------------------------------------------------------------------------------
// LED Delay Variables
//------------------------------------------------------------------------------------
  int           LEDState          = LOW;
  unsigned long CurrMillis        = 0;
  unsigned long PrevMillis        = 0;
  unsigned long Interval          = 1000;
//------------------------------------------------------------------------------------
// WIFI Authentication Variables
//------------------------------------------------------------------------------------
/* This Client Is Going To Connect To A WIFI Server Access Point
 * So You Have To Specify Server WIFI SSID & Password In The Code Not Here
 * Please See The Function Below Name (WiFi.Begin)
 * If WIFI dont need Any password Then WiFi.begin("SSIDNAME")
 * If WIFI needs a Password Then WiFi.begin("SSIDNAME", "PASSWORD")
 */
  char*         STA_ssid = "node03";          // Wifi Name
  char*         STA_password = "nodenodenode";        // Wifi Password
//------------------------------------------------------------------------------------
// WIFI Module Role & Port
//------------------------------------------------------------------------------------
/* This WIFI Module Code Works As A Client
 * That Will Connect To A Server WIFI Modul With (IP ADDress 192.168.4.1)
 */
  int             Servidor_Porta  = 9001;
  IPAddress       Servidor(192,168,4,1);
  WiFiClient      Cliente;




  WiFiUDP ntpUDP;

int16_t utc = -3; //UTC -3:00 Brazil
uint32_t currentMillis = 0;
uint32_t previousMillis = 0;

NTPClient timeClient(ntpUDP, "a.st1.ntp.br", utc*3600, 60000);
//====================================================================================

  void setup() 
  {
    contadorAnt = millis();
    // Setting The Serial Port ----------------------------------------------
    Serial.begin(115200);           // Computer Communication
    
    // Setting The Mode Of Pins ---------------------------------------------
    pinMode(LED0, OUTPUT);          // WIFI OnBoard LED Light
    pinMode(RELE_1, OUTPUT);
    pinMode(RELE_2, OUTPUT);
    digitalWrite(LED0, !LOW);       // Turn WiFi LED Off
    
    // Print Message Of I/O Setting Progress --------------------------------
   // Serial.println("\nI/O Pins Modes Set .... Done");

    // Starting To Connect --------------------------------------------------
    if(WiFi.status() == WL_CONNECTED)
    {
      WiFi.disconnect();
      WiFi.mode(WIFI_OFF);
      delay(50);
    }

    /* in this part it should load the ssid and password 
     * from eeprom they try to connect using them */
    
    WiFi.mode(WIFI_STA);            // To Avoid Broadcasting An SSID
    WiFi.begin(STA_ssid,STA_password);      // The SSID That We Want To Connect To

    // Printing Message For User That Connetion Is On Process ---------------
    //Serial.println("!--- Connecting To " + WiFi.SSID() + " ---!");

    // WiFi Connectivity ----------------------------------------------------
    CheckWiFiConnectivity();        // Checking For Connection

    // Stop Blinking To Indicate Connected ----------------------------------
    digitalWrite(LED0, !HIGH);
    //Serial.println("!-- Client Device Connected --!");

    // Printing IP Address --------------------------------------------------
    /*Serial.println("Connected To      : " + String(WiFi.SSID()));
    Serial.println("Signal Strenght   : " + String(WiFi.RSSI()) + " dBm");
    Serial.print  ("Server IP Address : ");
    Serial.println(Servidor);
    Serial.print  ("Server Port Num   : ");
    Serial.println(Servidor_Porta);
    // Printing MAC Address
    Serial.print  ("Device MC Address : ");
    Serial.println(String(WiFi.macAddress()));
    // Printing IP Address
    Serial.print  ("Device IP Address : ");
    Serial.println(WiFi.localIP());
    */
    // Conecting The Device As A Client -------------------------------------
    TKDRequest();

  timeClient.begin();
  timeClient.update();
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
    Serial.println(timeClient.getFormattedTime());
    //String hora =timeClient.getFormattedTime();
    //Cliente.println("Time Epoch:  " + (String)hora);
  }
}
//====================================================================================
  
  void loop()
  {
    readServer(); 
    contador = millis();
    if(contadorAnt-contador >= 30000){
      stat = WiFi.status();
      if(stat != 3){ 
         WiFi.disconnect();             
         connectWiFi();
      }
    }
  }

//====================================================================================

void readServer() {
  while(Cliente.available()) {
    String message = Cliente.readStringUntil('\r');
    Cliente.flush();
    if (message.equals("relay_1_ON")) {
        digitalWrite(RELE_1, LOW);   
    }
    else if (message.equals("relay_1_OFF")) {
        digitalWrite(RELE_1, HIGH);
    }
    else if (message.equals("relay_2_ON")) {
        digitalWrite(RELE_2, LOW);   
    }
    else if (message.equals("relay_2_OFF")) {
        digitalWrite(RELE_2, HIGH);
    }
    Serial.println(message);
  } 
}  
//====================================================================================

  void CheckWiFiConnectivity()
  {
    while(WiFi.status() != WL_CONNECTED)
    {
      for(int i=0; i < 10; i++)
      {
        digitalWrite(LED0, !HIGH);
        delay(250);
        digitalWrite(LED0, !LOW);
        delay(250);
        Serial.print(".");
      }
      Serial.println("");
    }
  }
   
//====================================================================================

  void TKDRequest()
  {
    // First Make Sure You Got Disconnected
    Cliente.stop();

    // If Sucessfully Connected Send Connection Message
    if(Cliente.connect(Servidor, Servidor_Porta))
    {
      Serial.println    ("<" + ESP_ID + "-CONNECTED>");
      Cliente.println ("<" + ESP_ID + "-CONNECTED>");
    }
  }

//====================================================================================



void connectWiFi () {
  WiFi.begin(STA_ssid, STA_password);
  int connRes = WiFi.waitForConnectResult();
  if (connRes != WL_CONNECTED) {
    WiFi.disconnect();
    //ESP.restart();
  }
}
