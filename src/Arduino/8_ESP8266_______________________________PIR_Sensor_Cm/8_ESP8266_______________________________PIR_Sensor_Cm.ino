/****************
  คอร์ส การใช้งาน ESP8266 ฉบับจับมือทำ สำหรับผู้เริ่มต้น
  https://www.facebook.com/IOTProductDesign/
****************/
const int motionSensor = 5;        // ประกาศตัวแปร motionSensor = D1 = GPIO5    
const int motionLED = 12;           // ประกาศตัวแปร motionLED = D6 = GPIO12

int val = 1;

boolean motionTriggered = false;    // ประกาศตัวแปรควบคุมสำหรับฟังก์ชั่น Motion

void setup() {
  Serial.begin(9600);               // เซต Baud rate ของ Serial Port เป็น 9600 ที่ใช้สำหรับ Serial Monitor

  pinMode(motionLED, OUTPUT);       // เซต motionLED เป็น OUTPUT
  attachInterrupt(digitalPinToInterrupt(motionSensor), detectsMovement, RISING);    // เซตการ Interrupt จาก pin -> motionSensor ให้เรียกใช้ฟังก์ชั่น detectsMovement แบบ Rising ตรวจจับขอบขาขึ้น
}

// ฟังก์ชั่นเช็คการเคลื่อนไหว
void detectsMovement() {
  if (!motionTriggered) {                       // เช็คถ้า motionTriggered = false (ยังไม่เคยถูก trig มาก่อน) ให้ทำคำสั่งวงเล็บ
    Serial.println("Detected!!!");              // ส่งข้อความออกทาง Serial Monitor พร้อมขึ้นบรรทัดใหม่
    digitalWrite(motionLED, HIGH);              // ทำการสั่ง ON LED โดยส่ง High state
    Serial.print(val);                          // arduino ส่งค่าในตัวแปล val ให้ arduino
    motionTriggered = true;                     // เซต motionTriggered = true ว่าถูก trig แล้ว 
  }
}
 
void loop() {
  if (motionTriggered)                          // เช็คถ้า motionTriggered = true (ถูก trig แล้ว) ให้ทำคำสั่งวงเล็บ      
  {
    delay(5000);                                // หน่วงเวลา 5 วินาที รอตรวจจับความเคลื่อนไหวรอบใหม่
    motionTriggered = false;                    // ทำการเคลียร์ motionTriggered = false เพื่อตรวจจับความเคลื่อนไหวรอบใหม่
    digitalWrite(motionLED, LOW);               // ทำการสั่ง OFF LED โดยส่ง Low state
    Serial.print(val);                          // arduino ส่งค่าในตัวแปล val ให้ arduino
    Serial.println("Not Detected -- Start to Detect again !!");      // ส่งข้อความออกทาง Serial Monitor พร้อมขึ้นบรรทัดใหม่
  }
}
