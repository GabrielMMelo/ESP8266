#include <Arduino.h>
//#include <LiquidCrystal.h>
#include <LiquidCrystal_I2C.h>

struct LCDNumber {
  byte top1;
  byte top2;
  byte top3;
  byte bottom1;
  byte bottom2;
  byte bottom3;
};
  
class LCDBigNumbers {
  private:
    LiquidCrystal_I2C * _lcd;
    int _row;
    int _col;
    long _value; /*0..100*/
      
    void _clear();
  public:
    const char c0[8] PROGMEM = {B00000, B00000, B00000, B00000, B00000, B11111, B11111, B11111};  //bottom
    const char c1[8] PROGMEM = {B11111, B11111, B11111, B00000, B00000, B00000, B00000, B00000};  //top
    const char c2[8] PROGMEM = {B11111, B11111, B11111, B11111, B11111, B11111, B11111, B11111};  //fill
    const char c3[8] PROGMEM = {B00000, B00000, B00001, B00011, B00011, B00001, B00000, B00000};
    const char c4[8] PROGMEM = {B00000, B00000, B10000, B11000, B11000, B10000, B00000, B00000};
    const char c5[8] PROGMEM = {B11111, B11111, B00000, B00000, B00000, B00000, B11111, B11111};   //top / bottom 
  
    static LCDNumber _lcd_numbers[];     
    void createChars();      
    LCDBigNumbers(LiquidCrystal_I2C * lcd, int row, int col);
    void setRow(int row);
    void setCol(int col);
    void setValue(long value);
};
  
/*************************************************************************************************************
*******************************FIM CLASSE LCD BIG NUMBERS*****************************************************
**************************************************************************************************************/
