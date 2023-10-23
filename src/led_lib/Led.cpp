#include "Led.h"

Led::Led() {
 led = Adafruit_NeoPixel(NUMPIXELS, DEFAULT_PIN, NEO_GRB + NEO_KHZ800);
}

Led::Led(int num, int pin) {
 led = Adafruit_NeoPixel(num, pin, NEO_GRB + NEO_KHZ800);
}

void Led::begin() {
  led.begin();
} 

void Led::off() {
  led.clear();
  led.show();
}

void Led::on() {
  on(led.Color(255, 255, 255));
}

void Led::on(int r, int g, int b) {
  on(led.Color(r, g, b));
}

void Led::on(uint32_t color) {
  led.setPixelColor(LED_INDEX, color);
  led.show();
}

void Led::color(Color color) {
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

  on(c);
}

uint32_t Led::wheel(byte wheelPos) {
  wheelPos = 255 - wheelPos;
  if(wheelPos < 85) {
    return led.Color(255 - wheelPos * 3, 0, wheelPos * 3);
  }
  if(wheelPos < 170) {
    wheelPos -= 85;
    return led.Color(0, wheelPos * 3, 255 - wheelPos * 3);
  }
  wheelPos -= 170;
  return led.Color(wheelPos * 3, 255 - wheelPos * 3, 0);
}

void Led::rainbow() {
  uint16_t j;
  for(j=0; j<256; j++) {
    on(wheel(j & 255));
    delay(DEFAULT_DELAY);
  }
}

void Led::rainbowCycle() {
  uint16_t j;
  for (j=0; j<256; j++) {
    led.setPixelColor(0, wheel(((256 / led.numPixels()) + j) & 255));
    led.show();
    delay(DEFAULT_DELAY);
  }
}