#include <Servo.h>
#include <FastLED.h>

// Include the Ease.h file
#include "Ease.h"

// Create Servo object
Servo motor1;
const int motor1_pin = 5;

// Create a new ease with QUARTIC_IN as the easing type
Ease my_ease(QUARTIC_IN);

void setup() {
  motor1.attach(motor1_pin);
}

float step_size = 0.01;
float i=0;
bool is_backwards = false;

void loop() {

  EVERY_N_MILLIS(10){
      // Use ease.y() to convert linear value to eased value
      float eased_value = my_ease.y(i);

    // (x*120)+30 scales the value from 0->1 to 30->150
    int motor_pos = (eased_value*120)+30;

    // If we are going backwards, then invert direction
    if(is_backwards){
      motor_pos = 180 - motor_pos;
    }

    // Now write the position
    motor1.write(motor_pos);

    // Advance value of i a bit
    i = i + step_size;
    if(i>=1){
      is_backwards = !is_backwards; // going other way now
      i=0; // reset counter
    }
  }

}
