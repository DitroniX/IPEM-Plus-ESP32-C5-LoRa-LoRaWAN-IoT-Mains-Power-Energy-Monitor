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
#include <GyverOLED.h>
#include <Adafruit_NeoPixel.h>

// **************** USER VARIABLES / DEFINES / STATIC / STRUCTURES / CONSTANTS ****************

// Define I2C (Expansion Port)
#define I2C_SDA 2
#define I2C_SCL 3

// RGB
#define PIN_WS2812B 27  // The ESP32-C6 pin GPIO8 connected to WS2812B
Adafruit_NeoPixel ws2812b(1, PIN_WS2812B, NEO_GRB + NEO_KHZ800);

// **************** MIXED MODE INPUT/OUTPUT ****************
#define User_GP14 14

// OLED Instance. You will need to select your OLED Display. 
// Uncomment/Comment as needed.
GyverOLED<SSD1306_128x32, OLED_BUFFER> oled;  //0.6"
//GyverOLED<SSD1306_128x32, OLED_NO_BUFFER> oled;
//GyverOLED<SSD1306_128x64, OLED_BUFFER> oled;
//GyverOLED<SSD1306_128x64, OLED_NO_BUFFER> oled;
// GyverOLED<SSH1106_128x64> oled; //1.1"

// Draw Battery
void drawBattery(byte percent) {
  oled.drawByte(0b00111100);
  oled.drawByte(0b00111100);
  oled.drawByte(0b11111111);
  for (byte i = 0; i < 100 / 8; i++) {
    if (i < (100 - percent) / 8) oled.drawByte(0b10000001);
    else oled.drawByte(0b11111111);
  }
  oled.drawByte(0b11111111);
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

  // Configure GPIO Inputs (Default)
  pinMode(User_GP14, INPUT_PULLUP);

  // Initialize I2C
  Wire.begin(I2C_SDA, I2C_SCL);

  ws2812b.begin();  // Initialize WS2812B
  ws2812b.clear();  // Turn off RGB

  Serial.println("IPEM Plus Bring Up and Test Example Code");

  Serial.println("Requires OLED Display to be connected");
}

void loop() {

  // Turn off RGB
  ws2812b.clear();
  ws2812b.show();

  // OLED
  oled.init();
  oled.clear();
  oled.setCursor(15, 0);
  oled.setScale(2);
  oled.print("IPEM Plus");
  oled.update();
  delay(500);

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

  // OLED
  oled.init();
  oled.clear();
  oled.setCursor(15, 1);
  oled.setScale(2);
  oled.print("IPEM Plus");
  oled.update();
  delay(500);

  // OLED
  oled.init();
  oled.clear();
  oled.setCursor(15, 2);
  oled.setScale(2);
  oled.print("IPEM Plus");
  oled.update();
  delay(500);

  // RED
  ws2812b.setPixelColor(0, ws2812b.Color(50, 0, 0));
  ws2812b.show();
  delay(500);

  // OLED
  oled.init();
  oled.clear();
  oled.setCursor(30, 1);
  oled.setScale(3);
  oled.print("LoRa");
  oled.update();

  // Turn off RGB
  ws2812b.clear();
  ws2812b.show();  // update to the WS2812B Led Strip

  // BLUE
  ws2812b.setPixelColor(0, ws2812b.Color(0, 0, 50));
  ws2812b.show();
  delay(500);

  // OLED
  oled.init();
  oled.clear();
  oled.setCursor(15, 1);
  oled.setScale(2);
  oled.print("IPEM Plus");
  oled.update();
  delay(500);

  // Turn off RGB
  ws2812b.clear();
  ws2812b.show();

  // GREEN
  ws2812b.setPixelColor(0, ws2812b.Color(0, 50, 0));
  ws2812b.show();
  delay(500);

  // Turn off RGB
  ws2812b.clear();
  ws2812b.show();

  // OLED
  oled.init();
  oled.clear();
  oled.setCursor(30, 1);
  oled.setScale(3);
  oled.print("LoRa");
  oled.update();

  delay(500);

  // OLED
  oled.init();
  oled.clear();
  oled.setCursor(20, 1);
  oled.setScale(3);
  oled.print("RS485");
  oled.update();

  delay(500);

  // OLED
  oled.init();
  oled.clear();
  oled.setCursor(19, 1);
  oled.setScale(3);
  oled.print("5-52V");
  oled.update();

  delay(500);

  // OLED
  oled.init();
  oled.clear();
  oled.setCursor(15, 0);
  oled.setScale(2);
  oled.print("IPEM Plus");
  oled.update();
  delay(500);

  // OLED
  oled.init();
  oled.clear();
  oled.setCursor(15, 1);
  oled.setScale(2);
  oled.print("GPIO");
  oled.update();
  delay(500);

  // GP LED - Mixed Mode GPIO
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

  // OLED
  oled.init();
  oled.clear();
  oled.setCursor(15, 2);
  oled.setScale(2);
  oled.print("GPIO");
  oled.update();
  delay(500);

  delay(500);

  // OLED
  oled.init();
  oled.clear();
  oled.setCursor(13, 1);
  oled.setScale(2);
  oled.print("GPIO");
  oled.update();

  delay(500);
}
