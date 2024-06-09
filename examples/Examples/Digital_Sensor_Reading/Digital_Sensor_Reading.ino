#include <Robot.h>

Robot myRobot;

void setup() {
  Serial.begin(115200);
}

void loop() {
  // Read value from Digital Sensor 1
  bool value1 = myRobot.getDigitalSensorValue(1);
  Serial.print("Digital Sensor 1 Value: ");
  Serial.println(value1 ? "HIGH" : "LOW");
  
  // Read value from Digital Sensor 2
  bool value2 = myRobot.getDigitalSensorValue(2);
  Serial.print("Digital Sensor 2 Value: ");
  Serial.println(value2 ? "HIGH" : "LOW");
  
  delay(1000);
}
