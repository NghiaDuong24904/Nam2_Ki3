#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "DHT.h"

int dht_pin = 4;
DHT dht(dht_pin, DHT11);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  
  lcd.clear();
  
  lcd.setCursor(0, 0);
  lcd.print("Humidity: ");
  lcd.print(h);
  
  lcd.setCursor(0, 1);
  lcd.print("Temp (C): ");
  lcd.print(t);

  lcd.backlight();
  delay(1000);
  lcd.noBacklight();
  delay(1000);
}
