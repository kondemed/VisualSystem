#include <utility.h>
#include <unwind-cxx.h>
#include <system_configuration.h>
#include <StandardCplusplus.h>
#include "rods.h"
#include "ganglion.h"
#include "horizontal.h"
#include "glViewer.h"

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
void stageHorizontalRow1(rods cell){
  
}
void stageHorizontalRow2(){
  
}

void stageGanglia(int N, rods cell, int M, horizontal surround){
  for (int i=0;i<N;i++){
    M += i;
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

stageGanglia(4, ganglia[], rods[], 6, horizontal[]);
stageGanglia(5, ganglia[], rods[], 12, horizontal[]);
stageGanglia(4, ganglia[], rods[], 19, horizontal[]);

// The setup() function runs once each time the micro-controller starts
void setup()
{
    Serial.begin(9600);

}

// Add the main program code into the continuous loop() function
void loop()
{


}
