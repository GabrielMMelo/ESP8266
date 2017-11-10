#ifndef UNIT_TEST
#include <Arduino.h>
#endif
#include <IRremoteESP8266.h>
#include <IRsend.h>
//#include <ir_Samsung.h>


#define SamsungPower        0xE0E040BF  // Panasonic Power button

IRsend irsend(12);  // An IR LED is controlled by GPIO pin 4 (D2)

void setup() {
  irsend.begin();
}

void loop() {
  // This should turn your TV on and off
  irsend.sendSAMSUNG(SamsungPower, SAMSUNG_BITS, 0);  // hex value, 16 bits, no repeat
  // see http://www.sbprojects.com/knowledge/ir/jvc.php for information
  delayMicroseconds(50);
  irsend.sendSAMSUNG(SamsungPower, SAMSUNG_BITS, 1);  // hex value, 16 bits, repeat
  delayMicroseconds(50);
}
