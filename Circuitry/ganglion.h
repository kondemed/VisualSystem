#ifndef __ganglion_H__INCLUDED
#define __ganglion_H__INCLUDED
#include "horizontal.h"
#include "rods.h"
#include <deque>

class ganglion {
public:
  void ganglion(rods cell, horizontal field);
	void addCenter(rods receptor);
	void addHorizontal(horizontal cell);
	int calcRate();
private:
	horizontal surround;
	rods center;
	int rate;
};
#endif // !__ganglion_H__INCLUDED

