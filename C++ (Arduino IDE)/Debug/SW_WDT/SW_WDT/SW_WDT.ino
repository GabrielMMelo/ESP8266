#define LED 4
void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(115200);
  //ESP.wdtDisable();//Desabilita o SW WDT.
}
void loop() {
    piscaLed(LED,15000); // recebe o tempo em milissegundos
}
    
int piscaLed(int led,int tempo) {
    int tempoInicial = millis();
    int contador = tempoInicial;
    int num = 0;
    while (contador - tempoInicial < tempo) {
        Serial.println(num);
        digitalWrite(LED, HIGH);
        delayMicroseconds(500000);
        digitalWrite(LED, LOW);
        delayMicroseconds(500000);
        contador = millis();
        //yield();
        num++;
       // ESP.wdtFeed();
    }
}

