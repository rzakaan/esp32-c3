/*
  @version 1.0
  @note
  @createdby Riza Kaan Ucak
  @date 21.10.2023

  U8g2lib overview
    u8g2_font_helvB08_tf      - 8 Pixel
    u8g2_font_tenfatguys_tf   - 10 Pixel
    
    Frame Buffer Examples: clearBuffer/sendBuffer. Fast, but may not work with all Arduino boards because of RAM consumption
    Page Buffer Examples: firstPage/nextPage. Less RAM usage, should work with all Arduino boards.
    U8x8 Text Only Example: No RAM usage, direct communication with display controller. No graphics, 8x8 Text only.    
*/

#ifndef _Oled_h
#define _Oled_h

#include <U8g2lib.h>
#include <Wire.h>

class Oled {
  public:
    Oled();
    void begin();
    U8G2 instance();
    void clear();
    void println(String text);
    void selection();
  private:
    U8G2 u8g2; // EastRising 0.42" OLED
    int lineHeight;
    int line;
    int x, y;
};

#endif