#ifndef __horizontal_h_INCLUDED__
#define __horizontal_h_INCLUDED__

//#include "rods.h"
#include <StandardCplusplus.h>
#include <system_configuration.h>
#include <unwind-cxx.h>
#include <utility.h>
//#include <deque>

class horizontal {
public:
	void addRecpt(int cell, int k);
  void reset();
  //void updateRecpt(int cell);
	int combineVal();
private:
	int surround[6];
	int totalVal;
};
#endif

