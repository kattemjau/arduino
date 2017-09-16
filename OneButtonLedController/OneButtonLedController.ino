int led1=6;
int led2=5; 
int led3=3;
int button=4;
int bs;
int s=true;
int rl=true;
int bl=true;
String state="off";


int g=255, r=0,b=0;

void setup() {
  // put your setup code here, to run once:
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  bs = (digitalRead(button));
  Serial.println(bs);
  if (bs == LOW){
    delay(100);
    if(bs==HIGH){
      analogWrite(led1, 0);
      analogWrite(led2, 0);
      analogWrite(led3, 0);
      g=255;
      r=0;
      b=0;
    } 
    while(digitalRead(button)==LOW){
      if(s){
        analogWrite(led1, g);
        g=g-5;
        delay(50);
      }
      if (g<=125){
        s=false;
        while(digitalRead(button)==LOW){
          if(g==250){
            break; 
          }
          
          if(r<125 && g>0) {
            analogWrite(led2, r);
            r=r+5;
            analogWrite(led1, g);
            g=g-5;
            delay(50);
          }
          else if(rl){
            analogWrite(led2, r);
            r=r+5;
            delay(50);
          }
          if(r==255){
            rl=false;
            s=true;
            while(digitalRead(button)==LOW){
              if(g==250){
                break; 
              }
 
              if(r>125){
                analogWrite(led2, r);
                r=r-5;
                delay(50);
              }
              else if(r>0 && b<125){
                analogWrite(led3, b);
                b=b+5;
                analogWrite(led2, r);
                r=r-5;
                delay(50);
              }
              else if(bl){
                analogWrite(led3, b);
                b=b+5;
                delay(50);
              }
              if(b==255){
                bl=false;
                rl=true;
                while(digitalRead(button)==HIGH){

                  if(b>125){
                    analogWrite(led3, b);
                    b=b-5;
                    delay(50);
                  }
                  else if(b>=125 && g<0){
                    analogWrite(led3, b);
                    b=b-5;
                    analogWrite(led1, g);
                    g=g+5;
                    delay(50);
                  }
                  else if(b==0){
                    analogWrite(led1, g);
                    g=g+5;
                    delay(50);
                  }
                  if(g==250){
                    break; 
                  }
                  
                }
                
              }
              
            }
            
          }  
             
        } 
             
      } 
    }
    //loop
    
  }  
}


