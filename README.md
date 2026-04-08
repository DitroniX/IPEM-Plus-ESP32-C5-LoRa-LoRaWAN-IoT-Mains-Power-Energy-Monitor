# IPEM Plus - ESP32-C5 | ATM90E36 | WiFi 2.4/5GHz | Zigbee | LoRa | IoT Mains Power Energy Monitor
**Supporting STEM Electronic Internet of Things & Home Automation Technology for Smart Energy Monitoring**

[![DitroniX WiKi Pages](https://github.com/DitroniX/IPEM-Plus-ESP32-C5-LoRa-LoRaWAN-IoT-Mains-Power-Energy-Monitor/blob/main/Datasheets%20and%20Information/GitHub%20WiKi.png?raw=true)](https://github.com/DitroniX/IPEM-Plus-ESP32-C5-LoRa-LoRaWAN-IoT-Mains-Power-Energy-Monitor/wiki)

[**For Latest Project Updates - Click Here**](https://github.com/DitroniX/IPEM-Plus-ESP32-C5-LoRa-LoRaWAN-IoT-Mains-Power-Energy-Monitor?tab=readme-ov-file#updates)

![IPEM Plus Preview](https://github.com/DitroniX/IPEM-Plus-ESP32-C5-LoRa-LoRaWAN-IoT-Mains-Power-Energy-Monitor/blob/main/Datasheets%20and%20Information/IPEM%20Plus%20-%20Overview.png)

## Welcome to IPEM Plus

The new **IPEM Plus** STEM board has been launched, with availability in April.

**IPEM Plus**  is a powerful ATM90E36 Smart Home and Industry Automation, [Mains Power Energy Monitor](https://github.com/DitroniX/IPEM-Plus-ESP32-C5-LoRa-LoRaWAN-IoT-Mains-Power-Energy-Monitor/wiki/What-is-a-Power-Energy-Monitor%3F) Board, and Kit.

### Standalone or Integrated Remote

**IPEM Plus**  has been designed to easily monitor, and offer a flexible interface too, a whole range mains installations.

The **IPEM Plus** is a 'standalone board', where its ESP32-C5, interfaces with ESPHome firmware (as an example).. If preferred, you could easily send MQTT messages.  As it is ESP based, it will just power up and work.  No waiting to boot up.

**IPEM Plus** runs locally, or via Home Assistant, Domoticz etc., or via IoT remote service. It is totally down the user as to which option is taken. Firmware is developed for example using Arduino IDE, PlatformIO (VS Code), ESP-IDF or ESPHome. Other local/remote platforms which have been used also include LabVIEW and Zabbix. Using the LoRa integration, MQTT type messages could be integrated locally or remotely. 

Using the [RS485 interface](https://github.com/DitroniX/IPEM-Plus-ESP32-C5-LoRa-LoRaWAN-IoT-Mains-Power-Energy-Monitor/wiki/RS%E2%80%90485), messages could also be sent locally over a 'twisted pair', up to typical maximum distance of 1,200 meters (4000 feet). This is ideal for local hard wired installations where multiple **IPEM Plus** boards, and other RS485 devices, could sit on the same multi-point network.

**Home | Industry | Housing | Educational | Farming | Agriculture | Solar | Energy**

Using its 2.4GHz and 5GHz Wi-Fi, Thread and Zigbee ESP32-C5 radio module, you can use the **IPEM Plus** to connect to a whole range of Smart Monitoring applications and projects.

Extending further, the built-in LoRa radio opens up long range and remote monitoring.

### How does the Power Energy Monitor Work?

A power energy monitor is a device that safely samples the [AC Voltage, and Current flow](https://github.com/DitroniX/IPEM-Plus-ESP32-C5-LoRa-LoRaWAN-IoT-Mains-Power-Energy-Monitor/wiki/What-is-a-Power-Energy-Monitor?), from one, or more, electrical phases, and from this, derives a range of accurate mains power measurements which can then be used for smart metering, or energy monitoring purposes.

These individual measurements can then be extrapolated into a range of useful real-time data such as total RMS Power, Active, Re-Active Power, Harmonic Power, Power Factor, Phase Angles, Frequency, etc.

This real-time data can then be sent via Wi-Fi, Lora, or RS485, through to IoT Home and Industrial Energy Monitoring systems like [Home Assistant](https://www.home-assistant.io/docs/energy/).

### IPEM Continuity

Following in the footsteps of the original popular [IPEM boards](https://github.com/DitroniX/IPEM-IoT-Power-Energy-Monitor), this **IPEM Plus** is the latest in IoT Mains Energy Monitoring for Home and Industry Automation.

**IPEM Plus** is a self-contained ESP32-C5 based IoT monitoring board. Ideal for local, or remoting, monitoring requirements.

**IPEM Plus** connectivity allows Wi-Fi connections to 2.4GHz or 5GHz, with Bluetooth, Thread and Zigbee.  In addition, you may also use the inbuilt LoRa Radio IoT 850 MHz through to 930 MHz.

**IPEM Plus** is the replacement to the original [IPEM boards](https://github.com/DitroniX/IPEM-IoT-Power-Energy-Monitor)

## [Compare Mains Power IoT Energy Monitors](https://github.com/DitroniX/IPEM-Plus-ESP32-C5-LoRa-LoRaWAN-IoT-Mains-Power-Energy-Monitor/wiki/Compare-Mains-Power-IoT-Energy-Monitors)

## *Preview*
![PREVIEW of IPEM Plus in DIN Enclosure Accessories](https://github.com/DitroniX/IPEM-Plus-ESP32-C5-LoRa-LoRaWAN-IoT-Mains-Power-Energy-Monitor/blob/main/Datasheets%20and%20Information/IPEM%20Plus%20in%20DIN%20Enclosure%20(Accessories).png)

## User Interface

**IPEM Plus** has been designed to interface the [Display User Panel](https://github.com/DitroniX/Display-User-Panel-Switches-LEDs-MicroSD)

## Overview

### Built to Reliably Stand-Alone, with Instant Power Up and Low Power

**IPEM Plus** includes the latest upgraded Espressif ESP32-C5, which has all the many features of the ESP32-C6, but with the dual band 2.4 GHz and 5 GHz Wi-fi. Bluetooth, Thread and Zigbee. 

The ESP32-C5 MCU enables the **IPEM Plus** to run as a low power, reliable, self-contained monitoring board.   Ideal for local or remoting monitoring requirements.  Powered from local DC or AC.

### Current Monitoring and Interfaces
Expanding the mains current sensors, either CT Clamps, or Rogowski Current Transformers, maybe connected. This allows for **IPEM Plus** to be used for both lower current Home systems and Industrial or commercial installations, which require higher current monitoring in hundreds of Amps.

![IPEM Plus Currrent Monitors](https://github.com/DitroniX/IPEM-Plus-ESP32-C5-LoRa-LoRaWAN-IoT-Mains-Power-Energy-Monitor/blob/main/Datasheets%20and%20Information/IPEM%20Plus%20-%20Current%20Monitoring.png)

 - The accurate **[Atmel ATM90E36](https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-46004-SE-M90E36A-Datasheet.pdf)** is used for Enhanced Poly-Phase High-Performance Wide-Span Energy Metering, with fast SPI data communications to an Espressif **ESP32-C5 MCU**.
 - The board can **safely monitor a range of mains AC circuits**, from Single phase, Split or Dual phase (such as USA), and both types of Three phase, Star and Delta. Full 50 Hz and 60 Hz.
 - An onboard accurate **16bit ADC** allows for monitoring of DC voltages up to 80V.
   
 - The **RS485** port allows interfacing to other local or remote sensors and monitors.
 
 - Accurate **Real Time Clock** DS3231SN, with Battery Backup Option.
   
 - A **galvanically isolated OPTO output** can be used to safely connect or drive a range of external systems or devices.
   
 - Two **expansion ports**, SPI and I2C, facilitate an optional display panel
 
 -  **MicroSD card**, for buffering or logging data.  This is mounted in the display panel.
   
 - The IPEM Plus has been designed to be compact, with an option to fit into a **DIN enclosure**, for cabinet or rack installations.
   
 ### Safety First
As with all our boards, safety is paramount, with AC sensing being from lower voltage inputs, through galvanically isolated mains transformers. Examples are bell transformers. This allows the IPEM Plus to fully safely function at voltages below 20V.  

## AC Monitoring
All AC Mains is safely and galvanically isolated using a low voltage transformer.  Examples are bell transformers.

### Supports AC Monitoring Around The [World](https://en.wikipedia.org/wiki/Mains_electricity_by_country)

-   **Europe and UK** which typically is 230 V @ 50 Hz
    -   With ranges around 216 V to 253 V
    
-   **USA and Canada** which typically is 120 V or 230 V @ 60 Hz
    -   With ranges around 114 V to 126 V

-   **Japan** which typically is 100 V @ 50 Hz or 60 Hz
    -   Eastern Japan is 50 Hz, and Western Japan is 60 Hz
-   **World** typically is 220V-240 V @ 50 Hz

### Where can IPEM Plus be used?

The IPEM  Plus board can be used in a number of projects and installations such as:

-   Homes
    
-   Education
    
-   Offices
    
-   Commercial
    
-   Factories
    
-   Farms
    
-   EV Charging
    
-   Smart Metering
    
-   Greenhouses
    
-   Factories
    
-   Industry
    
-   Solar Farms
    
-   Wind Farms
    
-   Off Grid Systems

- Remote and/or Hill Top Sites


### LoRa Long Range IoT Data Radio Integration

In addition, to compliment the powerful C5 radio, the **IPEM Plus** has an onboard LoRa SX1262 Transceiver Radio. 

This allows **IPEM Plus** to be also used on remote Power Energy Monitoring projects, using the integrated [LoRa and LoRaWan](https://github.com/DitroniX/IPEM-Plus-ESP32-C5-LoRa-LoRaWAN-IoT-Mains-Power-Energy-Monitor/wiki/Lora-Topology-Overview) long range wireless network. This includes networks such as [TTN](https://www.thethingsnetwork.org/), [Meshtastic](https://meshtastic.org/), [Helium](https://www.helium.com/iot) and [ChirpStack](https://www.chirpstack.io/).

![Lora Topology Overview](https://github.com/DitroniX/DitroniX/blob/main/Files/DitroniX.net%20Lora%20Topology%20Overview.png)

The LoRa radio module operates from 850 MHz through to 930 MHz, so providing worldwide capability.  This uses the LoRa module E22-900M22S, incorporating the Semtech SX1262.

Example  [bands](https://www.thethingsnetwork.org/docs/lorawan/frequencies-by-country/):

-   AS923 (AS1) band (920-923 MHz) in Japan, Malaysia, Singapore
-   AS923 (AS2) band (915–928 MHz) in Asia
-   AU915 band (915–928 MHz) in South America
-   CN779 band (779-787 MHz) in China
-   EU868 band (863–870 MHz) in Europe
-   IN865 band (865-867 MHz) in India
-   KR920 band (920-923 MHz) in Korea
-   RU864 band (864-870 MHz) in Russia
-   US915 band (902–928 MHz) in North America

### LoRa Long Satellite IoT

The **IPEM Plus** LoRa Wireless includes the expanded Satellite IoT range, enabling direct-to-satellite IoT connectivity, with suitable installation antenna.

![Lora Satellite Overview](https://github.com/DitroniX/DitroniX/blob/main/Files/DitroniX.net%20Lora%20Satellite%20Overview.png)

Suitable circular polarized antenna will be required.

This is really exciting, especially for those who wish to have really remote site monitoring and explore the available technology options.

## Updates

-   26-04-08 - Pre-Production Board Arrived and in Test.
-   26-03-29 - Preview Overview Released
-   26-03-20 - Pre-Production boards in SMT fabrication, for final testing.
-   26-03-15 - Beta Development Complete
-   26-02-15 - In Beta Development 
-   26-02-01 - Project Launched

## Preliminary Information and Spec to follow 

[Feature List Comparison](https://github.com/DitroniX/IPEM-Plus-ESP32-C5-LoRa-LoRaWAN-IoT-Mains-Power-Energy-Monitor/wiki/Compare-Mains-Power-IoT-Energy-Monitors)

### Availability

**IPEM Plus, along with the optional Display Board and DIN enclosure, will be available for purchase in April 2026.**

## **Further Information**

Additional information, and other technical details on this project, maybe found in the related repository pages.

**Repository Folders**

 - **Code** *(Code examples for Arduino  IDE, PlatformIO)*
 -  **Datasheets and Information** *(Component Datasheets, Schematics, Board Layouts, Photos, Technical Documentation)*
 - **Certification** *(Related Repository Project or Part, Certification Information)*

**Repository Tabs**

 - **Wiki** *(Related Repository Wiki pages and Technical User Information)*
 - **Discussions** *(Related Repository User Discussion Forum)*
 - **Issues** *(Related Repository Technical Issues and Fixes)*

***

We value our Customers, Users of our designs and STEM Communities, all over the World . Should you have any other questions, or feedback to share to others, please feel free to:

* Visit the related [Project](https://github.com/DitroniX?tab=repositories) *plus the related* **Discussions** and **Wiki** Pages.  See tab in each separate repository.
* **Project Community Information** can be found at https://www.hackster.io/DitroniX
* [DitroniX.net Website - Contact Us](https://ditronix.net/contact/)
* **Twitter**: [https://twitter.com/DitroniX](https://twitter.com/DitroniX)
* [Supporting the STEM Projects - BuyMeACoffee](https://www.buymeacoffee.com/DitroniX)
*  **LinkedIN**: [https://www.linkedin.com/in/g8puo/](https://www.linkedin.com/in/g8puo/)

***Dave Williams, Maidstone, UK.***

Electronics Engineer | Software Developer | R&D Support | RF Engineering | Product Certification and Testing | STEM Ambassador

## STEM

**Supporting [STEM Learning](https://www.stem.org.uk/)**
