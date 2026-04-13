# ESP8266 Gas Leakage Detection System

A Wi-Fi-enabled gas leakage detection system built with the ESP8266 microcontroller. It monitors gas/smoke levels via an analog sensor, triggers visual and audio alerts, and serves a real-time web dashboard over your local network.

---

## Features

- Wi-Fi connectivity via ESP8266
- Analog smoke/gas sensor monitoring
- Three-level alert system (No leak → Moderate → High)
- RGB LED indicators (Green / Yellow / Red)
- Buzzer alarm on gas detection
- Built-in web server dashboard (port 80)

---

## Hardware Requirements

| Component | Quantity |
|---|---|
| ESP8266 (e.g., NodeMCU) | 1 |
| MQ-2 / MQ-5 Smoke or Gas Sensor | 1 |
| Red LED | 1 |
| Yellow LED | 1 |
| Green LED | 1 |
| Buzzer | 1 |
| Resistors (220Ω for LEDs) | 3 |
| Jumper Wires + Breadboard | As needed |

---

## Pin Configuration

| Component | ESP8266 Pin |
|---|---|
| Smoke Sensor (Analog) | `A0` |
| Buzzer | `D1` |
| Red LED | `D2` |
| Yellow LED | `D3` |
| Green LED | `D4` |

---

## Software Requirements

- [Arduino IDE](https://www.arduino.cc/en/software)
- ESP8266 Board Package ([Install guide](https://arduino-esp8266.readthedocs.io/en/latest/installing.html))
- Libraries:
  - `ESP8266WiFi`
  - `ESP8266WebServer`

---

## Getting Started

1. Clone this repository:
   ```bash
   git clone https://github.com/sarangmenon947/Gas-Leakage-Detection-System
   ```

2. Create your `credentials.h` file.

3. Open the `.ino` file in Arduino IDE.

4. Select your board: **Tools → Board → NodeMCU 1.0 (ESP-12E Module)**

5. Select the correct COM port under **Tools → Port**.

6. Upload the sketch.

7. Open the Serial Monitor at **115200 baud** to find the assigned IP address.

8. Visit `http://<IP_ADDRESS>` in your browser to access the dashboard.

---

## Alert Logic

| Sensor Reading | LED | Buzzer |
|---|---|---|
| `0` (No gas) | Green ON | OFF |
| `>= 50` (Moderate) | Yellow ON | ON |
| `>= 75` (High) | Red ON | ON |

> **Note:** Threshold values (`noGasLeakage`, `moderateGasLeakage`, `highGasLeakage`) can be adjusted at the top of the sketch to match your specific sensor's output range.

---

## Project Structure

```
├── gas_leakage_detector.ino  
├── credentials.h             
├── .gitignore
└── README.md
```
