const int trigpin = 9;
const int echopin = 10;
long duration;
int distance;
void setup(){
  pinMode(trigpin,OUTPUT);
  pinMode(echopin,OUTPUT);
  Serial.begin(9600);
}
void loop(){
  digitalWrite(trigpin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin,LOW);
  duration = pulseIn(echopin,HIGH);
  distance = duration*0.034/2;
  Serial.print("distance=");
  Serial.println(distance);
}

