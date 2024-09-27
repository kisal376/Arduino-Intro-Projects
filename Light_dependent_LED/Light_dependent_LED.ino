
int const readPin = A2;
int const LEDPin = 11;
double readValue = 0.0;
float vaoltage = 0.0;
float highest = 0.0;
bool LEDon = false;
int count = 0;
int const delayTime = 500;
int const dimmingDelay = 50;
int const timeOfConstantENV = 8000;
float lastChangeUp = 0;
float lastChangeDown = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode (readPin, INPUT);
  pinMode (LEDPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  readValue = analogRead (readPin);
  Serial.print ("Current val = ");
  Serial.print (readValue);
  Serial.print (" Highest val = ");
  if (readValue > highest){
    highest = readValue;
  }
  
  Serial.println (highest);
  if ( readValue < 10 ) {
    lastChangeUp = millis();
  }
  if (readValue >= 10){
    lastChangeDown = millis();
  }
  if ((lastChangeDown - lastChangeUp + timeOfConstantENV) < 0){
    LEDon = true;
  }
  if ((lastChangeDown - lastChangeUp - timeOfConstantENV) > 0){
    LEDon = false;
  }
  if (LEDon) {
    while (count <= 255){
    analogWrite (LEDPin, count);
    delay (dimmingDelay);
    count = count + 5;
    }
  }else {
    while (count >= 0){
      analogWrite (LEDPin, count);
      delay (dimmingDelay);
      count  = count - 5;
    }
  }
}
