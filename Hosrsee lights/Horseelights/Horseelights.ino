#include <Adafruit_NeoPixel.h>

int count=0;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(316, 6, NEO_GRB + NEO_KHZ800);

int button = 4;

void setup() {
  // put your setup code here, to run once:
  pinMode(button, INPUT_PULLUP);
  
  Serial.begin(9600); 
  strip.begin();
  strip.show();

}

void loop() {
  if(digitalRead(button)==LOW){
    //cleard();
    count++;
    if(count>=3){
      count=0;
    }
    delay(200);
  }
  
  Serial.println(count);
  //testelitt();

  //rainbow2(70);
    if(count ==0){
     //LionKing();
     rainbowPP(50);
    // Alice(50);
    }
   if(count==1) {
    //allice in wounder baum
    Alice(70);

    
  } else if(count>=2){
    //lovenes kong
      LionKing();
    
  }  
  /*else if (count == 3){
    //peter pan
    //rainbowPP(60); 
    LionKing();
  }*/
}

void cleard() {
  for (int i = 0; i < 316; i++){
    strip.setPixelColor(i, strip.Color(0,0,0)); 
    
  }
  strip.show();  
}

//ALADDIN
void rainbowAL(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, WheelUG((i+j) & 255));
    }
    strip.show();
  
    if(digitalRead(button)==LOW){
      return;
    }
    delay(wait);
  }
}

//PETER PAN
void rainbowPP(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, WheelUR((i+j) & 255));
    }
    strip.show();
      if(digitalRead(button)==LOW){
        return;
      }
    delay(wait);
  }
}


uint32_t WheelUG(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 63) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
   if(WheelPos < 126) {
      WheelPos -= 63;
      return strip.Color(WheelPos * 3, 0, 255 - WheelPos * 3);
   } if (WheelPos < 182) {
      WheelPos -= 126;
      return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else {
    WheelPos -= 182;
    return strip.Color(WheelPos * 3, 0, 255 - WheelPos * 3);
  }
}

uint32_t WheelUR(byte WheelPos) {
    WheelPos = 255 - WheelPos;
    if(WheelPos < 63) {
      return strip.Color(0, 255 - WheelPos * 3, WheelPos * 3);
    }
    if(WheelPos < 126) {
      WheelPos -= 63;
      return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
   } if (WheelPos < 182) {
      WheelPos -= 126;
      return strip.Color(0, 255 - WheelPos * 3, WheelPos * 3);
  } else {
    WheelPos -= 182;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}

/*
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
} */


//ALICE
void Alice(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }
    if(digitalRead(button)==LOW){
      return;
    }
    strip.show();
    delay(wait);
  }
}

/*
uint32_t WheelUG(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(WheelPos * 3, 0, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 0, 255 - WheelPos * 3);
}
*/

//ALICE
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}


int k=0;
boolean tis = true;
int i;
int r = 0;

void LionKing(){
  for(i = 0; i< 316-120; i++){
    
     strip.setPixelColor(k, strip.Color(255-r, 100-r, 0));
      if (r >= 150){
        r = 0;
      }
      r++;
  }
 /* for(int l =316-120; l<316 ;l++){
    strip.setPixelColor(l, strip.Color(255-k, 100+k, 0));

  }*/
  delay(5);

  if(k>=316 || k <= 0){
    tis = !tis;
    }
 
   if (tis) {
    k=0; 
   } else {
    k++;
   }
  strip.show();
}

