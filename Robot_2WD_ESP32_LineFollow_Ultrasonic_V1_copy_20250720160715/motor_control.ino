void forward() {
  detect = false;
  Serial.println("forward");
  /////// Left Motor ///////        
  analogWrite(motorA_IN1, speed_l);
  analogWrite(motorA_IN2, 0);
  /////// Right Motor ///////
  analogWrite(motorB_IN1, speed_r);
  analogWrite(motorB_IN2, 0);
  /////////// LED ///////////
  digitalWrite(led_red, LOW);     //สั่งให้ LED สีแดง ไฟดับ
  digitalWrite(led_yellow, LOW);  //สั่งให้ LED สีเหลือง ไฟดับ
  digitalWrite(led_green, HIGH);  //สั่งให้ LED สีเขียว ไฟติด
}

void backward() {
  Serial.println("backward");
  /////// Left Motor ///////        
  analogWrite(motorA_IN1, 0);
  analogWrite(motorA_IN2, speed_l);
  /////// Right Motor ///////
  analogWrite(motorB_IN1, 0);
  analogWrite(motorB_IN2, speed_r);
  /////////// LED ///////////
  digitalWrite(led_red, LOW);     //สั่งให้ LED สีแดง ไฟดับ
  digitalWrite(led_yellow, LOW);  //สั่งให้ LED สีเหลือง ไฟดับ
  digitalWrite(led_green, HIGH);  //สั่งให้ LED สีเขียว ไฟติด
}

void left() {
  Serial.println("oneLeft");
  /////// Left Motor ///////        
  analogWrite(motorA_IN1, speed_l - offset_speed_3);
  analogWrite(motorA_IN2, 0);
  /////// Right Motor ///////
  analogWrite(motorB_IN1, speed_r - offset_speed_1);
  analogWrite(motorB_IN2, 0);
  /////////// LED ///////////
  digitalWrite(led_red, LOW);      //สั่งให้ LED สีแดง ไฟดับ
  digitalWrite(led_yellow, HIGH);  //สั่งให้ LED สีเหลือง ไฟติด
  digitalWrite(led_green, LOW);    //สั่งให้ LED สีเขียว ไฟดับ
}

void right() {
  Serial.println("oneRight");
  /////// Left Motor ///////        
  analogWrite(motorA_IN1, speed_l - offset_speed_1);
  analogWrite(motorA_IN2, 0);
  /////// Right Motor ///////
  analogWrite(motorB_IN1, speed_r - offset_speed_3);
  analogWrite(motorB_IN2, 0);
  /////////// LED ///////////
  digitalWrite(led_red, LOW);      //สั่งให้ LED สีแดง ไฟดับ
  digitalWrite(led_yellow, HIGH);  //สั่งให้ LED สีเหลือง ไฟติด
  digitalWrite(led_green, LOW);    //สั่งให้ LED สีเขียว ไฟดับ
}

void oneLeft() {
  Serial.println("oneLeft");
  /////// Left Motor ///////        
  analogWrite(motorA_IN1, 0);
  analogWrite(motorA_IN2, 0);
  /////// Right Motor ///////
  analogWrite(motorB_IN1, speed_r);
  analogWrite(motorB_IN2, 0);
  /////////// LED ///////////
  digitalWrite(led_red, LOW);      //สั่งให้ LED สีแดง ไฟดับ
  digitalWrite(led_yellow, HIGH);  //สั่งให้ LED สีเหลือง ไฟติด
  digitalWrite(led_green, LOW);    //สั่งให้ LED สีเขียว ไฟดับ
}

void oneRight() {
  Serial.println("oneRight");
  /////// Left Motor ///////        
  analogWrite(motorA_IN1, speed_l);
  analogWrite(motorA_IN2, 0);
  /////// Right Motor ///////
  analogWrite(motorB_IN1, 0);
  analogWrite(motorB_IN2, 0);
  /////////// LED ///////////
  digitalWrite(led_red, LOW);      //สั่งให้ LED สีแดง ไฟดับ
  digitalWrite(led_yellow, HIGH);  //สั่งให้ LED สีเหลือง ไฟติด
  digitalWrite(led_green, LOW);    //สั่งให้ LED สีเขียว ไฟดับ
}

void turnLeft() {  //ฟังก์ชันเลี้ยวซ้ายสองล้อสวนทางกัน
  Serial.println("turnLeft");
  /////// Left Motor ///////        
  analogWrite(motorA_IN1, 0);
  analogWrite(motorA_IN2, speed_l - offset_speed_2);
  /////// Right Motor ///////
  analogWrite(motorB_IN1, speed_r - offset_speed_2);
  analogWrite(motorB_IN2, 0);
  /////////// LED ///////////
  digitalWrite(led_red, LOW);      //สั่งให้ LED สีแดง ไฟดับ
  digitalWrite(led_yellow, HIGH);  //สั่งให้ LED สีเหลือง ไฟติด
  digitalWrite(led_green, LOW);    //สั่งให้ LED สีเขียว ไฟดับ
}

void turnRight() {  //ฟังก์ชันเลี้ยวขวาสองล้อสวนทางกัน
  Serial.println("turnRight");
  /////// Left Motor ///////        
  analogWrite(motorA_IN1, speed_l - offset_speed_2);
  analogWrite(motorA_IN2, 0);
  /////// Right Motor ///////
  analogWrite(motorB_IN1, 0);
  analogWrite(motorB_IN2, speed_r - offset_speed_2);
  /////////// LED ///////////
  digitalWrite(led_red, LOW);      //สั่งให้ LED สีแดง ไฟดับ
  digitalWrite(led_yellow, HIGH);  //สั่งให้ LED สีเหลือง ไฟติด
  digitalWrite(led_green, LOW);    //สั่งให้ LED สีเขียว ไฟดับ
}

void STOP() {  //ฟังก์ชันหยุด
  Serial.println("STOP");
  /////// Left Motor ///////        
  analogWrite(motorA_IN1, 255);
  analogWrite(motorA_IN2, 255);
  /////// Right Motor ///////
  analogWrite(motorB_IN1, 255);
  analogWrite(motorB_IN2, 255);
  /////////// LED ///////////
  digitalWrite(led_red, HIGH);    //สั่งให้ LED สีแดง ไฟติด
  digitalWrite(led_yellow, LOW);  //สั่งให้ LED สีเหลือง ไฟดับ
  digitalWrite(led_green, LOW);   //สั่งให้ LED สีเขียว ไฟดับ
}
