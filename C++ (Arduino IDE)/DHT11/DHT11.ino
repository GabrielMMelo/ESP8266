#include "DHT.h"

#define DHTPIN 4     // what digital pin we're connected to
#define DHTTYPE DHT11   // DHT 11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
	Serial.begin(115200);
	dht.begin();

}

void tempUmi() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  Serial.print(String(t));

}

void loop() {
	tempUmi();
	delay(500);
}

