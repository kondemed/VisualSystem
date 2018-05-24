#include "ganglion.h"
#include "horizontal.h"
#include <math.h>


void ganglion::addCenter(int receptor)
{
	center = receptor;

}
void ganglion::addHorizon(horizontal cell) {
	surround = cell;
}
int ganglion::calcRate(){
  float ADJUST = 0.05f;
  int nega, posi;
	nega = floor(surround.combineVal() * ADJUST);
	posi = center;
	rate = posi - nega;
  if (rate <= 0){
    rate = 0;
  }
	return rate;
}
