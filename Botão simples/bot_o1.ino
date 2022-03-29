int bnt1 = 0; int bnt2 = 0; int bnt3 = 0;

void setup()
{
  pinMode(2, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop()
{
  bnt1 = digitalRead(5);
  bnt2 = digitalRead(4);
  bnt3 = digitalRead(3);
  if (bnt1 == HIGH) {
    analogWrite(2, 250);
    analogWrite(9, LOW);
  }
  if (bnt2 == HIGH) {
    analogWrite(10, 250);
    analogWrite(2, LOW);
  }
  if (bnt3 == HIGH) {
    analogWrite(9, 250);
    analogWrite(10, LOW);
  }
  delay(2); 

}