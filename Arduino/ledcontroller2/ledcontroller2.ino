int led1=PD6;
int led2=PD5; //PD7 sender ikke pwm
int led3=PD3;
int button1=PD7;
int button2=PD4;
int button3=PD2;
int bs, bs1, bs2;
int s=true, s1=true, s2=true;
void setup() {
  // put your setup code here, to run once:
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  Serial.begin(9600);
}

void loop() {
  bs = digitalRead(button1);
  bs1 = digitalRead(button2);
  bs2 = digitalRead(button3);
  Serial.println(bs2);


  if (bs == LOW){
    leds(led1, s, button1);
    s=!s;
  }
  if (bs1 == LOW){
    leds(led2, s1, button2);
    s1=!s1;
  }
  if (bs2 == LOW){
    leds(led3, s2, button3);
    s2=!s2;
  }
  
}

void leds(int led, int s, int bs) {
  int k=255; int retning=true;
  if(s){
    analogWrite(led, 255);
    delay(100);
    while (digitalRead(bs)==LOW){
      if(k==0){
        retning=false;
      }
      else if(k==255){
        retning=true;
      }
      if (retning==true){
        analogWrite(led, k);
        k=k-5;
        delay(50);
        Serial.println(k);        
      }
      else{
        analogWrite(led, k);
        k=k+5;
        delay(50);
        Serial.println(k);  
      }
    }
  }
  else{
    analogWrite(led, 0);
    k=255;
  }
  delay(150);
  
}


