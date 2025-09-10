# 8051_universal_codes
This repo have all the coes i have written tested on hwardware and all are working for ready to use in any project related.
# OLED SD1306 I2C Interface on Port 1.0 & 1.1

This repository contains code and resources to interface an **OLED display with the SSD1306 controller** using the **I2C protocol**. The OLED is connected to **Port 1.0 (SCL)** and **Port 1.1 (SDA)** of the microcontroller.

## Features

- Supports SSD1306 OLED displays.
- Communication via **I2C interface**.
- Basic functions implemented:
  - Display text
  - Display numbers
  - Clear screen
  - Simple graphics (optional)
- Easy to integrate with embedded projects.

## Connections

| OLED Pin | Microcontroller Pin |
|----------|------------------|
| SDA      | P1.0             |
| SCL      | P1.1             |
| VCC      | 3.3V / 5V        |
| GND      | GND              |

> Ensure proper voltage compatibility with your OLED module.

## Usage

1. Include the OLED library files in your project.
2. Initialize the OLED in your main program:

```c
OLED_Init();  // Initialize OLED
OLED_Clear(); // Clear display
OLED_WriteString("Hello, World!");
```
<a href="https://www.buymeacoffee.com/bkasyap" target="_blank"><img src="https://cdn.buymeacoffee.com/buttons/v2/default-blue.png" alt="Buy Me A Coffee" style="height: 60px !important;width: 217px !important;" ></a>
