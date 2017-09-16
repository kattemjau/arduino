int led1=PD4;
int led2=PD5;
int led3=PD3;
int button1=PD7;
int button2=PD6;
int button3=PD2;
int bs, bs1, bs2;
int s=LOW, s1=LOW, s2=LOW;
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

  if (bs == LOW){
    leds(led1);
  }
   
}

void leds(int led) {
  analogWrite(led, 255);
  
}

