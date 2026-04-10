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

// Libraries
#include <Adafruit_NeoPixel.h>

// ****************  VARIABLES / DEFINES / STATIC / STRUCTURES / CONSTANTS ****************

// **************** INPUTS ****************
#define User_GP28 28
#define User_GP14 14

// **************** OUTPUTS ****************

// RGB
#define PIN_WS2812B 27  // The ESP32-C6 pin GPIO8 connected to WS2812B
Adafruit_NeoPixel ws2812b(2, PIN_WS2812B, NEO_GRB + NEO_KHZ800);

// **************** SETUP ****************
void setup() {

  // Stabalise
  delay(250);

  // Initialise UART
  Serial.begin(115200, SERIAL_8N1);  // 115200
  while (!Serial)
    ;
  Serial.println("");

  ws2812b.begin();  // Initialize WS2812B
  ws2812b.clear();  // Turn off RGB for two seconds

  // Turn off RGB
  ws2812b.clear();
  ws2812b.show();
  delay(250);

  // Configure GPIO Inputs
  pinMode(User_GP28, INPUT_PULLUP);
  pinMode(User_GP14, INPUT_PULLUP);

  Serial.println("IPEM Plus Bring Up and Test Example Code");
  Serial.println("Ready for Input");
}

// **************** LOOP ****************
void loop() {

  // Turn off RGB
  ws2812b.clear();
  ws2812b.show();  // update to the WS2812B Led Strip
  delay(250);

  // Check for Button Press
  if (digitalRead(User_GP28) == LOW) {

    Serial.println("User User_GP28");

    // BLUE
    ws2812b.setPixelColor(0, ws2812b.Color(0, 0, 150));
    ws2812b.show();
    delay(500);
  }

  if (digitalRead(User_GP14) == LOW) {

    Serial.println("User User_GP14");

    // RED
    ws2812b.setPixelColor(0, ws2812b.Color(150, 0, 0));
    ws2812b.show();
    delay(500);
  }
}
