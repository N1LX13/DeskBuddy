# DeskBuddy

DeskBuddy is a small animated desk companion built with an Arduino and an OLED screen. It shows a friendly little face, changes mood over time, reacts to button presses, and cycles through playful activities like coding, singing, thinking, and dancing.

It is a fun project for learning Arduino, OLED graphics, and simple state-driven animation.

## Features

- Animated face with blinking eyes and moving mouth
- Mood states: happy, bored, sad, sleepy, and excited
- Random activities such as coding, singing, thinking, and dancing
- Button interaction to "pet" the buddy and improve its mood
- Simple, lightweight behavior loop with no external dependencies beyond the Adafruit libraries

## Hardware required

- Arduino Uno / Nano / compatible board
- 128x64 I2C OLED display (SSD1306)
- Push button
- Breadboard and jumper wires
- 5V power source

## Wiring

For a standard Arduino Uno:

- OLED VCC -> 5V
- OLED GND -> GND
- OLED SDA -> A4
- OLED SCL -> A5
- Button -> digital pin 6
- Other side of button -> GND

The sketch uses `INPUT_PULLUP` on pin 6, so the button can be wired directly to ground without needing an extra pull-up resistor.

## Software

1. Install the Arduino IDE.
2. Install the following libraries:
   - Adafruit GFX Library
   - Adafruit SSD1306
3. Open `DeskBuddyGit.ino` in the Arduino IDE.
4. Select your board and serial port.
5. Click Upload.

## How it behaves

- The face starts in a happy state and displays a greeting.
- Over time, energy decreases and boredom increases.
- If the buddy gets too tired, it falls asleep.
- If you press the button, it reacts with a happy petting animation and improves its mood.
- During idle periods, it may start random activities and say different phrases.

## Project structure

- `DeskBuddyGit.ino` — the complete Arduino sketch
- `README.md` — project overview and usage instructions

## Example use cases

- Desk companion for your workbench or desk
- Interactive learning project for Arduino and displays
- A playful prototype for a character-based gadget

## Notes

This project is intentionally simple and easy to customize. You can change the phrases, animation timing, mood logic, or add more activities to make DeskBuddy feel more unique.

If you want to expand it further, possible upgrades include:

- more facial expressions
- sound effects or a speaker
- motion sensors
- custom mood triggers based on environmental input

## License

This project is provided as-is for personal and educational use, and is open for modification and remixing.
