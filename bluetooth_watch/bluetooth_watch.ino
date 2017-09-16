#include <SoftwareSerial.h>// import the serial library


SoftwareSerial Genotronex(10, 11); // RX, TX omvendt mbby

int BluetoothData; // the data given from Computer

//oled

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2

//time lib
#include <TimeLib.h>



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
#error("Height incorrect, ur code sux or oled does");
#endif
int counter=10;
//oled end stup

int a=false,b=false,c=false, d=false;

void setup() {

  Genotronex.begin(9600);
  

  Serial.begin(9600);
  Serial.println("Start");



  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 128x32)
  // init done
  

  display.display();
  delay(1000);

  // Clear the buffer.
  display.clearDisplay();

  Genotronex.println("Bluetooth Connected");

  /*
  while(setTheTime()){
    delay(50);
  } */
  
  
}

  int m1,m2,h1,h2;
  int h, m;

void loop() {
BluetoothData=Genotronex.read();

if(!a){
  
  if(!b){
    h1=BluetoothData;
    b=true;
    BluetoothData=13;
  }
  else if(!c && BluetoothData != 13){
    h2=BluetoothData;
    c=true;
    BluetoothData=13;
  }
  else if(!d && BluetoothData !=13){
    m1=BluetoothData;
    d=true;
    BluetoothData=13;
  }
  else if(BluetoothData != 13){
    m2=BluetoothData;

    
  }
  else{
   // a=true, b=true, c=true, d=true;
   h1=hc(h1);
   h2=hc(h2);
    h=h1+h2;
   // m=m1+m2;
    Serial.println(h);
    Serial.println(m);
    setTime(h,m,00,2,3,2016);
  }

  
}else{
  //start oled
  
  
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
  //end oled
}



  
  

  


  

  /*
  if(BluetoothData=='1'){  
    Genotronex.println("ja");
  }


  Genotronex.println("ja");
  */

}
char hc(char nibble)
{
 if (nibble >= '0' && nibble <= '9')
   return nibble - '0';
 else if (nibble >= 'a' && nibble <= 'f')
   return 10 + nibble - 'a';
 else
   return 10 + nibble - 'A';
}

/*
boolean setTheTime(){
  int h, m;
  
  if (Genotronex.available()){
    
    BluetoothData=Genotronex.read();
    m=teh%100;
    h=teh/10;
    Serial.println(h);
    Serial.println(teh);
    Serial.println(m);

    Genotronex.println("hour set");
    setTime(h,m,00,2,3,2016);
    return false;


} else{return true;}
    
}
*/
