
int button1 = A3;
int button2 = A2;
int button3 = 4;
int button4 = 5;
int button5 = 12;


int led1 = 6;
int led2 = 7;
int led3 = 8;
int led4 = 9;
int led5 = 10;
int led6 = 11;   


int buttonState1 = 0;    
int buttonState2 = 0;  
int buttonState3 = 0;  
int buttonState4 = 0;  
int buttonState5 = 0;       

void setup() {

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
 
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  pinMode(button4, INPUT);
  pinMode(button5, INPUT);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState1 = digitalRead(button1);
  buttonState2 = digitalRead(button2);
buttonState3 = digitalRead(button3);
buttonState4 = digitalRead(button4);
buttonState5 = digitalRead(button5);


  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState1 == LOW) {
    // turn LED on:
    digitalWrite(led1, HIGH);
  } else {
    // turn LED off:
    digitalWrite(led1, LOW);
  }

   if (buttonState2 == LOW) {
    // turn LED on:
    digitalWrite(led2, HIGH);
  } else {
    // turn LED off:
    digitalWrite(led2, LOW);
  }

  if (buttonState3 == LOW) {
    // turn LED on:
    digitalWrite(led3, HIGH);
  } else {
    // turn LED off:
    digitalWrite(led3, LOW);
  }

  if (buttonState4 == LOW) {
    // turn LED on:
    digitalWrite(led4, HIGH);
  } else {
    // turn LED off:
    digitalWrite(led4, LOW);
  }

  if (buttonState5 == LOW) {
    // turn LED on:
    digitalWrite(led5, HIGH);
  } else {
    // turn LED off:
    digitalWrite(led5, LOW);
  }
}
