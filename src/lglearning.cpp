#include "Arduino.h"
#include "lglearning.h"

float readTemperatureCelsius(void)
{
    float sensorInput = analogRead(PIN_TEMPERATURE_SENSOR);
    float temp = (double)sensorInput / 1024;
    temp = temp * 5;
    temp = temp - 0.5;
    temp = temp * 100;
    return temp;
}

float readTemperatureFahrenheit(void)
{
    return readTemperatureCelsius() * 9 / 5 + 32;
}