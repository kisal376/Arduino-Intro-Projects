#include <TimerOne.h>

const int readPin_1 = A2;
const int readPin_2 = A4;
const int trigPin = 9;
const int echoPin = 10;
const int LEDPin = 11;
const int dummyPin = 13;

float duration;
float currentTime;
float oldTime = 0;
float lastChangeUp = 0;
float lastChangeDown = 0;
float readValue_1 = 0;
float readValue_2 = 0;
float timeWhenLEDTurnedOn = 0;
int currentDistance = 0;
int checkDistance = 0;
int count = 0;
int numberOfChanges = 0;
bool LEDon = false;
bool LEDTurnedOn = false;
bool skip = false;
bool dark = false;
const int timeOfConstantENV = 8000;
const int dimmingDelay = 50;
const unsigned long timeForLightToStayOn = 60000;
const int refreshRate = 15;
const int distanceToWall = 228;
const int tolarence = 3;
const int allowedNumberOfChanges = 2;


void setup() {
  // put your setup code here, to run once:
  pinMode (readPin_1, INPUT);
  pinMode (readPin_2, INPUT);
  pinMode (trigPin, OUTPUT);
  pinMode (echoPin, INPUT);
  pinMode (LEDPin, OUTPUT);
  pinMode (dummyPin, OUTPUT);
  Timer1.initialize(1000000);
  Timer1.attachInterrupt(dummy);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print(numberOfChanges);
  Serial.print(" ");
  Serial.print(timeWhenLEDTurnedOn);
  Serial.print(" ");
  Serial.print(currentTime);
  Serial.print(" ");
  Serial.println (currentDistance);
  readValue_1 = analogRead (readPin_1);
  readValue_2 = analogRead (readPin_2);

  if ( readValue_1 < 10 && readValue_2 < 10 ) {
    lastChangeUp = millis();
  }
  if (readValue_1 >= 10 && readValue_2 >= 10){
    lastChangeDown = millis();
  }
  if ((lastChangeDown - lastChangeUp + timeOfConstantENV) < 0){
    dark = true;
  }
  if ((lastChangeDown - lastChangeUp - timeOfConstantENV) > 0){
    dark = false;
  }

  currentTime = millis();
  digitalWrite(trigPin, LOW);
  delay(2);

  digitalWrite(trigPin, HIGH);
  delay(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  currentDistance = duration*0.034/2;

  if ((currentTime - oldTime)> refreshRate){
    checkDistance = currentDistance;
    oldTime = currentTime;
  }

  if (((currentDistance > distanceToWall + tolarence) || (currentDistance < distanceToWall - tolarence)) && dark){
    numberOfChanges = numberOfChanges + 1;
    LEDon = true;
  }else {
    LEDon = false;
    numberOfChanges = 0;
  }
  if (((currentTime - timeWhenLEDTurnedOn) < timeForLightToStayOn) && LEDTurnedOn){
    LEDon = true;
  }
  if (((currentTime - timeWhenLEDTurnedOn) > timeForLightToStayOn) && LEDTurnedOn){
    LEDon = false;
  }
  if (numberOfChanges > allowedNumberOfChanges){
      timeWhenLEDTurnedOn = millis();
  }

  if (LEDon && (numberOfChanges > allowedNumberOfChanges)){
    timeWhenLEDTurnedOn = millis();
    LEDTurnedOn = true;
    while (count <= 255){
      analogWrite (LEDPin, count);
      delay (dimmingDelay);
      count = count + 5;
      numberOfChanges = 0;
    }
  }else if(!LEDon){
    LEDTurnedOn = false;
    while (count >= 0){
      analogWrite (LEDPin, count);
      delay (dimmingDelay);
      count  = count - 5;
    }
  }
}
void dummy(){
  digitalWrite(dummyPin, HIGH);
  digitalWrite(dummyPin, LOW);

  return;
}
