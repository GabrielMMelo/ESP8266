#include <Ultrasonic.h>

#define trigger 5
#define echo 4

Ultrasonic ultrasonic(trigger,echo);

float distCm;
long microsec;

void setup() {
  Serial.begin(115200);
  pinMode(echo, INPUT);
  pinMode(trigger,OUTPUT);
}

void loop() {
  microsec = ultrasonic.timing();
  distCm = ultrasonic.convert(microsec, Ultrasonic::CM);
  Serial.print("Distancia em cm: ");
  Serial.print(distCm);
  delay(100);
}

