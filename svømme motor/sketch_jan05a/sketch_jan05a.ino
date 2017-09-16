#include <Servo.h>

int pin1=5, pin2=6, button=9, voltSens=2;


int value = 0; // set values you need to zero
int change = 1;
Servo firstESC, secondESC; //Create as much as Servoobject you want. You can controll 2 or more Servos at the same time

void setup() {

  firstESC.attach(5);
  secondESC.attach(6);// attached to pin 9 I just do this with 1 Servo
  Serial.begin(9600);    // start serial at 9600 baud
  pinMode(button, INPUT_PULLUP);
  firstESC.writeMicroseconds(value);
  secondESC.writeMicroseconds(value);
  delay(1000);

}

void loop() {

//First connect your ESC WITHOUT Arming. Then Open Serial and follo Instructions
    firstESC.writeMicroseconds(value);
    secondESC.writeMicroseconds(value);
    Serial.println(value);
    if(digitalRead(button)==LOW){
      value=1000;
      while(digitalRead(button)==LOW){
        firstESC.writeMicroseconds(value);
    secondESC.writeMicroseconds(value);
Serial.println(value);
    value+=change;
    delay(10);
    if(value==2400){
      change=-5;
    }if(value==1000){
      change=5;
    }
  }
    }
  else if(digitalRead(button)==HIGH){
    value=1000;
    change=5;
  }
  

}
/*
 *   Serial.println(value);
  if(Serial.available()) 
    value = Serial.parseInt();    // Parse an Integer from Serial

 */
