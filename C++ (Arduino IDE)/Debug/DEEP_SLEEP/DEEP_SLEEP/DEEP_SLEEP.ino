 #define time_in_us 5000000

void setup() {
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Dormiu");
  ESP.deepSleep(time_in_us);
  Serial.println("Acordou");
}
