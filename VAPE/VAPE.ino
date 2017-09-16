int pwm=9;
int buttn=4;
int led1=2;
boolean lowV=false;

// int led2 =5, led3=6, led4=7, led5=8;

int bu;
//int k=155;

void setup() {
  pinMode(pwm, OUTPUT);
  pinMode(buttn, INPUT_PULLUP);
  pinMode(led1, OUTPUT);
  Serial.begin(9600);
  /*
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT); */

  //enabelig circuit, flashes led
  flash();   

}


void loop() {
  bu=digitalRead(buttn);
  int sensorValue = analogRead(A0);
  float voltage = sensorValue*(5.0/1023.0);
  Serial.println(voltage);

  if(bu==LOW){
    if(voltage<=3.0){
      flash();
    }else{
    //svak dimming av vape
    /*
    if(k<=150){  
    }else{
      k=k-1;
    } */
    analogWrite(pwm, 100);
    digitalWrite(led1, HIGH);
    
    }
  }else{
    //k=255;
    analogWrite(pwm, 0);
    delay(200);
    digitalWrite(led1, LOW);
  }

  
}

void flash(){
  digitalWrite(led1, HIGH);
  delay(300);
  digitalWrite(led1, LOW);
  delay(300);
  digitalWrite(led1, HIGH);
  delay(300);
  digitalWrite(led1, LOW);
  delay(300);
  digitalWrite(led1, HIGH);
  delay(300);
  digitalWrite(led1, LOW);
  delay(300); 
}

