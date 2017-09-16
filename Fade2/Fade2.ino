/*
 Fade

 This example shows how to fade an LED on pin 9
 using the analogWrite() function.

 This example code is in the public domain.
 */

int led = 9;
int led2 = 10;
int brightness = 0;    // how bright the LED is
int brightness2 = 130;
int fadeAmount = 5;    // how many points to fade the LED by
int fadeAmount2 = 5;

// the setup routine runs once when you press reset:
void setup() {
  // declare pin 9 to be an output:
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // set the brightness of pin 9:
  analogWrite(led, brightness);
  analogWrite(led2, brightness2);

  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;
  brightness2 = brightness2 + fadeAmount2;

  // reverse the direction of the fading at the ends of the fade:
  if (brightness == 0 || brightness == 255) {
    fadeAmount = -fadeAmount ;
  }
  if (brightness2 == 0 || brightness2 == 255) {
    fadeAmount2 = -fadeAmount2 ;
  }
  // wait for 30 milliseconds to see the dimming effect
  delay(30);
}

