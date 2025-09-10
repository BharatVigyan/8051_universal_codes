# DHT11 8051 Library

This repository contains the **DHT11 temperature and humidity sensor library** for 8051 microcontrollers. It provides easy-to-use functions to interface the DHT11 sensor with 8051-based projects.

---

## Features

- Read **temperature** in Celsius.
- Read **humidity** in percentage.
- Compatible with **standard 8051 microcontrollers**.
- Easy integration with your existing projects.

---

## Connections

| DHT11 Pin | 8051 Microcontroller Pin |
|-----------|-------------------------|
| VCC       | 5V                      |
| GND       | GND                     |
| DATA      | P1.0 (or any GPIO pin)  |

> Make sure to add a **10kΩ pull-up resistor** on the DATA line.

---

## Usage

1. Include the library in your project.  
2. Initialize the DHT11 sensor in your main program:

```c
#include "DHT11.h"

void main() {
    DHT11_Init();  // Initialize sensor
    int temperature = DHT11_ReadTemperature();
    int humidity = DHT11_ReadHumidity();
}
```
<a href="https://www.buymeacoffee.com/bkasyap" target="_blank"><img src="https://cdn.buymeacoffee.com/buttons/v2/default-blue.png" alt="Buy Me A Coffee" style="height: 60px !important;width: 217px !important;" ></a>
