#include <Robot.h>

Robot myRobot;

void setup() {
  Serial.begin(115200);
}

void loop() {
  // Check the status of each button
  for (int i = 1; i <= 5; i++) {
    if (myRobot.isButtonPressed(i)) {
      Serial.print("Button ");
      Serial.print(i);
      Serial.println(" is pressed.");
    }
  }
  delay(500);
}
