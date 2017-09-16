
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


#ifdef __AVR__
  #include <avr/power.h>
#endif


#include <TimeLib.h>
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2

int button = 4;
int bu;

#define LOGO16_GLCD_HEIGHT 16 
#define LOGO16_GLCD_WIDTH  16 
static const unsigned char PROGMEM logo16_glcd_bmp[] =
{ B00000000, B11000000,
  B00000001, B11000000,
  B00000001, B11000000,
  B00000011, B11100000,
  B11110011, B11100000,
  B11111110, B11111000,
  B01111110, B11111111,
  B00110011, B10011111,
  B00011111, B11111100,
  B00001101, B01110000,
  B00011011, B10100000,
  B00111111, B11100000,
  B00111111, B11110000,
  B01111100, B11110000,
  B01110000, B01110000,
  B00000000, B00110000 };

#if (SSD1306_LCDHEIGHT != 32)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif


void setup()   {                
  Serial.begin(9600);
 // pinMode(mosf, OUTPUT);

  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 128x32)
 
  display.display();
  delay(1000);

  display.clearDisplay();

  pinMode(button, INPUT_PULLUP);
  
  
  

}

int tid=300, tud=0;
int h=0, m=0;
boolean thing=false, nytid=true, mun=false, meny=false;


void loop() {
  bu=digitalRead(button);
  Serial.println(bu); //dette er verdien 1 default/idle

  
  if(bu==LOW){
    Serial.println("4");
    while(digitalRead(button)==LOW){
      tud++;
      delay(10);
      Serial.println(tud);
    }
    
    if(tud>=100 && mun==true){
      digitalWrite(13, LOW);  
      Serial.println("3");
      mun=false;
    } else if(tud>=100){
      mun=true;
      Serial.println("6");
    } else if(mun){
       m=minute() + 1;
    }
    else{
      h=hour()+1;
    }
    
    tud=0;
    setTime(h,m,40,2,3,2016); 
  }
  

  
  
  writeTime();
}
void writeTime(){
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.setCursor(0,0);
  display.println("Santander");
  display.setTextSize(3);
  
  
  display.setCursor(15,5);
  display.print(hour());
  
  display.print(":");

  if(minute()<=9){
    display.print(0);
    display.println(minute());
  }
  else{
    display.println(minute());
  }
 
  display.display();
  display.clearDisplay();
}





