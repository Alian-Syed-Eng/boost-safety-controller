# boost-safety-controller
Arduino-based boost monitoring and hardware overboost cut system with LCD display and hysteresis

# Embedded Boost Safety Controller

An Arduino-based embedded system designed to monitor boost pressure, display real-time values, and activate a hardware boost cut when unsafe pressure levels are detected.

# Overview

This project simulates an automotive boost safety system using analog input to represent manifold pressure. The system converts voltage into pressure (PSI), displays values on a 16×2 LCD, and triggers a hardware boost cut using a transistor when an overboost condition occurs.

Key design goals:
- Real-time boost monitoring
- Clear user feedback via LCD
- Hardware-level safety response
- Stable operation using hysteresis

# Features

- Real-time boost pressure display (PSI)
- Overboost detection at 20 PSI
- Hysteresis to prevent output flicker
- Hardware boost cut using NPN transistor
- LCD status display (SAFE / OVERBOOST)
- Startup self-test screen
- Modular and expandable design

# Highlights

- Analog signal conditioning
- ADC-to-pressure calibration
- Hysteresis-based state control
- Hardware output driving (transistor)
- Embedded C++ (Arduino)
- Breadboard-based prototyping

# Hardware Used

- Arduino Uno
- 16×2 LCD (HD44780 compatible)
- NPN transistor (2N3904)
- Resistors (10kΩ, 330Ω, 220Ω)
- Capacitors (0.033 µF)
- Joystick module (used as analog input)
- LEDs
- Breadboard & jumper wires


# Applications

- Automotive boost safety systems
- Embedded monitoring systems
- Hardware-interlocked safety controllers
- Educational embedded systems projects

# Future Improvements

- Real MAP sensor integration
- EEPROM-configurable thresholds
- PWM-controlled solenoid output
- PCB design version

---

