#ifndef _Button_h
#define _Button_h

#include <Arduino.h>

class Button {
public:
  Button(uint8_t pin, bool polarity = LOW);

  void setDebounce(uint32_t val);  // период дребезга (по умолч. 50 мс)
  void setCallback(void (*handler)());
  void loop();

private:
  uint8_t pin;
  bool polarity;
  uint32_t timer = 0, debounce = 10;
  bool state, lastState;
  void (*callback)();
};

#endif