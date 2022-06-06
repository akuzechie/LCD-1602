//----------------------------------
// LCD_1602.h - Header File
// Library for Programming 16x2 LCD
// by: Anas Kuzechie (June, 2022)
//-----------------------------------
//header guards
#ifndef LCD_1602_h
#define LCD_1602_h
//----------------------------------------------------------------------
//class definition
class LCD_1602
{
    public:
        //constructor
        LCD_1602(byte D4, byte D5, byte D6, byte D7, byte EN, byte RS);
        //methods
        void InitLCD();
        void writeByte(byte rs, unsigned char byteValue);
        void writeText(unsigned char text[]);
    private:
        byte _D4; byte _D5; byte _D6; byte _D7; byte _EN; byte _RS;
};
//----------------------------------------------------------------------
#endif