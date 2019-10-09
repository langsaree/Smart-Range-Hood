/*
การต่ออุปกรณ์ สามารถอ่านเพิ่มได้ที่ Link : https://www.ab.in.th/b/12
*/


#define LedRED  2 //D4
#define LEDgreen  12 //D0
int smokeA5 = A5; //A0

int sensorThres = 200;  //ตั้ง ค่าความหนาของตวัน แก๊ส ก๊าซที่ 400

void setup() {
  Serial.begin(9600);
  pinMode(LedRED, OUTPUT);
  pinMode(LEDgreen, OUTPUT);
  pinMode(smokeA5, INPUT);
}

void loop() {
  int analogSensor = analogRead(smokeA5);
  Serial.print("Pin A5: ");
  Serial.println(analogSensor); 


  if (analogSensor >= sensorThres)  {
    digitalWrite(LedRED, HIGH);
    digitalWrite(LEDgreen, LOW);
  }
  else  {
    digitalWrite(LedRED, LOW);
    digitalWrite(LEDgreen, HIGH);
  }
  delay(500);
}
