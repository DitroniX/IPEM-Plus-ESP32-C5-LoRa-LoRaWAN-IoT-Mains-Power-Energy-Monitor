/*
  Dave Williams, DitroniX 2019-2026 (ditronix.net)
  IPEM Plus - ESP32-C5 | ATM90E36 | WiFi 2.4/5GHz | Zigbee | Bluetooth | LoRa | LoRaWAN | IoT Mains Power Energy Monitor

  May 2026: Example Code, to demonstrate and test the IPEM Plus
 
  Remember!
  - Set the BOARD to Use ESP32C5 Dev Module (or similar).
  - You can also set the BAUD rate up to 921600 to speed up flashing.
  - The SDK does NOT need external power to flash.  It will take Power from the USB 5V.
  - The Serial Monitor is configured for BAUD 115200
  
  The purpose of this test code is to cycle through the various main functions of the board as part of bring up testing.

  This test code is OPEN SOURCE and formatted for easier viewing.  Although is is not intended for real world use, it may be freely used, or modified as needed.
  It is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.

  For board configuration, see https://github.com/DitroniX/IPEM-Plus-ESP32-C5-LoRa-LoRaWAN-IoT-Mains-Power-Energy-Monitor/wiki/Arduino-IDE

  Further information, details and examples can be found on our website or github.com/DitroniX

  * ditronix.net
  * github.com/DitroniX
  * github.com/DitroniX/IPEM-Plus-ESP32-C5-LoRa-LoRaWAN-IoT-Mains-Power-Energy-Monitor
  * github.com/DitroniX/IPEM-Plus-ESP32-C5-LoRa-LoRaWAN-IoT-Mains-Power-Energy-Monitor/wiki
  * hackster.io/DitroniX/ipem-plus-esp32-c5-atm90e36-lora-iot-power-energy-monitor-24d898
*/

// REMEMBER TO PUT THE LORA ENABLE JUMPER ON - OR THIS CODE WILL NOT WORK.

// IMPORTANT: ENSURE AN ANTENNA, OR RF LOAD, IS CONNECTED TO THE LORA MODULE - BEFORE TX.  OTHERWISE DAMAGE TO THE LORA MODULE COULD RESULT.

// Libraries
#include <RadioLib.h>
#include <SPI.h>
#include <Adafruit_NeoPixel.h>

// **************** USER VARIABLES / DEFINES / STATIC / STRUCTURES / CONSTANTS ****************

// Pin definitions
#define SPI_MOSI 8
#define SPI_MISO 9
#define SPI_SCK 10
#define SPI_CS 6

#define E22_IRQ 13
#define E22_NRST 5
#define E22_BUSY 4

#define RXLP 1
#define TXLP 0
#define ENLP 23  // RS485 UART Enable

// RGB
#define PIN_WS2812B 27  // The ESP32-C6 pin GPIO8 connected to WS2812B
Adafruit_NeoPixel ws2812b(1, PIN_WS2812B, NEO_GRB + NEO_KHZ800);

SX1262 radio = new Module(SPI_CS, E22_IRQ, E22_NRST, E22_BUSY);

// **************** FUNCTIONS AND ROUTINES ****************
void Serial1Flush() {

  // Force RS485 UART Driver Disabled and Receiver is Enabled
  digitalWrite(ENLP, LOW);

  while (Serial1.available() > 0) {
    char t = Serial1.read();
  }
}

// **************** SETUP ****************
void setup() {
  // Stabalise
  delay(250);

  // Initialise UART
  Serial.begin(115200);
  while (!Serial)
    ;  // Wait for serial port to connect
  Serial.println("");

  // Initialise UART 1 - RS485 Port
  Serial1.begin(9600, SERIAL_8N1, RXLP, TXLP);  //LP
  while (!Serial1)
    ;  // Wait for serial port to connect
  Serial.println("UART 1 Opened (RS485 Port)");

  //Initialise RS485 UART Enable on GP23
  pinMode(ENLP, OUTPUT);

  // WS2812B Initialise
  ws2812b.begin();  // Initialize WS2812B
  ws2812b.clear();  // Turn off RGB

  Serial1Flush();

  SPI.begin(SPI_SCK, SPI_MISO, SPI_MOSI, SPI_CS);

  Serial.print(F("\n[SX1262] Initializing ... "));

  int state = radio.begin(868.0);
  if (state == RADIOLIB_ERR_NONE) {
    Serial.println(F("success!"));
  } else {
    Serial.print(F("failed, code "));
    Serial.println(state);
    while (true) {
      delay(10);
    }
  }

  radio.setOutputPower(10);

  Serial.println("\nESPKnack Bring Up and Test Example Code");
  Serial.println("Please Remember to Fit LoRa Antenna before TX");
  Serial.println("Awaiting RS485 Byte and then send a packet over LoRa TX on 868 MHz");
}

// **************** LOOP ****************
void loop() {

  // // Turn off RGB
  // ws2812b.clear();  // Turn off RGB
  // ws2812b.show();

  // Force RS485 UART Driver Disabled and Receiver is Enabled
  digitalWrite(ENLP, LOW);

  if (Serial1.available() > 0) {

    // Read Incomming Byte from RS485 UART and Output to the Serial Monitor
    char incomingbyte = Serial1.read();

    // RX Packet Indication
    ws2812b.setPixelColor(0, ws2812b.Color(0, 150, 0));  // GREEN
    ws2812b.show();

    // TX Packet
    Serial.print("\nSending Packet\t");
    Serial.print(incomingbyte);
    Serial.print(F("\nstartTransmit code "));
    int transmissionState = radio.startTransmit("" + incomingbyte);
    Serial.println(transmissionState);
    Serial.println("Test End\n");
    delay(500);
  }
}