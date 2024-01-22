#include <Arduino.h>

#define SENSOR 33
#define LED 26

void setup() {
  Serial.begin(9200);
  pinMode(LED, OUTPUT);
}

void loop() {
  digitalWrite(LED, HIGH);
  delay(200);
  digitalWrite(LED, LOW);
  delay(200);
}