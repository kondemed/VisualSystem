#include <Arduino.h>
#include "rods.h"

rods::rods(const uint8_t pin)
{
	rodPin = pin;
}

void rods::initialize(int pin)
{
	rodPin = pin;
	sensorVal = 0;
	outputVal = 0;
}

int rods::read()
{
	outputVal = analogRead(rodPin);
	return outputVal;

}
