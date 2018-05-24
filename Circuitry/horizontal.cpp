#include "horizontal.h"
#include <Arduino.h>
//#include "rods.h"


void horizontal::addRecpt(int cell, int k) {
	surround[k] = cell;
}

int horizontal::combineVal(){
  totalVal = 0;
	for (int i=0; i<6; i++) {
		totalVal += surround[i];
	}
	return totalVal;
}


