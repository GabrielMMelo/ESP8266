#define PIR_pin 4

float signal;

void setup()
{
pinMode(PIR_pin, INPUT);
Serial.begin(115200);	
}

void loop()
{
	signal = analogRead(PIR_pin);
	Serial.print(signal);
	delay(1000);
}