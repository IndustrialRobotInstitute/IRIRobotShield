#include "Robot.h"

Robot myRobot;

void setup() {
  // Initialize the serial communication
  Serial.begin(115200);

  // Stop the motors initially
  myRobot.motorStop();
}

void loop() {
  // Drive forward with half speed
  myRobot.driveForward(128);
  Serial.println("Driving forward with PWM = 128");
  delay(2000);

  // Stop the motors
  myRobot.motorStop();
  Serial.println("Motors stopped");
  delay(1000);

  // Drive backward with half speed
  myRobot.driveBackward(128);
  Serial.println("Driving backward with PWM = 128");
  delay(2000);

  // Stop the motors
  myRobot.motorStop();
  Serial.println("Motors stopped");
  delay(1000);

  // Drive left with half speed
  myRobot.driveLeft(128);
  Serial.println("Driving left with PWM = 128");
  delay(2000);

  // Stop the motors
  myRobot.motorStop();
  Serial.println("Motors stopped");
  delay(1000);

  // Drive right with half speed
  myRobot.driveRight(128);
  Serial.println("Driving right with PWM = 128");
  delay(2000);

  // Stop the motors
  myRobot.motorStop();
  Serial.println("Motors stopped");
  delay(1000);

  // Drive slow left with half speed
  myRobot.driveSlowLeft(128);
  Serial.println("Driving slow left with PWM = 128");
  delay(2000);

  // Stop the motors
  myRobot.motorStop();
  Serial.println("Motors stopped");
  delay(1000);

  // Drive slow right with half speed
  myRobot.driveSlowRight(128);
  Serial.println("Driving slow right with PWM = 128");
  delay(2000);

  // Stop the motors
  myRobot.motorStop();
  Serial.println("Motors stopped");
  delay(1000);
}
