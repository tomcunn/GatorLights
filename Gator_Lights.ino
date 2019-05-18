/***********************************
Gator EYES

The eyeball portion is LED numbers
5,6,9,10

************************************/

#include <Adafruit_NeoPixel.h>

#define PIN D3
#define NUMBER_OF_LEDS 28


Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMBER_OF_LEDS, PIN, NEO_GRB + NEO_KHZ400);

void setup() 
{
  //Init the strip with all zeros
  strip.begin();

  pinMode(D0,INPUT);


  //Clear all the LEDS
  for(int i = 0; i<NUMBER_OF_LEDS ; i++)
  {
    strip.setPixelColor(i, 0, 0, 0);
  }
  strip.show(); // Initialize all pixels to 'off'
}

void loop() 
{
  //Set all the LEDS to white
  for(int i = 0; i<NUMBER_OF_LEDS ; i++)
  {
    strip.setPixelColor(i, 200, 200, 200);
  }
  if(digitalRead(D0) == true)
  {
     for(int i = 0; i<NUMBER_OF_LEDS ; i++)
     {
        strip.setPixelColor(i, 0, 200, 0);
     }

  }
  /*
  strip.setPixelColor(4, 10, 10, 10);
  strip.setPixelColor(5, 10, 10, 10);
  strip.setPixelColor(8, 10, 10, 10);
  strip.setPixelColor(9, 10, 10, 10);
  */
  //Show the strip
  strip.show();
   
  delay(1000);
}
