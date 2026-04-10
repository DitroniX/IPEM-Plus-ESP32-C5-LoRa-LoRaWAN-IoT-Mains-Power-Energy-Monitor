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

// This code is for the Display User Panel and to check the Main User GP14 LED.

// ****************  VARIABLES / DEFINES / STATIC / STRUCTURES / CONSTANTS ****************

// **************** MIXED MODE INPUT/OUTPUT ****************
#define User_GP14 14

// **************** SETUP ****************
void setup() {

  // Stabalise
  delay(250);

  // Initialise UART
  Serial.begin(115200, SERIAL_8N1);  // 115200
  while (!Serial)
    ;
  Serial.println("");

  // Configure GPIO Inputs (Default)
  pinMode(User_GP14, INPUT_PULLUP);

  Serial.println("IPEM Plus Bring Up and Test Example Code");
  Serial.println("Ready for Input");
}

// **************** LOOP ****************
void loop() {

  // Check for Button Press
  if (digitalRead(User_GP14) == LOW) {

    Serial.println("User User_GP14");

    pinMode(User_GP14, OUTPUT);

    // Red Panel LED
    digitalWrite(User_GP14, LOW);
    delay(500);
    digitalWrite(User_GP14, HIGH);
    delay(500);
    digitalWrite(User_GP14, LOW);
    delay(500);
    digitalWrite(User_GP14, HIGH);
    delay(500);
    digitalWrite(User_GP14, LOW);
    delay(500);
    digitalWrite(User_GP14, HIGH);

    pinMode(User_GP14, INPUT_PULLUP);
  }
}
