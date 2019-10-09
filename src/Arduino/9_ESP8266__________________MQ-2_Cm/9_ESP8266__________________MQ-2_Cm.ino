/****************
  คอร์ส การใช้งาน ESP8266 ฉบับจับมือทำ สำหรับผู้เริ่มต้น
  https://www.facebook.com/IOTProductDesign/
****************/
int smokePin = A5;                  // ประกาศตัวแปร smokePin = A0 = ADC0
const int smokeLEDR = 2;            // ประกาศตัวแปร smokeLED = D6 = GPIO12
const int smokeLEDG = 12; 

boolean smokeTriggered = false;     // ประกาศตัวแปรควบคุมสำหรับฟังก์ชั่น Smoke

int smokeThres = 60;                // ประกาศตัวแปร smokeThres ตั้งค่าระดับตรวจจับ Smoke

long now = millis();                // ประกาศตัวแปร Timers
long lastSmokeCheck = 0;            // ประกาศตัวแปรช่วย สำหรับฟังก์ชั่น ตรวจสอบ Gas&Smoke
long lastSmokeCheck2 = 0;           // ประกาศตัวแปรช่วย สำหรับการเริ่มตรวจสอบใหม่อีกครั้ง

void setup() {
  Serial.begin(9600);               // เซต Baud rate ของ Serial Port เป็น 9600 ที่ใช้สำหรับ Serial Monitor

  pinMode(smokeLEDR, OUTPUT);        // เซต smokeLED เป็น OUTPUT
  pinMode(smokeLEDG, OUTPUT);
  pinMode(smokePin, INPUT);         // เซต smokePin เป็น INPUT
}
 
void loop() {
  now = millis();                                     // นำค่าเวลาปัจจุบันใส่ตัวแปร now
  // ฟังก์ชั่นตรวจสอบ Gas&Smoke
  if (now - lastSmokeCheck > 200) {                   // ถ้าเวลาปัจจุบัน มากกว่า ครั้งสุดท้ายที่เข้าเงื่อนไข if นี้ เกินกว่า 200 หมายถึงจะเข้า if นี้ทุกๆ 200 msec 
    lastSmokeCheck = now;                             // เก็บเวลาปัจจุบันไปที่ lastSmokeCheck
    int smokeValue = analogRead(smokePin);            // อ่านค่าจาก smokePin ช่วงการวัด Range อยู่ที่ 0 - 1024
    if (smokeValue > smokeThres){                     // ถ้าค่า smokeValue > ค่า smokeThres ที่ตั้งไว้ จะทำคำสั่งวงเล็บ
      Serial.print("Pin A5: ");                       // ส่งข้อความออกทาง Serial Monitor
      Serial.println(smokeValue);                     // ส่งข้อความออกทาง Serial Monitor พร้อมขึ้นบรรทัดใหม่
      if(!smokeTriggered){                            // เช็คถ้า smokeTriggered = false (ยังไม่เคยถูก trig มาก่อน) ให้ทำคำสั่งวงเล็บ
        Serial.println("ตรวจพบแก๊สและควันรั่วไหล!!!");    // ส่งข้อความออกทาง Serial Monitor พร้อมขึ้นบรรทัดใหม่
        smokeTriggered = true;                        // เซต smokeTriggered = true ว่าถูก trig แล้ว 
        lastSmokeCheck2 = now;                        // เก็บเวลาปัจจุบันไปที่ lastSmokeCheck2 เพื่อใช้ในฟังก์ชั่น เริ่มตรวจสอบใหม่อีกครั้ง 
        digitalWrite(smokeLEDR, HIGH);                 // ทำการสั่ง ON LED โดยส่ง High state
      }
    }
  }
  // ฟังก์ชั่น เริ่มตรวจสอบใหม่อีกครั้ง จะ Delay 5 วินาที และเริ่มตรวจสอบใหม่อีกครั้ง
  if (smokeTriggered && (now - lastSmokeCheck2 > 5000))     // ถ้า smokeTriggered ถูก Trig และเวลาปัจจุบัน มากกว่า ครั้งสุดท้ายที่เข้าเงื่อนไข ฟังก์ชั่นตรวจสอบ Gas&Smoke เกินกว่า 5000  หมายถึงจะเข้า if นี้ หลังจากถูก Trig แล้วผ่านไป 5000 msec 
  { 
    lastSmokeCheck2 = now;                            // เก็บเวลาปัจจุบันไปที่ lastSmokeCheck2 เพื่อใช้ในฟังก์ชั่น เริ่มตรวจสอบใหม่อีกครั้ง 
    smokeTriggered = false;                           // ทำการเคลียร์ smokeTriggered = false เพื่อเริ่มตรวจสอบใหม่อีกครั้ง
    digitalWrite(smokeLEDG, LOW);                      // ทำการสั่ง OFF LED โดยส่ง Low state
    Serial.println("ฟังก์ชั่นตรวจสอบแก๊สและควันเริ่มต้นตรวจสอบอีกครั้ง!!!");      // ส่งข้อความออกทาง Serial Monitor พร้อมขึ้นบรรทัดใหม่
  } 
}
