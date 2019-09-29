#define _USE_MATH_DEFINES
#include "Simulation.h"
#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
#include <cmath>
#include <time.h>

using namespace std;

int generationNum;
Generation currentGen;
Generation nextGen;
Simulation::Simulation(){
  generationNum = 1;
}

Simulation::Simulation(Generation g){
  currentGen = g;
  
}

Simulation::~Simulation(){

}

void Simulation::play(int modeChoice, int intermissionChoice){
  if(modeChoice == 1){
    classicMode();
  }
  else if(modeChoice == 2){
    doughnutMode();
  }
  else if(modeChoice == 3){
    mirrorMode();
  }
}

void Simulation::doughnutMode(){

}

void Simulation::classicMode(){
  for(int i = 0;i < currentGen.numRows;++i){
    for(int j = 0;j < numCols;++j){

    }
  }
}

void Simulation::mirrorMode(){

}
