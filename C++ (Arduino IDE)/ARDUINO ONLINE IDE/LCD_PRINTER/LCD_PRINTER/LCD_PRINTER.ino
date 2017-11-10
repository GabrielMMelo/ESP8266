/*

*/

void setup() {
    
}

void loop() {
    
}


void printMove(String msg) {
  int sized = msg.length();
  if (sized>16) {
    for(int i=0;i<msg.length()-16;i++) {
      for(int j=0; i <16; j++) {
        lcd.setCursor(j,1);
        lcd.print(msg[i+j]);
      }
      delay(1000);
    }
  }
  else{
        lcd.setCursor(0,1);
        lcd.print(msg);
  }
}
