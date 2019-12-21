/*
การต่ออุปกรณ์ สามารถอ่านเพิ่มได้ที่ Link : https://www.ab.in.th/b/12
*/

#define LedRED  2 //D4
#define LEDgreen  16 //D0
int smokeA0 = 0; //A0
int buzzPin=4;  //D2

int frequency=1000; //Specified in Hz 
int timeOn=1000; //specified in milliseconds
int timeOff=1000; //specified in millisecods


int sensorThres = 450;  //ตั้ง ค่าความหนาของตวัน แก๊ส ก๊าซที่ 400

void setup() {
  Serial.begin(9600);
  pinMode(LedRED, OUTPUT);
  pinMode(LEDgreen, OUTPUT);
  pinMode(smokeA0, INPUT);
}

void loop() {
  int analogSensor = analogRead(smokeA0);
  Serial.print("Pin A0: ");
  Serial.println(analogSensor); 


  if (analogSensor >= sensorThres)  {
    digitalWrite(LedRED, HIGH);
    digitalWrite(LEDgreen, LOW);
      tone(buzzPin, frequency);
      delay(timeOn);
  }

  else  {
    digitalWrite(LedRED, LOW);
    digitalWrite(LEDgreen, HIGH);
     noTone(buzzPin);
    delay(timeOff);
  }
  delay(500);
}
