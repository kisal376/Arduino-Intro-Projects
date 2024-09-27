int counterArr[4];
int count = 0;
int zerothBit = 7;
int onethBit = 9;
int twothBit = 11;
int threethBit = 13;
void setup() {
  // put your setup code here, to run once:
pinMode (zerothBit, OUTPUT);
pinMode (onethBit, OUTPUT);
pinMode (twothBit, OUTPUT);
pinMode (threethBit, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  switch(count){
  case 0: 
  counterArr[0] = 0;
  counterArr[1] = 0;
  counterArr[2] = 0;
  counterArr[3] = 0;
  break;
  case 1: 
  counterArr[0] = 0;
  counterArr[1] = 0;
  counterArr[2] = 0;
  counterArr[3] = 1;
  break;
  case 2: 
  counterArr[0] = 0;
  counterArr[1] = 0;
  counterArr[2] = 1;
  counterArr[3] = 0;
  break;
  case 3: 
  counterArr[0] = 0;
  counterArr[1] = 0;
  counterArr[2] = 1;
  counterArr[3] = 1;
  break;
  case 4: 
  counterArr[0] = 0;
  counterArr[1] = 1;
  counterArr[2] = 0;
  counterArr[3] = 0;
  break;
  case 5: 
  counterArr[0] = 0;
  counterArr[1] = 1;
  counterArr[2] = 0;
  counterArr[3] = 1;
  break;
  case 6: 
  counterArr[0] = 0;
  counterArr[1] = 1;
  counterArr[2] = 1;
  counterArr[3] = 0;
  break;
  case 7: 
  counterArr[0] = 0;
  counterArr[1] = 1;
  counterArr[2] = 1;
  counterArr[3] = 1;
  break;
  case 8: 
  counterArr[0] = 1;
  counterArr[1] = 0;
  counterArr[2] = 0;
  counterArr[3] = 0;
  break;
  case 9: 
  counterArr[0] = 1;
  counterArr[1] = 0;
  counterArr[2] = 0;
  counterArr[3] = 1;
  break;
  case 10: 
  counterArr[0] = 1;
  counterArr[1] = 0;
  counterArr[2] = 1;
  counterArr[3] = 0;
  break;
  case 11: 
  counterArr[0] = 1;
  counterArr[1] = 0;
  counterArr[2] = 1;
  counterArr[3] = 1;
  break;
  case 12: 
  counterArr[0] = 1;
  counterArr[1] = 1;
  counterArr[2] = 0;
  counterArr[3] = 0;
  break;
  case 13: 
  counterArr[0] = 1;
  counterArr[1] = 1;
  counterArr[2] = 0;
  counterArr[3] = 1;
  break;
  case 14: 
  counterArr[0] = 1;
  counterArr[1] = 1;
  counterArr[2] = 1;
  counterArr[3] = 0;
  break;
  case 15: 
  counterArr[0] = 1;
  counterArr[1] = 1;
  counterArr[2] = 1;
  counterArr[3] = 1;
  break;
  }
  count = count + 1;
  if (count == 16){
    count =0;
  }
  if (counterArr[3] == 1){
    digitalWrite(zerothBit, HIGH);
  }else{
    digitalWrite(zerothBit, LOW);
  }
    if (counterArr[2] == 1){
    digitalWrite(onethBit, HIGH);
  }else{
    digitalWrite(onethBit, LOW);
  }
    if (counterArr[1] == 1){
    digitalWrite(twothBit, HIGH);
  }else{
    digitalWrite(twothBit, LOW);
  }
    if (counterArr[0] == 1){
    digitalWrite(threethBit, HIGH);
  }else{
    digitalWrite(threethBit, LOW);
  }
  delay (1000);
}
