#include <MQ2.h>

int fan = 13;
int smokeA0 = 36;
// Your threshold value
int sensorThres = 200;

void setup() {
  pinMode(fan, OUTPUT);
  pinMode(smokeA0, INPUT);
  Serial.begin(115200);
}

void loop() {
  int analogSensor = analogRead(smokeA0);
  Serial.print("Pin A0: ");
  Serial.println(analogSensor);
  // Checks if it has reached the threshold value
  if (analogSensor > sensorThres)
  {
    digitalWrite(fan, HIGH);
    delay(1000);
  }
  else
  {
    digitalWrite(fan, LOW);
  }
}
