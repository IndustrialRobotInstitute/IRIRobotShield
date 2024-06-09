# Robot Library

This is the `Robot` library for Arduino IRI shield, which simplifies the control of various components like LEDs, buttons, buzzer, ultrasonic sensor, servos, analog and digital sensors, and motors.

## Installation

### Using Arduino Library Manager

1. Open the Arduino IDE.
2. Go to `Sketch` -> `Include Library` -> `Manage Libraries...`.
3. Search for "Robot" and click the `Install` button.

### Using GitHub Repository

1. Open the Arduino IDE.
2. Go to `File` -> `Preferences` (on Windows) or `Arduino` -> `Preferences` (on macOS).
3. In the Preferences window, find the field labeled "Additional Boards Manager URLs".
4. Paste the following URL: `https://github.com/yourusername/Robot.git`.
5. Click `OK` to close the Preferences window.
6. Go to `Sketch` -> `Include Library` -> `Manage Libraries...`.
7. Search for "Robot" and click the `Install` button.

## Usage

Include the library in your sketch:

```cpp
#include <Robot.h>

Robot myRobot;

void setup() {
  Serial.begin(115200);
}

void loop() {
  myRobot.lightOn(1);
  delay(1000);
  myRobot.lightOff(1);
  delay(1000);
}
Refer to the examples folder for more usage examples.

Examples
LED Control: Control LEDs connected to your Arduino board.
Button Status: Read the status of buttons.
Buzzer Control: Control a buzzer to produce sounds.
Ultrasonic Sensor: Measure distance using an ultrasonic sensor.
Servo Control: Control servo motors for precise movements.
Analog Sensor Reading: Read analog sensor values.
Digital Sensor Reading: Read digital sensor values.
Motor Control: Control motors for driving mechanisms.
Contributing
Contributions are welcome! If you find any issues or have suggestions for improvement, please create an issue or pull request on GitHub.

License
This library is released under the MIT License. See the LICENSE file for details.
