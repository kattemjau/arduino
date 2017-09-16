//mosfet to pin 5
//battery voltage to pin A0
//button to pin 4
//button led to pin 3

int mosf = 5;
int button=4;
int red=7;
int blue =8;
int bu;


void setup() {
  // put your setup code here, to run once:
  pinMode(mosf, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  bu=digitalRead(button);
  /*
  int sensorValue = analogRead(A2);
  float voltage = sensorValue*(5.0/1023.0);
  Serial.println(voltage);
    */

   if(bu==LOW){
      analogWrite(mosf, 255);
      digitalWrite(blue, HIGH);
      
   }else{
    analogWrite(mosf, 0);
    digitalWrite(blue, LOW);
   }

}

void flash(){
  for(int i=0;i<3;i++){
    analogWrite(red, 255);
    delay(50);
    analogWrite(red, 0);
    delay(50);
  }
}

