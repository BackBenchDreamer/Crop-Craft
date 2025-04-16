#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

// Pin Configurations
#define DHT_PIN D4
#define DHT_TYPE DHT11
#define MOISTURE_SENSOR A0

// Sensor and Display Setup
DHT dht(DHT_PIN, DHT_TYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);

  dht.begin();
  lcd.begin();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Crop Craft Init");
  delay(2000);
}

void loop() {
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();
  int rawMoisture = analogRead(MOISTURE_SENSOR);
  float moisture = map(rawMoisture, 1023, 350, 0, 100);  // To percent

  // Debug to Serial Monitor
  Serial.print("Temp: ");
  Serial.print(temperature);
  Serial.print(" °C | Humidity: ");
  Serial.print(humidity);
  Serial.print(" % | Moisture: ");
  Serial.print(moisture);
  Serial.println(" %");

  // LCD Output
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperature, 1);
  lcd.print((char)223);  // Degree symbol
  lcd.print("C");

  lcd.setCursor(0, 1);
  lcd.print("Moist: ");
  lcd.print(moisture, 1);
  lcd.print("%");

  delay(3000);
}
