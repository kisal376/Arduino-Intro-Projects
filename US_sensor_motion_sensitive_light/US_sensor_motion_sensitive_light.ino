const int trigPin = 9;
const int echoPin = 10;
const int LEDPin = 11;

long duration;
int currentDistance = 0;
int checkDistance = 0;
float oldTime = 0;
float currentTime;
bool LEDon = false;
int count = 0;
const int dimmingDelay = 50;
const int timeForLightToStayOn = 30000;
const int refreshRate = 500;

void setup() {
  // put your setup code here, to run once:
  pinMode (trigPin, OUTPUT);
  pinMode (echoPin, INPUT);
  pinMode (LEDPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  currentTime = millis();
  digitalWrite(trigPin, LOW);
  delay(2);

  digitalWrite(trigPin, HIGH);
  delay(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  currentDistance = duration*0.034/2;

  if ((currentTime - oldTime)> refreshRate;){
    checkDistance = currentDistance;
    oldTime = currentTime;
  }

  if ((currentDistance > checkDistance + 1) || (currentDistance < checkDistance - 1)){
    LEDon = true;
  }else {
    LEDon = false;
  }

   if (LEDon) {
    while (count <= 255){
    analogWrite (LEDPin, count);
    delay (dimmingDelay);
    count = count + 5;
    }
    delay (timeForLightToStayOn);
  }else {
    while (count >= 0){
      analogWrite (LEDPin, count);
      delay (dimmingDelay);
      count  = count - 5;
    }
  }
}
