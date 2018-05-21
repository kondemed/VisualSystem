#ifndef __horizontal_h_INCLUDED__
#define __horizontal_h_INCLUDED__

#include "rods.h"
#include <deque>
#include <iterator>

class horizontal {
public:
	void addRecpt(int cell);
  void reset();
  void updateRecpt(int cell);
	int combineVal();
private:
  std::deque<int>::iterator it = surround.begin();
	std::deque<int> surround;
	int totalVal;
};
#endif

