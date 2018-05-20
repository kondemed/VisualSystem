#include "horizontal.h"
#include <deque>
#include "rods.h"


void horizontal::addRecpt(rods cell) {
	surround.push_back(cell);
}

int horizontal::combineVal()
{
	for (int i=0; i<surround.size(); i++) {
		totalVal += surround[i].read();
	}
	return totalVal;
}
