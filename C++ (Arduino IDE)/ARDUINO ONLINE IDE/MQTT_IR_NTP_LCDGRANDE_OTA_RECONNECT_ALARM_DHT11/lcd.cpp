#include "lcd.h"

void LCDBigNumbers::_clear(){
      int cont = 1;
      long x = 9;
      while (_value > x){
        cont++;
        x = x * 10 + 9;
      }
      for (int i=0; i<cont; i++) {
        _lcd->setCursor(_col+i, _row);
        _lcd->print( "    " );
        _lcd->setCursor(_col+i, _row+1);
        _lcd->print( "    " );
      }
    }

    void LCDBigNumbers::createChars() {
      _lcd->createChar(0, c0);
      _lcd->createChar(1, c1);
      _lcd->createChar(2, c2);
      _lcd->createChar(3, c3);
      _lcd->createChar(4, c4);
      _lcd->createChar(5, c5);
      //_lcd->createChar(6, c6);
      //_lcd->createChar(7, c7);
    }
      
    LCDBigNumbers::LCDBigNumbers(LiquidCrystal * lcd, int row, int col) {
      _lcd = lcd;      _row = row;      _col = col;
    }
      
    void LCDBigNumbers::setRow(int row){
      _clear();
      _row = row;
      setValue(_value);
    }
    void LCDBigNumbers::setCol(int col){
    //  _clear();
      _col = col;
      setValue(_value);
    }
      
    void LCDBigNumbers::setValue(long value){
     // _clear();
      _value = value;
        
      int cont = 1;
      long x = 9;
      while (abs(_value) > x){
        cont++;
        x = x * 10 + 9;
      }
        
      for (int i=0; i<cont; i++) {
        int n = value / pow(10, cont-1-i);
        value = value - pow(10, cont-1-i) * n;
          
        _lcd->setCursor(_col+i*4, _row);
        _lcd_numbers[n].top1 == 9 ? _lcd->print(" ") : _lcd->write( _lcd_numbers[n].top1 );
        _lcd_numbers[n].top2 == 9 ? _lcd->print(" ") : _lcd->write( _lcd_numbers[n].top2 );
        _lcd_numbers[n].top3 == 9 ? _lcd->print(" ") : _lcd->write( _lcd_numbers[n].top3 );
        _lcd->setCursor(_col+i*4, _row+1);
        _lcd_numbers[n].bottom1 == 9 ? _lcd->print(" ") : _lcd->write( _lcd_numbers[n].bottom1 );
        _lcd_numbers[n].bottom2 == 9 ? _lcd->print(" ") : _lcd->write( _lcd_numbers[n].bottom2 );
        _lcd_numbers[n].bottom3 == 9 ? _lcd->print(" ") : _lcd->write( _lcd_numbers[n].bottom3 );
      }
    }

    LCDNumber LCDBigNumbers::_lcd_numbers[] = { 
      {2, 1, 2, 2, 0, 2}, //0
      {1, 2, 9, 0, 2, 0}, //1
      {1, 5, 2, 2, 0, 0}, //2
      {1, 5, 2, 0, 0, 2}, //3
      {2, 0, 2, 9, 9, 2}, //4
      {2, 5, 1, 0, 0, 2}, //5
      {2, 5, 1, 2, 0, 2}, //6
      {1, 1, 2, 9, 9, 2}, //7
      {2, 5, 2, 2, 0, 2}, //8
      {2, 5, 2, 0, 0, 2} // 9
    };

void LCDBigNumbers::imprime(String aux) {
  switch(aux[0]) {
    case '1':
    setCol(0);
    setValue(1);
    break;
    case '2':
    setCol(0);
    setValue(2);
    break;
    case '3':
    setCol(0);
    setValue(3);
    break;
    case '4':
    setCol(0);
    setValue(4);
    break;
    case '5':
    setCol(0);
    setValue(5);
    break;
    case '6':
    setCol(0);
    setValue(6);
    break;
    case '7':
    setCol(0);
    setValue(7);
    break;
    case '8':
    setCol(0);
    setValue(8);
    break;
    case '9':
    setCol(0);
    setValue(9);
    break;
    case '0':
    setCol(0);
    setValue(0);
    break;   
  }
  
  switch(aux[1]) {
    case '1':
    setCol(4);
    setValue(1);
    break;
    case '2':
    setCol(4);
    setValue(2);
    break;
    case '3':
    setCol(4);
    setValue(3);
    break;
    case '4':
    setCol(4);
    setValue(4);
    break;
    case '5':
    setCol(4);
    setValue(5);
    break;
    case '6':
    setCol(4);
    setValue(6);
    break;
    case '7':
    setCol(4);
    setValue(7);
    break;
    case '8':
    setCol(4);
    setValue(8);
    break;
    case '9':
    setCol(4);
    setValue(9);
    break;
    case '0':
    setCol(4);
    setValue(0);
    break;   
  }
  if(!blynk){
 _lcd->setCursor(7,0);
  _lcd->print("..");
  _lcd->setCursor(7,1);
  _lcd->print("..");
  blynk=true;}
  else{
    _lcd->setCursor(7,0);
  _lcd->print("  ");
  _lcd->setCursor(7,1);
  _lcd->print("  ");
  blynk=false;
  }
  
  switch(aux[3]) {
    case '1':
    setCol(9);
    setValue(1);
    break;
    case '2':
    setCol(9);
    setValue(2);
    break;
    case '3':
    setCol(9);
    setValue(3);
    break;
    case '4':
    setCol(9);
    setValue(4);
    break;
    case '5':
    setCol(9);
    setValue(5);
    break;
    case '6':
    setCol(9);
    setValue(6);
    break;
    case '7':
    setCol(9);
    setValue(7);
    break;
    case '8':
    setCol(9);
    setValue(8);
    break;
    case '9':
    setCol(9);
    setValue(9);
    break;
    case '0':
    setCol(9);
    setValue(0);
    break;   
  }
  
  switch(aux[4]) {
    case '1':
    setCol(13);
    setValue(1);
    break;
    case '2':
    setCol(13);
    setValue(2);
    break;
    case '3':
    setCol(13);
    setValue(3);
    break;
    case '4':
    setCol(13);
    setValue(4);
    break;
    case '5':
    setCol(13);
    setValue(5);
    break;
    case '6':
    setCol(13);
    setValue(6);
    break;
    case '7':
    setCol(13);
    setValue(7);
    break;
    case '8':
    setCol(13);
    setValue(8);
    break;
    case '9':
    setCol(13);
    setValue(9);
    break;
    case '0':
    setCol(13);
    setValue(0);
    break;   
  }
}

  byte LCDBigNumbers::c0[8] = {B00000, B00000, B00000, B00000, B00000, B11111, B11111, B11111};  //bottom
  byte LCDBigNumbers::c1[8] = {B11111, B11111, B11111, B00000, B00000, B00000, B00000, B00000};  //top
  byte LCDBigNumbers::c2[8] = {B11111, B11111, B11111, B11111, B11111, B11111, B11111, B11111};  //fill
  byte LCDBigNumbers::c3[8] = {B00000, B00000, B00001, B00011, B00011, B00001, B00000, B00000};
  byte LCDBigNumbers::c4[8] = {B00000, B00000, B10000, B11000, B11000, B10000, B00000, B00000};
  byte LCDBigNumbers::c5[8] = {B11111, B11111, B00000, B00000, B00000, B00000, B11111, B11111};   //top / bottom 
