const int directionA = 12;
const int directionB = 13;
const int brakeA = 9;
const int brakeB = 8;
const int speedA = 3;
const int speedB = 11;
const int Max_speed = 120;

const int trigPinAvant = 41;
const int echoPinAvant = 43;

const int trigPinGauche = 30;
const int echoPinGauche = 31;

const int trigPinDroite = 47;
const int echoPinDroite = 46;

float distanceAvant;
float distanceGauche;
float distanceDroite;

bool isReculer = false; 

void setup() {
      //Init Serial USB
      Serial.begin(9600);
      Serial.println(F("Initialize System"));
      pinMode(directionA, OUTPUT); 
      pinMode(brakeA, OUTPUT);
      pinMode(directionB, OUTPUT); 
      pinMode(brakeB, OUTPUT);
      
      pinMode(trigPinAvant, OUTPUT);
      pinMode(echoPinAvant, INPUT);
      pinMode(trigPinGauche, OUTPUT);
      pinMode(echoPinGauche, INPUT);
      pinMode(trigPinDroite, OUTPUT);
      pinMode(echoPinDroite, INPUT);
      
}
void loop() {
      if (!isReculer) {
          avancer();
          }
      // Mesure de la distance
      distanceAvant = mesurerDistance(trigPinAvant, echoPinAvant);
      distanceDroite - mesurerDistance(trigPinDroite, echoPinDroite);
      distanceGauche - mesurerDistance(trigPinGauche, echoPinGauche);
      // Affichage de la distance sur le moniteur série
      Serial.print("Distance A: ");
      Serial.print(distanceAvant, 2); 
      Serial.println(" cm");
      Serial.print("Distance D:");
      Serial.print(distanceDroite, 2); 
      Serial.println(" cm");
      Serial.print("Distance G: ");
      Serial.print(distanceGauche, 2); 
      Serial.println(" cm");


      // Vérifier la distance du capteur avant
      if (distanceAvant < 40) {
    // Arrêter le mouvement
        stop();
        Serial.print("stop");
        Serial.println("");
        delay(1000);
        
        // Prise de décision
        char decision[10];
        strcpy(decision, priseDecision()); // Copier la chaîne de décision
        
        // Comparer la variable decision avec la chaîne littérale
        if (strcmp(decision, "Droite") == 0) {
            stop();
            tournerDroite();
            isReculer = false;
            Serial.print("tourner Droite");
            Serial.println("");
        } else if (strcmp(decision, "Gauche") == 0) {
            stop();
            tournerGauche();
            isReculer = false;
            Serial.print("tourner Gauche");
            Serial.println("");
        } else {
            reculer();
            isReculer = true;
            Serial.print("reculer");
            Serial.println("");
    }
}
if (isReculer) {
    // Prise de décision
    char decision[10];
    strcpy(decision, priseDecision()); // Copier la chaîne de décision
    
    // Comparer la variable decision avec la chaîne littérale
    if (strcmp(decision, "Droite") == 0) {
        tournerDroite();
        isReculer = false;
        Serial.print("tourner Droite");
        Serial.println("");
    } else if (strcmp(decision, "Gauche") == 0) {
        tournerGauche();
        isReculer = false;
        Serial.print("tournerGauche");
        Serial.println("");
    } else {
        reculer();
        isReculer = true;
        Serial.print("reculer");
        Serial.println("");
    }
}

}
float mesurerDistance(int trigPin, int echoPin) {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    // Mesurer la durée pendant laquelle le signal d'écho reste élevé
    long duration = pulseIn(echoPin, HIGH);
    // Calculer la distance en fonction de la durée
    float distance = duration * 0.034 / 2;
    return distance;
}
char* priseDecision() {
    if (distanceDroite > 30 && distanceGauche > 30 ) {
        if (distanceDroite > distanceGauche)
            return "Droite";
        else
            return "Gauche";
    } else {
        if (distanceDroite > 30 ) {
            return "Droite";
        } else if (distanceGauche > 30 ) {
            return "Gauche";
        } else {
            return "reculer";
        }
    }
}
void avancer() {
    digitalWrite(directionA, HIGH); // Établit la direction avant du canal A
    digitalWrite(brakeA, LOW);       // Désengagez le frein pour le canal A
    analogWrite(speedA, Max_speed);  // Applique une certaine vitesse au canal A
    
    digitalWrite(directionB, HIGH); // Établit la direction avant du canal B
    digitalWrite(brakeB, LOW);      // Désengagez le frein pour le canal B
    analogWrite(speedB, Max_speed); // Applique une certaine vitesse au canal B
}
void tourner() {
    digitalWrite(directionA, HIGH); // Établit la direction avant du canal A
    digitalWrite(brakeA, LOW);      // Désengagez le frein pour le canal A
    analogWrite(speedA, Max_speed); // Applique une certaine vitesse au canal A
    
    digitalWrite(directionB, LOW);  // Établit la direction arrière du canal B
    digitalWrite(brakeB, LOW);      // Désengagez le frein pour le canal B
    analogWrite(speedB, Max_speed); // Applique une certaine vitesse au canal B
}
void tournerDroite() {
    digitalWrite(directionA, HIGH); // Établit la direction avant du canal A
    digitalWrite(brakeA, LOW);      // Désengagez le frein pour le canal A
    analogWrite(speedA, Max_speed); // Applique une certaine vitesse au canal A
    
    digitalWrite(directionB, LOW);  // Établit la direction arrière du canal B
    digitalWrite(brakeB, LOW);      // Désengagez le frein pour le canal B
    analogWrite(speedB, Max_speed); // Applique une certaine vitesse au canal B
}
void tournerGauche() {
    digitalWrite(directionA, LOW); // Établit la direction arrière du canal A
    digitalWrite(brakeA, LOW);     // Désengagez le frein pour le canal A
    analogWrite(speedA, Max_speed); // Applique une certaine vitesse au canal A
    
    digitalWrite(directionB, HIGH); // Établit la direction avant du canal B
    digitalWrite(brakeB, LOW);      // Désengagez le frein pour le canal B
    analogWrite(speedB, Max_speed); // Applique une certaine vitesse au canal B
}
void stop() {
    digitalWrite(brakeA, HIGH);
    digitalWrite(brakeB, HIGH);
}
void reculer() {
    digitalWrite(directionA, LOW);  // Établit la direction arrière du canal A
    digitalWrite(brakeA, LOW);      // Désengagez le frein pour le canal A
    analogWrite(speedA, Max_speed); // Applique une certaine vitesse au canal A
    
    digitalWrite(directionB, LOW);  // Établit la direction arrière du canal B
    digitalWrite(brakeB, LOW);      // Désengagez le frein pour le canal B
    analogWrite(speedB, Max_speed); // Applique une certaine vitesse au canal B
}