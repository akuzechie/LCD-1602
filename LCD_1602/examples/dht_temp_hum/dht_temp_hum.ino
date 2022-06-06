//----------------------------------------
// DHT Sensor Temp & Humidity on 1602 LCD
// using LCD_1602.h & DHT.h Libraries
// by: Anas Kuzechie (June, 2022)
//----------------------------------------
#include <LCD_1602.h>
#include <DHT.h>
//----------------------------------------
           /*D4 D5 D6 D7 EN RS*/
LCD_1602 lcd(4, 5, 6, 7, 8, 9);
DHT dht(10, DHT22);     /*DHT22 sensor connected to pin 10*/
//============================================================
void setup()
{
  dht.begin();              /*initialize DHT sensor*/
  lcd.InitLCD();            /*initialize 16x2 LCD*/
  delay(1000);
  //------------------------------------------------------
  lcd.writeText("--DHT22 Sensor--");
  lcd.writeByte(0, 0xC0);   /*beginning of 2nd line*/
  lcd.writeText("Temp & Humidity");
  delay(2000);
  lcd.writeByte(0, 0x01);   /*clear LCD*/
}
//============================================================
void loop()
{
  delay(2000);
  //---------------------------------------------------
  float temp = dht.readTemperature();
  int temp_MSD = int(temp)/10 + 48;
  int temp_LSD = int(temp)%10 + 48;
  int temp_fraction = (temp - int(temp))*10 + 48;
  //---------------------------------------------------
  lcd.writeText("Temp    : ");
  lcd.writeByte(1, temp_MSD);
  lcd.writeByte(1, temp_LSD);
  lcd.writeByte(1, '.');
  lcd.writeByte(1, temp_fraction);
  lcd.writeText(" C");
  //---------------------------------------------------
  float hum = dht.readHumidity();
  int hum_MSD = int(hum)/10 + 48;
  int hum_LSD = int(hum)%10 + 48;
  int hum_fraction = (hum - int(hum))*10 + 48;
  //---------------------------------------------------
  lcd.writeByte(0, 0xC0);     /*beginning of 2nd line*/
  //---------------------------------------------------
  lcd.writeText("Humidity: ");
  lcd.writeByte(1, hum_MSD);
  lcd.writeByte(1, hum_LSD);
  lcd.writeByte(1, '.');
  lcd.writeByte(1, hum_fraction);
  lcd.writeText(" %");
  //---------------------------------------------------
  lcd.writeByte(0, 0x80);     /*beginning of 1st line*/
}