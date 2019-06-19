const int analogInPin = 2;  // Analog input pin that the potentiometer is attached to
const int analogOut =16; // Analog output pin that the LED is attached to

int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  pinMode(analogOut,OUTPUT);
  pinMode(analogInPin,INPUT);
}

void loop() {
  // read the analog in value:
  sensorValue = analogRead(analogInPin);
  //analogWrite=(analogOutPin,sensorValue);
  // map it to the range of the analog out: 
    outputValue = (255./4096.)*sensorValue;
  // change the analog out value:
//  analogWrite(analogOut,outputValue);

  // print the results to the Serial Monitor:
  Serial.print("\n sensor = ");
  Serial.print(sensorValue);
//Serial.print("\t output = ");
 // Serial.println(outputValue);

  // wait 2 milliseconds before the next loop for the analog-to-digital
  // converter to settle after the last reading:
  delay(50);
}
