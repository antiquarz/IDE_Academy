// Include FastLED library by Daniel Garcia
#include <FastLED.h>

// Setup FastLED pins
#define DATA_PIN 6
#define NUM_LEDS 16

// Array of led data
CRGB leds[NUM_LEDS];

// Circular gradient from red to blue and back
CRGBPalette256 my_gradient = CRGBPalette256(
   CRGB::Red,
   CRGB::Blue,
   CRGB::Red
);

void setup() { 
   // Neopixel ring is WS2813 chipset, GRB ordering
   FastLED.addLeds<WS2813, DATA_PIN, GRB>(leds, NUM_LEDS);
   FastLED.clear();
}

uint8_t pos = 0;

void loop() { 
   EVERY_N_MILLIS(5){
      for(uint8_t i=0; i<NUM_LEDS; i++){
         // Calculate position with map() then use pos to cycle it around the ring a bit
         uint8_t this_position = map(i,0,NUM_LEDS-1,0,255)+pos;
         leds[i] = ColorFromPalette(my_gradient,this_position);
      }
      FastLED.show();
      pos++; // defined as uint8_t so it will loop back to 0 after 255
  }  
}
