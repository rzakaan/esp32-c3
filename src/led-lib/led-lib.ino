#include <Arduino.h>
#include "Led.h"

Led led;

void setup() {
  led.begin();
}

int state = 0;
void loop() {
  switch (state) {
    case 0:
      led.on(64, 0, 0);
      break;
    case 1:
      led.on(0, 64, 0);
      break;
    case 2:
      led.on(0, 0, 64);
      break;
    case 3:
      led.on(64, 64, 64);
      break;
  }

  state = ++state % 4;
  delay(1000);
}
