#include "DHT.h"
int dht_pin = 10;
DHT dht(dht_pin, DHT11);
void setup() {
  Serial.begin(9600);
  dht.begin();
}
void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);
  Serial.print("Humidity: ");
  Serial.println(h);
  Serial.print("Temperature (C): ");
  Serial.println(t);
  Serial.print("Temperature (F): ");
  Serial.println(f);
  delay(1000);
}