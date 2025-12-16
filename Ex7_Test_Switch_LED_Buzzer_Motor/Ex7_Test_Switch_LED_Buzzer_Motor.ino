///////////////////////////////////////////////////////////////////////////////////////
// Robot 2WD Line Tracking Ultrasonic             Version 3.0                        //
// Create : Mr.Chartthai Santhanaboun by #EarthElectronics #ThaiRoboShop #ThaiRobo3D //
// Date : 19/05/2025                                                                 //
// Hardware : Robot 2WD, Arduino ESP32, Line Sensor Module, Ultrasonic Sensor, LED   //
// Software : Version 3.0                                                            //
///////////////////////////////////////////////////////////////////////////////////////

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

//Value Speed motor Control
int speed_l = 190;
int speed_r = 195;  //0-255

void setup() {
  Serial.begin(115200);           // กำหนดความเร็ว Baudrate SerialPort
  Serial.println("Robot_Ready");  // พิมพ์ข้อความโชว์ผ่านทาง Serial Monitor ว่า "Robot_Ready"

  // Set button controller pins as input
  pinMode(button, INPUT_PULLUP);  // กำหนดให้ขา button เป็น INPUT แบบ PULLUP

  // Set buzzer controller pins as output
  pinMode(buzzer, OUTPUT);     // กำหนดให้ขา buzzer เป็น OUTPUT
  digitalWrite(buzzer, HIGH);  //กำหนดค่าเริ่มต้นของ buzzer ให้ไม่ดัง

  // Set LED controller pins as output
  pinMode(led_red, OUTPUT);                   //กำหนดให้ LED สีแดง เป็น OUTPUT
  pinMode(led_yellow, OUTPUT);                //กำหนดให้ LED สีเหลือง เป็น OUTPUT
  pinMode(led_green, OUTPUT);                 //กำหนดให้ LED สีเขียว เป็น OUTPUT

  // Set motor controller pins as output
  pinMode(motorA_IN1, OUTPUT);  // กำหนดให้ขา motorA_IN1 เป็น OUTPUT
  pinMode(motorA_IN2, OUTPUT);  // กำหนดให้ขา motorA_IN2 เป็น OUTPUT
  pinMode(motorB_IN1, OUTPUT);  // กำหนดให้ขา motorB_IN1 เป็น OUTPUT
  pinMode(motorB_IN2, OUTPUT);  // กำหนดให้ขา motorB_IN2 เป็น OUTPUT
  // กำหนดค่าให้มอเตอร์หยุดหมุนตั้งแต่แรก
  /////// Left Motor ///////   /////// Right Motor ///////
  analogWrite(motorA_IN1, 0);
  analogWrite(motorB_IN1, 0);
  analogWrite(motorA_IN2, 0);
  analogWrite(motorB_IN2, 0);

  beep();  // สั่งงานให้ Buzzer ส่งเสียงดัง 1 ครั้ง
  delay(300);
}

void loop() {
  while (digitalRead(button) == 1)
    ;  //รอการกดปุ่มเพื่อเริ่มการทำงาน
  beep();

  Serial.println("Push Switch");
  digitalWrite(led_red, HIGH);     //สั่งให้ LED สีแดง ไฟติด
  digitalWrite(led_yellow, HIGH);  //สั่งให้ LED สีเหลือง ไฟติด
  digitalWrite(led_green, HIGH);   //สั่งให้ LED สีเขียว ไฟติด
  delay(1000);
  digitalWrite(led_red, LOW);     //สั่งให้ LED สีแดง ไฟดับ
  digitalWrite(led_yellow, LOW);  //สั่งให้ LED สีเหลือง ไฟดับ
  digitalWrite(led_green, LOW);   //สั่งให้ LED สีเขียว ไฟดับ
  delay(500);
  digitalWrite(led_red, HIGH);     //สั่งให้ LED สีแดง ไฟติด
  digitalWrite(led_yellow, HIGH);  //สั่งให้ LED สีเหลือง ไฟติด
  digitalWrite(led_green, HIGH);   //สั่งให้ LED สีเขียว ไฟติด
  delay(1000);
  digitalWrite(led_red, LOW);     //สั่งให้ LED สีแดง ไฟดับ
  digitalWrite(led_yellow, LOW);  //สั่งให้ LED สีเหลือง ไฟดับ
  digitalWrite(led_green, LOW);   //สั่งให้ LED สีเขียว ไฟดับ
  delay(500);
  digitalWrite(led_red, HIGH);     //สั่งให้ LED สีแดง ไฟติด
  digitalWrite(led_yellow, HIGH);  //สั่งให้ LED สีเหลือง ไฟติด
  digitalWrite(led_green, HIGH);   //สั่งให้ LED สีเขียว ไฟติด
  delay(1000);
  digitalWrite(led_red, LOW);     //สั่งให้ LED สีแดง ไฟดับ
  digitalWrite(led_yellow, LOW);  //สั่งให้ LED สีเหลือง ไฟดับ
  digitalWrite(led_green, LOW);   //สั่งให้ LED สีเขียว ไฟดับ
  delay(500);

  beep();
  delay(500);
  forward();    //เดินหน้า
  delay(2000);
  backward();   //ถอยหลัง
  delay(2000);
  oneLeft();    //เลี้ยวซ้ายข้างเดียว
  delay(2000);
  oneRight();   //เลี้ยวขวาข้างเดียว
  delay(2000);
  turnLeft();   //หมุนซ้าย
  delay(2000);
  turnRight();  //หมุนขวา
  delay(2000);
  STOP();
  beep();
  beep();
}

void beep() {
  digitalWrite(buzzer, LOW);  //ติด
  delay(50);
  digitalWrite(buzzer, HIGH);  //ดับ
  delay(50);
}

void forward() {
  Serial.println("forward");
  /////// Left Motor ///////        /////// Right Motor ///////
  analogWrite(motorA_IN1, speed_l);
  analogWrite(motorB_IN1, speed_r);
  analogWrite(motorA_IN2, 0);
  analogWrite(motorB_IN2, 0);
  digitalWrite(led_red, LOW);     //สั่งให้ LED สีแดง ไฟดับ
  digitalWrite(led_yellow, LOW);  //สั่งให้ LED สีเหลือง ไฟดับ
  digitalWrite(led_green, HIGH);  //สั่งให้ LED สีเขียว ไฟติด
}

void backward() {
  Serial.println("backward");
  /////// Left Motor ///////        /////// Right Motor ///////
  analogWrite(motorA_IN1, 0);
  analogWrite(motorB_IN1, 0);
  analogWrite(motorA_IN2, speed_l);
  analogWrite(motorB_IN2, speed_r);
  digitalWrite(led_red, LOW);     //สั่งให้ LED สีแดง ไฟดับ
  digitalWrite(led_yellow, LOW);  //สั่งให้ LED สีเหลือง ไฟดับ
  digitalWrite(led_green, HIGH);  //สั่งให้ LED สีเขียว ไฟติด
}

void oneLeft() {
  Serial.println("oneLeft");
  /////// Left Motor ///////        /////// Right Motor ///////
  analogWrite(motorA_IN1, 0);
  analogWrite(motorB_IN1, speed_r);
  analogWrite(motorA_IN2, 0);
  analogWrite(motorB_IN2, 0);
  digitalWrite(led_red, LOW);      //สั่งให้ LED สีแดง ไฟดับ
  digitalWrite(led_yellow, HIGH);  //สั่งให้ LED สีเหลือง ไฟติด
  digitalWrite(led_green, LOW);    //สั่งให้ LED สีเขียว ไฟดับ
}

void oneRight() {
  Serial.println("oneRight");
  /////// Left Motor ///////        /////// Right Motor ///////
  analogWrite(motorA_IN1, speed_l);
  analogWrite(motorB_IN1, 0);
  analogWrite(motorA_IN2, 0);
  analogWrite(motorB_IN2, 0);
  digitalWrite(led_red, LOW);      //สั่งให้ LED สีแดง ไฟดับ
  digitalWrite(led_yellow, HIGH);  //สั่งให้ LED สีเหลือง ไฟติด
  digitalWrite(led_green, LOW);    //สั่งให้ LED สีเขียว ไฟดับ
}

void turnLeft() {  //ฟังก์ชันเลี้ยวซ้ายสองล้อสวนทางกัน
  Serial.println("turnLeft");
  /////// Left Motor ///////        /////// Right Motor ///////
  analogWrite(motorA_IN1, 0);
  analogWrite(motorB_IN1, speed_r);
  analogWrite(motorA_IN2, speed_l);
  analogWrite(motorB_IN2, 0);
  digitalWrite(led_red, LOW);      //สั่งให้ LED สีแดง ไฟดับ
  digitalWrite(led_yellow, HIGH);  //สั่งให้ LED สีเหลือง ไฟติด
  digitalWrite(led_green, LOW);    //สั่งให้ LED สีเขียว ไฟดับ
}

void turnRight() {  //ฟังก์ชันเลี้ยวขวาสองล้อสวนทางกัน
  Serial.println("turnRight");
  /////// Left Motor ///////        /////// Right Motor ///////
  analogWrite(motorA_IN1, speed_l);
  analogWrite(motorB_IN1, 0);
  analogWrite(motorA_IN2, 0);
  analogWrite(motorB_IN2, speed_r);
  digitalWrite(led_red, LOW);      //สั่งให้ LED สีแดง ไฟดับ
  digitalWrite(led_yellow, HIGH);  //สั่งให้ LED สีเหลือง ไฟติด
  digitalWrite(led_green, LOW);    //สั่งให้ LED สีเขียว ไฟดับ
}

void STOP() {  //ฟังก์ชันหยุด
  Serial.println("STOP");
  /////// Left Motor ///////        /////// Right Motor ///////
  analogWrite(motorA_IN1, 255);
  analogWrite(motorB_IN1, 255);
  analogWrite(motorA_IN2, 255);
  analogWrite(motorB_IN2, 255);
  digitalWrite(led_red, HIGH);    //สั่งให้ LED สีแดง ไฟติด
  digitalWrite(led_yellow, LOW);  //สั่งให้ LED สีเหลือง ไฟดับ
  digitalWrite(led_green, LOW);   //สั่งให้ LED สีเขียว ไฟดับ
}
