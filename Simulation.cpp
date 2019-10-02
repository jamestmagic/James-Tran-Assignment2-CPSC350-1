#define _USE_MATH_DEFINES
#include "Simulation.h"
#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
#include <cmath>
#include <time.h>
//#include <dos.h>

using namespace std;

int generationNum;
Generation currentGen;
Generation* nextGen;
bool stopSim;//in case simulation needs to be aborted
Simulation::Simulation(){
  generationNum = 0;
  stopSim = false;
}

Simulation::Simulation(Generation g){
  generationNum = 0;
  currentGen = g; //given dimensions and spaces
  nextGen = Generation(g.getNumRows(), g.getNumCols()); //empty grid with given dimensions
  stopSim = false;
}

Simulation::~Simulation(){

}

void Simulation::play(int modeChoice, int intermissionChoice){ //runs the simulation
  ofstream writeFile; //starts an out stream to write to a file
  writeFile.open("life.out"); //opens a new .out file
  while(!currentGen.emptyGen() && (nextGen.compareGen(currentGen) == false) && generationNum < 100){ //only runs when generations are different or not empty or when generations surpass 100
    if(intermissionChoice!= 3 && generationNum == 0){//prints the inital configuration
      cout << generationNum << endl;
      currentGen.printGen();
      ++generationNum;
    }
    else if(intermissionChoice == 3 && generationNum == 0){//prints the inital configuration
      writeFile << generationNum << endl;
      for(int i = 0;i < currentGen.getNumRows();++i){
        for(int j = 0;j < currentGen.getNumCols();++j){
          writeFile << currentGen.getMyGrid()[i][j];
        }
        writeFile << endl;
      }
      ++generationNum;
    }
    if(modeChoice == 1){ //runs classic mode
      classicMode();
    }
    else if(modeChoice == 2){ //runs doughnut mode
      doughnutMode();
    }
    else if(modeChoice == 3){ //runs mirror mode
      mirrorMode();
    }
    if(((intermissionChoice == 1 || intermissionChoice == 2))){ //prints grid and generationNum to console accordingly
      cout << generationNum << endl;
      nextGen.printGen();
      if(intermissionChoice == 1){
        //usleep(2000);
        //could not find a way to implement system("pause")
      }
      else if(intermissionChoice == 2){
        cout << "Press Enter to Continue to next Generation" << endl;
        cin.ignore(); //allows for a pause
        if(generationNum == 0){
          cin.ignore();
        }
      }
    }
    else if(intermissionChoice == 3){ //writes all info to file
      writeFile << generationNum << endl;
      for(int i = 0;i < nextGen.getNumRows();++i){
        for(int j = 0;j < nextGen.getNumCols();++j){
          writeFile << nextGen.getMyGrid()[i][j];
        }
        writeFile << endl;
      }
    }
    if(nextGen.compareGen(currentGen)){ //checks if the previous and current generation are the same
      continue; //returns to the while loop and ends
    }
    currentGen.copyGen(nextGen); //copies grid from nextGen to currentGen
    nextGen = Generation(currentGen.getNumRows(), currentGen.getNumCols()); //resets nextGen
    ++generationNum;
  }
  writeFile.close();
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Simulation::doughnutMode(){
  int adjacentCells;
  for(int i = 0;i < currentGen.getNumRows();++i){
    for(int j = 0;j < currentGen.getNumCols();++j){
      adjacentCells = 0; //tracks how many cells are adjacent to given location
      //if statements are in order of iteration, prioritizing corners and edges over the middle of the grid
      //each time a cell is detected in an adjacent location, adjacent cells is incremented by 1
      //at the end of each case, the value of adjacent cells determines what takes the cell location in the next generation
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
        if(!currentGen.isEmpty((currentGen.getNumRows()-1), (currentGen.getNumCols()-1))){
          ++adjacentCells;
        }
        if(!currentGen.isEmpty((currentGen.getNumRows()-1), 0)){
          ++adjacentCells;
        }
        if(!currentGen.isEmpty((currentGen.getNumRows()-1), j+1)){
          ++adjacentCells;
        }
        if(!currentGen.isEmpty(0, (currentGen.getNumCols()-1))){
          ++adjacentCells;
        }
        if(!currentGen.isEmpty(i+1, (currentGen.getNumCols()-1))){
          ++adjacentCells;
        }
        nextGen.changeLocation(i, j, newLocation(adjacentCells, i, j));
        continue;
      }
      else if(i==0 && j<(currentGen.getNumCols()-1)){//top edge
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
        if(!currentGen.isEmpty((currentGen.getNumRows()-1), j-1)){
          ++adjacentCells;
        }
        if(!currentGen.isEmpty((currentGen.getNumRows()-1), j)){
          ++adjacentCells;
        }
        if(!currentGen.isEmpty((currentGen.getNumRows()-1), j+1)){
          ++adjacentCells;
        }
        nextGen.changeLocation(i, j, newLocation(adjacentCells, i, j));
        continue;
      }
      else if(i==0 && j==(currentGen.getNumCols()-1)){//top right corner
        if(!currentGen.isEmpty(i+1, j)){
          ++adjacentCells;
        }
        if(!currentGen.isEmpty(i+1, j-1)){
          ++adjacentCells;
        }
        if(!currentGen.isEmpty(i, j-1)){
          ++adjacentCells;
        }
        if(!currentGen.isEmpty((currentGen.getNumRows()-1), j-1)){
          ++adjacentCells;
        }
        if(!currentGen.isEmpty((currentGen.getNumRows()-1), (currentGen.getNumCols()-1))){
          ++adjacentCells;
        }
        if(!currentGen.isEmpty((currentGen.getNumRows()-1), 0)){
          ++adjacentCells;
        }
        if(!currentGen.isEmpty(i+1, 0)){
          ++adjacentCells;
        }
        if(!currentGen.isEmpty(0,0)){
          ++adjacentCells;
        }
        nextGen.changeLocation(i, j, newLocation(adjacentCells, i, j));
        continue;
      }
      else if(i<(currentGen.getNumRows()-1) && j==0){//left edge
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
        if(!currentGen.isEmpty(i-1, (currentGen.getNumCols()-1))){
          ++adjacentCells;
        }
        if(!currentGen.isEmpty(i, (currentGen.getNumCols()-1))){
          ++adjacentCells;
        }
        if(!currentGen.isEmpty(i+1, (currentGen.getNumCols()-1))){
          ++adjacentCells;
        }
        nextGen.changeLocation(i, j, newLocation(adjacentCells, i, j));
        continue;
      }
      else if(i<(currentGen.getNumRows()-1) && j==(currentGen.getNumCols()-1)){//right edge
        if(!currentGen.isEmpty(i+1,j)){
          ++adjacentCells;
        }
        if(!currentGen.isEmpty(i-1,j)){
          ++adjacentCells;
        }
        if(!currentGen.isEmpty(i, j-1)){
          ++adjacentCells;
        }
        if(!currentGen.isEmpty(i+1, j-1)){
          ++adjacentCells;
        }
        if(!currentGen.isEmpty(i-1, j-1)){
          ++adjacentCells;
        }
        if(!currentGen.isEmpty(i-1, 0)){
          ++adjacentCells;
        }
        if(!currentGen.isEmpty(i, 0)){
          ++adjacentCells;
        }
        if(!currentGen.isEmpty(i+1, 0)){
          ++adjacentCells;
        }
        nextGen.changeLocation(i, j, newLocation(adjacentCells, i, j));
        continue;
      }
      else if(i==(currentGen.getNumRows()-1) && j==0){ //bottom left corner
        if(!currentGen.isEmpty(i-1, j)){
          ++adjacentCells;
        }
        if(!currentGen.isEmpty(i-1, j+1)){

          ++adjacentCells;
        }
        if(!currentGen.isEmpty(i, j+1)){
          ++adjacentCells;
        }
        if(!currentGen.isEmpty(i-1, (currentGen.getNumCols()-1))){
          ++adjacentCells;
        }
        if(!currentGen.isEmpty(i, (currentGen.getNumCols()-1))){
          ++adjacentCells;
        }
        if(!currentGen.isEmpty(0, (currentGen.getNumCols()-1))){
          ++adjacentCells;
        }
        if(!currentGen.isEmpty(0,0)){
          ++adjacentCells;
        }
        if(!currentGen.isEmpty(0, j+1)){
          ++adjacentCells;
        }
        nextGen.changeLocation(i, j, newLocation(adjacentCells, i, j));
        continue;
      }
      else if(i == (currentGen.getNumRows()-1) && j<(currentGen.getNumCols()-1)){//bottom edge
        if(!currentGen.isEmpty(i,j+1)){
          ++adjacentCells;
        }
        if(!currentGen.isEmpty(i-1,j+1)){
          ++adjacentCells;
        }
        if(!currentGen.isEmpty(i-1,j)){
          ++adjacentCells;
        }
        if(!currentGen.isEmpty(i-1, j-1)){
          ++adjacentCells;
        }
        if(!currentGen.isEmpty(i, j-1)){
          ++adjacentCells;
        }
        if(!currentGen.isEmpty(0, j-1)){
          ++adjacentCells;
        }
        if(!currentGen.isEmpty(0, j)){
          ++adjacentCells;
        }
        if(!currentGen.isEmpty(0, j+1)){
          ++adjacentCells;
        }
        nextGen.changeLocation(i, j, newLocation(adjacentCells, i, j));
        continue;
      }
      else if(i==(currentGen.getNumRows()-1) && j==(currentGen.getNumCols()-1)){//bottom right corner
        if(!currentGen.isEmpty(i-1, j)){
          ++adjacentCells;
        }
        if(!currentGen.isEmpty(i-1, j-1)){
          ++adjacentCells;
        }
        if(!currentGen.isEmpty(i, j-1)){
          ++adjacentCells;
        }
        if(!currentGen.isEmpty(0, j-1)){
          ++adjacentCells;
        }
        if(!currentGen.isEmpty(0, j)){
          ++adjacentCells;
        }
        if(!currentGen.isEmpty(0, 0)){
          ++adjacentCells;
        }
        if(!currentGen.isEmpty((currentGen.getNumRows()-1), 0)){
          ++adjacentCells;
        }
        if(!currentGen.isEmpty(i-1, 0)){
          ++adjacentCells;
        }
        nextGen.changeLocation(i, j, newLocation(adjacentCells, i, j));
        continue;
      }
      else if(i>0 && j>0 && i<(currentGen.getNumRows()-1) && j<(currentGen.getNumCols()-1)){ //eveything inbetween
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
        if(!currentGen.isEmpty(i-1, j)){
          ++adjacentCells;
        }
        if(!currentGen.isEmpty(i-1, j-1)){
          ++adjacentCells;
        }
        if(!currentGen.isEmpty(i-1, j+1)){
          ++adjacentCells;
        }
        nextGen.changeLocation(i, j, newLocation(adjacentCells, i, j));
        continue;
      }
    }
  }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Simulation::classicMode(){
  int adjacentCells;
  for(int i = 0;i < currentGen.getNumRows();++i){
    for(int j = 0;j < currentGen.getNumCols();++j){
      adjacentCells = 0; //tracks how many cells are adjacent to given location
      //if statements are in order of iteration, prioritizing corners and edges over the middle of the grid
      //each time a cell is detected in an adjacent location, adjacent cells is incremented by 1
      //at the end of each case, the value of adjacent cells determines what takes the cell location in the next generation
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
        nextGen.changeLocation(i, j, newLocation(adjacentCells, i, j)); //sets the appriate location of the grid according to how many adjacent cells there are
        continue;
      }
      else if(i==0 && j<(currentGen.getNumCols()-1)){//top edge
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
        nextGen.changeLocation(i, j, newLocation(adjacentCells, i, j));
        continue;
      }
      else if(i==0 && j==(currentGen.getNumCols()-1)){//top right corner
        if(!currentGen.isEmpty(i+1, j)){
          ++adjacentCells;
        }
        if(!currentGen.isEmpty(i+1, j-1)){
          ++adjacentCells;
        }
        if(!currentGen.isEmpty(i, j-1)){
          ++adjacentCells;
        }
        nextGen.changeLocation(i, j, newLocation(adjacentCells, i, j));
        continue;
      }
      else if(i<(currentGen.getNumRows()-1) && j==0){//left edge
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
        nextGen.changeLocation(i, j, newLocation(adjacentCells, i, j));
        continue;
      }
      else if(i<(currentGen.getNumRows()-1) && j==(currentGen.getNumCols()-1)){//right edge
        if(!currentGen.isEmpty(i+1,j)){
          ++adjacentCells;
        }
        if(!currentGen.isEmpty(i-1,j)){
          ++adjacentCells;
        }
        if(!currentGen.isEmpty(i, j-1)){
          ++adjacentCells;
        }
        if(!currentGen.isEmpty(i+1, j-1)){
          ++adjacentCells;
        }
        if(!currentGen.isEmpty(i-1, j-1)){
          ++adjacentCells;
        }
        nextGen.changeLocation(i, j, newLocation(adjacentCells, i, j));
        continue;
      }
      else if(i==(currentGen.getNumRows()-1) && j==0){ //bottom left corner
        if(!currentGen.isEmpty(i-1, j)){
          ++adjacentCells;
        }
        if(!currentGen.isEmpty(i-1, j+1)){
          ++adjacentCells;
        }
        if(!currentGen.isEmpty(i, j+1)){
          ++adjacentCells;
        }
        nextGen.changeLocation(i, j, newLocation(adjacentCells, i, j));
        continue;
      }
      else if(i == (currentGen.getNumRows()-1) && j<(currentGen.getNumCols()-1)){//bottom edge
        if(!currentGen.isEmpty(i,j+1)){
          ++adjacentCells;
        }
        if(!currentGen.isEmpty(i-1,j+1)){
          ++adjacentCells;
        }
        if(!currentGen.isEmpty(i-1,j)){
          ++adjacentCells;
        }
        if(!currentGen.isEmpty(i-1, j-1)){
          ++adjacentCells;
        }
        if(!currentGen.isEmpty(i, j-1)){
          ++adjacentCells;
        }
        nextGen.changeLocation(i, j, newLocation(adjacentCells, i, j));
        continue;
      }
      else if(i==(currentGen.getNumRows()-1) && j==(currentGen.getNumCols()-1)){//bottom right corner
        if(!currentGen.isEmpty(i-1, j)){
          ++adjacentCells;
        }
        if(!currentGen.isEmpty(i-1, j-1)){
          ++adjacentCells;
        }
        if(!currentGen.isEmpty(i, j-1)){
          ++adjacentCells;
        }
        nextGen.changeLocation(i, j, newLocation(adjacentCells, i, j));
        continue;
      }
      else if(i>0 && j>0 && i<(currentGen.getNumRows()-1) && j<(currentGen.getNumCols()-1)){ //eveything inbetween
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
        if(!currentGen.isEmpty(i-1, j)){
          ++adjacentCells;
        }
        if(!currentGen.isEmpty(i-1, j-1)){
          ++adjacentCells;
        }
        if(!currentGen.isEmpty(i-1, j+1)){
          ++adjacentCells;
        }
        nextGen.changeLocation(i, j, newLocation(adjacentCells, i, j));
        continue;
      }
    }
  }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Simulation::mirrorMode(){
  int adjacentCells;
  for(int i = 0;i < currentGen.getNumRows();++i){
    for(int j = 0;j < currentGen.getNumCols();++j){
      adjacentCells = 0; //tracks how many cells are adjacent to given location
      //if statements are in order of iteration, prioritizing corners and edges over the middle of the grid
      //each time a cell is detected in an adjacent location, adjacent cells is incremented by 1
      //at the end of each case, the value of adjacent cells determines what takes the cell location in the next generation
      if(i==0 && j==0){ //position [0][0]
        if(!currentGen.isEmpty(i+1,j)){
          adjacentCells = adjacentCells + 2;
        }
        if(!currentGen.isEmpty(i+1,j+1)){
          ++adjacentCells;
        }
        if(!currentGen.isEmpty(i, j+1)){
          adjacentCells = adjacentCells + 2;
        }
        if(!currentGen.isEmpty(i,j)){
          adjacentCells = adjacentCells + 3;
        }
        nextGen.changeLocation(i, j, newLocation(adjacentCells, i, j)); //sets the appriate location of the grid according to how many adjacent cells there are
        continue;
      }
      else if(i==0 && j<(currentGen.getNumCols()-1)){//top edge
        if(!currentGen.isEmpty(i+1,j)){
          ++adjacentCells;
        }
        if(!currentGen.isEmpty(i+1,j+1)){
          ++adjacentCells;
        }
        if(!currentGen.isEmpty(i,j+1)){
          adjacentCells = adjacentCells + 2;
        }
        if(!currentGen.isEmpty(i, j-1)){
          adjacentCells = adjacentCells + 2;
        }
        if(!currentGen.isEmpty(i+1, j-1)){
          ++adjacentCells;
        }
        if(!currentGen.isEmpty(i,j)){
          adjacentCells++;
        }
        nextGen.changeLocation(i, j, newLocation(adjacentCells, i, j));
        continue;
      }
      else if(i==0 && j==(currentGen.getNumCols()-1)){//top right corner
        if(!currentGen.isEmpty(i+1, j)){
          adjacentCells = adjacentCells + 2;
        }
        if(!currentGen.isEmpty(i+1, j-1)){
          ++adjacentCells;
        }
        if(!currentGen.isEmpty(i, j-1)){
          adjacentCells = adjacentCells + 2;
        }
        if(!currentGen.isEmpty(i,j)){
          adjacentCells = adjacentCells + 3;
        }
        nextGen.changeLocation(i, j, newLocation(adjacentCells, i, j));
        continue;
      }
      else if(i<(currentGen.getNumRows()-1) && j==0){//left edge
        if(!currentGen.isEmpty(i+1,j)){
          adjacentCells = adjacentCells + 2;
        }
        if(!currentGen.isEmpty(i+1,j+1)){
          ++adjacentCells;
        }
        if(!currentGen.isEmpty(i, j+1)){
          ++adjacentCells;
        }
        if(!currentGen.isEmpty(i-1, j)){
          adjacentCells = adjacentCells + 2;
        }
        if(!currentGen.isEmpty(i-1, j+1)){
          ++adjacentCells;
        }
        if(!currentGen.isEmpty(i,j)){
          ++adjacentCells;
        }
        nextGen.changeLocation(i, j, newLocation(adjacentCells, i, j));
        continue;
      }
      else if(i<(currentGen.getNumRows()-1) && j==(currentGen.getNumCols()-1)){//right edge
        if(!currentGen.isEmpty(i+1,j)){
          adjacentCells = adjacentCells + 2;
        }
        if(!currentGen.isEmpty(i-1,j)){
          adjacentCells = adjacentCells + 2;
        }
        if(!currentGen.isEmpty(i, j-1)){
          ++adjacentCells;
        }
        if(!currentGen.isEmpty(i+1, j-1)){
          ++adjacentCells;
        }
        if(!currentGen.isEmpty(i-1, j-1)){
          ++adjacentCells;
        }
        if(!currentGen.isEmpty(i,j)){
          ++adjacentCells;
        }
        nextGen.changeLocation(i, j, newLocation(adjacentCells, i, j));
        continue;
      }
      else if(i==(currentGen.getNumRows()-1) && j==0){ //bottom left corner
        if(!currentGen.isEmpty(i-1, j)){
          adjacentCells = adjacentCells + 2;
        }
        if(!currentGen.isEmpty(i-1, j+1)){
          ++adjacentCells;
        }
        if(!currentGen.isEmpty(i, j+1)){
          adjacentCells = adjacentCells + 2;
        }
        if(!currentGen.isEmpty(i,j)){
          adjacentCells = adjacentCells + 3;
        }
        nextGen.changeLocation(i, j, newLocation(adjacentCells, i, j));
        continue;
      }
      else if(i == (currentGen.getNumRows()-1) && j<(currentGen.getNumCols()-1)){//bottom edge
        if(!currentGen.isEmpty(i,j+1)){
          adjacentCells = adjacentCells + 2;
        }
        if(!currentGen.isEmpty(i-1,j+1)){
          ++adjacentCells;
        }
        if(!currentGen.isEmpty(i-1,j)){
          ++adjacentCells;
        }
        if(!currentGen.isEmpty(i-1, j-1)){
          ++adjacentCells;
        }
        if(!currentGen.isEmpty(i, j-1)){
          adjacentCells = adjacentCells + 2;
        }
        if(!currentGen.isEmpty(i,j)){
          ++adjacentCells;
        }
        nextGen.changeLocation(i, j, newLocation(adjacentCells, i, j));
        continue;
      }
      else if(i==(currentGen.getNumRows()-1) && j==(currentGen.getNumCols()-1)){//bottom right corner
        if(!currentGen.isEmpty(i-1, j)){
          adjacentCells = adjacentCells + 2;
        }
        if(!currentGen.isEmpty(i-1, j-1)){
          ++adjacentCells;
        }
        if(!currentGen.isEmpty(i, j-1)){
          adjacentCells = adjacentCells + 2;
        }
        if(!currentGen.isEmpty(i,j)){
          adjacentCells = adjacentCells + 3;
        }
        nextGen.changeLocation(i, j, newLocation(adjacentCells, i, j));
        continue;
      }
      else if(i>0 && j>0 && i<(currentGen.getNumRows()-1) && j<(currentGen.getNumCols()-1)){ //eveything inbetween
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
        if(!currentGen.isEmpty(i-1, j)){
          ++adjacentCells;
        }
        if(!currentGen.isEmpty(i-1, j-1)){
          ++adjacentCells;
        }
        if(!currentGen.isEmpty(i-1, j+1)){
          ++adjacentCells;
        }
        nextGen.changeLocation(i, j, newLocation(adjacentCells, i, j));
        continue;
      }
    }
  }
}

char Simulation::newLocation(int adjacentCells, int row, int col){ //returns a new location type('-' or 'X') based on number of adjacent cells
  if(adjacentCells<=1 || adjacentCells >=4){
    return '-';
  }
  else if(adjacentCells == 3){
    return 'X';
  }
  else if(adjacentCells == 2){
    return currentGen.getMyGrid()[row][col]; //sets to previous location
  }
  else{
    return '-';
  }
}
