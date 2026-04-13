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

// ---------------------------------------------------------------------------
// Configuration — adjust to match your hardware
// ---------------------------------------------------------------------------
#define LED_GPIO    27          // data pin connected to strip DIN
#define LED_COUNT   2          // number of LEDs in your strip

// ---------------------------------------------------------------------------
// Create the PARLIO-backed strip
// Replace LiteLEDpio with LiteLED to switch to the RMT driver
// ---------------------------------------------------------------------------
LiteLEDpio strip( LED_STRIP_WS2812, false );

// ---------------------------------------------------------------------------
// HSV → RGB helper
// ---------------------------------------------------------------------------
crgb_t HSVtoRGB( uint8_t h, uint8_t s, uint8_t v ) {
    if ( s == 0 ) {
        return ( ( uint32_t )v << 16 ) | ( ( uint32_t )v << 8 ) | v;
    }

    uint8_t region    = h / 43;
    uint8_t remainder = ( h - ( region * 43 ) ) * 6;
    uint8_t p = ( v * ( 255 - s ) ) >> 8;
    uint8_t q = ( v * ( 255 - ( ( s * remainder ) >> 8 ) ) ) >> 8;
    uint8_t t = ( v * ( 255 - ( ( s * ( 255 - remainder ) ) >> 8 ) ) ) >> 8;
    uint8_t r, g, b;

    switch ( region ) {
        case 0:
            r = v;
            g = t;
            b = p;
            break;
        case 1:
            r = q;
            g = v;
            b = p;
            break;
        case 2:
            r = p;
            g = v;
            b = t;
            break;
        case 3:
            r = p;
            g = q;
            b = v;
            break;
        case 4:
            r = t;
            g = p;
            b = v;
            break;
        default:
            r = v;
            g = p;
            b = q;
            break;
    }

    return ( ( uint32_t )r << 16 ) | ( ( uint32_t )g << 8 ) | b;
}

// ---------------------------------------------------------------------------
// setup
// ---------------------------------------------------------------------------
void setup() {
    Serial.begin( 115200 );

    esp_err_t err = strip.begin( LED_GPIO, LED_COUNT );
    if ( err != ESP_OK ) {
        Serial.printf( "LiteLEDpio begin() failed: %s\n", esp_err_to_name( err ) );
        while ( true ) {
            delay( 1000 );
        }
    }

    strip.brightness( 50 );
    strip.clear( true );
}

// ---------------------------------------------------------------------------
// loop — scrolling rainbow
// ---------------------------------------------------------------------------
void loop() {
    static uint8_t hue = 0;

    for ( size_t i = 0; i < LED_COUNT; i++ ) {
        uint8_t pixelHue = hue + ( i * 255 / LED_COUNT );
        strip.setPixel( i, HSVtoRGB( pixelHue, 255, 255 ) );
    }

    strip.show();
    hue += 2;
    delay( 20 );
}