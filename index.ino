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

  int Da = pulseIn(2, HIGH);
  int Db = pulseIn(2, LOW);

  // us
  int P = (Da + Db) * 40;
  int F = 1000000/P; 

  int RPM = F * 60;

  Serial.println(RPM);

  delay(500);
}
