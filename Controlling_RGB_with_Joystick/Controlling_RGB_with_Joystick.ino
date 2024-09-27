int Xpin = A0;
int Ypin = A2;
int SWpin = 12;
int Redpin = 5;
int Bluepin = 3;
int Greenpin = 9;
int Redval = 0;
int Blueval = 0;
int Greenval = 0;
float Xval = 0;
float Yval = 0;
int dt = 250;
void setup() {
  // put your setup code here, to run once:
  pinMode (Xpin, INPUT);
  pinMode (Ypin, INPUT);
  pinMode (SWpin, INPUT);
  digitalWrite(SWpin, HIGH);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Xval = analogRead(Xpin);
  Yval = analogRead(Ypin);
  Redval = (Xval/1023.)*255.;
  Blueval = (Yval/1023.)*255.;
  Serial.print ("X : ");
  Serial.print (Xval);
  Serial.print (" X : ");
  Serial.print (Yval);
  if(!digitalRead(SWpin)){
    Serial.print(" Clicked");
    Greenval = Greenval ^ 1;
    }
  Serial.println(".");
  digitalWrite(Greenpin, Greenval);
  analogWrite(Redpin, Redval);
  analogWrite(Bluepin, Blueval);
  delay(dt);
}
