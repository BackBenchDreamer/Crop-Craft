# Crop Craft

**Crop Craft** is a smart IoT-based irrigation system designed to optimize water usage in agriculture using real-time soil moisture sensing and cloud connectivity.

## Features
- Automated irrigation control based on live soil data
- Cloud dashboard integration using Arduino IoT Cloud
- LCD feedback for local monitoring
- Real-time temperature, humidity, and heat index tracking

## Tech Stack
- NodeMCU (ESP8266)
- DHT11 Sensor
- Soil Moisture Sensor
- Arduino IoT Cloud
- LiquidCrystal_I2C Display
- Relay Module

## Project Structure
- `cropCraftController.ino`: Main sketch controlling pump and sensors
- `cropCraftDisplay.ino`: LCD output test and sensor preview
- `cropCraftProperties.h`: IoT variable setup
- `sketch.json`: Arduino config with Wi-Fi/device secrets

## Hackathon Achievement
Built in 36 hours for the **REVA University SMART AGRO HACKATHON (Nov 2023)**, Crop Craft secured a winning position for its innovation, real-world impact, and potential scalability.  
[See the winning moment here](https://www.linkedin.com/feed/update/urn:li:activity:7136759213950734336/)

## 🔧 Setup Instructions
1. Add your Wi-Fi and Arduino IoT Cloud credentials to `sketch.json`.
2. Upload `cropCraftController.ino` to your NodeMCU via Arduino IDE.
3. Ensure sensors are correctly connected as per the pin layout.
4. Monitor values on Arduino IoT Cloud or locally via LCD.

## 📸 Demo

![Demo image](https://github.com/user-attachments/assets/966ffa11-5598-4cb7-b7ba-8635a3a268f4)
![Demo image](https://github.com/user-attachments/assets/18b6932f-caa7-4d7c-a926-c4d697d18649)
![Demo image](https://github.com/user-attachments/assets/7ea21ff7-fe1a-42ca-abab-2de553861c98)
