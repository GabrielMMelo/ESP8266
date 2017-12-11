extern "C" {
#include "user_interface.h"
}
uint32_t mem_free = system_get_free_heap_size();

//static const char xyz[] PROGMEM = "This is a string stored in flash";

void setup() {
  Serial.begin(115200);

}

void loop() {
  char xyz[] = "This is a string stored in flashThis is a string stored in flashThis is a string stored in flashThis is a string stored in flashThis is a string stored in flashThis is a string stored in flashThis is a string stored in flashThis is a string stored in flash";
  char xy[] = "This is a string stored in flashThis is a string stored in flashThis is a string stored in flashThis is a string stored in flashThis is a string stored in flashThis is a string stored in flashThis is a string stored in flashThis is a string stored in flash";
  char x = xy[2];
  Serial.println(mem_free);
  delay(1000);
  
}
