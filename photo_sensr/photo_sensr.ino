int ledPin = 11;
int Pins = 3;
int sensorPin = 5;
int sensorPins = 9;
int sensorValue;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(Pins, OUTPUT);
  pinMode(sensorPins, INPUT);
  pinMode(sensorPin, INPUT);
  Serial.begin(9600);
}

void loop(){
  int sensorValue1
  sensorValue = analogRead(sensorPin);
  sensorValue1 = analogRead(sensorPins);
  /*int newVal = map(sensorValue, 0, 1023, 0, 100);
  Serial.println(newVal);
  delay(100); */
  if(sensorValue >= 60 ){
    digitalWrite(ledPin, HIGH);
    digitalWrite(Pins, LOW);
  }
  else if(sensorValue1 <=60 ) {
    digitalWrite (Pins, HIGH);
    digitalWrite(ledPin, LOW);
  }
  /* else  {
    //digitalWrite(Pins, HIGH);
    digitalWrite(ledPin, LOW);
  }  */
} 
