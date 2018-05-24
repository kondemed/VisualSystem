#ifndef __horizontal_h_INCLUDED__
#define __horizontal_h_INCLUDED__

//#include "rods.h"

class horizontal {
public:
	void addRecpt(int cell, int k);
	int combineVal();
private:
	int surround[6];
	int totalVal;
};
#endif

