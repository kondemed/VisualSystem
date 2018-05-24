#ifndef __horizontal_h_INCLUDED__
#define __horizontal_h_INCLUDED__

//#include "rods.h"

class horizontal {
public:
  horizontal();    //Default Constructor
  horizontal(int field);    //Secondary Constructor
	void addRecpt(int cell, int pos);
	int combineVal();
private:
	//rods surround[];
	int surround[];
  int fieldSize;
	int totalVal;
};
#endif

