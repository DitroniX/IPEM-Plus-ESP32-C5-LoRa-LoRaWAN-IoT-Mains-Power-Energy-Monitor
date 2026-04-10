/*
  Dave Williams, DitroniX 2019-2026 (ditronix.net)
  IPEM Plus - ESP32-C5 | ATM90E36 | WiFi 2.4/5GHz | Zigbee | LoRa | IoT Mains Power Energy Monitor

  Example Code, to demonstrate and test the IPEM Plus
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
#include <RadioLib.h>
#include <SPI.h>

// **************** USER VARIABLES / DEFINES / STATIC / STRUCTURES / CONSTANTS ****************

// Pin definitions
#define SPI_MOSI 8
#define SPI_MISO 9
#define SPI_SCK 10
#define SPI_CS 6

#define E22_IRQ 13
#define E22_NRST 5
#define E22_BUSY 4

SX1262 radio = new Module(SPI_CS, E22_IRQ, E22_NRST, E22_BUSY);

// **************** SETUP ****************
void setup()
{
  Serial.begin(115200);

  SPI.begin(SPI_SCK, SPI_MISO, SPI_MOSI, SPI_CS);

  Serial.print(F("\n[SX1262] Initializing ... "));

  int state = radio.begin(868.0);
  if (state == RADIOLIB_ERR_NONE)
  {
    Serial.println(F("success!"));
  }
  else
  {
    Serial.print(F("failed, code "));
    Serial.println(state);
    while (true)
    {
      delay(10);
    }
  }

  Serial.print("\nSending Packet\n");

  radio.setOutputPower(10);

  Serial.println("IPEM Plus Bring Up and Test Example Code");
}

// **************** LOOP ****************
void loop()
{
  Serial.print("\nSending Packet\n");
  Serial.print(F("startTransmit code "));
  int transmissionState = radio.startTransmit("Hello World!");
  Serial.println(transmissionState);
  Serial.println("Test End\n");

  delay(2000);
}