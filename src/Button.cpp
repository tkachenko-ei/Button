#include "Button.h"

Button::Button(uint8_t pin, bool polarity)
  : pin(pin), polarity(polarity) {
  if (polarity == LOW) {
    pinMode(pin, INPUT_PULLUP);
  } else {
    pinMode(pin, INPUT_PULLDOWN);
  }
  state = polarity;
  lastState = polarity;
}

void Button::setDebounce(uint32_t val) {
  debounce = val;
}

void Button::setCallback(void (*handler)()) {
  callback = handler;
}

void Button::loop() {
  bool val = digitalRead(pin);
  if (val != lastState) {
    timer = millis();
  }
  if ((millis() - timer) > debounce) {
    if (val != state) {
      state = val;
      if (state != polarity) {
        if (callback) callback();
      }
    }
  }
  lastState = val;
}