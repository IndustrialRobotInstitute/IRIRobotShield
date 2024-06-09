#include <Robot.h>

Robot myRobot;

void setup() {
  // Nothing to initialize
}

void loop() {
  // Set Servo1 to 90 degrees
  myRobot.ServoSetAngle(1, 90);
  delay(1000);
  
  // Set Servo1 to 0 degrees
  myRobot.ServoSetAngle(1, 0);
  delay(1000);
  
  // Sweep Servo2 from 0 to 180 degrees
  myRobot.ServoSweep(2, 0, 180, 10);
}
