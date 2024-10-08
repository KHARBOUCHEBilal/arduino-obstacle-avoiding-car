int motor1ENA = 4;
int motor1pin1 = 5;
int motor1pin2 = 6;

int motor2pin1 = 7;
int motor2pin2 = 8;

int motor2ENB = 9;

void setup() {
  // Initialisation des pins
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);
  pinMode(motor1ENA, OUTPUT);
  pinMode(motor2ENB, OUTPUT);
}

void loop() {
  avancer(); // Avancer pendant 1 seconde
  delay(1000);
  reculer(); // Reculer pendant 1 seconde
  delay(1000);
  tournerDroite(); // Tourner à droite pendant 1 seconde
  delay(1000);
  tournerGauche(); // Tourner à gauche pendant 1 seconde
  delay(1000);
}

void avancer() {
  // Régler les pins pour avancer
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);
  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);
  // Régler la vitesse
  analogWrite(motor1ENA, 125);
  analogWrite(motor2ENB, 125);
}

void reculer() {
  // Régler les pins pour reculer
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);
  // Régler la vitesse
  analogWrite(motor1ENA, 125);
  analogWrite(motor2ENB, 125);
}

void tournerDroite() {
  // Régler les pins pour tourner à droite
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);
  // Régler la vitesse
  analogWrite(motor1ENA, 125);
  analogWrite(motor2ENB, 125);
}

void tournerGauche() {
  // Régler les pins pour tourner à gauche
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);
  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);
  // Régler la vitesse
  analogWrite(motor1ENA, 125);
  analogWrite(motor2ENB, 125);
}