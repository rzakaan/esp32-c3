#ifndef  _Led_h
#define  _Led_h

#include <Adafruit_NeoPixel.h>

#define DEFAULT_PIN 2
#define NUMPIXELS   1
#define LED_INDEX   0
#define DEFAULT_DELAY 50

enum Color {
  RED,
  GREEN,
  BLUE
};

class Led {
  public:
    Led();
    Led(int num, int pin);
    void begin();
    void on(); 
    void on(uint32_t color);
    void on(int r, int g, int b);
    void color(Color color); 
    void off();
    uint32_t wheel(byte wheelPos);
    void rainbow();
    void rainbowCycle();
  private:
    Adafruit_NeoPixel led;
};


#endif
