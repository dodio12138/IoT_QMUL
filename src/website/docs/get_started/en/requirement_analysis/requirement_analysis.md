---
title: Requirement Analysis
---
## Functional Requirements
| Requirements | Priority |
| -------- | -------- |
| Use GPS module to get location coordinate information | Essential |
| Data storage and backup | Essential |
| OLED screen displaying data | Optional |
| Bluetooth matching and transmission | Essential |
| Visual Web Development | Optional |

## Hardware Requirements
### Board selection
The main Boards available in the market are Arduino series, ESP series and STM32 series. Some boards in Arduino and esp are selected for this project, as the project wants the device to be small enough and low power consumption, some types of Boards are selected to be shown in the table below.

| Board Name | PCB Size (mm) | Flash Memory | Wi-Fi | Bluetooth | Power consumption | Price (￡) |
| -------- | -------- | -------- | -------- | -------- | -------- | -------- |
| Arduino Nano[^1] | 18 x 45 x 2.6 | 32 KB | N | N | normal | 21.6 |
| Arduino Nano 33 IoT[^2] | 18 x 45 x 2.6 | 1 MB | Y | Y | low | 22.8 |
| ESP32-C3 mini[^3] | 13.20 × 16.60 x 2.4 | 4 MB | Y | Y | low | 9.90 |

Based on functional requirements, cost and size considerations, the **ESP32-C3 mini** is chosen for this project.
### Other selection
- GPS Module: Ultimate GPS Breakout V3
- Screen: 0.96 Inch OLED I2C Display 128 x 64: Used to display some simple information as well as to develop user interaction possibilities for subsequent extensions.
- Breadboard
- External power supply: As this is a prototype development, no built-in power supply module has been designed, and the project focuses on verifying GPS-related.
- Smartphone
- Jumper Cables and connecting wires

## Software Requirements
- Arduino IDE: ESP supports Arduino for programming, which is obviously more efficient and convenient.
- U8g2 Library for screen development
- TinyGPSPlus Library for GPS development
- HTML + CSS + JS for web design

---
[^1]: https://store.arduino.cc/products/arduino-nano
[^2]: https://store.arduino.cc/products/arduino-nano-33-iot
[^3]: https://www.wemos.cc/en/latest/c3/c3_mini.html