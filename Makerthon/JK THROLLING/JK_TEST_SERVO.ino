// JK TEST SERVO (MOTOR)

// LIBRARY
#include <Servo.h> 

// DEFINE
Servo MOON_LEFT;
Servo MOON_RIGHT;
int moon = 0;
#define PIN_MOON_LEFT 11
#define PIN_MOON_RIGHT 6

// SETUP
void setup() 
{ 
  MOON_LEFT.attach(PIN_MOON_LEFT);
  MOON_RIGHT.attach(PIN_MOON_RIGHT);
} 

// LOOP
void loop() 
{ 
  for(moon = 0; moon <= 90; moon += 1)
  {
    MOON_LEFT.write(moon);
    MOON_RIGHT.write(90-moon);
    delay(15);
  }
  
  for(moon = 90; moon>=0; moon-=1)
  {
    MOON_LEFT.write(moon);
    MOON_RIGHT.write(90-moon);
    delay(15); 
  }
} 
