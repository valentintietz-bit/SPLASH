# Smart Weather & Water Drainage Unit for Flat Roofs

## Overview

This project implements a **self-powered, autonomous system** designed to monitor environmental conditions and **drain stagnant water** from flat rooftops. It combines multiple sensors to collect real-time weather data and automatically activates a pump when necessary.

Ideal for smart building applications and environmental monitoring, the device runs on an ESP32 and uses FreeRTOS to handle concurrent sensor reading and pump control tasks.

---

## Features

* Real-time measurement of:

  * Temperature
  * Atmospheric pressure
  * Humidity
  * Rain detection
  * Light intensity
  * Water level
* Automatic water pump activation when water level is high
* Uses FreeRTOS to run tasks on separate CPU cores
* Designed to be solar-powered or battery-operated
* Data output via Serial (can be extended to wireless/cloud)

---

## Hardware Requirements

* ESP32 development board
* BME280 (temperature, pressure, humidity sensor)
* BH1750 (light intensity sensor)
* Rain sensor (analog)
* Water level sensor (digital)
* Relay or MOSFET module to control a pump
* Water pump (low-voltage)
* Power source (battery/solar panel)
* Wires, connectors, enclosure (for outdoor use)

---

## Software Requirements

* Arduino IDE with the following libraries:

  * `Wire.h`
  * `Adafruit_BME280.h`
  * `Adafruit_Sensor.h`
  * `BH1750.h`
* FreeRTOS (included in ESP32 core)

---

## How It Works

1. The ESP32 continuously reads data from environmental sensors.
2. If the water level sensor detects standing water, the pump is automatically activated to evacuate it.
3. Weather data is logged to the Serial monitor every 2 seconds.
4. The system uses **FreeRTOS tasks pinned to separate cores** for better performance:

   * Sensor readings on Core 0
   * Pump control on Core 1

---

## Usage

1. Upload the code to your ESP32 using the Arduino IDE.
2. Power the system (e.g. via battery or solar panel).
3. Open the Serial Monitor (115200 baud) to view live weather data and pump status.
4. When standing water is detected, the pump will automatically turn on for a fixed duration (e.g., 5 seconds).

---

## Author

* **Valentin TIETZ**

---

