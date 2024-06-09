
#include <Servo.h>

Servo myservo1;  
Servo myservo2;  


int pos = 0;    // variable to store the servo position

void setup() {
  myservo1.attach(11);  
  myservo2.attach(10);  
}

void loop() {
  for (pos = 0; pos <= 180; pos += 1) { 
    // in steps of 1 degree
    myservo1.write(pos);   
    myservo2.write(pos);              
    delay(15);                       
  }
  for (pos = 180; pos >= 0; pos -= 1) { 
    myservo1.write(pos);  
    myservo2.write(pos);               
    delay(15);                       
  }
}
