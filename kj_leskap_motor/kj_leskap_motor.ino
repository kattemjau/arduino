int E=6;
int M=5;

void setup() {
  pinMode(M, OUTPUT);

}

void loop() {

  startMotor();
  
}

void startMotor(){
  if(stengt==true){
    while(aapen==false){
      digitalWrite(M, LOW);
      analogWrite(E, 255);
    }
    analogWrite(E, 0);
    
  }else{
    while(stengt==false){
      digitalWrite(M, HIGH);
      analogWrite(E, 255);    
    }
    analogWrite(E, 0);
  }

}

