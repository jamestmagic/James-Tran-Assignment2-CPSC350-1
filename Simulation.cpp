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
bool stopSim;
Simulation::Simulation(){
  generationNum = 1;
  stopSim = false;
}

Simulation::Simulation(Generation g){
  currentGen = g;
  //nextGen = new Generation(currentGen.getNumRows(), currentGen.getNumCols());
  stopSim = false;
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
  if(intermissionChoice == 1){

  }
  else if(intermissionChoice == 2){
    cin.ignore();
  }
  else if(intermissionChoice == 3){

  }
}

void Simulation::doughnutMode(){

}

void Simulation::classicMode(){
  int adjacentCells;
  for(int i = 0;i < currentGen.getNumRows();++i){
    for(int j = 0;j < currentGen.getNumCols();++j){
      adjacentCells = 0; //tracks how many cells are adjacent to given location
      if(i==0 && j==0){ //position [0][0]
        if(!currentGen.isEmpty(i+1,j)){
          ++adjacentCells;
        }
        if(!currentGen.isEmpty(i+1,j+1)){
          ++adjacentCells;
        }
        if(!currentGen.isEmpty(i, j+1)){
          ++adjacentCells;
        }
        nextGen.getMyGrid()[i][j] = newLocation(adjacentCells, i, j);
      }
      else if(i==0 && j>0){
        if(!currentGen.isEmpty(i+1,j)){
          ++adjacentCells;
        }
        if(!currentGen.isEmpty(i+1,j+1)){
          ++adjacentCells;
        }
        if(!currentGen.isEmpty(i,j+1)){
          ++adjacentCells;
        }
        if(!currentGen.isEmpty(i, j-1)){
          ++adjacentCells;
        }
        if(!currentGen.isEmpty(i+1, j-1)){
          ++adjacentCells;
        }
        nextGen.getMyGrid()[i][j] = newLocation(adjacentCells, i, j);
      }
      else if(i>0 && j==0){
        if(!currentGen.isEmpty(i+1,j)){
          ++adjacentCells;
        }
        if(!currentGen.isEmpty(i+1,j+1)){
          ++adjacentCells;
        }
        if(!currentGen.isEmpty(i, j+1)){
          ++adjacentCells;
        }
        if(!currentGen.isEmpty(i-1, j)){
          ++adjacentCells;
        }
        if(!currentGen.isEmpty(i-1, j+1)){
          ++adjacentCells;
        }
        nextGen.getMyGrid()[i][j] = newLocation(adjacentCells, i, j);
      }

    }
  }
}

void Simulation::mirrorMode(){

}

char Simulation::newLocation(int adjacentCells, int row, int col){ //returns a new location type('-' or 'X') based on number of adjacent cells
  if(adjacentCells<=1 || adjacentCells >=4){
    return '-';
  }
  else if(adjacentCells == 3){
    return 'X';
  }
  else if(adjacentCells == 2){
    return currentGen.getMyGrid()[row][col];
  }
}
