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
  nextGen = g;
  stopSim = false;
}

Simulation::~Simulation(){

}

void Simulation::play(int modeChoice, int intermissionChoice){
  if(modeChoice == 1){
    classicMode();
    cout << "classic end" << endl;
  }
  else if(modeChoice == 2){
    doughnutMode();
  }
  else if(modeChoice == 3){
    mirrorMode();
  }
  cout << "printing new gen" << endl;
  currentGen.printGen();
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
  cout << "classic" << endl;
  for(int i = 0;i < currentGen.getNumRows();++i){
    cout << "iterating through rows" << endl;
    for(int j = 0;j < currentGen.getNumCols();++j){
      cout << "iterating through cols" << endl;
      adjacentCells = 0; //tracks how many cells are adjacent to given location
      cout << "changed adjacent cells" << endl;
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
        cout << "changed new gen grid" << endl;
      }
      else if(i==currentGen.getNumRows()-1 && j==0){
        if(!currentGen.isEmpty(i-1, j)){
          ++adjacentCells;
        }
        if(!currentGen.isEmpty(i-1, j+1)){
          ++adjacentCells;
        }
        if(!currentGen.isEmpty(i, j+1)){
          ++adjacentCells;
        }
        nextGen.getMyGrid()[i][j] = newLocation(adjacentCells, i, j);
      }
      else if(i==currentGen.getNumRows()-1 && j==currentGen.getNumRows()-1){
        if(!currentGen.isEmpty(i-1, j)){
          ++adjacentCells;
        }
        if(!currentGen.isEmpty(i-1, j-1)){
          ++adjacentCells;
        }
        if(!currentGen.isEmpty(i, j-1)){
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
        cout << "changed new gen grid" << endl;
      }
      else if(i>0 && j==0){
        cout << "i >0 && j == 0" << endl;
        cout << " i, j = " << i << "," << j << endl;
        if(!currentGen.isEmpty(i+1,j)){
          cout << "Test" << endl;
          ++adjacentCells;
        }
        if(!currentGen.isEmpty(i+1,j+1)){
          cout << "Test" << endl;
          ++adjacentCells;
        }
        if(!currentGen.isEmpty(i, j+1)){
          cout << "Test" << endl;
          ++adjacentCells;
        }
        if(!currentGen.isEmpty(i-1, j)){
          cout << "Test" << endl;
          ++adjacentCells;
        }
        if(!currentGen.isEmpty(i-1, j+1)){
          cout << "Test" << endl;
          ++adjacentCells;
        }
        cout <<"about to change new gen grid" << endl;
        nextGen.changeLocation(i, j, newLocation(adjacentCells, i, j));
        cout << "changed new gen grid" << endl;
      }
      
      cout << "classic4" << endl;
    }
    cout << "classic end for" << endl;
  }
  cout << "classic endd" << endl;
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
  else{
    return '-';
  }
}
