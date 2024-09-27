int LEDR = 3;
int LEDB = 6;
int LEDG = 9;
int count = 255;
bool increasing = false;
int period = 50;
void setup() {
  // put your setup code here, to run once:
pinMode (LEDR, OUTPUT);
pinMode (LEDB, OUTPUT);
pinMode (LEDG, OUTPUT);
analogWrite(LEDG, 0);
analogWrite(LEDB, 0);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(LEDR, count);
  delay(period);
  if (count <= 0  || increasing){
    count = count + 1;
    increasing = true;
  }
  if (count >= 255 || !increasing){
    count = count - 5;
    increasing = false;
  }
}
