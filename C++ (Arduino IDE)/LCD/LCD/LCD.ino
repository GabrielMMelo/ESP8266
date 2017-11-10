#include <LiquidCrystal.h>

//Aqui ocorreu a mudança dos pinos
LiquidCrystal lcd(5, 4, 16, 14, 12, 13);

void setup() {
lcd.begin(16, 2);
lcd.print(" irving.com.br");
//Seta o cursor para a segunda coluna e segunda linha
lcd.setCursor(1, 1);
lcd.print("NodeMCU + LCD");

}

void loop() {
}

