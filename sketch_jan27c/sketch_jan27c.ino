#include <DHT22.h>
#include "LittleFS.h"

#define pinDATA 19 
DHT22 dht22(pinDATA); 

void setup() {
  Serial.begin(115200);
  Serial.println("\n--- ESP32 DHT22 Datalogger ---");

  // 1. เริ่มต้นระบบไฟล์ LittleFS
  if(!LittleFS.begin(true)){
    Serial.println("An Error has occurred while mounting LittleFS");
    return;
  }
  Serial.println("LittleFS mounted successfully");
}

void loop() {
  // อ่านค่าจากเซนเซอร์
  float t = dht22.getTemperature();
  float h = dht22.getHumidity();

  if (dht22.getLastError() != dht22.OK) {
    Serial.print("Sensor error: ");
    Serial.println(dht22.getLastError());
  } else {
    // แสดงผลทาง Serial Monitor
    Serial.print("H="); Serial.print(h, 1);
    Serial.print("%  T="); Serial.print(t, 1); Serial.println("C");

    // 2. บันทึกลงไฟล์
    appendFile(LittleFS, "/datalog.txt", h, t);
  }

  delay(5000); // บันทึกทุกๆ 5 วินาที (ปรับเปลี่ยนได้ตามต้องการ)
}

// ฟังก์ชันสำหรับเขียนข้อมูลต่อท้ายไฟล์ (Append)
void appendFile(fs::FS &fs, const char * path, float humidity, float temp){
  File file = fs.open(path, FILE_APPEND);
  if(!file){
    Serial.println("- failed to open file for appending");
    return;
  }

  // สร้างรูปแบบข้อความที่จะบันทึก เช่น "H: 45.5, T: 28.0"
  String dataLine = "H: " + String(humidity, 1) + "%, T: " + String(temp, 1) + "C\n";

  if(file.print(dataLine)){
    Serial.println("- Message appended");
  } else {
    Serial.println("- Append failed");
  }
  file.close();
}

