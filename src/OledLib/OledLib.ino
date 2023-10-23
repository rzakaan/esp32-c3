#include <Arduino.h>
#include <U8g2lib.h>
#include <Wire.h>

#define SDA_PIN 5
#define SCL_PIN 6

/*
  U8g2lib overview
    Frame Buffer Examples: clearBuffer/sendBuffer. Fast, but may not work with all Arduino boards because of RAM consumption
    Page Buffer Examples: firstPage/nextPage. Less RAM usage, should work with all Arduino boards.
    U8x8 Text Only Example: No RAM usage, direct communication with display controller. No graphics, 8x8 Text only.    
*/

U8G2_SSD1306_72X40_ER_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);   // EastRising 0.42" OLED
int lineht;
void setup(void) {
  Wire.begin(SDA_PIN, SCL_PIN);
  u8g2.begin();
  u8g2.setFont(u8g2_font_ncenB08_tr);
  u8g2.setFontPosTop();
  lineht = u8g2.getMaxCharHeight();
}

void loop(void) {
  u8g2.clear();
  delay(1000);

  u8g2.setCursor(0, 0);
  u8g2.print("Hello");
  u8g2.updateDisplay();
  delay(1000);
  
  u8g2.setCursor(0, lineht);
  u8g2.print("World");
  u8g2.updateDisplay();
  delay(1000);   
}