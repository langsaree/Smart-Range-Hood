/****************
  คอร์สฟรี การใช้งาน ESP8266 ฉบับจับมือทำ สำหรับผู้เริ่มต้น
  https://www.facebook.com/IOTProductDesign/
****************/

int pin = 16;

void setup() {
  // เซต GPIO 2 เป็น OUTPUT
  pinMode(pin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(pin, HIGH);  // ทำการเปิดไฟ LED โดยส่ง High state
  delay(1000);              // รอ 1 วินาที
  digitalWrite(pin, LOW);   // ทำการปิดไฟ LED โดยส่ง Low state
  delay(1000);              // รอ 1 วินาที
}
