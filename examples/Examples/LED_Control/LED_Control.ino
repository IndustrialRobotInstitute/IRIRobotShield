#include <Robot.h>

Robot myRobot;

void setup() {
  Serial.begin(115200);
}

void loop() {
  // Turn on each LED one by one
  for (int i = 1; i <= 6; i++) {
    myRobot.lightOn(i);
    delay(500);
    myRobot.lightOff(i);
    delay(500);
  }
}
