void setup()
{
  Serial.begin(9600);
  pinMode(2,INPUT);
}
void loop()
{
  digitalWrite(2,HIGH);
  delay(200);
  digitalWrite(2,LOW);
  delay(200);
}

