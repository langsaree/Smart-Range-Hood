/* 
 * ไลบรารี่ TridentTD_LineNotify version 2.1
 * ใช้สำหรับ ส่ง แจ้งเตือนไปยัง LINE สำหรับ ESP8266 และ ESP32
 * สามารถส่งได้ทั้ง ข้อความ , สติกเกอร์ และรูปภาพ(ด้วย url)
 * -----------------------------------------------------
 * ให้ save เป็น file ต่างหากก่อนถึงจะส่ง Line Notify ภาษาไทยได้
 */

#include <TridentTD_LineNotify.h>

#define SSID        "BrainwaveEshop"
#define PASSWORD    "0837684321"
#define LINE_TOKEN  "qdEvAxTa53l6sEraNve4YopoTXJIUxArY7ee0ibOHPw"

void setup() {
  Serial.begin(115200); Serial.println();
  Serial.println(LINE.getVersion());
  
  WiFi.begin(SSID, PASSWORD);
  Serial.printf("WiFi connecting to %s\n",  SSID);
  while(WiFi.status() != WL_CONNECTED) { Serial.print("."); delay(400); }
  Serial.printf("\nWiFi connected\nIP : ");
  Serial.println(WiFi.localIP());  

  // กำหนด Line Token
  LINE.setToken(LINE_TOKEN);

  // ตัวอย่างส่งข้อความ
  LINE.notify("อุณหภูมิ เกินกำหนด");

  // ตัวอย่างส่งข้อมูล ตัวเลข
  LINE.notify("Hello / Hi Temp is overdue");          // จำนวนเต็ม

  // เลือก Line Sticker ได้จาก https://devdocs.line.me/files/sticker_list.pdf
  // LINE.notifySticker(2,39);        // ส่ง Line Sticker ด้วย PackageID 3 , StickerID 240
  LINE.notifySticker("come on 22 Quickly to check me !!!!! ",2,19);  // ส่ง Line Sticker ด้วย PackageID 1 , StickerID 2  พร้อมข้อความ

  // ตัวอย่างส่ง รูปภาพ ด้วย url
  LINE.notifyPicture("ไฟไหม้ .....","https://png.pngtree.com/png-clipart/20190617/original/pngtree-fire-safety-fire-fire-prevention-fire-png-image_3827808.jpg");
 // LINE.notifyPicture("จตุธาตุ","https://www.fotoaparat.cz/storage/pm/09/10/23/670915_a5351.jpg");
}

void loop() {
  delay(1);
}
