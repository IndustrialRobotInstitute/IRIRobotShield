#include <Robot.h>

Robot myRobot;

void setup() {
  Serial.begin(115200);
  myRobot.motorStop();
}

void loop() {
  // Drive forward with PWM 128
  myRobot.driveForward(128);
  delay(2000);
  myRobot.motorStop();
  delay(1000);
  
  // Drive backward with PWM 128
  myRobot.driveBackward(128);
  delay(2000);
  myRobot.motorStop();
  delay(1000);
  
  // Drive left with PWM 128
  myRobot.driveLeft(128);
  delay(2000);
  myRobot.motorStop();
  delay(1000);
  
  // Drive right with PWM 128
  myRobot.driveRight(128);
  delay(2000);
  myRobot.motorStop();
  delay(1000);
  
  // Drive slow left with PWM 64
  myRobot.driveSlowLeft(64);
  delay(2000);
  myRobot.motorStop();
  delay(1000);
  
  // Drive slow right with PWM 64
  myRobot.driveSlowRight(64);
  delay(2000);
  myRobot.motorStop();
  delay(1000);
}
