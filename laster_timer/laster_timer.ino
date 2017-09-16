int sens = A5;

void setup() {
  // put your setup code here, to run once:
  pinMode(sens, INPUT);
  Serial.begin(9600);
}

void loop() {
  int tall = analogRead(sens);
  Serial.println(tall);
  delay(1000);

}
