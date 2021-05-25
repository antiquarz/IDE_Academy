#include <Servo.h>

// Include the FastLED library for the handy EVERY_N_MILLIS functions
#include <FastLED.h>

// Create Servo object
Servo motor1;
Servo motor2;
const int motor1_pin = 5;
const int motor2_pin = 4;

void setup() {
   // Attach the servo motor to the pin
   motor1.attach(motor1_pin);
   motor2.attach(motor2_pin);
}

// Variables to save current positions and step sizes
int motor1_step = 1;
int motor2_step = 5;
int motor1_pos = 50;
int motor2_pos = 50;

void loop() {
   EVERY_N_MILLIS(25){
      // Set new motor positions
      motor1.write(motor1_pos);
      motor2.write(motor2_pos);

      // Check if we are at the ends
      if((motor1_pos >= 170)||(motor1_pos <= 10)){
         motor1_step = -motor1_step;
      }
      if((motor2_pos >= 50)||(motor2_pos <= 30)){
         motor2_step = -motor2_step;
      }

      // Move the motors on a bit
      motor1_pos = motor1_pos + motor1_step;
      motor2_pos = motor2_pos + motor2_step;
  }
}
