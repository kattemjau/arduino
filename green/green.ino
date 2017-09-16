// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            6

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      288

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define button      5
boolean tis= HIGH;
void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
  // End of trinket special code

  pixels.begin(); // This initializes the NeoPixel library.
  pinMode(button, INPUT_PULLUP);
  Serial.begin(9600);
}
int k=0, i=0;
int counter=0;
void loop() {
if(digitalRead(button)==LOW){counter++; Serial.println(counter); cler(); while(digitalRead(button)==LOW){green();} k=0;i=0;}
if(counter==0){
  green();
}
if(counter==1){
  tis= !tis;
  lsd();
}
if(counter==2){
  blue();
}
if(counter==3){
  counter=0;
}
  
  
  

}
void green(){
  pixels.setPixelColor(i, pixels.Color(0,150,0));
  if(i>=16){
    pixels.setPixelColor(k, pixels.Color(0,0,0));
    k++;
  }
  if(i==NUMPIXELS){
    i=0;
  }
  if(k==NUMPIXELS){
    k=0;
  }
  pixels.show();
  delay(10); 
  i++;
  
  
}
void lsd(){
  int f=0;
  if(tis){
    f=1;
  }
  
  while(f<NUMPIXELS){
    pixels.setPixelColor(f, pixels.Color(0,150,0));
    pixels.setPixelColor(f+1, pixels.Color(0,0,0));
    f+=2;  }
  pixels.show();
  delay(60);
  
}
void cler(){
  for(int f=0;f<NUMPIXELS;f++){
    pixels.setPixelColor(f, pixels.Color(0,0,0));
  }
  pixels.show();
}
void blue(){
  for(int f=0;f<NUMPIXELS;f++){
    pixels.setPixelColor(f, pixels.Color(0,0,80));
  }
  
  while(k<32){
      pixels.setPixelColor(i-k, pixels.Color(0,200,0));
      
      k++;
  }
  k=0;
  if(i==NUMPIXELS+32){
    i=0;
  }
 pixels.show();
 delay(2);
 i++;
  
}

