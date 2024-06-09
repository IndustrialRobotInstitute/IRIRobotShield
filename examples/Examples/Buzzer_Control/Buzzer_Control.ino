#include <Robot.h>

Robot myRobot;

void setup() {
  Serial.begin(115200);
}

void loop() {
  // Turn on the buzzer
  myRobot.buzzerOn();
  delay(1000);
  
  // Turn off the buzzer
  myRobot.buzzerOff();
  delay(1000);
  
  // Turn on the buzzer with a specific frequency
  myRobot.buzzerOnWithFrequency(1000);
  delay(1000);
  
  // Turn off the buzzer
  myRobot.buzzerOff();
  delay(1000);
}
