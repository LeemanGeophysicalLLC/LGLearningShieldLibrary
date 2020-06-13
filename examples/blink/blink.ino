/*
 * blink.ino
 * Blink Example for Leeman Geophysical LLC Learning Shield
 * Blinks all four LEDs on the learning shield - turning them
 * on for one second and then off for one second.
 */

#include <lglearning.h>

// Runs once when the Arduino turns on
void setup()
{
  // Set the pins to be outputs
  pinMode(PIN_LED_BLUE, OUTPUT);
  pinMode(PIN_LED_RED, OUTPUT);
  pinMode(PIN_LED_YELLOW, OUTPUT);
  pinMode(PIN_LED_GREEN, OUTPUT);
}

// This block of code repeats over and over
void loop()
{
  // Turn the LEDs on
  digitalWrite(PIN_LED_BLUE, HIGH);
  digitalWrite(PIN_LED_RED, HIGH);
  digitalWrite(PIN_LED_YELLOW, HIGH);
  digitalWrite(PIN_LED_GREEN, HIGH);

  // Wait for 1 second (1000 milliseconds)
  delay(1000);

  // Turn the LEDs off
  digitalWrite(PIN_LED_BLUE, LOW);
  digitalWrite(PIN_LED_RED, LOW);
  digitalWrite(PIN_LED_YELLOW, LOW);
  digitalWrite(PIN_LED_GREEN, LOW);

  // Wait for 1 second (1000 milliseconds)
  delay(1000);
}
