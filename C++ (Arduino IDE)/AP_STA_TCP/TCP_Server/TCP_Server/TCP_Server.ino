//-- Libraries Included --------------------------------------------------------------
  #include <ESP8266WiFi.h>
  #include <ArduinoOTA.h>
  #include <WiFiUdp.h>
  #include <NTPClient.h>
//------------------------------------------------------------------------------------
  // Define I/O Pins
  #define     LED0      2           // WIFI Module LED
  #define     LED1      D0          // Connectivity With Client #1
  #define     LED2      D2          // Connectivity With Client #2
  #define     BUTTON    D1          // Connectivity ReInitiate Button
//------------------------------------------------------------------------------------
  // Authentication Variables
  char*       AP_ssid;              // SERVER WIFI NAME
  char*       AP_password;          // SERVER PASSWORD
  char*       STA_ssid = "Dougras";
  char*       STA_password = "eusouodougrasvocenaoehodougras";
  long contador, contadorAnt;
  bool rele = false;
  int aux;
//------------------------------------------------------------------------------------
  #define     MAXSC     6           // MAXIMUM NUMBER OF CLIENTS
  //char message = 'O';
  /*
   * MAXSC => Maximum Server Clients
   * They Are 6 Because
   * 1. Blue Fighter Suit
   * 2. Red Fighter Suit
   * 3. Corner Referee 1
   * 4. Corner Referee 2
   * 5. Corner Referee 3
   * 6. Corner Referee 4
   */
  
  WiFiServer  Servidor(9001);      // THE SERVER AND THE PORT NUMBER
  WiFiClient  Cliente[MAXSC];     // THE SERVER CLIENTS (Devices)

//====================================================================================

  WiFiUDP ntpUDP;

int16_t utc = -3; //UTC -3:00 Brazil
uint32_t currentMillis = 0;
uint32_t previousMillis = 0;

NTPClient timeClient(ntpUDP, "a.st1.ntp.br", utc*3600, 60000);
//====================================================================================

  void setup()
  {
    contadorAnt = millis();
    // Setting The Serial Port
    Serial.begin(115200);           // Computer Communication
    
    // Setting The Mode Of Pins
    pinMode(LED0, OUTPUT);          // WIFI OnBoard LED Light
    pinMode(LED1, OUTPUT);          // Indicator For Client #1 Connectivity
    pinMode(LED2, OUTPUT);          // Indicator For Client #2 Connectivity
    pinMode(BUTTON, INPUT_PULLUP);  // Initiate Connectivity
    
    // Print Message Of I/O Setting Progress
    Serial.println();
    Serial.println("I/O Pins Modes Set .... Done");

    // Setting Up A Wifi Access Point
    SetWifi("ESP_04", "");

    WiFi.begin(STA_ssid, STA_password);
  while(WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(100);
  }
  Serial.print("Conectado em " + (String)STA_ssid);
  // Port defaults to 8266
  // ArduinoOTA.setPort(8266);

  // Hostname defaults to esp8266-[ChipID]
   ArduinoOTA.setHostname("node-04");

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
   timeClient.begin();
  timeClient.update();
  }

//====================================================================================
  
  void loop()
  {
    ArduinoOTA.handle();
    // Checking For Available Clients
    AvailableClients();
    //checkOST();
    // Checking For Available Client Messages
    AvailableMessage();
    contador = millis();
    if(contador-contadorAnt>=10000){
    if(!rele) {
      aux = sendMessage("ligar");
      rele = true;
    }
    else {
      aux = sendMessage("desligar");
      rele = false;
    }
    if(aux == 1)
      Serial.println("Mensagem enviada!");
    else if(aux == 0) 
      Serial.println("Mensagem não enviada");
    else if(aux == -1)
        Serial.println("Cliente não disponivel");
    contadorAnt = millis();
    }
  }

//====================================================================================
  
  void SetWifi(char* Name, char* Password)
  {
    // Stop Any Previous WIFI
    WiFi.disconnect();

    // Setting The Wifi Mode
    WiFi.mode(WIFI_AP_STA);
    Serial.println("WIFI Mode : AccessPoint Station");
    
    // Setting The AccessPoint Name & Password
    AP_ssid      = Name;
    AP_password  = Password;
    
    // Starting The Access Point
    WiFi.softAP(AP_ssid, AP_password);
    Serial.println("WIFI < " + String(AP_ssid) + " > ... Started");
    
    // Wait For Few Seconds
    delay(1000);
    
    // Getting Server IP
    IPAddress IP = WiFi.softAPIP();
    
    // Printing The Server IP Address
    Serial.print("AccessPoint IP : ");
    Serial.println(IP);

    // Printing MAC Address
    Serial.print("AccessPoint MC : ");
    Serial.println(String(WiFi.softAPmacAddress()));

    // Starting Server
    Servidor.begin();
    Servidor.setNoDelay(true);
    Serial.println("Server Started");
  }

//====================================================================================

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
  }
}

//====================================================================================
  void AvailableClients()
  {   
    if (Servidor.hasClient())
    {
      // Read LED0 Switch To Low If High.
      if(digitalRead(LED0) == HIGH) digitalWrite(LED0, LOW);
      
      // Light Up LED1
      digitalWrite(LED1, HIGH);
      
      for(uint8_t i = 0; i < MAXSC; i++)
      {
        //find free/disconnected spot
        if (!Cliente[i] || !Cliente[i].connected())
        {
          // Checks If Previously The Client Is Taken
          if(Cliente[i])
          {
            Cliente[i].stop();
          }

          // Checks If Clients Connected To The Server
          if(Cliente[i] = Servidor.available())
          {
            Serial.println("New Client: " + String(i));
          }

          // Continue Scanning
          continue;
        }
      }
      
      //no free/disconnected spot so reject
      WiFiClient Cliente = Servidor.available();
      Cliente.stop();
    }
    else
    {
      // This LED Blinks If No Clients Where Available
      digitalWrite(LED0, HIGH);
      delay(250);
      digitalWrite(LED0, LOW);
      delay(250);
    }
  }

//====================================================================================

  void AvailableMessage()
  {
    //check clients for data
    for(uint8_t i = 0; i < MAXSC; i++)
    {
      if (Cliente[i] && Cliente[i].connected() && Cliente[i].available())
      {
          while(Cliente[i].available())
          {
            String Message = Cliente[i].readStringUntil('\r');
            Cliente[i].flush();
            Serial.println("Client No " + String(i) + " - " + Message);
          }
      }
    }
  }

//====================================================================================

int sendMessage(String message) { 
  if((Cliente[0]) or (Cliente[1]) or (Cliente[2]) or (Cliente[3]) or (Cliente[4])) {
    if(Cliente[0].print(message))
     return 1;
    return 0;
  }
  return -1;
}

