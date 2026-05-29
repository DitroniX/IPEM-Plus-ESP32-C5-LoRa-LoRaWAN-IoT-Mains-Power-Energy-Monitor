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

// Libraries
#include <Arduino.h>
#include <Wire.h>
#include <ADS1115_WE.h>  // https://github.com/wollewald/ADS1115_WE

// ****************  VARIABLES / DEFINES / STATIC / STRUCTURES / CONSTANTS ****************

// ******************************** DATA ********************************

// Define I2C (Expansion Port)
#define I2C_SDA 2
#define I2C_SCL 3
#define I2C_CLOCK 4000000UL

// ******************************** ADC ********************************
// Default ESPKnack ADS1115 Address
#define ADS1115_Address 0x49

// Variables User
const int AverageSamples = 50;  // Average Multi-Samples on each Channel Read.  (Default 50)
const int AverageDelay = 10;    // Average Inter Multi-Sample ms Delay.  (Default 10)

// Voltage Factoring (Values will vary slightly due to passive tolerances)
const float DCVoltageFactor = 9.0588235;  // DC Input Scaled Multiplier (Default 9.0588235)
const float ADCVoltageFactor = 24.10500;  // DC Input Scaled Multiplier (Default 24.10500)

// Current User
const float DCCurrentFactor = 6.369427;  // Current Scaling Adjustment.  (Default 6.369427)
const float DCCurrentOffset = -0.01;     // Current Zero Calibration Offset (Default -0.01)
const float DCCurrentThreshold = 0.63;   // Minimum Current - removing noise.  (Default 0.63)

// Externs - No Change
float DCVoltageDrop = 0.54;  // Schottky Diodes on 60V Net.

// **************** INSTANCES ****************

ADS1115_WE adc = ADS1115_WE(ADS1115_Address);  // 16bit ADC

// ADC Channels
// * Channel 0 - DC Voltage Input
// * Channel 1 - ADC1+
// * Channel 2 - ADC2+
// * Channel 3 - ADC3+

// **************** FUNCTIONS AND ROUTINES ****************

// Initialise IBEM ADS1115 ADC (Default Address 0x48)
void Initialise_ADS1115_ADC() {

  Serial.println("Initialising ADC\n");

  // Functions https://github.com/wollewald/ADS1115_WE/blob/master/List%20of%20public%20functions.pdf

  /* Set the voltage range of the ADC to adjust the gain
   * ADS1115_RANGE_6144  ->  +/- 6144 mV 2/3x gain +/- 6.144V  1 bit = 0.1875mV
   * ADS1115_RANGE_4096  ->  +/- 4096 mV (default) 1x gain   +/- 4.096V  1 bit = 0.125mV
   * ADS1115_RANGE_2048  ->  +/- 2048 mV +/- 2.048V  1 bit = 0.0625mV
   * ADS1115_RANGE_1024  ->  +/- 1024 mV +/- 1.024V  1 bit = 0.03125mV
   * ADS1115_RANGE_0512  ->  +/- 512 mV +/- 0.512V  1 bit = 0.015625mV
   * ADS1115_RANGE_0256  ->  +/- 256 mV +/- 0.256V  1 bit = 0.0078125mV
   */

  adc.setVoltageRange_mV(ADS1115_RANGE_4096);  // (Default ADS1115_RANGE_4096)
  adc.setCompareChannels(ADS1115_COMP_0_GND);
  adc.setMeasureMode(ADS1115_CONTINUOUS);
  adc.setConvRate(ADS1115_128_SPS);

}  // Initialise_ADS1115_ADC

// Read and Calculate Average Value with Reduce Jitter
float readChannel(ADS1115_MUX channel) {
  float VoltageRaw = 0.0;

  adc.setCompareChannels(channel);

  for (int i = 0; i < AverageSamples; i++) {
    VoltageRaw = VoltageRaw + adc.getResult_V();
    delay(AverageDelay);
  }
  VoltageRaw = VoltageRaw / AverageSamples;
  return VoltageRaw;
}  // readChannel

// **************** SETUP ****************
void setup() {
  // Stabalise
  delay(250);

  // Initialise UART
  Serial.begin(115200, SERIAL_8N1);  // 115200
  while (!Serial)
    ;
  Serial.println("");

  // Initialise I2C
  Wire.begin(I2C_SDA, I2C_SCL);
  Wire.setClock(I2C_CLOCK);  // 400kHz | Standard-mode (Sm) and Fast-mode (Fm) which can go up to 100kHz and 400kHz respectively

  Initialise_ADS1115_ADC();

  Serial.println("IPEM Plus Bring Up and Test Example Code");
}

// **************** LOOP ****************
void loop(void) {
  float ADCV0, ADCV1, ADCV2, ADCV3, VoltageRaw, DCVoltage;

  // Read all ADC Channels
  ADCV0 = readChannel(ADS1115_COMP_0_GND);
  ADCV1 = readChannel(ADS1115_COMP_1_GND);
  ADCV2 = readChannel(ADS1115_COMP_2_GND);
  ADCV3 = readChannel(ADS1115_COMP_3_GND);

  // Display Raw Values
  // Heading
  Serial.println("RAW ADC ADS1115 Input Voltages");
  Serial.print("ADC0\t");
  Serial.print("ADC1\t");
  Serial.print("ADC2\t");
  Serial.print("ADC3");
  Serial.println();
  Serial.print("VIN\t");
  Serial.print("ADC1+\t");
  Serial.print("ADC2+\t");
  Serial.print("ADC3+");
  Serial.println();

  // Reading
  Serial.print(ADCV0);
  Serial.print("\t");
  Serial.print(ADCV1);
  Serial.print("\t");
  Serial.print(ADCV2);
  Serial.print("\t");
  Serial.print(ADCV3);
  Serial.println();

  Serial.println();

  // ----------------------------------------------------

  // ADCV0 - Output Expressed Values
  DCVoltage = (ADCV0 * DCVoltageFactor) + DCVoltageDrop;

  if (DCVoltage < 0.010) DCVoltage = 0;  // Remove Noise

  Serial.print("VIN Calculated: \t");
  Serial.print(DCVoltage);
  Serial.print("V");

  Serial.print("\t ADC0 Voltage Scaled : \t");

  if (DCVoltage < 5.5)
    Serial.println("(USB Powered)");

  if (DCVoltage > 5.5)
    Serial.println("(DC/AC Powered)");

  // ----------------------------------------------------

  // ADCV1 0-3V3 - This is normally floating as the input just goes to a test pad.
  DCVoltage = ADCV1;

  if (DCVoltage < 0) DCVoltage = 0;  // Remove Noise

  Serial.print("ADC1 Calculated: \t");
  Serial.print(DCVoltage);
  Serial.print("V");

  DCVoltage = (ADCV1 * ADCVoltageFactor) + DCVoltageDrop;

  if (DCVoltage < 0.65) DCVoltage = 0;

  Serial.print("\t ADC1 Voltage Scaled : \t");
  Serial.print(DCVoltage);
  Serial.println("V (Default Floating Input)");

  // ----------------------------------------------------

  // ADCV2 0-3V3
  DCVoltage = ADCV2;

  if (DCVoltage < 0) DCVoltage = 0;  // Remove Noise


  Serial.print("ADC2 Calculated: \t");
  Serial.print(DCVoltage);
  Serial.print("V");

  DCVoltage = (ADCV2 * ADCVoltageFactor) + DCVoltageDrop;

  if (DCVoltage < 0.65) DCVoltage = 0;

  Serial.print("\t ADC2 Voltage Scaled : \t");
  Serial.print(DCVoltage);
  Serial.println("V");

  // ----------------------------------------------------

  // ADCV3 0-3V3
  DCVoltage = ADCV3;

  if (DCVoltage < 0) DCVoltage = 0;  // Remove Noise

  Serial.print("ADC3 Calculated: \t");
  Serial.print(DCVoltage);
  Serial.print("V");

  DCVoltage = (ADCV3 * ADCVoltageFactor) + DCVoltageDrop;

  if (DCVoltage < 0.65) DCVoltage = 0;

  Serial.print("\t ADC3 Voltage Scaled : \t");
  Serial.print(DCVoltage);
  Serial.println("V");


  Serial.println("----------------------------------------------------\n");

  delay(1000);
}
