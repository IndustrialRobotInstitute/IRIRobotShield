
int AnalogSensor1 = A0;
int AnalogSensor2 = A1;

int DigitalSensor1 = 4;
int DigitalSensor2 = 5;

int Digital1State = 0;
int Digital2State = 0;

void setup() {
 
  Serial.begin(9600);
}


void loop() {

  int Analogsensor1Value = analogRead(AnalogSensor1);
 int Analogsensor2Value = analogRead(AnalogSensor2);
 
 Digital1State = digitalRead(DigitalSensor1);
 Digital2State = digitalRead(DigitalSensor2);

 
  Serial.println("Channel 1 Value Digital:"+String(Digital1State)+" Analog:"+String(Analogsensor1Value));
  Serial.println("Channel 2 Value Digital:"+String(Digital2State)+" Analog:"+String(Analogsensor2Value));
  delay(1);        
}
