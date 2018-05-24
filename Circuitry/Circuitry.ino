/*  Written by Blades Walker and Andrew Woosnam
 *Commented out code are for rods as a class. Our hardware setup prevented us
 *from using the rods class because the multiplexor changes how the pins are  
 *read.
 */

//#include "rods.h"
#include "ganglion.h"
#include "horizontal.h"

//Convenient names
#define CONTROL0 5    
#define CONTROL1 4
#define CONTROL2 3
#define CONTROL3 2

//Global values for modularity
#define RODS 29
#define TARE 42
#define GANGLIA 13
#define HORIZONTAL 13 
#define SURROUND_WEIGHT 0.01
//#define FIELD 6        //Uncomment if adjusting the surrounding field size


//Store the classes
int rods[RODS];
float ganglion::adjust = SURROUND_WEIGHT;
ganglion ganglia[GANGLIA];
horizontal horizon[HORIZONTAL];
int baselines[RODS];

//Functions to build the necessary cells
/*Create the rods of the rods class
void stageRods(int N){
  for (int i=0;i<N;i++){
    rods[i].init(Ai);
  }
}*/

//Create the Horizontal cells. 
void initHorizontal(int i){
  if(i<4){ //Range 0 to 3
    //Top
    horizon[i].addRecpt(rods[i],0);
    horizon[i].addRecpt(rods[i+1],1);
    //Next to center
    horizon[i].addRecpt(rods[i+3],2);
    horizon[i].addRecpt(rods[i+5],3);
    //Bottom
    horizon[i].addRecpt(rods[i+12],4);
    horizon[i].addRecpt(rods[i+13],5);
  }
  else if(i>=4 && i<9){ //Range 4 to 8
    //Top
    horizon[i].addRecpt(rods[i+1],0);
    horizon[i].addRecpt(rods[i+2],1);
    //Next to center
    horizon[i].addRecpt(rods[i+7],2);
    horizon[i].addRecpt(rods[i+9],3);
    //Bottom
    horizon[i].addRecpt(rods[i+14],4);
    horizon[i].addRecpt(rods[i+15],5);    
  }
  else{ //Range 9 to 12
    //Top
    horizon[i].addRecpt(rods[i+3],0);
    horizon[i].addRecpt(rods[i+4],1);
    //Next to center
    horizon[i].addRecpt(rods[i+9],2);
    horizon[i].addRecpt(rods[i+11],3);
    //Bottom
    horizon[i].addRecpt(rods[i+15],4);
    horizon[i].addRecpt(rods[i+16],5);
  }
}

void stageHorizontals(int N){
  for (int i = 0;i<N;i++){
    initHorizontal(i);
  }
}

void updateHorizontals(){
  for (int i=0;i<HORIZONTAL;i++){
    initHorizontal(i);
  }
}

//Create the Ganglion Cells
void stageGanglia(){
  for (int i=0;i<GANGLIA;i++){
    if (i<4){
      ganglia[i].addCenter(rods[i+6]);
      ganglia[i].addHorizon(horizon[i]);
    }
    else if (i>=4 && i<9){
      ganglia[i].addCenter(rods[i+8]);
      ganglia[i].addHorizon(horizon[i]);
    }
    else{
      ganglia[i].addCenter(rods[i+10]);
      ganglia[i].addHorizon(horizon[i]);
    }
  }  
}

void updateGanglia(){
  for (int i=0;i<GANGLIA;i++){
    if (i<4){
      ganglia[i].addCenter(rods[i+6]);
    }
    else if (i>=4 && i<9){
      ganglia[i].addCenter(rods[i+8]);
    }
    else{
      ganglia[i].addCenter(rods[i+10]);
    }
  }  
}

void printRate(){
  for (int i=0;i<GANGLIA;i++){
    Serial.print(i);
    Serial.print(": ");
    int out = ganglia[i].calcRate();
    Serial.print(out);
    Serial.print(" ");
  }
}

//Global update function
void updateCells(){
  recordRaw();
  updateHorizontals();
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
  delay(1000);
  recordRaw();
  for (byte i=0; i<RODS; i++){
    baselines[i] = rods[i];
  }
    Serial.println("*** TARE ***");
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
void setup(){
  pinMode(CONTROL0, OUTPUT);
  pinMode(CONTROL1, OUTPUT);
  pinMode(CONTROL2, OUTPUT);
  pinMode(CONTROL3, OUTPUT);
  pinMode(TARE, INPUT);
  
  Serial.begin(9600);

  tare();
  recordRaw();
  stageHorizontals(HORIZONTAL);
  stageGanglia();
}

//Loop through code as desired
void loop(){
  if (digitalRead(TARE) == HIGH){
    tare();
  }
//  recordNormalized(); 
//  normalize(25);
//  printNormalized();

  printRodsRawPy();
  updateCells();
  delay(1000);

}

void printRodsRawPy(){
  for (byte i=0; i<RODS; i++){
    Serial.print(rods[i]);
    Serial.print(",");
  }
  Serial.print("*,");
  for (byte i=0; i<GANGLIA; i++){
    Serial.print(ganglia[i].calcRate());
    Serial.print(",");
  }
  Serial.println();
}
