void memory_black() {                           //ฟังก์ชันเก็บค่าสีดำ
  for (int i = 0; i <= 20; i++) {
    blackValue_1 += analogRead(line_1);
    blackValue_2 += analogRead(line_2);
    blackValue_3 += analogRead(line_3);
    blackValue_4 += analogRead(line_4);
    blackValue_5 += analogRead(line_5);
    blackValue_6 += analogRead(line_6);
    blackValue_7 += analogRead(line_7);
    blackValue_8 += analogRead(line_8);
    delay(20);
  }
  blackValue_1 /= 20 * 16;
  blackValue_2 /= 20 * 16;
  blackValue_3 /= 20 * 16;
  blackValue_4 /= 20 * 16;
  blackValue_5 /= 20 * 16;
  blackValue_6 /= 20 * 16;
  blackValue_7 /= 20 * 16;
  blackValue_8 /= 20 * 16;

  beep();beep();
  
  Serial.print("Black : ");  Serial.print(blackValue_1);  Serial.print('\t');
  Serial.print(blackValue_2);  Serial.print('\t');
  Serial.print(blackValue_3);  Serial.print('\t');
  Serial.print(blackValue_4);  Serial.print('\t');
  Serial.print(blackValue_5);  Serial.print('\t');
  Serial.print(blackValue_6);  Serial.print('\t');
  Serial.print(blackValue_7);  Serial.print('\t');
  Serial.println(blackValue_8);  //Serial.print('\t');
}

void memory_white() {                             //ฟังก์ชันเก็บค่าสีขาว
  for (int i = 0; i <= 20; i++) {
    whiteValue_1 += analogRead(line_1);
    whiteValue_2 += analogRead(line_2);
    whiteValue_3 += analogRead(line_3);
    whiteValue_4 += analogRead(line_4);
    whiteValue_5 += analogRead(line_5);
    whiteValue_6 += analogRead(line_6);
    whiteValue_7 += analogRead(line_7);
    whiteValue_8 += analogRead(line_8);
    delay(20);
  }
  whiteValue_1 /= 20 * 16;
  whiteValue_2 /= 20 * 16;
  whiteValue_3 /= 20 * 16;
  whiteValue_4 /= 20 * 16;
  whiteValue_5 /= 20 * 16;
  whiteValue_6 /= 20 * 16;
  whiteValue_7 /= 20 * 16;
  whiteValue_8 /= 20 * 16;
  
  beep();beep();
  
  Serial.print("White : ");  Serial.print(whiteValue_1);  Serial.print('\t');
  Serial.print(whiteValue_2);  Serial.print('\t');
  Serial.print(whiteValue_3);  Serial.print('\t');
  Serial.print(whiteValue_4);  Serial.print('\t');
  Serial.print(whiteValue_5);  Serial.print('\t');
  Serial.print(whiteValue_6);  Serial.print('\t');
  Serial.print(whiteValue_7);  Serial.print('\t');
  Serial.println(whiteValue_8);
}

void compare() {                                //ฟังก์ชันหาค่ากึ่งกลางระหว่างสีขาวกับดำ
  midValue_1 = (blackValue_1 + whiteValue_1) / 2;
  midValue_2 = (blackValue_2 + whiteValue_2) / 2;
  midValue_3 = (blackValue_3 + whiteValue_3) / 2;
  midValue_4 = (blackValue_4 + whiteValue_4) / 2;
  midValue_5 = (blackValue_5 + whiteValue_5) / 2;
  midValue_6 = (blackValue_6 + whiteValue_6) / 2;
  midValue_7 = (blackValue_7 + whiteValue_7) / 2;
  midValue_8 = (blackValue_8 + whiteValue_8) / 2;

  EEPROM.write(0, midValue_1);
  EEPROM.commit();
  EEPROM.write(1, midValue_2);
  EEPROM.commit();
  EEPROM.write(2, midValue_3);
  EEPROM.commit();
  EEPROM.write(3, midValue_4);
  EEPROM.commit();
  EEPROM.write(4, midValue_5);
  EEPROM.commit();
  EEPROM.write(5, midValue_6);
  EEPROM.commit();
  EEPROM.write(6, midValue_7);
  EEPROM.commit();
  EEPROM.write(7, midValue_8);
  EEPROM.commit();

  Serial.print("Mid : ");  Serial.print(midValue_1);  Serial.print('\t');
  Serial.print(midValue_2);  Serial.print('\t');
  Serial.print(midValue_3);  Serial.print('\t');
  Serial.print(midValue_4);  Serial.print('\t');
  Serial.print(midValue_5);  Serial.print('\t');
  Serial.print(midValue_6);  Serial.print('\t');
  Serial.print(midValue_7);  Serial.print('\t');
  Serial.println(midValue_8);
}

void write_eeprom() {                           //ฟังก์ชันบันทึกค่าเส้นใหม่
  for (int i = 0 ; i < 8 ; i++) {
    EEPROM.write(i, 0);
    EEPROM.commit();
  }
  while (digitalRead(button) == 0) {
    ;
  }
  beep();
  beep();
  beep();

  wait_start();                             //รอการกดปุ่ม Start
  memory_black();                           // เก็บค่าสีดำ
  wait_start();                             //รอการกดปุ่ม Start
  memory_white();                           // เก็บค่าสีขาว
  compare();                                // วิเคราะห์ค่าเส้น

  Serial.println("Write EEPROM Complete");
}

void read_eeprom() {                            //ฟังก์ชันอ่านค่าเส้นที่บันทึกไว้
  midValue_1 = EEPROM.read(0);
  midValue_2 = EEPROM.read(1);
  midValue_3 = EEPROM.read(2);
  midValue_4 = EEPROM.read(3);
  midValue_5 = EEPROM.read(4);
  midValue_6 = EEPROM.read(5);
  midValue_7 = EEPROM.read(6);
  midValue_8 = EEPROM.read(7);
  beep(); beep(); beep(); 
  Serial.println("Read EEPROM Complete");
}