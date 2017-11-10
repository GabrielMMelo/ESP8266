void setup() {
  // Define o pino 13 como saida
  pinMode(2, OUTPUT);
  Serial.begin(115200);
}
 
void loop() {
  digitalWrite(2, HIGH);   // Acende o Led
  delay(1000);              // Aguarda 1 segundo
  Serial.println(digitalRead(4));
  digitalWrite(2, LOW);    // Apaga o Led
  delay(1000);              // Aguarda 1 segundo
  Serial.println(digitalRead(4));
}
