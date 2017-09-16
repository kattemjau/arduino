int dp=13;
int a=6,b=7,c=8,d=9,e=10,f=11,g=12;
void setup() {
  pinMode(a, OUTPUT);
  pinMode(dp, OUTPUT);

  
  digitalWrite(dp, LOW);  
  delay(150);
  digitalWrite(dp, HIGH);  
  delay(150);
  digitalWrite(dp, LOW);  
  delay(150);
  digitalWrite(dp, LOW);  
  delay(150);
  digitalWrite(a, LOW);  
  delay(150);

}

void loop() {
  // put your main code here, to run repeatedly:

}
