#define Pin_Motore 5
#define Pin_Potenziometro A3

void setup() {
  Serial.begin(9600);

  pinMode(2, INPUT);
  pinMode(Pin_Motore, OUTPUT);
}

void loop() {
  int pot = analogRead(Pin_Potenziometro); // 0-1023
  analogWrite(Pin_Motore, pot / 4); // 0-255

  double Da = pulseIn(2, HIGH);
  double Db = pulseIn(2, LOW);

  // us
  double P = (Da + Db) * 40;
  double F = 1000000/P; 

  double RPM = F * 60;

  Serial.println(RPM);

  delay(500);
}
