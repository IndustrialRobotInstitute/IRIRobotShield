#include "Robot.h"

Robot myRobot;

void setup() {
  Serial.begin(9600);

  // Initial state
  myRobot.lightOff(1);
  myRobot.lightOff(2);
  myRobot.lightOff(3);
  myRobot.lightOff(4);
  myRobot.lightOff(5);
  myRobot.lightOff(6);

  myRobot.buzzerOff();
}

void loop() {
  // Test LEDs
  for (int i = 1; i <= 6; i++) {
    myRobot.lightOn(i);
    myRobot.wait(500);
    myRobot.lightOff(i);
    myRobot.wait(500);
  }

  // Test Buzzer
  myRobot.buzzerOn();
  myRobot.wait(1000);
  myRobot.buzzerOff();
  myRobot.wait(1000);

  // Test Buzzer with frequency
  myRobot.buzzerOnWithFrequency(1000); // 1 kHz
  myRobot.wait(1000);
  myRobot.buzzerOnWithFrequency(0); // 0 kHz
  myRobot.buzzerOff();
  myRobot.wait(1000);

  // Test Button Status
  for (int i = 1; i <= 5; i++) {
    if (myRobot.isButtonPressed(i)) {
      Serial.print("Button ");
      Serial.print(i);
      Serial.println(" is pressed.");
    } else {
      Serial.print("Button ");
      Serial.print(i);
      Serial.println(" is not pressed.");
    }
    myRobot.wait(500);
  }


  // Get the distance from the ultrasonic sensor
  int distance = myRobot.getDistance();

  // Print the distance to the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Test Servo Set Angle
  myRobot.ServoSetAngle(1, 90);
  myRobot.wait(1000);
  myRobot.ServoSetAngle(2, 90);
  myRobot.wait(1000);

  // Test Servo Sweep
  myRobot.ServoSweep(1, 0, 180, 15);
  myRobot.wait(1000);
  myRobot.ServoSweep(2, 0, 180, 15);
  myRobot.wait(1000);

  // Test Analog Sensors
  int analogValue1 = myRobot.getAnalogSensorValue(1);
  int analogValue2 = myRobot.getAnalogSensorValue(2);
  Serial.print("Analog Sensor 1: ");
  Serial.println(analogValue1);
  Serial.print("Analog Sensor 2: ");
  Serial.println(analogValue2);

  // Test Digital Sensors
  bool digitalValue1 = myRobot.getDigitalSensorValue(1);
  bool digitalValue2 = myRobot.getDigitalSensorValue(2);
  Serial.print("Digital Sensor 1: ");
  Serial.println(digitalValue1 ? "HIGH" : "LOW");
  Serial.print("Digital Sensor 2: ");
  Serial.println(digitalValue2 ? "HIGH" : "LOW");


  myRobot.wait(2000); // Wait for 2 seconds before repeating the loop
}
