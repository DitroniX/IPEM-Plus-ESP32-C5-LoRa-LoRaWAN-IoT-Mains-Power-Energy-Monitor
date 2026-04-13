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

  For board configuration, see https://github.com/DitroniX/ESPRanger-LoRa-GNSS-GPS-IMU-RS485-60V/wiki/Arduino-IDE

  Further information, details and examples can be found on our website or github.com/DitroniX

  * ditronix.net
  * github.com/DitroniX
  * github.com/DitroniX/IPEM-Plus-ESP32-C5-LoRa-LoRaWAN-IoT-Mains-Power-Energy-Monitor
  * github.com/DitroniX/IPEM-Plus-ESP32-C5-LoRa-LoRaWAN-IoT-Mains-Power-Energy-Monitor/wiki
  * hackster.io/DitroniX/ipem-plus-esp32-c5-atm90e36-lora-iot-power-energy-monitor-24d898
*/

// Libraries
#include <LiteLED.h>

// Choose the LED type from the list below.
// Comment out all but one LED_TYPE.
#define LED_TYPE        LED_STRIP_WS2812
// #define LED_TYPE        LED_STRIP_SK6812
// #define LED_TYPE        LED_STRIP_APA106
// #define LED_TYPE        LED_STRIP_SM16703

#define LED_TYPE_IS_RGBW 0   // if the LED is an RGBW type, change the 0 to 1
#define LED_GPIO 27     // change this number to be the GPIO pin connected to the LED
#define LED_BRIGHT 50   // sets how bright the LED is. O is off; 255 is burn your eyeballs out (not recommended)

// pick the colour you want from the list here and change it in setup()
static const crgb_t L_RED = 0xff0000;
static const crgb_t L_GREEN = 0x00ff00;
static const crgb_t L_BLUE = 0x0000ff;
static const crgb_t L_WHITE = 0xe0e0e0;

LiteLED myLED( LED_TYPE, LED_TYPE_IS_RGBW );    // create the LiteLED object; we're calling it "myLED"

void setup() {
    myLED.begin( LED_GPIO, 1 );         // initialze the myLED object. Here we have 1 LED attached to the LED_GPIO pin
}

void loop() {

    myLED.brightness( 0, 1 );           // turn the LED off

    // Cycle the LEDs
    myLED.setPixel( 0, L_RED, 1 );    // set the LED colour and show it
    delay( 1000 );
    myLED.brightness( LED_BRIGHT, 1 );  // turn the LED on
    delay( 1000 );    

    myLED.setPixel( 0, L_GREEN, 1 );    // set the LED colour and show it
    delay( 1000 );
    myLED.brightness( LED_BRIGHT, 1 );  // turn the LED on
    delay( 1000 );

    myLED.setPixel( 0, L_BLUE, 1 );    // set the LED colour and show it
    delay( 1000 );
    myLED.brightness( LED_BRIGHT, 50 );  // turn the LED on
    delay( 1000 );

    myLED.setPixel( 0, L_WHITE, 1 );    // set the LED colour and show it
    delay( 1000 );
    myLED.brightness( LED_BRIGHT, 1 );  // turn the LED on
    delay( 1000 );

} 
