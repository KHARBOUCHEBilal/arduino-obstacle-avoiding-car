const int phrR=A2;
const int phrL=A1;

 
void setup() {
   
   Serial.begin(9600);

   pinMode(phrR, INPUT);
   pinMode(phrL, INPUT);
}
 
void loop() {
   // mesure la tension sur la broche A1
   int valeurR = analogRead(phrR);
   float voltageR = valeurR * (5.0 / 1023.0);
   Serial.print("Voltage R :");
   Serial.print(voltageR);
   Serial.println(" V");
   delay(1000);
   int valeurL = analogRead(phrL);
   float voltageL = valeurL * (5.0 / 1023.0);
   Serial.print("Voltage L :");
   Serial.print(voltageL);
   Serial.println(" L");
   delay(1000);
}
