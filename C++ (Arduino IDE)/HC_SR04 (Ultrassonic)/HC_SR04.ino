#include<UltraDistSensor.h>
UltraDistSensor mysensor;
float reading;
void setup() {
    Serial.begin(115200);
    mysensor.attach(5,4);//Trigger pin , Echo pin
}

void loop() {
    reading=mysensor.distanceInCm();
    Serial.print("Sensor Reading :");Serial.print(reading);Serial.println(" CM");
    delay(1000);
}
