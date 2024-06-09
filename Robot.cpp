#include "Arduino.h"
#include "Robot.h"
#include <Servo.h>

// Define the pin configuration within the library
const int Robot::LED_PINS[6] = {6, 7, 8, 9, 10, 11};
const int Robot::BUTTON_PINS[5] = {A3, A2, 4, 5, 12};
const int Robot::BUZZER_PIN = 13; // Example pin for buzzer
const int Robot::TRIG_PIN = 2; // Pin number for the ultrasonic sensor trig
const int Robot::ECHO_PIN = 3; // Pin number for the ultrasonic sensor echo
const int Robot::SERVO_PINS[2] = {10, 11}; // Pin numbers for the servos
const int Robot::ANALOG_SENSOR_PINS[2] = {A0, A1}; // Pin numbers for the analog sensors
const int Robot::DIGITAL_SENSOR_PINS[2] = {4, 5}; // Pin numbers for the digital sensors
const int Robot::MOTOR_PINS[4] = {6, 7, 8, 9}; // Pin numbers for the motors

Robot::Robot() {
  // Initialize LED pins
  for (int i = 0; i < 6; i++) {
    pinMode(LED_PINS[i], OUTPUT);
  }

  // Initialize button pins
  for (int i = 0; i < 5; i++) {
    pinMode(BUTTON_PINS[i], INPUT);
  }

  // Initialize buzzer pin
  pinMode(BUZZER_PIN, OUTPUT);

  // Initialize ultrasonic sensor pins
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  // Attach servos
  for (int i = 0; i < 2; i++) {
    servos[i].attach(SERVO_PINS[i]);
  }

  // Initialize analog sensor pins (No need for pinMode as analogRead configures it automatically)
  
  // Initialize digital sensor pins
  for (int i = 0; i < 2; i++) {
    pinMode(DIGITAL_SENSOR_PINS[i], INPUT);
  }

  // Initialize motor pins
  for (int i = 0; i < 4; i++) {
    pinMode(MOTOR_PINS[i], OUTPUT);
  }
}

void Robot::lightOn(int ledNumber) {
  if (ledNumber >= 1 && ledNumber <= 6) {
    digitalWrite(LED_PINS[ledNumber - 1], HIGH);
  }
}

void Robot::lightOff(int ledNumber) {
  if (ledNumber >= 1 && ledNumber <= 6) {
    digitalWrite(LED_PINS[ledNumber - 1], LOW);
  }
}

bool Robot::isButtonPressed(int buttonNumber) {
  if (buttonNumber >= 1 && buttonNumber <= 5) {
    return digitalRead(BUTTON_PINS[buttonNumber - 1]) == HIGH;
  }
  return false;
}

void Robot::buzzerOn() {
  digitalWrite(BUZZER_PIN, HIGH);
}

void Robot::buzzerOff() {
  digitalWrite(BUZZER_PIN, LOW);
}

void Robot::buzzerOnWithFrequency(int frequency) {
  tone(BUZZER_PIN, frequency);
}

void Robot::wait(int milliseconds) {
  delay(milliseconds);
}

int Robot::getDistance() {
  long duration = readUltrasonicSensor();
  int distance = duration * 0.034 / 2;
  return distance;
}

long Robot::readUltrasonicSensor() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);
  return duration;
}

void Robot::ServoSetAngle(int ServoNumber, int angle) {
  if (ServoNumber >= 1 && ServoNumber <= 2) {
    servos[ServoNumber - 1].write(angle);
  }
}

void Robot::ServoSweep(int ServoNumber, int minAngle, int maxAngle, int delayInMilliseconds) {
  if (ServoNumber >= 1 && ServoNumber <= 2) {
    for (int angle = minAngle; angle <= maxAngle; angle++) {
      servos[ServoNumber - 1].write(angle);
      delay(delayInMilliseconds);
    }
    for (int angle = maxAngle; angle >= minAngle; angle--) {
      servos[ServoNumber - 1].write(angle);
      delay(delayInMilliseconds);
    }
  }
}

int Robot::getAnalogSensorValue(int sensorNumber) {
  if (sensorNumber >= 1 && sensorNumber <= 2) {
    return analogRead(ANALOG_SENSOR_PINS[sensorNumber - 1]);
  }
  return -1; // Invalid sensor number
}

bool Robot::getDigitalSensorValue(int sensorNumber) {
  if (sensorNumber >= 1 && sensorNumber <= 2) {
    return digitalRead(DIGITAL_SENSOR_PINS[sensorNumber - 1]) == HIGH;
  }
  return false; // Invalid sensor number
}

void Robot::driveForward(int pwm) {
  analogWrite(MOTOR_PINS[0], pwm);
  digitalWrite(MOTOR_PINS[1], LOW);
  digitalWrite(MOTOR_PINS[2], HIGH);
  analogWrite(MOTOR_PINS[3], -pwm);
}

void Robot::driveBackward(int pwm) {
  analogWrite(MOTOR_PINS[0], -pwm);
  digitalWrite(MOTOR_PINS[1], HIGH);
  digitalWrite(MOTOR_PINS[2], LOW);
  analogWrite(MOTOR_PINS[3], pwm);
}

void Robot::driveLeft(int pwm) {
  analogWrite(MOTOR_PINS[0], -pwm);
  digitalWrite(MOTOR_PINS[1], HIGH);
  digitalWrite(MOTOR_PINS[2], HIGH);
  analogWrite(MOTOR_PINS[3], -pwm);
}

void Robot::driveRight(int pwm) {
  analogWrite(MOTOR_PINS[0], pwm);
  digitalWrite(MOTOR_PINS[1], LOW);
  digitalWrite(MOTOR_PINS[2], LOW);
  analogWrite(MOTOR_PINS[3], pwm);
}

void Robot::driveSlowLeft(int pwm) {
  analogWrite(MOTOR_PINS[0], -pwm);
  digitalWrite(MOTOR_PINS[1], HIGH);
  digitalWrite(MOTOR_PINS[2], HIGH);
  digitalWrite(MOTOR_PINS[3], HIGH);
}

void Robot::driveSlowRight(int pwm) {
  digitalWrite(MOTOR_PINS[0], LOW);
  digitalWrite(MOTOR_PINS[1], LOW);
  digitalWrite(MOTOR_PINS[2], LOW);
  analogWrite(MOTOR_PINS[3], pwm);
}

void Robot::motorStop() {
  digitalWrite(MOTOR_PINS[0], LOW);
  digitalWrite(MOTOR_PINS[1], LOW);
  digitalWrite(MOTOR_PINS[2], HIGH);
  digitalWrite(MOTOR_PINS[3], HIGH);
}
