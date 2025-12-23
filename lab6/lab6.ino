int ldr = 36;
int led[4] = {17, 2, 15, 12};

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 4; i++) {
    pinMode(led[i], OUTPUT);
    digitalWrite(led[i], HIGH);
  }
}

void loop() {
  int x = analogRead(ldr);
  int y = map(x, 400, 700, 0, 4);

  Serial.print("x = ");
  Serial.print(x);
  Serial.print("\t y = ");
  Serial.println(y);

  for (int i = 0; i < 4; i++) {
    digitalWrite(led[i],  HIGH);
  }
  
  if (y == 0) {
  }
  else if (y == 1) {
    digitalWrite(led[0],LOW);

  }
  else if (y == 2) {
    digitalWrite(led[0],LOW);
    digitalWrite(led[1],LOW);
  }
  else if (y == 3) {
    digitalWrite(led[0],LOW);
    digitalWrite(led[1],LOW);
    digitalWrite(led[2],LOW);
  }
  else if (y >= 4) {
    for (int i = 0; i < 4; i++) {
      digitalWrite(led[i],LOW);
    }
  }
  delay(100);
}