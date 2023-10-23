#ifndef  _Led_h
#define  _Led_h

#include <Adafruit_NeoPixel.h>

#define PIN        2
#define NUMPIXELS  1
#define LED_INDEX  0

enum Color {
  RED,
  GREEN,
  BLUE
};

class Led {
  public:
    Led();
    void begin();
    void on(); 
    void on(Color color); 
    void on(int r, int g, int b);
    void off(); 
  private:
    Adafruit_NeoPixel led;
};


#endif
