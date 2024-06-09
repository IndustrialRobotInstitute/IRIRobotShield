#include <Robot.h>

Robot myRobot;

void setup() {
  Serial.begin(115200);
}

void loop() {
  // Get distance in cm from the ultrasonic sensor
  int distance = myRobot.getDistance();
  
  // Print the distance
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  delay(500);
}
