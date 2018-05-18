#include "rods.h"
#include "ganglion.h"
#include "horizontal.h"
#include "glViewer.h"

#define GANGLIA 12
#define RODS 28

//Creating the rods
def stageRods(int N){
  for (int i;i<N;i++){
    rods(Ai);
  }
}
def stageGanglia(int N){
  for (int i;i<N;i++){
    ganglia.addCenter(rod);
    ganglia
  }
}
stageRods(RODS);


// The setup() function runs once each time the micro-controller starts
void setup()
{
    Serial.begin(9600);

}

// Add the main program code into the continuous loop() function
void loop()
{


}
