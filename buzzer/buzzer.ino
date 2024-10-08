int Buzzer = 11;

void setup() {
  pinMode(Buzzer, OUTPUT); // Initialize as output pin
}

void loop() {
  for (int i = 0; i <= 5; i++) {
    tone(Buzzer, 1000);
    delay(300);
    noTone(Buzzer);
    delay(100);

    tone(Buzzer, 950);
    delay(200);
    noTone(Buzzer);
    delay(100);

    tone(Buzzer, 1500);
    delay(500);
    noTone(Buzzer);
    delay(100);

    tone(Buzzer, 700);
    delay(350);
    noTone(Buzzer);
    delay(100);
  }

  noTone(Buzzer);
  delay(500);

  digitalWrite(Buzzer, HIGH);
  delay(500);
  digitalWrite(Buzzer, LOW);
  delay(2000);
}
