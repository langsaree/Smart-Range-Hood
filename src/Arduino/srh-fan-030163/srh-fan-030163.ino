#include <MQ2.h>

#define LEDgreen 9 //ขา led

int in1 = 2;
int in2 = 4;

int fan = 3;
int fanSpeed;

int smokeA0; //A5
int sensorThresMin = 0;  //ตั้ง ค่าความหนาของตวัน แก๊ส ก๊าซที่ 400
int sensorThresMax = 255;
void setup() {
  Serial.begin(9600);
  pinMode(9, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(smokeA0, INPUT);
  digitalWrite(2, LOW);
  digitalWrite(4, HIGH);

  delay(500);
}

void loop() {

   int analogSensor = analogRead(A0);
  smokeA0 = map(analogSensor,0,1023,0,255);

 smokeA0 = analogSensor;
  Serial.print("Pin A0: ");
  Serial.println(smokeA0);

  if (smokeA0 > 255){
  analogWrite(9, 255);
}
else if (smokeA0 >=100){
  analogWrite(9,200);
}
else if (smokeA0 >=50){
  analogWrite(9,100);
}
else {
  analogWrite(9, 0);
}

//  if (smokeA0 <= 254)  {
//    analogWrite(9, 255);
//    analogWrite(3, smokeA0);
//    digitalWrite(2, LOW);
//    digitalWrite(4, HIGH);
//  }
//
//  else if (smokeA0 >= 100) {
//    analogWrite(9, 100);
//    analogWrite(3, smokeA0);
//    digitalWrite(2, LOW);
//    digitalWrite(4, HIGH);
//  }
//  else if (smokeA0 >= 50) {
//    analogWrite(9, 100);
//    analogWrite(3, smokeA0);
//    digitalWrite(2, LOW);
//    digitalWrite(4, HIGH);
//  }
//  else {
//    analogWrite(9, smokeA0);
//    analogWrite(3, smokeA0);
//    digitalWrite(2, LOW);
//    digitalWrite(4, HIGH);
//  }
// if ((analogSensor  >= sensorThresMin) && (analogSensor <= sensorThresMax))  {

//    fanSpeed = map(analogSensor, sensorThresMin, sensorThresMax, 32, 255);
//    digitalWrite(LedRED, HIGH);

//    digitalWrite(fan, fanSpeed);
//


}
