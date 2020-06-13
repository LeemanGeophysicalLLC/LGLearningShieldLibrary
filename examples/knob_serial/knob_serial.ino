/*
 * knob_serial.ino
 * Reads the potentiometer knob on the board and sends the
 * reading out over the serial port.
 */

#include <lglearning.h>

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  Serial.println(analogRead(PIN_POT));
  delay(100);
}
