#include "ganglion.h"
#include "horizontal.h"
#include <math.h>


void ganglion::addCenter(rods receptor)
{
	center = receptor;

}
void ganglion::addHorizontal(horizontal cell) {
	surround = cell;
}
int ganglion::calcRate(){
	int nega = surround.combineVal();
	int posi = center.read();
	rate = posi - nega;
	return rate;
}