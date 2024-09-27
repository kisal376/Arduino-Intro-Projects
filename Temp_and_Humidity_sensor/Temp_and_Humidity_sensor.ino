#include <DHT.h>
#define Type DHT11

int sensePin = 2;
DHT HT(sensePin, Type);
float humidity;
float tempC;
float tempF;
int setupTime = 500;
int dt = 500;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  HT.begin();
  delay(setupTime);
}

void loop() {
  // put your main code here, to run repeatedly:
  humidity = HT.readHumidity();
  tempC = HT.readTemperature();
  tempF = HT.readTemperature(true);
  Serial.print("humidity: ");
  Serial.print(humidity);
  Serial.print(" tempC: ");
  Serial.print(tempC);
  Serial.print(" tempF: ");
  Serial.println(tempF);
  delay(dt);
}
