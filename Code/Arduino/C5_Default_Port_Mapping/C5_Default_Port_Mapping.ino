/*
  Dave Williams, DitroniX 2019-2026 (ditronix.net)
  IPEM Plus - ESP32-C5 | ATM90E36 | WiFi 2.4/5GHz | Zigbee | LoRa | IoT Mains Power Energy Monitor

  Example Code, to demonstrate and test the IPEM Plus
 
  Remember!
  - Set the BOARD to Use ESP32C5 Dev Module (or similar).
  - You can also set the BAUD rate up to 921600 to speed up flashing.
  - The SDK does NOT need external power to flash.  It will take Power from the USB 5V.
  - The Serial Monitor is configured for BAUD 115200
  
  The purpose of this test code is to cycle through the various main functions of the board as part of bring up testing.

  This test code is OPEN SOURCE and formatted for easier viewing.  Although is is not intended for real world use, it may be freely used, or modified as needed.
  It is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.

  For board configuration, see github.com/DitroniX/IPEM-Plus-ESP32-C5-LoRa-LoRaWAN-IoT-Mains-Power-Energy-Monitor/wiki/Arduino-IDE

  Further information, details and examples can be found on our website or github.com/DitroniX

  * ditronix.net
  * github.com/DitroniX
  * github.com/DitroniX/IPEM-Plus-ESP32-C5-LoRa-LoRaWAN-IoT-Mains-Power-Energy-Monitor
  * github.com/DitroniX/IPEM-Plus-ESP32-C5-LoRa-LoRaWAN-IoT-Mains-Power-Energy-Monitor/wiki
  * hackster.io/DitroniX/ipem-plus-esp32-c5-atm90e36-lora-iot-power-energy-monitor-24d898
*/

/*
  ESP32-C5 Default Factory Serial Port Initialized
  MOSI: 8
  MISO: 9
  SCL / SCLK: 10
  CS / SS: 6
  SDA: 0
  SCL: 1
  IPEM Plus Bring Up and Test Example Code
*/

// Libraries
#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>

void setup() {
  Serial.begin(115200, SERIAL_8N1);  // U0
  // Serial.begin(115200);
  while (!Serial)
    ;  // Wait for serial port to connect
  Serial.println("\n\nESP32-C5 Default Factory Serial Port Initialized");

  Serial.print("MOSI: ");
  Serial.println(MOSI);

  Serial.print("MISO: ");
  Serial.println(MISO);

  Serial.print("SCL / SCLK: ");
  Serial.println(SCK);

  Serial.print("CS / SS: ");
  Serial.println(SS);

  Serial.print("SDA: ");
  Serial.println(SDA);

  Serial.print("SCL: ");
  Serial.println(SCL);

  Serial.println("IPEM Plus Bring Up and Test Example Code");
}

void loop() {}