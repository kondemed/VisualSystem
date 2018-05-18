#ifndef __horizontal_h_INCLUDED__
#define __horizontal_h_INCLUDED__

#include "rods.h"
#include <deque>
#include <iterator>

class horizontal {
public:
	void addRecpt(rods cell);
	int combineVal();
private:
	std::deque<rods> surround;
	int totalVal;
};
#endif

