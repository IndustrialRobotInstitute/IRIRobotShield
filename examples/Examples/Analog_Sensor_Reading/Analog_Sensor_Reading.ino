#include <Robot.h>

Robot myRobot;

void setup() {
  Serial.begin(115200);
}

void loop() {
  // Read value from Analog Sensor 1
  int value1 = myRobot.getAnalogSensorValue(1);
  Serial.print("Analog Sensor 1 Value: ");
  Serial.println(value1);
  
  // Read value from Analog Sensor 2
  int value2 = myRobot.getAnalogSensorValue(2);
  Serial.print("Analog Sensor 2 Value: ");
  Serial.println(value2);
  
  delay(1000);
}
