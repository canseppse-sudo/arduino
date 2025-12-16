const int button = 27;
const int led_red = 23;
const int led_green = 18;


void setup() {
  pinMode(button, INPUT_PULLUP);
  pinMode(led_red, OUTPUT);
  pinMode(led_green, OUTPUT);
}

void loop() {
  while(digitalRead(button)==HIGH);
  digitalWrite(led_red, HIGH);
  digitalWrite(led_green, LOW);
  delay(400);

  while(digitalRead(button)==HIGH);
  digitalWrite(led_red, LOW);
  digitalWrite(led_green, HIGH);
  delay(400);
  
  while(digitalRead(button)==HIGH);
  digitalWrite(led_red, LOW);
  digitalWrite(led_green, LOW);
  delay(400);  
  
}
