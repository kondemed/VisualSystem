#include "horizontal.h"
//#include "rods.h"

horizontal::horizontal(){   //Default Constructor
  surround[6];
  fieldSize = 6;
}

horizontal::horizontal(int field){   //Secondary Constructor
  surround[field];
  fieldSize = field;
}
  
void horizontal::addRecpt(int cell, int pos) {
	surround[pos] = cell;
}

/*
void horizontal::addRecpt(rods cell, int pos) {
  surround[pos] = cell;
}
*/

int horizontal::combineVal(){
  totalVal = 0;
	for (int i=0; i<fieldSize; i++) {
		totalVal += surround[i];
	}
	return totalVal;
}

/*
int horizontal::combineVal(){
  totalVal = 0;
  for (int i=0; i<fieldSize; i++) {
    totalVal += surround[i].read();
  }
  return totalVal;
}
*/

