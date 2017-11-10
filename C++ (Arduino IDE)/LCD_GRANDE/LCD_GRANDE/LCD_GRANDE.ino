#include <LiquidCrystal.h>
    
/*************************************************************************************************************
*******************************CLASSE LCD BIG NUMBERS*********************************************************
**************************************************************************************************************/
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
      
    void _clear(){
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
  public:
    static byte c0[8];  //bottom
    static byte c1[8];  //top
    static byte c2[8];  //fill
    static byte c3[8];
    static byte c4[8];
    static byte c5[8];  //top-bottom 
    static LCDNumber _lcd_numbers[];
     
    void createChars() {
      _lcd->createChar(0, c0);
      _lcd->createChar(1, c1);
      _lcd->createChar(2, c2);
      _lcd->createChar(3, c3);
      _lcd->createChar(4, c4);
      _lcd->createChar(5, c5);
      //_lcd->createChar(6, c6);
      //_lcd->createChar(7, c7);
    }
      
    LCDBigNumbers(LiquidCrystal * lcd, int row, int col) {
      _lcd = lcd;      _row = row;      _col = col;
    }
      
    void setRow(int row){
      _clear();
      _row = row;
      setValue(_value);
    }
    void setCol(int col){
      _clear();
      _col = col;
      setValue(_value);
    }
      
    void setValue(long value){
      _clear();
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
};
 
byte LCDBigNumbers::c0[8] = {B00000, B00000, B00000, B00000, B00000, B11111, B11111, B11111};  //bottom
byte LCDBigNumbers::c1[8] = {B11111, B11111, B11111, B00000, B00000, B00000, B00000, B00000};  //top
byte LCDBigNumbers::c2[8] = {B11111, B11111, B11111, B11111, B11111, B11111, B11111, B11111};  //fill
byte LCDBigNumbers::c3[8] = {B00000, B00000, B00001, B00011, B00011, B00001, B00000, B00000};
byte LCDBigNumbers::c4[8] = {B00000, B00000, B10000, B11000, B11000, B10000, B00000, B00000};
byte LCDBigNumbers::c5[8] = {B11111, B11111, B00000, B00000, B00000, B00000, B11111, B11111};   //top / bottom 
 
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
/*************************************************************************************************************
*******************************FIM CLASSE LCD BIG NUMBERS*****************************************************
**************************************************************************************************************/
    
    
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
LCDBigNumbers lcdNum(&lcd, 0,0); //inclui uma barra no lcd, primeira linha, coluna 1
    
void setup()   {
  Serial.begin(9600);
  lcdNum.createChars();
  lcdNum.setCol(1); //muda para a coluna 1
   
  pinMode(44, OUTPUT);  //arduino mega - pino de contraste do display
  analogWrite(44, 255/6); //utilizado para aumentar o contraste
  lcd.begin(16, 2);
}
  
long i = 0;
int col = 0;
  
void loop() {
  lcdNum.setValue(i++ * 11);
    
  if (i>=10000) { i = 0; }
 
  delay(500);  
}

