#include "ganglion.h"
#include "horizontal.h"
#include <StandardCplusplus.h>
#include <system_configuration.h>
#include <unwind-cxx.h>
#include <utility.h>
#include <math.h>

/*void ganglion::ganglion(rods cell, horizontal field){
  center = cell;
  surround = field;
}
*/
void ganglion::addCenter(int receptor)
{
	center = receptor;

}
void ganglion::addHorizontal(horizontal cell) {
	surround = cell;
}
int ganglion::calcRate(){
  float adjust = 0.1f;
  int nega, posi;
	nega = floor(surround.combineVal() * adjust);
	posi = center;
	rate = posi - nega;
  if (rate <= 0){
    rate = 0;
  }
	return rate;
}
