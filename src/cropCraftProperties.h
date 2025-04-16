// cropCraftProperties.h
// Configurations for Crop Craft IoT Monitoring System

#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>

// Unique device credentials
const char DEVICE_LOGIN_NAME[]  = "cropcraft-device-7001e182";
const char SSID[]               = SECRET_SSID;
const char PASS[]               = SECRET_OPTIONAL_PASS;
const char DEVICE_KEY[]         = SECRET_DEVICE_KEY;

// Variable Declarations
float heatIndex;
float humidityLevel;
float moistureLevel;
float temperatureCelsius;
bool irrigationPumpStatus;

// Trigger function
void onIrrigationToggle();

void initProperties() {
  ArduinoCloud.setBoardId(DEVICE_LOGIN_NAME);
  ArduinoCloud.setSecretDeviceKey(DEVICE_KEY);
  ArduinoCloud.addProperty(heatIndex, READ, 5 * SECONDS, NULL);
  ArduinoCloud.addProperty(humidityLevel, READ, 5 * SECONDS, NULL);
  ArduinoCloud.addProperty(moistureLevel, READ, 5 * SECONDS, NULL);
  ArduinoCloud.addProperty(temperatureCelsius, READ, 5 * SECONDS, NULL);
  ArduinoCloud.addProperty(irrigationPumpStatus, READWRITE, ON_CHANGE, onIrrigationToggle, 1);
}

// Network handler
WiFiConnectionHandler CropCraftWiFiConnection(SSID, PASS);
