#include <Servo.h>
int servoPin = 10;
int servoPosition = 165;
int valueEntered;
Servo servo1;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
servo1.attach(servoPin);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println ("Enter Angle : ");
  while (Serial.available() == 0){
  }
  
  servoPosition = Serial.parseInt();
  servo1.write(servoPosition);
}
