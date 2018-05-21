#ifndef __ganglion_H__INCLUDED
#define __ganglion_H__INCLUDED
#include "horizontal.h"
#include "rods.h"

class ganglion {
public:
  //void ganglion(int cell, horizontal field);
	void addCenter(int receptor);
	void addHorizontal(horizontal cell);
	int calcRate();
private:
	horizontal surround;
	int center;
	int rate;
};
#endif // !__ganglion_H__INCLUDED

