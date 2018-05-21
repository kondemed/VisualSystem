#include <StandardCplusplus.h>
#include <system_configuration.h>
#include <unwind-cxx.h>
#include <utility.h>

#include "rods.h"
#include "ganglion.h"
#include "horizontal.h"
//#include "glViewer.h"

//Global values
#define GANGLIA 12
#define RODS 28

//Store the classes
std::<array> rods[RODS-1];
std::<array> ganglia[GANGLIA-1];
std::<array> horizontal[GANGLIA-1];

//Functions to build the necessary cells
//Create the rods
void stageRods(int N){
  for (int i=0;i<N;i++){
    rods[i].initialize(Ai);
  }
}
//Create the Horizontal cells. Row# determines the algorithm used
void stageHorizontalRow1(){
  int i = 0;
  for (i; i<2; i++){
    horizontal.addRecpt(rods[i]);
  }
    horizontal.addRecpt(rods[i+3];
    horizontal.addRecpt(rods[i+2];
    horizontal.addRecpt(rods[i+7];
    horizontal.addRecpt(rods[i+1];
    
  //for (int i+3; i<
}
void stageHorizontalRow2(){
  
}

void stageGanglia(int N, int M){
  for (int i=0;i<N;i++){
    M += i;
    ganglion ganglia[i];
    ganglia[i].addCenter(rods[M]);
    ganglia[i].addHorizontal(surround[i]);
  }
}

stageRods(RODS);
/* One example receptive field
horizontal horizon0;
horizon0.addRecpt(A0);
horizon0.addRecpt(A1);
horizon0.addRecpt(A2);
horizon0.addRecpt(A5);
horizon0.addRecpt(A7);
horizon0.addRecpt(A12);
horizon0.addRecpt(A13);
ganglion0.addCenter(A6);
*/

stageGanglia(4, 6);
stageGanglia(5, 12);
stageGanglia(4, 19);

// The setup() function runs once each time the micro-controller starts
void setup()
{
    Serial.begin(9600);

}

// Add the main program code into the continuous loop() function
void loop()
{


}
