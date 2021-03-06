#ifndef LCD_H
#define LCD_H
#include <Arduino.h>
#include <PubSubClient.h> 
#include <LiquidCrystal.h>
#define brightness 2 

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
    LiquidCrystal * _lcd;
    int _row;
    int _col;
    long _value; /*0..100*/
      
    void _clear();
  public:
    static byte c0[8];  //bottom
    static byte c1[8];  //top
    static byte c2[8];  //fill
    static byte c3[8];
    static byte c4[8];
    static byte c5[8];  //top-bottom 
    static LCDNumber _lcd_numbers[];     
    void createChars();      
    LCDBigNumbers(LiquidCrystal * lcd, int row, int col);
    void setRow(int row);
    void setCol(int col);
    void setValue(long value);
    void imprime(String);
    bool blynk=false;
    void printMove(String, unsigned short int,LiquidCrystal*,PubSubClient*);
    void greetings(unsigned short int,String,LiquidCrystal*); 
    void setBrightness(unsigned short int);
};
  
#endif
