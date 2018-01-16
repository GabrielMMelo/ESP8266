#include "lcd.h"

LiquidCrystal_I2C lcd(0x3F, 16, 2);
LCDBigNumbers lcdNum(&lcd, 0,0); //inclui uma barra no lcd, primeira linha, coluna 1

String aux = "11:50";
bool blink =false;

void imprime() {
  //String aux = timeClient.getFormattedTime();
  switch(aux[0]) {
    case '1':
    lcdNum.setCol(0);
    lcdNum.setValue(1);
    break;
    case '2':
    lcdNum.setCol(0);
    lcdNum.setValue(2);
    break;
    case '3':
    lcdNum.setCol(0);
    lcdNum.setValue(3);
    break;
    case '4':
    lcdNum.setCol(0);
    lcdNum.setValue(4);
    break;
    case '5':
    lcdNum.setCol(0);
    lcdNum.setValue(5);
    break;
    case '6':
    lcdNum.setCol(0);
    lcdNum.setValue(6);
    break;
    case '7':
    lcdNum.setCol(0);
    lcdNum.setValue(7);
    break;
    case '8':
    lcdNum.setCol(0);
    lcdNum.setValue(8);
    break;
    case '9':
    lcdNum.setCol(0);
    lcdNum.setValue(9);
    break;
    case '0':
    lcdNum.setCol(0);
    lcdNum.setValue(0);
    break;   
  }
  
  switch(aux[1]) {
    case '1':
    lcdNum.setCol(4);
    lcdNum.setValue(1);
    break;
    case '2':
    lcdNum.setCol(4);
    lcdNum.setValue(2);
    break;
    case '3':
    lcdNum.setCol(4);
    lcdNum.setValue(3);
    break;
    case '4':
    lcdNum.setCol(4);
    lcdNum.setValue(4);
    break;
    case '5':
    lcdNum.setCol(4);
    lcdNum.setValue(5);
    break;
    case '6':
    lcdNum.setCol(4);
    lcdNum.setValue(6);
    break;
    case '7':
    lcdNum.setCol(4);
    lcdNum.setValue(7);
    break;
    case '8':
    lcdNum.setCol(4);
    lcdNum.setValue(8);
    break;
    case '9':
    lcdNum.setCol(4);
    lcdNum.setValue(9);
    break;
    case '0':
    lcdNum.setCol(4);
    lcdNum.setValue(0);
    break;   
  }
  if(!blink){
    lcd.setCursor(7,0);
    lcd.print("..");
    lcd.setCursor(7,1);
    lcd.print("..");
    blink=true;
  }
  else{
    lcd.setCursor(7,0);
    lcd.print("  ");
    lcd.setCursor(7,1);
    lcd.print("  ");
    blink=false;
  }
  
  switch(aux[3]) {
    case '1':
    lcdNum.setCol(9);
    lcdNum.setValue(1);
    break;
    case '2':
    lcdNum.setCol(9);
    lcdNum.setValue(2);
    break;
    case '3':
    lcdNum.setCol(9);
    lcdNum.setValue(3);
    break;
    case '4':
    lcdNum.setCol(9);
    lcdNum.setValue(4);
    break;
    case '5':
    lcdNum.setCol(9);
    lcdNum.setValue(5);
    break;
    case '6':
    lcdNum.setCol(9);
    lcdNum.setValue(6);
    break;
    case '7':
    lcdNum.setCol(9);
    lcdNum.setValue(7);
    break;
    case '8':
    lcdNum.setCol(9);
    lcdNum.setValue(8);
    break;
    case '9':
    lcdNum.setCol(9);
    lcdNum.setValue(9);
    break;
    case '0':
    lcdNum.setCol(9);
    lcdNum.setValue(0);
    break;   
  }
  
  switch(aux[4]) {
    case '1':
    lcdNum.setCol(13);
    lcdNum.setValue(1);
    break;
    case '2':
    lcdNum.setCol(13);
    lcdNum.setValue(2);
    break;
    case '3':
    lcdNum.setCol(13);
    lcdNum.setValue(3);
    break;
    case '4':
    lcdNum.setCol(13);
    lcdNum.setValue(4);
    break;
    case '5':
    lcdNum.setCol(13);
    lcdNum.setValue(5);
    break;
    case '6':
    lcdNum.setCol(13);
    lcdNum.setValue(6);
    break;
    case '7':
    lcdNum.setCol(13);
    lcdNum.setValue(7);
    break;
    case '8':
    lcdNum.setCol(13);
    lcdNum.setValue(8);
    break;
    case '9':
    lcdNum.setCol(13);
    lcdNum.setValue(9);
    break;
    case '0':
    lcdNum.setCol(13);
    lcdNum.setValue(0);
    break;   
  }
}

void setup() {
  lcdNum.createChars();
  lcd.begin(16, 2);
  lcd.init();
  lcd.backlight();
}


void loop() {
  imprime();
  delay(1000);
  
}

