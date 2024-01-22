#include <Arduino.h>
#include "DHT.h"

#define SENSOR 33
#define LED 26
#define SLEEP_TIME 5e6 

DHT dht(SENSOR, DHT11);

void setup() {
  Serial.begin(9600);
  
  dht.begin();

  pinMode(LED, OUTPUT);

  delay(1000);

  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
  } else {
    if (temperature > 25) {
      digitalWrite(LED, HIGH);
    } else {
      digitalWrite(LED, LOW);
    }

    Serial.print("Humidity : ");
    Serial.print(humidity);
    Serial.println("%");
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println("°C");
  }

  esp_deep_sleep(SLEEP_TIME);
}

void loop() {
}
