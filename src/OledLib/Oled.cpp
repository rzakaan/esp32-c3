#include "Oled.h"

Oled::Oled() {
  line = 0;
}

U8G2 Oled::instance() {
  return u8g2;
} 

void Oled::begin() {
  u8g2 = U8G2_SSD1306_72X40_ER_F_HW_I2C(U8G2_R0, /* reset */ U8X8_PIN_NONE);
  u8g2.begin();
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_helvB08_tf);
  u8g2.setFontPosTop();
  lineHeight = u8g2.getMaxCharHeight();
}

void Oled::clear() {
  u8g2.clear();
  line = 0;
}

void Oled::println(String text) {
  u8g2.setCursor(0, line);
  u8g2.print(text);
  u8g2.updateDisplay();
  line += lineHeight;
}

void Oled::selection() {
  
  //u8g2.setFont(u8g2_font_6x10_tf);
  //u8g2.setFontRefHeightAll();  	/* this will add some extra space for the text inside the buttons */
  //u8g2.userInterfaceMessage("Title1", "Title2", "Title3", " Ok \n Cancel ");
  int i;
  for (i=1; i<4; i++) {
    u8g2.userInterfaceSelectionList("Title", i, "Asli\nLkoum\nSurat");
    delay(500);
  }
  

}