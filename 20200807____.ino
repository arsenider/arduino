void setup() {
  pinMode (A5, INPUT);          //FLAME
  pinMode (9, OUTPUT);          //LED RED
  pinMode (10, OUTPUT);         //LED GREEN
  pinMode (6, OUTPUT);          //BUZZER

}

void loop() {
  if (analogRead(A5) > 500)
  {
    digitalWrite (9, HIGH);
    digitalWrite (10, LOW);
    digitalWrite (6, HIGH);
  }
  else
  {
    digitalWrite (9, LOW);
    digitalWrite (10, HIGH);
    digitalWrite (6, LOW);
  }
}
