#include "horizontal.h"
#include <StandardCplusplus.h>
#include <system_configuration.h>
#include <unwind-cxx.h>
#include <utility.h>
#include <Arduino.h>
//#include <deque>
//#include "rods.h"


void horizontal::addRecpt(int cell, int k) {
	surround[k] = cell;
}

int horizontal::combineVal()
{
  totalVal = 0;
  Serial.print("Horizontal values are: ");
	for (int i=0; i<6; i++) {
		totalVal += surround[i];
    Serial.print(totalVal);
    Serial.print(" ");
	}
	return totalVal;
}


