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

// **************** USER VARIABLES / DEFINES / STATIC / STRUCTURES / CONSTANTS ****************

int PWM_Out = 25;

// **************** FUNCTIONS AND ROUTINES ****************

// **************** SETUP ****************
void setup() {
  // Stabalise
  delay(250);

  // Initialise UART
  Serial.begin(115200, SERIAL_8N1);  //115200
  while (!Serial)
    ;
  Serial.println("");

  Serial.println("IPEM Plus Bring Up and Test Example Code");
}

// **************** LOOP ****************
void loop() {
  // fade in from min to max in increments of 5 points:
  for (int fadeValue = 0; fadeValue <= 255; fadeValue += 5) {
    // sets the value (range from 0 to 255):
    analogWrite(PWM_Out, fadeValue);
    // wait for 30 milliseconds to see the dimming effect
    delay(30);
  }

  // fade out from max to min in increments of 5 points:
  for (int fadeValue = 255; fadeValue >= 0; fadeValue -= 5) {
    // sets the value (range from 0 to 255):
    analogWrite(PWM_Out, fadeValue);
    // wait for 30 milliseconds to see the dimming effect
    delay(30);
  }
}
