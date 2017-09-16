int trans1 = 5;
int trans2 = 6;

void setup() {
  // put your setuetup code here, to run once:

  pinMode(trans1, OUTPUT);
  pinMode(trans2, OUTPUT);
  
}

void loop() {
  digitalWrite(trans1, HIGH);
  digitalWrite(trans1, LOW);
  digitalWrite(trans2, HIGH);
  digitalWrite(trans2, LOW);

  

}
