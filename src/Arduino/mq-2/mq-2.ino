#include <MQ2.h>

#define LedRED  2  //ขา led
#define LEDgreen  12 //ขา led

int fan = 9;       // the pin where fan is
int smokeMin = 300;   // the temperature to start the fan
int smokeMax = 700;   // the maximum temperature when fan is at 100%
int fanSpeed;

int smokeA5; //A5
int sensorThres = 200;  //ตั้ง ค่าความหนาของตวัน แก๊ส ก๊าซที่ 400


void setup() {
  pinMode(fan, OUTPUT);
  pinMode(LedRED, OUTPUT);
  pinMode(LEDgreen, OUTPUT);
  pinMode(smokeA5, INPUT);
  Serial.begin(9600);
}

void loop() {
  int analogSensor = analogRead(smokeA5);
  Serial.print("Pin A5: ");
  Serial.println(analogSensor); 


  if (analogSensor < 200)  {
    fanSpeed = 0; // fan is not spinning 
    digitalWrite(fan, LOW);
    digitalWrite(LedRED, LOW);
    digitalWrite(LEDgreen, HIGH);
  }

  if ((analogSensor >= smokeMin)&& (analogSensor <= smokeMax))  {
    fanSpeed = map(analogSensor, smokeMin, smokeMax, 32, 255); // the actual speed of fan 
      analogWrite(fan, fanSpeed); // spin the fan at the fanSpeed spe    
    digitalWrite(LedRED, HIGH);
    digitalWrite(LEDgreen, LOW);
  } 
  delay(500);
}
