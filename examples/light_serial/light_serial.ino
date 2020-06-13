/*
 * light_serial.ino
 * Reads the on-board photoresistor sensor and displays the reading.
 * Updates at 10Hz and works well with the plotter utility!
 */

#include <lglearning.h>

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  Serial.println(analogRead(PIN_LIGHT_SENSOR));
  delay(100);
}
