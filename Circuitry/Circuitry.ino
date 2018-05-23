#include <StandardCplusplus.h>
#include <system_configuration.h>
#include <unwind-cxx.h>
#include <utility.h>


//#include "rods.h"
#include "ganglion.h"
#include "horizontal.h"
//#include "glViewer.h"

//Global values
#define CONTROL0 5    
#define CONTROL1 4
#define CONTROL2 3
#define CONTROL3 2
#define GANGLIA 13
#define RODS 29
#define SURROUND_WEIGHT 1
#define TARE 42

//Store the classes
int rods[RODS];
ganglion ganglia[GANGLIA];
horizontal horizontal[GANGLIA];
int baselines[RODS];

//Functions to build the necessary cells
//Create the rods
/*void stageRods(int N){
  for (int i=0;i<N;i++){
    rods[i].initialize(Ai);
  }
}*/
//Create the Horizontal cells. 
void initHorizontal(int i){
  if(i<4){ //Range 0 to 3
    //Top
    horizontal[i].addRecpt(rods[i],0);
    horizontal[i].addRecpt(rods[i+1],1);
    //Next to center
    horizontal[i].addRecpt(rods[i+3],2);
    horizontal[i].addRecpt(rods[i+5],3);
    //Bottom
    horizontal[i].addRecpt(rods[i+12],4);
    horizontal[i].addRecpt(rods[i+13],5);
  }
  else if(i>=4 && i<9){ //Range 4 to 8
    //Top
    horizontal[i].addRecpt(rods[i+1],0);
    horizontal[i].addRecpt(rods[i+2],1);
    //Next to center
    horizontal[i].addRecpt(rods[i+7],2);
    horizontal[i].addRecpt(rods[i+9],3);
    //Bottom
    horizontal[i].addRecpt(rods[i+14],4);
    horizontal[i].addRecpt(rods[i+15],5);    
  }
  else{ //Range 9 to 12
    //Top
    horizontal[i].addRecpt(rods[i+3],0);
    horizontal[i].addRecpt(rods[i+4],1);
    //Next to center
    horizontal[i].addRecpt(rods[i+9],2);
    horizontal[i].addRecpt(rods[i+11],3);
    //Bottom
    horizontal[i].addRecpt(rods[i+15],4);
    horizontal[i].addRecpt(rods[i+16],5);
  }
}

void stageHorizontals(int N){
  for (int i = 0;i<N;i++){
    initHorizontal(i);
  }
}

void updateHorizontal(){
  for (int i=0;i<GANGLIA;i++){
    initHorizontal(i);
  }
}

//Create the Ganglion Cells
void stageGanglia(){
  for (int i=0;i<GANGLIA;i++){
    if (i<4){
      ganglia[i].addCenter(rods[i+6]);
    }
    else if (i=4 && i<9){
      ganglia[i].addCenter(rods[i+8]);
    }
    else{
      ganglia[i].addCenter(rods[i+10]);
    }
  }  
}

void printRate(){
  for (int i=0;i<GANGLIA;i++){
    int out = ganglia[i].calcRate();
    Serial.print(out);
    Serial.print(" ");
  }
}

//Global update function
void updateCells(){
  recordRaw();
  updateHorizontal();
  updateGanglia(); 
}

//Populate Rods
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

//Establish a baseline
void tare(){
  Serial.println("*** TARE ***");
  delay(1000);
  recordRaw();
  for (byte i=0; i<RODS; i++){
    baselines[i] = rods[i];
  }
}

void printRaw(){
  for (byte i=0; i<RODS; i++){
    if (i==0 || i==5 || i==11 || i==18 || i==24){
      Serial.println(" / ");
    } 
    Serial.print(" / ");
    Serial.print(rods[i]);
  }
  Serial.println();
}




// The setup() function runs once each time the micro-controller starts
void setup()
{
  pinMode(CONTROL0, OUTPUT);
  pinMode(CONTROL1, OUTPUT);
  pinMode(CONTROL2, OUTPUT);
  pinMode(CONTROL3, OUTPUT);
  pinMode(TARE, INPUT);
  
  Serial.begin(9600);

  tare();
  recordRaw();
  stageHorizontals(GANGLIA);
  stageGanglia();
}

// Add the main program code into the continuous loop() function
void loop()
{
  if (digitalRead(TARE) == HIGH){
    tare();
  }
  printRate();
  Serial.println("");
//  recordNormalized(); 
//  normalize(25);
//  printNormalized();
//  calculateGanglia();
//  printGanglia();
//  printRaw();
  //printRodsRawPy();
  updateCells();
  delay(1000);

}
