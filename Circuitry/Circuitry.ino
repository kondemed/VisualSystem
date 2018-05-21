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
    horizontal[i].addRecpt(rods[i],0);
    horizontal[i].addRecpt(rods[i+1],1);
    Serial.println(rods[i+1]);
    horizontal[i].addRecpt(rods[i+3],2);
    horizontal[i].addRecpt(rods[i+5],3);
    horizontal[i].addRecpt(rods[i+12],4);
    horizontal[i].addRecpt(rods[i+13],5);
}
void stageHorizontal(int N){
  for (int i = 0;i<N;i++){
    initHorizontal(i);
  }
}
void updateHorizontal(){
  for (int i=0;i<GANGLIA;i++){
    initHorizontal(i);
  }

}
void stageGanglia(int N, int M){
  for (int i=0;i<N;i++){
    M += i;
    //ganglia[i](rods[M],ganglia[i];
    ganglia[i].addCenter(rods[M]);
    ganglia[i].addHorizontal(horizontal[i]);
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
  stageHorizontal(GANGLIA);

  stageGanglia(4, 6);
  stageGanglia(5, 12);
  stageGanglia(4, 19);
}

// Add the main program code into the continuous loop() function
void loop()
{
  if (digitalRead(TARE) == HIGH){
    tare();
  }
  for (int i=0;i<GANGLIA;i++){
    int out = ganglia[i].calcRate();
    Serial.print(out);
  }
  recordRaw();
//  recordNormalized(); 
//  normalize(25);
//  printNormalized();
//  calculateGanglia();
//  printGanglia();
//  printRaw();
  //printRodsRawPy();
  updateHorizontal();
  delay(1000);

}
