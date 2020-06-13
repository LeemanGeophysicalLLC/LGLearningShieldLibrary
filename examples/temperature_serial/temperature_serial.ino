/*
 * temperature_serial.ino
 * Reads the on-board TMP36 sensor and displays the temperature in
 * both Celsius and Fahrenheit. Waits one second between readings
 * as temperature changes are slow events.
 */

#include <lglearning.h>

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  Serial.print(readTemperatureCelsius());
  Serial.print(", ");
  Serial.println(readTemperatureFahrenheit());
  delay(1000);
}
