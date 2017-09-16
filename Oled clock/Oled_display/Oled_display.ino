
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 6

#include <TimeLib.h>
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2

//int mosf=PD6;


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
int tiime=0;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(8, PIN, NEO_GRB + NEO_KHZ800);
void setup()   {                
  Serial.begin(9600);
 // pinMode(mosf, OUTPUT);

  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 128x32)
  // init done
  
  // Show image buffer on the display hardware.
  // Since the buffer is intialized with an Adafruit splashscreen
  // internally, this will display the splashscreen.
  display.display();
  delay(1000);
  strip.begin();
  strip.show();
  // Clear the buffer.
  display.clearDisplay();
  setTime(17,47,40,2,3,2016);
  

}



void loop() {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, strip.Color(120/hour()*i, 10*i, 2*minute()/i));
   strip.show();
   delay(150);
  }

  
  
 
  
  display.setTextSize(3);
  display.setTextColor(WHITE);
  
  display.setCursor(20,5);
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
  strip.show();
/*  if(hour()>20){
    tiime=255;
  }
  else {
    tiime=165;
  }

  for(int i=0; i<8; i++){
    strip.setPixelColor(i, (200, 160, 120) );
    strip.show();
  } */
  
  
  /*
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("CLOCK FROM HELL");
  display.println("SONEN");
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(45,12);  
  display.println("100%");
  display.display();
  delay(10000);
  display.clearDisplay(); */

}

void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}


