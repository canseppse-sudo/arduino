///////////////////////////////////////////////////////////////////////////////////////
// Robot 2WD Line Tracking Ultrasonic             Version 3.0                        //
// Create : Mr.Chartthai Santhanaboun by #EarthElectronics #ThaiRoboShop #ThaiRobo3D //
// Date : 19/05/2025                                                                 //
// Hardware : Robot 2WD, Arduino ESP32, Line Sensor Module, Ultrasonic Sensor, LED   //
// Software : Version 3.0                                                            //
///////////////////////////////////////////////////////////////////////////////////////
#include <NewPing.h>  // เรียกใช้งานไลบรารี NewPing
#include <EEPROM.h>   // เรียกใช้งานไลบรารี EEPROM

#define EEPROM_SIZE 8

const int TRIGGER_PIN = 13;   // กำหนดตำแหน่งขา trigger ของ ultrasonic sensor.
const int ECHO_PIN = 5;       // กำหนดตำแหน่งขา echo ของ ultrasonic sensor.
const int MAX_DISTANCE = 30;  // กำหนดระยะทางสูงสุดที่ต้องการตรวจจับหน่วยเป็น (centimeters). ค่าสูงสุดที่กำหนดได้ประมาณ 400-500cm.
// Create Ultrasonic object
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);  // ตั้งค่าตำแหน่งขาที่ใช้ของ ultrasonic และระยะสูงสุดที่ต้องการอ่านค่า

// Define channels for each motor
const int motorA_IN1 = 2;   // กำหนดขาที่ใช้สั่งงานบอร์ดขับมอเตอร์
const int motorA_IN2 = 4;   // กำหนดขาที่ใช้สั่งงานบอร์ดขับมอเตอร์
const int motorB_IN1 = 16;  // กำหนดขาที่ใช้สั่งงานบอร์ดขับมอเตอร์
const int motorB_IN2 = 17;  // กำหนดขาที่ใช้สั่งงานบอร์ดขับมอเตอร์

// Define channels for Buzzer
const int buzzer = 15;

// Define channels for Button
const int button = 27;

// Define channels for LED
const int led_red = 23;     //กำหนดให้ขา 23 เป็นขาสั่งงาน LED สีแดง
const int led_yellow = 19;  //กำหนดให้ขา 19 เป็นขาสั่งงาน LED สีเหลือง
const int led_green = 18;   //กำหนดให้ขา 18 เป็นขาสั่งงาน LED สีเขียว

// Define channels for Line Tracking Sensor
const int line_1 = 26;  // กำหนดขา GPIO ของเซ็นเซอร์ตรวจจับเส้น ที่เชื่อมต่อกับ ESP32
const int line_2 = 25;
const int line_3 = 33;
const int line_4 = 32;
const int line_5 = 35;
const int line_6 = 34;
const int line_7 = 39;
const int line_8 = 36;

//ค่าตัวแปลเก็บค่าระยะทาง
int distance;         // สร้างตัวแปลเก็บค่าระยะทาง
bool detect = false;  // สร้างตัวแปลตรวจจับวัตถุ
int count = 0;        // สร้างตัวแปลนับจำนวนวัตถุ

//Line Value
int lineValue_1, lineValue_2, lineValue_3, lineValue_4,  // สร้างตัวแปรเก็บค่าการตรวจจับเส้นของเซ็นเซอร์แต่ละตำแหน่ง
  lineValue_5, lineValue_6, lineValue_7, lineValue_8;

int midValue_1, midValue_2, midValue_3, midValue_4,  // สร้างตัวแปรเก็บค่าแบ่งค่ากลางระหว่างขาวกับดำ
  midValue_5, midValue_6, midValue_7, midValue_8;

int blackValue_1, blackValue_2, blackValue_3, blackValue_4,  // สร้างตัวแปรเก็บค่าสีดำ
  blackValue_5, blackValue_6, blackValue_7, blackValue_8;

int whiteValue_1, whiteValue_2, whiteValue_3, whiteValue_4,  // สร้างตัวแปรเก็บค่าสีขาว
  whiteValue_5, whiteValue_6, whiteValue_7, whiteValue_8;

//Line Detect
const int black = 1;  // สร้างตัวแปลเพื่อระบุค่าสีดำ
const int white = 0;  // สร้างตัวแปลเพื่อระบุค่าสีขาว

//Value Speed motor Control
int speed_l = 170;
int speed_r = 150;        // ตั้งค่าความเร็วมอเตอร์ซ้ายและขวาสามารถตั้งค่าได้ตั้งแต่ 0-255
int offset_speed_1 = 20;  // ตั้งค่าความต่างของความเร็วมอเตอร์แล้วแต่จะใช้ก็ได้ไม่ใช้ก็ได้
int offset_speed_2 = 50;
int offset_speed_3 = 40;

// Timer สำหรับหน่วงเวลา จะกำหนดกี่ตัวก็ได้
int time1 = 160;   //ค่าหน่วงเวลา ใช้สำหรับการเดินหน้าของหุ่นยนต์
int time2 = 300;   //ค่าหน่วงเวลา ใช้สำหรับการเลี้ยวของหุ่นยนต์
int time3 = 10;    //ค่าหน่วงเวลา ใช้สำหรับคั้นคำสั่งในการเคลื่อนที่
int time4 = 1000;  //ค่าหน่วงเวลา ใช้สำหรับการหยุดหุ่นยนต์เพื่อตรวจจับสีของสิ่งของ
int time5 = 400;   //ค่าหน่วงเวลา ใช้สำหรับการถอยหลัง
int time6 = 10;    //ค่าหน่วงเวลา ใช้สำหรับตอนเลี้ยวแต่ละแยก
int time7 = 530;   //ค่าหน่วงเวลา ใช้สำหรับหมุนหลบสิ่งกีดขวาง
int time8 = 600;   //ค่าหน่วงเวลา ใช้ทางตรงสั้นหลบสิ่งกีดขวาง
int time9 = 1200;  //ค่าหน่วงเวลา ใช้ทางตรงยาวหลบสิ่งกีดขวาง

void setup() {
  EEPROM.begin(EEPROM_SIZE);
  Serial.begin(115200);           // กำหนดความเร็ว Baudrate SerialPort
  Serial.println("Robot_Ready");  // พิมพ์ข้อความโชว์ผ่านทาง Serial Monitor ว่า "Robot_Ready"

  initial();  //Setting INPUT, OUTPUT

  //////////////////////////////ตรวจเช็คการเข้าโหมดเก็บค่าเส้น///////////////////////////////////////////
  if (digitalRead(button) == 0) {  //ถ้าเริ่มโปรแกรมปุ่มถูกกดแต่แรกจะเข้าโหมดเก็บค่าเส้น
    write_eeprom();                //ฟังก์ชันเก็บค่าเส้นใหม่
  } else {                         //ถ้าเริ่มโปรแกรมมาปุ่มกดไม่ถูกกดโปรแกรมจะทำการดึงค่าเส้นที่บันทึกไว้มาใช้เลย
    read_eeprom();                 //ฟังก์ชันอ่านค่าเส้น
  }
  ////////////////////////////////////////////////////////////////////////////////////////////////

  wait_start();  //รอการกดปุ่ม Start เริ่มต้นการทำงาน

  //////////////////////////////////////////////////////////////////////////////////
  /////////////////////พื้นที่สำหรับเขียนโปรแกรมเดินตามเส้น//////////////////////////////
  forward();
  delay(1000);

  // forward_tracking();]
  // right_tracking();
  // forward_tracking();
  // right_tracking();
  // forward_tracking();
  // right_tracking();
  // forward_tracking();

  // forward_tracking();
  // left_tracking();
  // forward_tracking();
  // left_tracking();
  // forward_tracking();
  // left_tracking();
  // forward_tracking();

  forward();
  delay(1000);
  STOP();

  ///////////////////////////////////////////////////////////////////////////////
  /////////////////////////พื้นที่วางชื่อฟังก์ชั่นที่ใช้งานได้สำหรับคัดลอกนำไปวางทางด้านบน//////////
  //  forward_tracking();                       // ฟังก์ชันการเดินหน้าไปด้วยตรวจจับเส้นไปด้วย
  //  right_tracking();                         // ฟังก์ชันการเลี้ยวขวาจนกว่าจะเจอเส้น
  //  left_tracking();                          // ฟังก์ชันการเลี้ยวซ้ายจนกว่าจะเจอเส้น
  //  forward();                                // ฟังก์ชันเดินหน้า
  //  backward();                               // ฟังก์ชันถอยหลัง
  //  left();                                   // ฟังก์ชันเลี้ยวซ้ายแบบลดความเร็ว
  //  right();                                  // ฟังก์ชันเลี้ยวขวาแบบลดความเร็ว
  //  oneLeft();                                // ฟังก์ชันเลี้ยวซ้ายแบบข้างเดียว
  //  oneRight();                               // ฟังก์ชันเลี้ยวขวาแบบข้างเดียว
  //  turnLeft();                               // ฟังก์ชันหมุนซ้าย 2 ล้อสวนทาง
  //  turnRight();                              // ฟังก์ชันหมุนขวา 2 ล้อสวนทาง
  //  STOP();
  ///////////////////////ตัวอย่างท่าเดินถอยหลังแล้วกลับหลังหัน///////////////////////////////
  //  backward();delay(time5);                  // ถอยหลัง
  //  right_tracking();                         // ฟังก์ชัน การเลี้ยวขวาตรงทางแยก
  //  forward_tracking();                       // ฟังก์ชันการเดินหน้าไปด้วยตรวจจับเส้นไปด้วย
  //////////////////////////////////////////////////////////////////////////////////
}

void loop() {
  // readSensor();
  // forward_tracking();
}

void initial() {  //ฟังก์ชันตั้งค่าเริ่มต้นของ INPUT, OUTPUT
  // Set button controller pins as input
  pinMode(button, INPUT_PULLUP);  // กำหนดให้ขา button เป็น INPUT แบบ PULLUP

  // Set buzzer controller pins as output
  pinMode(buzzer, OUTPUT);     // กำหนดให้ขา buzzer เป็น OUTPUT
  digitalWrite(buzzer, HIGH);  //กำหนดค่าเริ่มต้นของ buzzer ให้ไม่ดัง

  // Set LED controller pins as output
  pinMode(led_red, OUTPUT);     //กำหนดให้ LED สีแดง เป็น OUTPUT
  pinMode(led_yellow, OUTPUT);  //กำหนดให้ LED สีเหลือง เป็น OUTPUT
  pinMode(led_green, OUTPUT);   //กำหนดให้ LED สีเขียว เป็น OUTPUT

  // Set motor controller pins as output
  pinMode(motorA_IN1, OUTPUT);  // กำหนดให้ขา motorA_IN1 เป็น OUTPUT
  pinMode(motorA_IN2, OUTPUT);  // กำหนดให้ขา motorA_IN2 เป็น OUTPUT
  pinMode(motorB_IN1, OUTPUT);  // กำหนดให้ขา motorB_IN1 เป็น OUTPUT
  pinMode(motorB_IN2, OUTPUT);  // กำหนดให้ขา motorB_IN2 เป็น OUTPUT

  // กำหนดค่าให้มอเตอร์หยุดหมุนตั้งแต่แรก
  /////// Left Motor ///////   
  analogWrite(motorA_IN1, 0);
  analogWrite(motorB_IN1, 0);
  /////// Right Motor ///////
  analogWrite(motorA_IN2, 0);
  analogWrite(motorB_IN2, 0);

  beep();  // สั่งงานให้ Buzzer ส่งเสียงดัง 1 ครั้ง
  delay(300);
}

void wait_start() {                   //ฟังก์ชันรอการกดปุ่ม
  while (digitalRead(button) != 0) {  //ติดลูปค้างไว้ถ้ายังไม่กดปุ่ม
    ;
  }
  Serial.println("Push Switch");
  delay(300);
}

void beep() {
  digitalWrite(buzzer, LOW);  //ติด
  delay(50);
  digitalWrite(buzzer, HIGH);  //ดับ
  delay(50);
}