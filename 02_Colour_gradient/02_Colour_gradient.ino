// Include FastLED library by Daniel Garcia
#include <FastLED.h>

// Setup FastLED pins
#define DATA_PIN 6
#define NUM_LEDS 20

// Pin for rotary button
#define ROTARY_BUTTON A0

// Array of led data
CRGB leds[NUM_LEDS];

// Create a gradient palette 
// |-----------------------|
// GREEN......BLUE.......RED
CRGBPalette256 my_gradient = CRGBPalette256(
   CRGB::Green,
   CRGB::Blue,
   CRGB::Red
);

void setup() { 
   // Neopixel ring is WS2813 chipset, GRB ordering
   FastLED.addLeds<WS2813, DATA_PIN, GRB>(leds, NUM_LEDS);
   FastLED.clear();
}

// Variable to save colour of ring
CRGB ring_colour;

void loop() { 
  // Scale analog value from 0->1023 to 0->255
  int gradient_value = map(analogRead(ROTARY_BUTTON),0,1023,0,255);

  // Pick colour from gradient
   for(uint8_t i=0; i<NUM_LEDS; i++){
      leds[i] = ColorFromPalette(my_gradient, gradient_value);
   }
   FastLED.show();  
}