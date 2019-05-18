/***********************************
Gator Head Lights
************************************/

#include <Adafruit_NeoPixel.h>

#define PIN D3
#define NUMBER_OF_LEDS 28

static bool Flashers = false;
static int Flasher_Counter = 0;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMBER_OF_LEDS, PIN, NEO_GRB + NEO_KHZ400);

void setup() 
{
  //Init the strip with all zeros
  strip.begin();

  //This is for the blue button on the console
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
  int flash_color2;
  int flash_color;
  
  //Set all the LEDS to white
  for(int i = 0; i<NUMBER_OF_LEDS ; i++)
  {
    strip.setPixelColor(i, 220, 220, 220);
  }
  //Turn on the flashers for 15 seconds
  if(digitalRead(D0) == true)
  {
     Flashers = true;
     
     while (Flashers == true)
     {
        //Makes the flash on every other cycle
        if(Flasher_Counter % 2 == 0)
        {
           flash_color = 250;
           flash_color2 = 0;
        }
        else
        {
           flash_color = 0;
           flash_color2 = 250;
        }
        
        //Write the LEDS for Right Light
        for(int i = 0; i<14 ; i++)
        {
           strip.setPixelColor(i, flash_color, 0, flash_color2);
        }
        
        //Write the LEDS for Left Light
        for(int i = 14; i<NUMBER_OF_LEDS ; i++)
        {
           strip.setPixelColor(i, flash_color2, 0, flash_color);
        }
         
        //Increment the counter
        Flasher_Counter++;
        
        //Controls the time between flashes
        delay(250);
        
        if(Flasher_Counter > 60)
        {
          //Turn off the counter and set the flag to false
          Flasher_Counter = 0;
          Flashers = false;
        }
        
        //Output the values to the lights
        strip.show();
     }
  }

  //Show the strip
  strip.show();
   
  delay(1000);
}
