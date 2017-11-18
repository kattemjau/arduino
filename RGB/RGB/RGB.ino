
int brightnes=3;
int redled=3;
int blueled=5;
int greenled=6;
int white=9;
int button=7;

int bu;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(redled, OUTPUT);
  pinMode(blueled, OUTPUT);
  pinMode(greenled, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  
}
int on=1;
int red=150, blue=150, green=150, pot1;

int check(){
  pot1 = analogRead(A0)*0.2490234375;
  //100=pot1/4;
  green = analogRead(A1)*0.2490234375;
  blue = analogRead(A2)*0.2490234375;
  red = analogRead(A3)*0.2490234375;
  //bu=digitalRead(button);
  if(green<5){
    green=0;
  }if(red<5){
    red=0;
  }if(blue<5){
    blue=0;
  }if(pot1<5){
    pot1=0;
  }if(green>245){
    green=255;
  }if(red>245){
    red=255;
  }if(blue>245){
    blue=255;
  }if(pot1>245){
    pot1=255;
  }
 /* if(bu==LOW){
    on++;
    delay(200);
    return 1;
  } */
  return 0;
}

void loop() {

  //check();
  
  //debug();
  //analogWrite(white, pot1);
  
 // if(on==1){
   //solidColour(); 
  //}else if(on==2){
   // blinky();
 // }else if(on==3){
   fade();
  //}else if(on>=4){
  //  on=1;
 // }
  

  
  delay(10);

}
void blinky(){
  if(pot1<10){
    pot1=10;
  }
  analogWrite(redled, red);
  delay(pot1);
  if(check()){
    return;
  }
  analogWrite(blueled, 0);
  analogWrite(greenled, green);
  delay(pot1);
  if(check()){
    return;
  }
  analogWrite(redled, 0);
  delay(pot1);
  if(check()){
    return;
  }
  analogWrite(blueled, blue);
  delay(pot1);
  if(check()){
    return;
  }
  analogWrite(greenled, 0);
    

}
void fade(){
  int r, g, b;
 
  // fade from blue to violet
  for (r = 0; r < red; r++) { 
    analogWrite(redled, r);
    delay(100);
    } 
  
  // fade from violet to red
  for (b = 255; b > 0; b--) { 
    analogWrite(blueled, b);
    delay(100);
   
  } 
  // fade from red to yellow
  for (g = 0; g < green; g++) { 
    analogWrite(greenled, g);
    delay(100);
   
  } 
  
  // fade from yellow to green
  for (r = 255; r > 0; r--) { 
    analogWrite(redled, r);
    delay(100);
    
  } 
 
  // fade from green to teal
  for (b = 0; b < blue; b++) { 
    analogWrite(blueled, b);
    delay(100);

  } 

  // fade from teal to blue
  for (g = 255; g > 0; g--) { 
    analogWrite(greenled, g);
    delay(100);

  } 
}

void solidColour(){
  /*if(pot1>=250){
    pot1=250;
  }
  if(green<pot1){
    if(green==0){
      analogWrite(greenled, 0);
    }else{
      analogWrite(greenled, 5);
    }
    
  }else{
    analogWrite(greenled, green-pot1);
  }
  if(red<pot1){
    if(red==0){
      analogWrite(redled, 0);
    }else{
      analogWrite(redled, 5);
    }
    
  }else{
    analogWrite(redled, red-pot1);
  }
  if(blue<pot1){
    if(blue==0){
      analogWrite(blueled, 0);
    }else{
      analogWrite(blueled, 5);
    }
    
  }else{
    analogWrite(blueled, blue-pot1);
  }*/
  analogWrite(greenled, green);
  analogWrite(blueled, blue);
  analogWrite(redled, red);

  
}
void debug(){
  Serial.print("Led Brightnes ");
  Serial.print(pot1);
  Serial.print(" Green value ");
  Serial.print(green);
  Serial.print(" Blue value ");
  Serial.print(blue);
  Serial.print(" RED value ");
  Serial.println(red);
  Serial.println("Button State");
  Serial.println(on);

}

