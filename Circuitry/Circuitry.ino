#include <StandardCplusplus.h>
#include <system_configuration.h>
#include <unwind-cxx.h>
#include <utility.h>

#include "rods.h"
#include "ganglion.h"
#include "horizontal.h"
//#include "glViewer.h"

//Global values
#define GANGLIA 13
#define RODS 29

//Store the classes
std::<array> rods[RODS];
std::<array> ganglia[GANGLIA];
std::<array> horizontal[GANGLIA];

//Functions to build the necessary cells
//Create the rods
void stageRods(int N){
  for (int i=0;i<N;i++){
    rods[i].initialize(Ai);
  }
}
//Create the Horizontal cells. Row# determines the algorithm used
void initHorizontal(int i){
    horizontal[i].addRecpt(rods[i]);
    horizontal[i].addRecpt(rods[i+1];
    horizontal[i].addRecpt(rods[i+3];
    horizontal[i].addRecpt(rods[i+5];
    horizontal[i].addRecpt(rods[i+12];
    horizontal[i].addRecpt(rods[i+13];
}
void stageHorizontal(int N){
  for (int i = 0;i<N;i++){
    initHorizontal(i);
  }
}

void recordRaw(){
  for (byte i=0; i<16; i++){
    
    //The following 4 commands set the correct logic for the control pins to select the desired input
    digitalWrite(CONTROL0, (i&15)>>3); 
    digitalWrite(CONTROL1, (i&7)>>2);  
    digitalWrite(CONTROL2, (i&3)>>1);  
    digitalWrite(CONTROL3, (i&1));     

    rods[i] = analogRead(A0); // load light vals from M0 into array
    if (i<13){
      rods[i+16] = analogRead(A1); // load light vals from M1 into array
    } 
  }
}

void stageGanglia(int N, int M){
  for (int i=0;i<N;i++){
    M += i;
    ganglion ganglia[i];
    ganglia[i].addCenter(rods[M]);
    ganglia[i].addHorizontal(surround[i]);
  }
}

recordRaw();
stageHorizontal(GANGLIA);

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
