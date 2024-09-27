#include <LiquidCrystal.h>

void scroll(String msg, int strln);
void flush();
void diplayMsg(String msg);

int rs = 7;
int en = 8;
int d4 = 9;
int d5 = 10;
int d6 = 11;
int d7 = 12;
int dt = 250;
int count = 0;
int lmc = 0;
int rmc = 0;
int roll_over = 0;
float x;
float y;
float z;
char op;
String msg1 = "  Enter First Number.      ";
String msg2 = "  Enter Second Number.     ";
String msg3 = "Enter Operator.";
String dummy;

LiquidCrystal lcd(rs,en,d4,d5,d6,d7);

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  flush();
  lcd.clear();
  lcd.setCursor(0,0);
  while (Serial.available() == 0) {
    scroll(msg1, msg1.length());
    delay(dt);
    lcd.clear();
  }
  lmc = 0;
  x = Serial.parseFloat();
  flush();

  lcd.clear();
  lcd.setCursor(0,0);
  while (Serial.available() == 0) {
    scroll(msg2, msg2.length());
    delay(dt);
    lcd.clear();
  }
  lmc = 0;

  y = Serial.parseFloat();
  flush();

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(msg3);

  while (Serial.available() == 0) {
    scroll(msg3, msg3.length());
    delay(dt);
  }
  lmc = 0;

  op = Serial.read();
  flush();

  if (op == '+') {
    z = x + y;
  }
  if (op == '-') {
    z = x - y;
  }
  if (op == '*') {
    z = x * y;
  }
  if (op == '/') {
    z = x / y;
  }

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("ANS");
  lcd.setCursor(0, 1);
  lcd.print(x);
  lcd.print(op);
  lcd.print(y);
  lcd.print("=");
  lcd.print(z);
  while (Serial.available() == 0) {
  }
  flush();
  // dummy = Serial.readString();
}

void scroll(String msg, int strln){
  if (strln > 15) {
    lmc++;
    diplayMsg(msg);
  }
  if (lmc == msg.length()){
    lmc = 0;
  }
}

void flush(){
  while(Serial.available() > 0){
    String t = Serial.readString();
  }
}

void diplayMsg(String msg){
    rmc = lmc + 15;
    if (rmc >= msg.length()) {
      roll_over = rmc - msg.length();
      rmc = msg.length();
    }
    lcd.setCursor(0, 0);
    for (int i = lmc; i <= rmc; i++) {
      if (msg[i] != '\0'){
      lcd.print(msg[i]);
    }
    }
    if (rmc >= msg.length()) {
      for (int i = 0; i <= roll_over; i++) {
        if (msg[i] != '\0'){
        lcd.print(msg[i]);
      }
      }
    }
}
