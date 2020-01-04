#include <MQ2.h>

#define LedRED  2  //ขา led
#define LEDgreen  12 //ขา led

int fan = A5;
int fanSpeed;

int smokeA0; //A5
int sensorThresMin = 100;  //ตั้ง ค่าความหนาของตวัน แก๊ส ก๊าซที่ 400
int sensorThresMax = 400;
void setup() {
  Serial.begin(9600);
  pinMode(LedRED, OUTPUT);
  pinMode(fan, OUTPUT);
  pinMode(LEDgreen, OUTPUT);
  pinMode(smokeA0, INPUT);
    delay(500);
}

void loop() {
  int analogSensor = analogRead(smokeA0);
  Serial.print("Pin A0: ");
  Serial.println(analogSensor); 

//  if ((analogSensor  >= sensorThresMin) && (analogSensor <= sensorThresMax))  {
//    fanSpeed = map(analogSensor, sensorThresMin, sensorThresMax, 32, 255);
//    digitalWrite(LedRED, HIGH);
//    digitalWrite(LEDgreen, LOW);
//    digitalWrite(fan, fanSpeed);
//  }

if (analogSensor >= 400)  {
    digitalWrite(LedRED, HIGH);
    digitalWrite(LEDgreen, LOW);
    digitalWrite(fan, HIGH);
  }

  else  {
    digitalWrite(LedRED, LOW);
    digitalWrite(LEDgreen, HIGH);
    digitalWrite(fan, LOW);
  }
  
}
