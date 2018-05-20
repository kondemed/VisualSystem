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
  for (int i;i<N;i++){
    rods[i].initialize(Ai);
  }
}
//Create the Horizontal cells. Row# determines the algorithm used
void stageHorizontalRow1(rods cell){
  
}
void stageHorizontalRow2(){
  
}

void stageGanglia(int N, rods cell, horizontal surround){
  for (int i;i<N;i++){
    int R = 8 + i;
    ganglion gangliai.addCenter(rodsR);
    gangliai.addHorizontal(surround);
  }
}

stageRods(RODS);
horizontal horizon0 = horizontal.addRecpt(A0);
horizon0.addRecpt(A1);
horizon0.addRecpt(A2);
horizon0.addRecpt(A7);
horizon0.addRecpt(A9);
horizon0.addRecpt(A11);
horizon0.addRecpt(A12);
horizon0.addRecpt(A13);

stageGanglia(ganglion0, A8, horizon0);
// The setup() function runs once each time the micro-controller starts
void setup()
{
    Serial.begin(9600);

}

// Add the main program code into the continuous loop() function
void loop()
{


}
