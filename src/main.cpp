#include <Arduino.h>

#define P0_13 13 // The battery internal pin

void setup() {
  pinMode(P0_13, OUTPUT);
}

void loop() {
  digitalWrite(P0_13, LOW); // Battery charge current HIGH: 50 mA; LOW: 100 mA
}