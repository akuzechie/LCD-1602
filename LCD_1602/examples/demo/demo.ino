//---------------------------------------
// Displaying Text & Numbers on 1602 LCD
// using LCD_1602.h Library
// by: Anas Kuzechie (June, 2022)
//---------------------------------------
#include <LCD_1602.h>
//---------------------------------------
           /*D4 D5 D6 D7 EN RS*/
LCD_1602 lcd(4, 5, 6, 7, 8, 9);
//=========================================================
void setup()
{
  lcd.InitLCD();            /*initialize 16x2 LCD*/
  delay(1000);
}
//=========================================================
void loop()
{
  lcd.writeText("Arduino  Library");
  //------------------------------------------------------
  lcd.writeByte(0, 0xC0);   /*beginning of 2nd line*/
  //------------------------------------------------------
  lcd.writeText("--for 1602 LCD--");
  //------------------------------------------------------
  delay(2000);
  lcd.writeByte(0, 0x01);   /*clear LCD*/
  delay(1000);
  //------------------------------------------------------
  lcd.writeText("Count: ");
  //------------------------------------------------------
  for(byte i=0; i<=99; i++) /*display count from 0 to 99*/
  {
    lcd.writeByte(1, 0x30+(i/10)%10);
    lcd.writeByte(1, 0x30+i%10);
    lcd.writeByte(0, 0x87); /*cursor line 1, position 7*/
    delay(200);
  }
  //------------------------------------------------------
  lcd.writeByte(0, 0xC0);   /*beginning of 2nd line*/
  //------------------------------------------------------
  lcd.writeText("end of count!");
  //------------------------------------------------------
  delay(2000);
  lcd.writeByte(0, 0x01);   /*clear LCD*/
  delay(2000);
}