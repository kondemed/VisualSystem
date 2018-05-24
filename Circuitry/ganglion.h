/*  Ganglion class
 *Stores the center rod and its 
 *associated horizontal cell.
 */
 
#ifndef __ganglion_H__INCLUDED
#define __ganglion_H__INCLUDED
#include "horizontal.h"
//#include "rods.h"

class ganglion {
public:
  static float adjust;
	//void addCenter(rods receptor);
	void addCenter(int receptor);
	void addHorizon(horizontal cell);
	int calcRate();
private:
	horizontal surround;
	int center;
	int rate;
};
#endif // !__ganglion_H__INCLUDED

