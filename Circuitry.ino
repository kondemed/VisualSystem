#include "rods.h"
#include "ganglion.h"
#include "horizontal.h"
#include "glViewer.h"

//Creating the rods
def stage(int N){
  for (int i;i<N;i++){
    rods(Ai);
  }
}
stage(29);

// Define Functions below here or use other .ino or cpp files
//

// The setup() function runs once each time the micro-controller starts
void setup()
{
    Serial.begin(9600);

}

// Add the main program code into the continuous loop() function
void loop()
{


}
