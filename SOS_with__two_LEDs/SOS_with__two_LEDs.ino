int count = 0;
int dashTime = 500;
int dotTime = 100;
int dashLED = 13;
int dotLED = 12;
void setup() {
  // put your setup code here, to run once:
pinMode (13,OUTPUT);
pinMode (12,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
    delay (1000);
    while(count < 3){
    digitalWrite(dotLED, HIGH);
    delay (dotTime);
    digitalWrite(dotLED, LOW);
    delay(dotTime);
    count = count + 1;
  }
  count = 0;
  while(count < 3){
    digitalWrite(dashLED, HIGH);
    delay (dashTime);
    digitalWrite(dashLED, LOW);
    delay(dashTime);
    count = count + 1;
  }
  count = 0;
  while(count < 3){
    digitalWrite(dotLED, HIGH);
    delay (dotTime);
    digitalWrite(dotLED, LOW);
    delay(dotTime);
    count = count + 1;
  }
  count = 0;
  }
