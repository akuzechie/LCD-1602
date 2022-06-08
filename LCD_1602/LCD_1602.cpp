//----------------------------------
// LCD_1602.cpp - Header File
// Library for Programming 16x2 LCD
// by: Anas Kuzechie (June, 2022)
//-----------------------------------
#include <Arduino.h>
#include <LCD_1602.h>
//========================================================================
// Assembly Function Prototypes
//========================================================================
extern "C" {void delay_short(); void delay_us(); void delay_ms();}
//========================================================================
// Constructor
//========================================================================
LCD_1602::LCD_1602(byte D4, byte D5, byte D6, byte D7, byte EN, byte RS)
{
  pinMode(D4, OUTPUT); _D4 = D4;
  pinMode(D5, OUTPUT); _D5 = D5;
  pinMode(D6, OUTPUT); _D6 = D6;
  pinMode(D7, OUTPUT); _D7 = D7;
  pinMode(EN, OUTPUT); _EN = EN;
  pinMode(RS, OUTPUT); _RS = RS;
}
//========================================================================
// Public Methods
//========================================================================
void LCD_1602::InitLCD()
{
  writeByte(0, 0x33);            /*initialize LCD for 4-bit data*/
  delay_ms();
  writeByte(0, 0x32);
  delay_ms();
  writeByte(0, 0x28);            /*LCD 2 lines, 5x7 matrix*/
  delay_ms();
  writeByte(0, 0x0C);            /*display ON, cursor OFF*/
  writeByte(0, 0x01);            /*clear LCD*/
  delay_ms();
  writeByte(0, 0x06);            /*shift cursor right*/
}
//========================================================================
void LCD_1602::writeText(unsigned char text[])
{
  byte i = 0;
  while(text[i] != '\0')
  {
      writeByte(1, text[i]); i++;
  }
}
//========================================================================
void LCD_1602::writeByte(byte rs, unsigned char byteValue)
{
  PORTD = byteValue & 0xF0;       /*mask & o/p high nibble of cmd or data*/
  digitalWrite(_RS, rs);          /*RS = 0 (command) RS = 1 (data)*/
  digitalWrite(_EN, HIGH);        /*EN = 1*/
  delay_short();                  /*widen EN pulse*/
  digitalWrite(_EN, LOW);         /*EN = 0*/
  delay_us();
  //----------------------------------------------------------------------
  PORTD = (byteValue << 4) & 0xF0;/*mask & o/p low nibble of cmd or data*/
  digitalWrite(_EN, HIGH);        /*EN = 1*/
  delay_short();                  /*widen EN pulse*/
  digitalWrite(_EN, LOW);         /*EN = 0*/
  delay_us();
}
