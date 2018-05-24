/*  Ganglion class function definitions
 *associated horizontal cell.
 */
 
 //#include "rods.h"
#include "ganglion.h"
#include "horizontal.h"
#include <math.h>

void ganglion::addCenter(int receptor){
	center = receptor;
}

/*
void ganglion::addCenter(rods receptor){
  center = receptor;
} 
*/

void ganglion::addHorizon(horizontal cell) {
	surround = cell;
}

int ganglion::calcRate(){
  //float ADJUST = 0.05f;
  int nega, posi;
	nega = floor(surround.combineVal() * adjust);
	posi = center;
	rate = posi - nega;
  if (rate < 10){
    rate = 10;
  }
	return rate;
}
