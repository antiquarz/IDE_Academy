// Include FastLED library by Daniel Garcia
#include <FastLED.h>

// Setup FastLED pins
#define DATA_PIN 6
#define NUM_LEDS 20

// Debouncer for button
#define PUSH_BUTTON 7

// Array of led data
CRGB leds[NUM_LEDS];

void setup() { 
   // Neopixel ring is WS2813 chipset, GRB ordering
   FastLED.addLeds<WS2813, DATA_PIN, GRB>(leds, NUM_LEDS);
   FastLED.clear();
   
   // Setup buttons
 	 pinMode(PUSH_BUTTON, INPUT_PULLUP);
}

// Variable to save ring colour in
CRGB ring_colour;

void loop() { 

   // Set colour we want to use based on whether button is pushed
   if(digitalRead(PUSH_BUTTON) == HIGH){
      ring_colour = CRGB::Red;
   }else{
      ring_colour = CRGB::Green;
   }

   // Update colours for ring
   for(int i=0; i<NUM_LEDS; i++){
      leds[i] = ring_colour; 
   }
   FastLED.show();  
}
