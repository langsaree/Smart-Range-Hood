/****************
  คอร์ส การใช้งาน ESP8266 ฉบับจับมือทำ สำหรับผู้เริ่มต้น
  https://www.facebook.com/IOTProductDesign/
****************/
#include "DHT.h"          // include file .h เพื่อใช้งาน Library
 
#define DHTPIN 2         // DHT Pin  กำหนดเป็น D4
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321 หากใช้ DHT22 ให้ uncomment บรรทัดนี้ แล้ว comment บรรทัด DHT11 ออกแทน

DHT dht(DHTPIN, DHTTYPE); // ประกาศตัวแปรคลาส dht

void setup() {
  Serial.begin(9600);                       // เซต Baud rate ของ Serial Port เป็น 9600 ที่ใช้สำหรับ Serial Monitor
  Serial.println("DHT22  Sensor");    // ส่งข้อความออกทาง Serial Monitor พร้อมขึ้นบรรทัดใหม่
  dht.begin();                              // initial ตัวแปรคลาส dht
}
 
void loop() {
  
  delay(2000);                              // หน่วงเวลา 2 วินาทีให้เซนเซอร์ทำงาน
  float h = dht.readHumidity();             // อ่านค่าความชื้นด้วยฟังก์ชั่น readHumidity ไปยังตัวแปร h
  float t = dht.readTemperature();          // อ่านค่าอุณหภูมิด้วยฟังก์ชั่น readTemperature ไปยังตัวแปร t
  float f = dht.readTemperature(true);      // ส่งผ่าน True ไปยังฟังก์ชั่น readTemperature เพื่ออ่านค่าเป็นหน่วย Fahrenheit ไปยังตัวแปร f
 
  
  if (isnan(h) || isnan(t) || isnan(f)) {                 // เช็คตัวแปรทุกตัวมีตัวใดตัวหนึ่งเป็น อนันต์ ถือว่าอ่านค่าไม่สำเร็จ
    Serial.println("Failed to read from DHT sensor!");    // ส่งข้อความออกทาง Serial Monitor พร้อมขึ้นบรรทัดใหม่
    return;                                               // เช็คถ้าอ่านค่าไม่สำเร็จให้เริ่มอ่านใหม่ โดยกระโดดกลับไปยังบรรทัด loop() ใหม่
  }
 
  Serial.print("DHT22 Humidity: ");                       // ส่งข้อความออกทาง Serial Monitor
  Serial.print(h);
  Serial.print(" %\t");                                   // \t คือการใช้ Tab จะเว้นระยะห่างตัวอักษรเหมือนใช้โปรแกรมพิมพ์ Word ทั่วไป
  Serial.print("DHT22 Temperature: ");
  Serial.print(t);
  Serial.print(" *C ");
  Serial.print(f);
  Serial.print(" *F\t\n");                                // \n คือการกด Enter จะขึ้นบรรทัดใหม่เหมือนใช้โปรแกรมพิมพ์ Word ทั่วไป
}
