#include <SoftwareSerial.h>// import the serial library

SoftwareSerial Genotronex(10, 11); // RX, TX
//int ledpin=13; // led on D13 will show blink on / off
int BluetoothData; // the data given from Computer
int E=6;
int M=5;

int inn=3;
int ut=2;

void setup() {
  // put your setup code here, to run once:
  Genotronex.begin(9600);
  Genotronex.println("Bluetooth On please press 1 or 0 blink LED ..");
//  pinMode(ledpin,OUTPUT);
  pinMode(M, OUTPUT);
  pinMode(inn, INPUT_PULLUP);
  pinMode(ut, INPUT_PULLUP);
  Serial.begin(9600);
  Serial.println("Start");
  
  
}

void loop() {
  
  //Serial.println("inn");
  Serial.println(digitalRead(inn));
  //Serial.println("ut");
  Serial.println(digitalRead(ut));
  if (Genotronex.available()){
    BluetoothData=Genotronex.read();
    Serial.println("Test");
  Serial.println(digitalRead(ut));
  if(BluetoothData=='1'){  
    Serial.println("ja");
    if (digitalRead(inn)==LOW){
      while(true){
     // digitalWrite(ledpin,1);
      Genotronex.println("låser ");
      
      digitalWrite(M, HIGH);
      analogWrite(E, 255);
      if (digitalRead(ut)==LOW){
        digitalWrite(E, 0);
        break;
        } 
      }
    }
   }
  if (BluetoothData=='0'){
    if(digitalRead(ut)==LOW){
      while(true){
     // digitalWrite(ledpin,1);
      Genotronex.println("låser opp");
      
      digitalWrite(M, LOW);
      analogWrite(E, 255);
      if (digitalRead(inn)==LOW){
        digitalWrite(E, 0);
        break;
        } 
      }
    }
  }
}
delay(100);
}

