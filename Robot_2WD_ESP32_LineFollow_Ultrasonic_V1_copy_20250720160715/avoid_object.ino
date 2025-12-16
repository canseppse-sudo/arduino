void read_distance() {                        //ฟังก์ชันอ่านระยะทางของวัตถุด้านหน้า
  delay(50);// Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  distance = sonar.ping_cm();                 //อ่านค่าระยะวัตถุไปเก็บค่าไว้ที่ distance
  Serial.print("Ping: ");
  Serial.print(distance); // Send ping, get distance in cm and print result (0 = outside set distance range)
  Serial.println("cm");
  ////////////////////////////////////แก้ค่าระยะทางและเพิ่มลดการตรวจจับสิ่งกีดขวางได้/////////////////////////////////////
    if ((distance >= 5) && (distance <= 10) && (detect == false)) { //ตั้งค่าระยะวัตถุระหว่าง 5-10cm
      STOP(); delay(100);
      count++;
      if(count == 1){                         //วัตถุที่ 1 ให้หลบด้านซ้าย
        avoid_left();
      }
      else if(count == 2){                    //วัตถุที่ 2 ให้หลบด้านขวา
        avoid_right();               
      }
      else if(count == 3){                    //วัตถุที่ 3 ให้หลบด้านซ้าย
        avoid_left();               
      }
      else if(count == 4){                    //วัตถุที่ 4 ให้หลบด้านขวา
        avoid_right();               
      }
      else if(count == 5){                    //วัตถุที่ 5 ให้หลบด้านขวา
        avoid_left();               
      }
      else if(count == 6){                    //วัตถุที่ 6 ให้หลบด้านขวา
        avoid_right();               
      }
  //////////////////////////////////////////////////////////////////////////////////////////////////////////
      detect = true;
    }
}

void avoid_left() {                            //ฟังก์ชันหลบวัตถุไปทางด้านซ้าย
    turnLeft(); delay(time7); STOP();
    forward(); delay(time8); STOP();
    turnRight(); delay(time7); STOP();
    forward(); delay(time9); STOP();
    turnRight(); delay(time7); STOP();
    forward_tracking();
    left_tracking();
}

void avoid_right() {                           //ฟังก์ชันหลบวัตถุไปทางด้านขวา
    turnRight(); delay(time7); STOP();
    forward(); delay(time8); STOP();
    turnLeft(); delay(time7); STOP();
    forward(); delay(time9); STOP();
    turnLeft(); delay(time7); STOP();
    forward_tracking();
    right_tracking();
}