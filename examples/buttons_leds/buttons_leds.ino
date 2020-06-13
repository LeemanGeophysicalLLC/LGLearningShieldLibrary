/*
 * buttons_leds.ino
 * Turns on the light by a button when the button is pressed.
 */

#include <lglearning.h>

void setup()
{
  // Make the LED pins outputs
  pinMode(PIN_LED_BLUE, OUTPUT);
  pinMode(PIN_LED_RED, OUTPUT);
  pinMode(PIN_LED_YELLOW, OUTPUT);
  pinMode(PIN_LED_GREEN, OUTPUT);

  // Make the button pins inputs
  pinMode(PIN_SWITCH_A, INPUT);
  pinMode(PIN_SWITCH_B, INPUT);
  pinMode(PIN_SWITCH_C, INPUT);
  pinMode(PIN_SWITCH_D, INPUT);
}

void loop()
{
  // Check switch A - make the state of the LED match!
  digitalWrite(PIN_LED_GREEN, digitalRead(PIN_SWITCH_A));

  // Check switch B - make the state of the LED match!
  digitalWrite(PIN_LED_RED, digitalRead(PIN_SWITCH_B));

  // Check switch C - make the state of the LED match!
  digitalWrite(PIN_LED_BLUE, digitalRead(PIN_SWITCH_C));

  // Check switch D - make the state of the LED match!
  digitalWrite(PIN_LED_YELLOW, digitalRead(PIN_SWITCH_D));
}
