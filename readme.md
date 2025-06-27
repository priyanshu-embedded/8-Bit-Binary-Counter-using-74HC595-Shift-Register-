# 8-Bit Binary Counter using 74HC595 and Interrupts

This project demonstrates a binary counter (0–255) using a 74HC595 shift register and an external pushbutton interrupt.

## 🔧 Features
- Uses 74HC595 for serial-to-parallel LED output
- Hardware interrupt with attachInterrupt() on button press
- Debounce handling using millis()
- Clean and responsive code (non-blocking)

## 🔌 Components
- Arduino UNO
- 74HC595 Shift Register
- 8 LEDs
- Pushbutton
- 220K Resistor




## 🧪 Simulation Link
[Click here to view on Wokwi](https://wokwi.com/projects/434894183559524353)


## 📁 Code Highlights

```cpp
attachInterrupt(digitalPinToInterrupt(buttonPin), countUp, FALLING);