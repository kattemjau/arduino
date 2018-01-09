#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel strip = Adafruit_NeoPixel(316, 6, NEO_GRB + NEO_KHZ800);

String data="";


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  //annimations for starting
  strip.begin();
  strip.show(); 
  for (int k = 0; k < 255; k++){
    //rgb
    for (int i = 0; i < 121; i++){
      //addresering
    //(int) i/2
      strip.setPixelColor(i, strip.Color(0,(int) k/4,k)); 
      //delay(5);
    }
    strip.show(); 
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  //Serial.println("schnigger");
  //Seriaial.write("snik");
  if(Serial.available() >0){
    data=Serial.read();
    Serial.println(data);  
  }else{
    Serial.println("no data");
  }
  
  delay(1000); 
}
