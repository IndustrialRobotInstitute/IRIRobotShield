#ifndef Robot_h
#define Robot_h

#include "Arduino.h"
#include <Servo.h>

class Robot {
  public:
    Robot(); // Constructor
    void lightOn(int ledNumber); // Turn on the specified LED
    void lightOff(int ledNumber); // Turn off the specified LED
    bool isButtonPressed(int buttonNumber); // Get the status of the specified button
    void buzzerOn(); // Turn on the buzzer
    void buzzerOff(); // Turn off the buzzer
    void buzzerOnWithFrequency(int frequency); // Turn on the buzzer with a specific frequency
    void wait(int milliseconds); // Wait for a specified number of milliseconds
    int getDistance(); // Get the distance from the distance sensor in cm
    void ServoSetAngle(int ServoNumber, int angle); // Set the angle of the specified servo
    void ServoSweep(int ServoNumber, int minAngle, int maxAngle, int delayInMilliseconds); // Sweep the specified servo
    int getAnalogSensorValue(int sensorNumber); // Get analog value from the specified sensor
    bool getDigitalSensorValue(int sensorNumber); // Get digital value from the specified sensor
    void driveForward(int pwm); // Drive the motors forward with PWM
    void driveBackward(int pwm); // Drive the motors backward with PWM
    void driveLeft(int pwm); // Drive the motors to turn left with PWM
    void driveRight(int pwm); // Drive the motors to turn right with PWM
    void driveSlowLeft(int pwm); // Drive the motors to turn slowly left with PWM
    void driveSlowRight(int pwm); // Drive the motors to turn slowly right with PWM
    void motorStop(); // Stop the motors

  private:
    static const int LED_PINS[6]; // Pin numbers of the LEDs
    static const int BUTTON_PINS[5]; // Pin numbers of the buttons
    static const int BUZZER_PIN; // Pin number of the buzzer
    static const int TRIG_PIN; // Pin number of the ultrasonic sensor trig
    static const int ECHO_PIN; // Pin number of the ultrasonic sensor echo
    static const int SERVO_PINS[2]; // Pin numbers of the servos
    static const int ANALOG_SENSOR_PINS[2]; // Pin numbers of the analog sensors
    static const int DIGITAL_SENSOR_PINS[2]; // Pin numbers of the digital sensors
    static const int MOTOR_PINS[4]; // Pin numbers of the motors
    Servo servos[2]; // Servo objects

    long readUltrasonicSensor(); // Read the ultrasonic sensor
};

#endif
