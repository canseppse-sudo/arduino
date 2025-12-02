int bt= 17;
int wifi = 2;
int ntp = 15;
int iot = 12;

void setup() {
  pinMode(bt, OUTPUT);
  pinMode(wifi, OUTPUT);
  pinMode(ntp, OUTPUT);
  pinMode(iot, OUTPUT);

}

void loop() {
  digitalWrite(bt, LOW);
  delay(1000);
  digitalWrite(bt, HIGH);
  delay(900);
  digitalWrite(wifi, LOW);
  delay(800);
  digitalWrite(wifi, HIGH);
  delay(700);
   digitalWrite(ntp, LOW);
  delay(600);
  digitalWrite(ntp, HIGH);
  delay(500);
   digitalWrite(iot, LOW);
  delay(400);
  digitalWrite(iot, HIGH);
  delay(300);
}
