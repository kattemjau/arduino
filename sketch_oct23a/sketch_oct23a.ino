// which analog pin to connect
#define THERMISTORPIN A0         
// resistance at 25 degrees C
#include <LiquidCrystal.h>
#define THERMISTORNOMINAL 10000      
// temp. for nominal resistance (almost always 25 C)
#define TEMPERATURENOMINAL 25   
// how many samples to take and average, more takes longer
// but is more 'smooth'
#define NUMSAMPLES 5
// The beta coefficient of the thermistor (usually 3000-4000)
#define BCOEFFICIENT 3950
// the value of the 'other' resistor
#define SERIESRESISTOR 10000

#define relay1 8
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
 
int samples[NUMSAMPLES];

boolean test = "false"
;
 
void setup(void) {
  Serial.begin(9600);
  analogReference(EXTERNAL);
  pinMode(relay1, OUTPUT);
  lcd.begin(16, 2);
  // Print a message to the LCD.
}
 
void loop(void) {
  uint8_t i;
  float average;
 
  // take N samples in a row, with a slight delay
  for (i=0; i< NUMSAMPLES; i++) {
   samples[i] = analogRead(THERMISTORPIN);
   delay(10);
  }
 
  // average all the samples out
  average = 0;
  for (i=0; i< NUMSAMPLES; i++) {
     average += samples[i];
  }
  average /= NUMSAMPLES;
 
  //Serial.print("Average analog reading "); 
  //Serial.println(average);
 
  // convert the value to resistance
  average = 1023 / average - 1;
  average = SERIESRESISTOR / average;
  //Serial.print("Thermistor resistance "); 
  //Serial.println(average);
 
  float steinhart;
  steinhart = average / THERMISTORNOMINAL;     // (R/Ro)
  steinhart = log(steinhart);                  // ln(R/Ro)
  steinhart /= BCOEFFICIENT;                   // 1/B * ln(R/Ro)
  steinhart += 1.0 / (TEMPERATURENOMINAL + 273.15); // + (1/To)
  steinhart = 1.0 / steinhart;                 // Invert
  steinhart -= 273.15;                         // convert to C
 
  //Serial.print("Temperature "); 
  //Serial.print(steinhart);
  //Serial.println(" *C");

  lcd.print(steinhart);
  lcd.setCursor(4,0);
  lcd.print(" *C");
  lcd.setCursor(0,1);
  test = Serial.readString();
  Serial.println(steinhart);

  if(test) {
    if(steinhart <= 4) {
    digitalWrite(relay1, HIGH);
    lcd.print("Relay off");
    } else if(steinhart >= 10) {
    digitalWrite(relay1, LOW);
    lcd.print("Relay on");
    }
  } else {
    digitalWrite(relay1, HIGH);
  }

  //digitalWrite(relay1, HIGH);
 
  delay(1000);
  lcd.clear();
}
