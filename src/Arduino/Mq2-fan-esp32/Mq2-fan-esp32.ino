#include <MQ2.h>


//motor A
 int in1 = 27;
 int in2 = 26;
 int enable1FanPin = 14;
 int fanSpeed;

int smoke=35; //A5
int sensorThresMin = 0;  //ตั้ง ค่าความหนาของตวัน แก๊ส ก๊าซที่ 400
int sensorThresMax = 255;

// Setting PWM properties
const int freq = 30000;
const int pwmChannel = 0;
const int resolution = 8;
int dutyCycle = 200;

void setup() {
// sets the pins as outputs:

  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(smoke, INPUT);
  

  // configure LED PWM functionalitites
  ledcSetup(pwmChannel, freq, resolution);
  
  // attach the channel to the GPIO to be controlled
  ledcAttachPin(enable1FanPin, pwmChannel);

  Serial.begin(115200);

  // testing
  Serial.print("Testing DC Motor...");
  delay(500);
}

void loop() {

  // Move the DC motor forward at maximum speed
  Serial.println("Moving Forward");
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH); 
  delay(2000);

  // Stop the DC motor
  Serial.println("Motor stopped");
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  delay(1000);

  // Move DC motor backwards at maximum speed
  Serial.println("Moving Backwards");
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW); 
  delay(2000);

  // Stop the DC motor
  Serial.println("Motor stopped");
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  delay(1000);

  // Move DC motor forward with increasing speed
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  while (dutyCycle <= 255){
    ledcWrite(pwmChannel, dutyCycle);   
    Serial.print("Forward with duty cycle: ");
    Serial.println(dutyCycle);
    dutyCycle = dutyCycle + 5;
    delay(500);
  }
  dutyCycle = 200;
}
