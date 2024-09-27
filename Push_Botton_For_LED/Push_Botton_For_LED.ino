int readBotton;
bool LEDOn = false;
int bottonPin = 12;
int LEDPin = 8;
bool pressed = false;
bool released = false;
int delayTime = 10;
 
void setup() {
  // put your setup code here, to run once:
pinMode(bottonPin, INPUT);
pinMode(LEDPin, OUTPUT);
Serial.begin(9600);
}

void loop() {
  if (LEDOn){
    digitalWrite(LEDPin, HIGH);
  }else{
    digitalWrite(LEDPin, LOW);
  }
  readBotton = digitalRead(bottonPin);
  if (readBotton == 0){
    pressed = true;
  }
  if (pressed && readBotton == 1){
    released = true;
    if (LEDOn){
      LEDOn = false;
    }else{
      LEDOn = true;
    }
  }
  if (released){
    pressed = false;
    released = false;
  }
  Serial.println(readBotton);
  delay(delayTime);
 
  // put your main code here, to run repeatedly:

}
