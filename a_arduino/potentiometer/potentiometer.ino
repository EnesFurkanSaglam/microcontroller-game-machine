int potpin = A0;
int ledpin = 8;
int potv = 0;
void setup(){
  pinMode(ledpin,OUTPUT);
}
void loop(){
  potv = analogRead(potpin);
  analogWrite(ledpin,potv/4);
  delay(10);
}