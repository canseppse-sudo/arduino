//ห้ามแก้
void readSensor() {  //ฟังก์ชันอ่านค่าเซ็นเซอร์
  lineValue_1 = analogRead(line_1) / 16;
  lineValue_2 = analogRead(line_2) / 16;
  lineValue_3 = analogRead(line_3) / 16;
  lineValue_4 = analogRead(line_4) / 16;
  lineValue_5 = analogRead(line_5) / 16;
  lineValue_6 = analogRead(line_6) / 16;
  lineValue_7 = analogRead(line_7) / 16;
  lineValue_8 = analogRead(line_8) / 16;

  if (lineValue_1 > midValue_1) {
    lineValue_1 = black;
  } else {
    lineValue_1 = white;
  }

  if (lineValue_2 > midValue_2) {
    lineValue_2 = black;
  } else {
    lineValue_2 = white;
  }

  if (lineValue_3 > midValue_3) {
    lineValue_3 = black;
  } else {
    lineValue_3 = white;
  }

  if (lineValue_4 > midValue_4) {
    lineValue_4 = black;
  } else {
    lineValue_4 = white;
  }

  if (lineValue_5 > midValue_5) {
    lineValue_5 = black;
  } else {
    lineValue_5 = white;
  }

  if (lineValue_6 > midValue_6) {
    lineValue_6 = black;
  } else {
    lineValue_6 = white;
  }

  if (lineValue_7 > midValue_7) {
    lineValue_7 = black;
  } else {
    lineValue_7 = white;
  }

  if (lineValue_8 > midValue_8) {
    lineValue_8 = black;
  } else {
    lineValue_8 = white;
  }

  Serial.print("Line :");
  Serial.print('\t');
  Serial.print(lineValue_1);
  Serial.print('\t');
  Serial.print(lineValue_2);
  Serial.print('\t');
  Serial.print(lineValue_3);
  Serial.print('\t');
  Serial.print(lineValue_4);
  Serial.print('\t');
  Serial.print(lineValue_5);
  Serial.print('\t');
  Serial.print(lineValue_6);
  Serial.print('\t');
  Serial.print(lineValue_7);
  Serial.print('\t');
  Serial.println(lineValue_8);
}

void forward_tracking() {  //ฟังก์ชันแทร๊กเส้นไปข้างหน้า
  while (1) {              //ลูปในการอ่านเส้น จะวนลูปแทร๊กเส้นจนกว่าจะเจอแยก
    // read_distance();           //กระโดดไปฟังก์ชันตรวจจับวัตถุ
    readSensor();  //กระโดดไปฟังก์ชันอ่านค่าเส้น

    /////////////////////////////เงื่อนไขที่ใช้ในการตรวจจับเส้น////////////////////////////////////////
    /////////////////////สามารถเพิ่มลดเงื่อนไขได้ ตัวอย่างนี้ใช้เซ็นเซอร์ 6 ตำแหน่ง////////////////////////////////////////
    if (lineValue_2 == white && lineValue_3 == white && lineValue_4 == white && lineValue_5 == white && lineValue_6 == white && lineValue_7 == white) {
      forward();
    } else if (lineValue_2 == white && lineValue_3 == white && lineValue_4 == white && lineValue_5 == white && lineValue_6 == white && lineValue_7 == black) {
      oneRight();
    } else if (lineValue_2 == white && lineValue_3 == white && lineValue_4 == white && lineValue_5 == white && lineValue_6 == black && lineValue_7 == black) {
      oneRight();
    } else if (lineValue_2 == white && lineValue_3 == white && lineValue_4 == white && lineValue_5 == black && lineValue_6 == black && lineValue_7 == black) {
      right();
    } else if (lineValue_2 == white && lineValue_3 == white && lineValue_4 == white && lineValue_5 == white && lineValue_6 == black && lineValue_7 == white) {
      right();
    } else if (lineValue_2 == white && lineValue_3 == white && lineValue_4 == white && lineValue_5 == black && lineValue_6 == black && lineValue_7 == white) {
      right();
    } else if (lineValue_2 == white && lineValue_3 == white && lineValue_4 == black && lineValue_5 == black && lineValue_6 == black && lineValue_7 == white) {
      right();
    } else if (lineValue_2 == white && lineValue_3 == white && lineValue_4 == white && lineValue_5 == black && lineValue_6 == white && lineValue_7 == white) {
      forward();
    } else if (lineValue_2 == white && lineValue_3 == white && lineValue_4 == black && lineValue_5 == black && lineValue_6 == white && lineValue_7 == white) {
      forward();
    } else if (lineValue_2 == white && lineValue_3 == white && lineValue_4 == black && lineValue_5 == white && lineValue_6 == white && lineValue_7 == white) {
      forward();
    } else if (lineValue_2 == white && lineValue_3 == black && lineValue_4 == black && lineValue_5 == black && lineValue_6 == white && lineValue_7 == white) {
      left();
    } else if (lineValue_2 == white && lineValue_3 == black && lineValue_4 == black && lineValue_5 == white && lineValue_6 == white && lineValue_7 == white) {
      left();
    } else if (lineValue_2 == white && lineValue_3 == black && lineValue_4 == white && lineValue_5 == white && lineValue_6 == white && lineValue_7 == white) {
      left();
    } else if (lineValue_2 == black && lineValue_3 == black && lineValue_4 == black && lineValue_5 == white && lineValue_6 == white && lineValue_7 == white) {
      left();
    } else if (lineValue_2 == black && lineValue_3 == black && lineValue_4 == white && lineValue_5 == white && lineValue_6 == white && lineValue_7 == white) {
      oneLeft();
    } else if (lineValue_2 == black && lineValue_3 == white && lineValue_4 == white && lineValue_5 == white && lineValue_6 == white && lineValue_7 == white) {
      oneLeft();
    } else {
      forward();
    }

    //////////////////////////////////////////////////////////// เงื่อนไขเมื่อเจอทางแยก ////////////////////////////////////////////////////////////////
    if (lineValue_2 == black && lineValue_3 == black && lineValue_4 == black && lineValue_5 == black && lineValue_6 == black && lineValue_7 == black) {
      forward();
      delay(time1);
      STOP();
      delay(time3);
      beep();
      //      forward();
      break;
    }

    else if (lineValue_1 == black && lineValue_2 == black && lineValue_3 == black && lineValue_4 == black) {
      forward();
      delay(time1);
      STOP();
      delay(time3);
      beep();
      //      left_tracking();
      break;
    }

    else if (lineValue_5 == black && lineValue_6 == black && lineValue_7 == black && lineValue_8 == black) {
      forward();
      delay(time1);
      STOP();
      delay(time3);
      beep();
      //      right_tracking();
      break;
    }
  }
}

void left_tracking() {  //ฟังก์ชันแทร๊กเส้นเลี้ยวซ้ายจนเจอเส้นใหม่
  turnLeft();
  delay(time2);
  while (analogRead(line_1) / 16 < midValue_1) {  //วนลูปเมื่อยังอ่านค่าเส้นเป็นสีขาว
    turnLeft();
  }
  delay(time6);
  STOP();
  delay(time3);
  beep();
}

void right_tracking() {  //ฟังก์ชันแทร๊กเส้นเลี้ยวขวาจนเจอเส้นใหม่
  turnRight();
  delay(time2);
  while (analogRead(line_8) / 16 < midValue_8) {  //วนลูปเมื่อยังอ่านค่าเส้นเป็นสีขาว
    turnRight();
  }
  delay(time6);
  STOP();
  delay(time3);
  beep();
}