#include "cropCraftProperties.h"
#include <DHT.h>
#include <LiquidCrystal_I2C.h>

// Pin Configuration
#define SOIL_MOISTURE_PIN A0
#define RELAY_PIN D1
#define DHT_PIN D4
#define DHT_TYPE DHT11

// LCD and Sensor Setup
DHT dhtSensor(DHT_PIN, DHT_TYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Initialization
void setup() {
  Serial.begin(9600);

  // LCD
  lcd.begin();
  lcd.backlight();
  lcd.print("Crop Craft 🌱");

  // Sensors and Relay
  dhtSensor.begin();
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);

  // Cloud
  initProperties();
  ArduinoCloud.begin(CropCraftWiFiConnection);
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

// Main loop
void loop() {
  ArduinoCloud.update();

  // Sensor Readings
  float humidity = dhtSensor.readHumidity();
  float temperature = dhtSensor.readTemperature();
  float heatIdx = dhtSensor.computeHeatIndex(temperature, humidity, false);
  int rawSoil = analogRead(SOIL_MOISTURE_PIN);
  float soil = map(rawSoil, 1023, 350, 0, 100);  // Percentage

  // Store values
  humidityLevel = humidity;
  temperatureCelsius = temperature;
  heatIndex = heatIdx;
  moistureLevel = soil;

  // LCD Display
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Moisture:");
  lcd.print(soil, 1);
  lcd.print("%");
  lcd.setCursor(0, 1);
  lcd.print("Temp:");
  lcd.print(temperature, 1);
  lcd.print("C");

  delay(2000);
}

// Cloud-controlled pump switch
void onIrrigationToggle() {
  digitalWrite(RELAY_PIN, irrigationPumpStatus ? HIGH : LOW);
}
