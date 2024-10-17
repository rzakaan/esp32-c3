#include <Wire.h>
#include "Oled.h"

#define SDA_PIN 5
#define SCL_PIN 6

Oled oled;
U8G2 u8g2;
void setup(void) {
  Wire.begin(SDA_PIN, SCL_PIN);
  oled.begin();
  u8g2 = oled.instance();
  /*
  oled.println("Lokum");
  oled.println("Surat");
  oled.println("Asli");
  */
  
}

uint8_t i = 1;
void loop(void) {
  oled.clear();
  u8g2.userInterfaceSelectionList("Title", i, "Asli\nLkoum\nSurat");

  i = ++i % 3;
  delay(1000);
}