/*
  Dave Williams, DitroniX 2019-2026 (ditronix.net)
  IPEM Plus - ESP32-C5 | ATM90E36 | WiFi 2.4/5GHz | Zigbee | LoRa | IoT Mains Power Energy Monitor

  Example Code, to demonstrate and test the IPEM Plus.  Flash this to two, or more, boards and press USER button to TX Broadcast.
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

// REMEMBER TO PUT THE LORA ENABLE JUMPER ON - OR THIS CODE WILL NOT WORK.

// IMPORTANT: ENSURE AN ANTENNA, OR RF LOAD, IS CONNECTED TO THE LORA MODULE - BEFORE TX.  OTHERWISE DAMAGE TO THE LORA MODULE COULD RESULT.

// Libraries
#include <RadioLib.h>
#include <SPI.h>
#include <Adafruit_NeoPixel.h>
#include "WiFi.h"  // Used only to get the unique number

// **************** USER VARIABLES / DEFINES / STATIC / STRUCTURES / CONSTANTS ****************

// **************** INPUTS ****************
#define User_GP28 28
#define User_GP14 14

// RGB
#define PIN_WS2812B 27  // The ESP32-C6 pin GPIO8 connected to WS2812B
Adafruit_NeoPixel ws2812b(1, PIN_WS2812B, NEO_GRB + NEO_KHZ800);

// Pin definitions
#define SPI_MOSI 8
#define SPI_MISO 9
#define SPI_SCK 10
#define SPI_CS 6

#define E22_IRQ 13
#define E22_NRST 5
#define E22_BUSY 4

SX1262 radio = new Module(SPI_CS, E22_IRQ, E22_NRST, E22_BUSY);

//Example Values.  Leave 00 between P2P testing.  Just compile as is, to all devices under test.
// uint8_t appEui[] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
// uint8_t devEui[] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
// uint8_t appKey[] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

uint32_t counter = 0;
uint8_t payload[64];  // buffer for receive

// **************** SETUP ****************
void setup() {
  Serial.begin(115200);

  // Configure GPIO Inputs
  pinMode(User_GP28, INPUT_PULLUP);
  pinMode(User_GP14, INPUT_PULLUP);

  // WS2812B Initialise
  ws2812b.begin();  // Initialize WS2812B
  ws2812b.clear();  // Turn off RGB

  // Used only to get the unique number
  WiFi.mode(WIFI_MODE_STA);

  // initialize SPI
  SPI.begin(SPI_SCK, SPI_MISO, SPI_MOSI, SPI_CS);

  // initialize SX1262 FSK modem with default settings
  Serial.print(F("\n[SX1262] Initializing ... "));

  // Initialize the radio
  Serial.print(F("[SX1262] Initializing ... "));

  // radio.XTAL = true;

  int state = radio.begin(868.0,  // frequency (MHz)
                          125.0,  // bandwidth (kHz)
                          9,      // spreading factor
                          5,      // coding rate
                          RADIOLIB_SX126X_SYNC_WORD_PRIVATE,
                          20,    // TX power (dBm)
                          8,     // preamble length
                          1.6);  // TCXO voltage (use 0.0 if no TCXO)

  if (state == RADIOLIB_ERR_NONE) {
    Serial.println(F("Initialise Success!"));
    ws2812b.setPixelColor(0, ws2812b.Color(0, 150, 0));  // GREEN
    ws2812b.show();
  } else {
    ws2812b.setPixelColor(0, ws2812b.Color(150, 0, 0));  // RED
    ws2812b.show();
    Serial.print(F("Initialise Failed, Code "));
    Serial.println(state);
    while (true) {
      delay(10);
    }
  }

  Serial.println(F("Ready!\n"));

  Serial.print("IPEM Plus Plusk MAC Address:\t");
  Serial.println(WiFi.macAddress());

  Serial.println("\nIPEM Plus - LoRa Point-to-Point Messaging");
  Serial.println("Press USER Button to send Message\n");
}

// **************** LOOP ****************
void loop() {

  // Turn off RGB
  ws2812b.clear();  // Turn off RGB
  ws2812b.show();

  // Check for Button Press
  if (digitalRead(User_GP28) == LOW) {

    Serial.print("Button GP28 Pressed\t");
    sendPacket();
  }

  // Check for Button Press
  if (digitalRead(User_GP14) == LOW) {

    Serial.print("Button GP14 Pressed\t");
    sendPacket();
  }  

  // Receive Packet if Payload Available
  receivePacket();

  // Heartbeat & Turn off RGB
  ws2812b.clear();  // Turn off RGB
  ws2812b.show();
}

// ====================== RECEIVE PACKET ======================
void receivePacket() {

  // Try to receive a packet
  int state = radio.receive(payload, sizeof(payload) - 1);  // leave 1 byte for null terminator

  if (state == RADIOLIB_ERR_NONE) {

    ws2812b.setPixelColor(0, ws2812b.Color(0, 150, 0));  // GREEN
    ws2812b.show();

    // Packet received successfully
    payload[sizeof(payload) - 1] = '\0';  // ensure null termination

    Serial.print(F("Received: "));
    Serial.print(F(" RSSI: "));
    Serial.print(radio.getRSSI());
    Serial.print(F(" dBm   SNR: "));
    Serial.print(radio.getSNR());
    Serial.print(F(" dB\tRX: "));
    Serial.println((char*)payload);
    delay(500);
  }
}

// ====================== SEND PACKET ======================
void sendPacket() {

  // Turn off RGB
  ws2812b.clear();  // Turn off RGB
  ws2812b.show();
  delay(250);

  // Build a simple text message
  snprintf((char*)payload, sizeof(payload), "Hello from IPEM Plus %08X  #%lu", WiFi.macAddress(), counter);

  Serial.print(F("Sending: \t\t\tTX: "));
  Serial.println((char*)payload);

  int state = radio.transmit(payload, strlen((char*)payload));

  if (state == RADIOLIB_ERR_NONE) {
    ws2812b.setPixelColor(0, ws2812b.Color(0, 0, 150));  // BLUE
    ws2812b.show();
  } else {
    ws2812b.setPixelColor(0, ws2812b.Color(150, 0, 0));  // RED
    ws2812b.show();
    Serial.print(F("Sending Failed. Code "));
    Serial.println(state);
    while (true) {
      delay(10);
    }
  }

  counter++;
  delay(500);
}