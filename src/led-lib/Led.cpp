#include "Led.h"

Led::Led() {
 led = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
}

void Led::begin() {
  led.begin();
} 

void Led::off() {
  led.setPixelColor(LED_INDEX, led.Color(0,0,0));
  led.show();
}

void Led::on() {
  led.setPixelColor(LED_INDEX, led.Color(255, 255, 255)); 
  led.show();
}

void Led::on(int r, int g, int b) {
  led.setPixelColor(LED_INDEX, led.Color(r, g, b)); 
  led.show();
}

void Led::on(Color color) {
  uint32_t c;
  switch (color) {
    case RED:
      c = led.Color(255, 0, 0);
      break;
    case GREEN:
      c = led.Color(0, 255, 0);
      break;
    case BLUE:
      c = led.Color(0, 0, 255);
      break;
  }

  led.setPixelColor(LED_INDEX, c); 
  led.show();
}