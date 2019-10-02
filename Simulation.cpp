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
bool stopSim;
Simulation::Simulation(){
  generationNum = 0;
  stopSim = false;
}

Simulation::Simulation(Generation g){
  generationNum = 0;
  currentGen = g;
  nextGen = Generation(g.getNumRows(), g.getNumCols());
  stopSim = false;
}

Simulation::~Simulation(){

}

void Simulation::play(int modeChoice, int intermissionChoice){
  cout << intermissionChoice << endl;
  while(!currentGen.emptyGen() && (nextGen.compareGen(currentGen) == false)){ //only runs when generations are different or not empty
    if(modeChoice == 1){
      classicMode();
      cout << "classic end" << endl;
    }
    else if(modeChoice == 2){
      doughnutMode();
      cout << "doughnut end" << endl;
    }
    else if(modeChoice == 3){
      mirrorMode();
    }
    // currentGen = g;
    // nextGen = Generation(g.getNumRows(), g.getNumCols());
    // currentGen.printGen();
    cout << "printing new gen" << endl;
    nextGen.printGen();
    // cout << "copying" << endl;
    currentGen.copyGen(nextGen);
    cout << "copied" << endl;
    nextGen = Generation(currentGen.getNumRows(), currentGen.getNumCols());
    if(intermissionChoice == 1 && (nextGen.compareGen(currentGen) == false)){
      system("pause");
    }
    else if(intermissionChoice == 2 && (nextGen.compareGen(currentGen) == false)){
      cout << "Press Enter to Continue to next Generation" << endl;
      cin.ignore();
      cin.ignore();
    }
    else if(intermissionChoice == 3){

    }
  }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Simulation::doughnutMode(){
  int adjacentCells;
  cout << "doughnut" << endl;
  for(int i = 0;i < currentGen.getNumRows();++i){
    cout << "iterating through rows" << endl;
    cout << "Row = " << i << endl;
    for(int j = 0;j < currentGen.getNumCols();++j){
      cout << "iterating through cols" << endl;
      cout << "Col = " << j << endl;
      cout << "Row = " << i << endl;
      adjacentCells = 0; //tracks how many cells are adjacent to given location


      //if statements are in order of iteration, prioritizing corners and edges over the middle of the grid
      //each time a cell is detected in an adjacent location, adjacent cells is incremented by 1
      //at the end of each case, the value of adjacent cells determines what takes the cell location in the next generation
      if(i==0 && j==0){ //position [0][0]
        cout << " i, j = " << i << "," << j << endl;
        cout << "Row1 = " << i << endl;
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
        cout << "changing location" << endl;
        cout << "Row2 = " << i << endl;
        cout << "Adjacent Cells = " << adjacentCells << endl;
        nextGen.changeLocation(i, j, newLocation(adjacentCells, i, j));
        continue;
      }
      else if(i==0 && j<(currentGen.getNumCols()-1)){//top edge
        cout << " i, j = " << i << "," << j << endl;
        if(!currentGen.isEmpty(i+1,j)){
          ++adjacentCells;
        }
        cout << "Row1 = " << i << endl;
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
        cout << "Row2 = " << i << endl;
        cout << "Adjacent Cells = " << adjacentCells << endl;
        nextGen.changeLocation(i, j, newLocation(adjacentCells, i, j));
        cout << "changed new gen grid" << endl;
        continue;
      }
      else if(i==0 && j==(currentGen.getNumCols()-1)){//top right corner
        cout << " i, j = " << i << "," << j << endl;
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
        cout << "Adjacent Cells = " << adjacentCells << endl;
        nextGen.changeLocation(i, j, newLocation(adjacentCells, i, j));
        continue;
      }
      else if(i<(currentGen.getNumRows()-1) && j==0){//left edge
        cout << " i, j = " << i << "," << j << endl;
        cout << "Row1 = " << i << endl;
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
        cout << "Row2 = " << i << endl;
        cout << "Adjacent Cells = " << adjacentCells << endl;
        nextGen.changeLocation(i, j, newLocation(adjacentCells, i, j));
        cout << "Row3 = " << i << endl;
        cout << "changed new gen grid" << endl;
        continue;
      }
      else if(i<(currentGen.getNumRows()-1) && j==(currentGen.getNumCols()-1)){//right edge
        cout << " i, j = " << i << "," << j << endl;
        cout << "Row1 = " << i << endl;
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
        cout << "Row2 = " << i << endl;
        cout << "Adjacent Cells = " << adjacentCells << endl;
        nextGen.changeLocation(i, j, newLocation(adjacentCells, i, j));
        cout << "changed new gen grid" << endl;
        continue;
      }
      else if(i==(currentGen.getNumRows()-1) && j==0){ //bottom left corner
        cout << " i, j = " << i << "," << j << endl;
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
        cout << "Adjacent Cells = " << adjacentCells << endl;
        nextGen.changeLocation(i, j, newLocation(adjacentCells, i, j));
        continue;
      }
      else if(i == (currentGen.getNumRows()-1) && j<(currentGen.getNumCols()-1)){//bottom edge
        cout << " i, j = " << i << "," << j << endl;
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
        cout << "Adjacent Cells = " << adjacentCells << endl;
        nextGen.changeLocation(i, j, newLocation(adjacentCells, i, j));
        cout << "changed new gen grid" << endl;
        continue;
      }
      else if(i==(currentGen.getNumRows()-1) && j==(currentGen.getNumCols()-1)){//bottom right corner
        cout << " i, j = " << i << "," << j << endl;
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
        cout << "Adjacent Cells = " << adjacentCells << endl;
        nextGen.changeLocation(i, j, newLocation(adjacentCells, i, j));
        continue;
      }
      else if(i>0 && j>0 && i<(currentGen.getNumRows()-1) && j<(currentGen.getNumCols()-1)){ //eveything inbetween
        cout << " i, j = " << i << "," << j << endl;
        cout << ">>Row1 = " << i << endl;
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
        cout << ">>Row2 = " << i << endl;
        cout << "Adjacent Cells = " << adjacentCells << endl;
        nextGen.changeLocation(i, j, newLocation(adjacentCells, i, j));
        cout << "changed new gen grid" << endl;
        continue;
      }
      cout << "End column iteration" << endl;
      cout << "Col = " << j << endl;
    }
    cout << "End row iteration" << endl;
    cout << "Row = " << i << endl;
  }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Simulation::classicMode(){
  int adjacentCells;
  cout << "classic" << endl;
  for(int i = 0;i < currentGen.getNumRows();++i){
    cout << "iterating through rows" << endl;
    cout << "Row = " << i << endl;
    for(int j = 0;j < currentGen.getNumCols();++j){
      cout << "iterating through cols" << endl;
      cout << "Col = " << j << endl;
      cout << "Row = " << i << endl;
      adjacentCells = 0; //tracks how many cells are adjacent to given location
      if(i==0 && j==0){ //position [0][0]
        cout << " i, j = " << i << "," << j << endl;
        cout << "Row1 = " << i << endl;
        if(!currentGen.isEmpty(i+1,j)){
          cout << "isEmpty"<< endl;
          ++adjacentCells;
        }
        if(!currentGen.isEmpty(i+1,j+1)){
          cout << "isEmpty"<< endl;
          ++adjacentCells;
        }
        if(!currentGen.isEmpty(i, j+1)){
          cout << "isEmpty"<< endl;
          ++adjacentCells;
        }
        cout << "changing location" << endl;
        cout << "Row2 = " << i << endl;
        cout << "Adjacent Cells = " << adjacentCells << endl;
        //nextGen.changeLocation(i, j, newLocation(adjacentCells, i, j));
        nextGen.changeLocation(i, j, newLocation(adjacentCells, i, j));
        continue;
        //cout << "changed new gen grid" << endl;
      }
      else if(i==0 && j<(currentGen.getNumCols()-1)){//top edge
        cout << " i, j = " << i << "," << j << endl;
        if(!currentGen.isEmpty(i+1,j)){
          ++adjacentCells;
        }
        cout << "Row1 = " << i << endl;
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
        cout << "Row2 = " << i << endl;
        cout << "Adjacent Cells = " << adjacentCells << endl;
        nextGen.changeLocation(i, j, newLocation(adjacentCells, i, j));
        cout << "changed new gen grid" << endl;
        continue;
      }
      else if(i==0 && j==(currentGen.getNumCols()-1)){//top right corner
        cout << " i, j = " << i << "," << j << endl;
        if(!currentGen.isEmpty(i+1, j)){
          ++adjacentCells;
        }
        if(!currentGen.isEmpty(i+1, j-1)){
          ++adjacentCells;
        }
        if(!currentGen.isEmpty(i, j-1)){
          ++adjacentCells;
        }
        cout << "Adjacent Cells = " << adjacentCells << endl;
        nextGen.changeLocation(i, j, newLocation(adjacentCells, i, j));
        continue;
      }
      else if(i<(currentGen.getNumRows()-1) && j==0){//left edge
        cout << " i, j = " << i << "," << j << endl;
        cout << "Row1 = " << i << endl;
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
        cout << "Row2 = " << i << endl;
        cout << "Adjacent Cells = " << adjacentCells << endl;
        nextGen.changeLocation(i, j, newLocation(adjacentCells, i, j));
        cout << "Row3 = " << i << endl;
        cout << "changed new gen grid" << endl;
        continue;
      }
      else if(i<(currentGen.getNumRows()-1) && j==(currentGen.getNumCols()-1)){//right edge
        cout << " i, j = " << i << "," << j << endl;
        cout << "Row1 = " << i << endl;
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
        cout << "Row2 = " << i << endl;
        cout << "Adjacent Cells = " << adjacentCells << endl;
        nextGen.changeLocation(i, j, newLocation(adjacentCells, i, j));
        cout << "changed new gen grid" << endl;
        continue;
      }
      else if(i==(currentGen.getNumRows()-1) && j==0){ //bottom left corner
        cout << " i, j = " << i << "," << j << endl;
        if(!currentGen.isEmpty(i-1, j)){

          ++adjacentCells;
        }
        if(!currentGen.isEmpty(i-1, j+1)){

          ++adjacentCells;
        }
        if(!currentGen.isEmpty(i, j+1)){
          ++adjacentCells;
        }
        cout << "Adjacent Cells = " << adjacentCells << endl;
        nextGen.changeLocation(i, j, newLocation(adjacentCells, i, j));
        continue;
      }
      else if(i == (currentGen.getNumRows()-1) && j<(currentGen.getNumCols()-1)){//bottom edge
        cout << " i, j = " << i << "," << j << endl;
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
        cout << "Adjacent Cells = " << adjacentCells << endl;
        nextGen.changeLocation(i, j, newLocation(adjacentCells, i, j));
        cout << "changed new gen grid" << endl;
        continue;
      }
      else if(i==(currentGen.getNumRows()-1) && j==(currentGen.getNumCols()-1)){//bottom right corner
        cout << " i, j = " << i << "," << j << endl;
        if(!currentGen.isEmpty(i-1, j)){

          ++adjacentCells;
        }
        if(!currentGen.isEmpty(i-1, j-1)){

          ++adjacentCells;
        }
        if(!currentGen.isEmpty(i, j-1)){
          ++adjacentCells;
        }
        cout << "Adjacent Cells = " << adjacentCells << endl;
        nextGen.changeLocation(i, j, newLocation(adjacentCells, i, j));
        continue;
      }
      else if(i>0 && j>0 && i<(currentGen.getNumRows()-1) && j<(currentGen.getNumCols()-1)){ //eveything inbetween
        cout << " i, j = " << i << "," << j << endl;
        cout << ">>Row1 = " << i << endl;
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
        cout << ">>Row2 = " << i << endl;
        cout << "Adjacent Cells = " << adjacentCells << endl;
        nextGen.changeLocation(i, j, newLocation(adjacentCells, i, j));
        cout << "changed new gen grid" << endl;
        continue;
      }
      cout << "End column iteration" << endl;
      cout << "Col = " << j << endl;
    }
    cout << "End row iteration" << endl;
    cout << "Row = " << i << endl;
  }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Simulation::mirrorMode(){
  int adjacentCells;
  cout << "doughnut" << endl;
  for(int i = 0;i < currentGen.getNumRows();++i){
    cout << "iterating through rows" << endl;
    cout << "Row = " << i << endl;
    for(int j = 0;j < currentGen.getNumCols();++j){
      cout << "iterating through cols" << endl;
      cout << "Col = " << j << endl;
      cout << "Row = " << i << endl;
      adjacentCells = 0; //tracks how many cells are adjacent to given location


      //if statements are in order of iteration, prioritizing corners and edges over the middle of the grid
      //each time a cell is detected in an adjacent location, adjacent cells is incremented by 1
      //at the end of each case, the value of adjacent cells determines what takes the cell location in the next generation
      if(i==0 && j==0){ //position [0][0]
        cout << " i, j = " << i << "," << j << endl;
        cout << "Row1 = " << i << endl;
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
        cout << "changing location" << endl;
        cout << "Row2 = " << i << endl;
        cout << "Adjacent Cells = " << adjacentCells << endl;
        nextGen.changeLocation(i, j, newLocation(adjacentCells, i, j));
        continue;
      }
      else if(i==0 && j<(currentGen.getNumCols()-1)){//top edge
        cout << " i, j = " << i << "," << j << endl;
        if(!currentGen.isEmpty(i+1,j)){
          ++adjacentCells;
        }
        cout << "Row1 = " << i << endl;
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
        cout << "Row2 = " << i << endl;
        cout << "Adjacent Cells = " << adjacentCells << endl;
        nextGen.changeLocation(i, j, newLocation(adjacentCells, i, j));
        cout << "changed new gen grid" << endl;
        continue;
      }
      else if(i==0 && j==(currentGen.getNumCols()-1)){//top right corner
        cout << " i, j = " << i << "," << j << endl;
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
        cout << "Adjacent Cells = " << adjacentCells << endl;
        nextGen.changeLocation(i, j, newLocation(adjacentCells, i, j));
        continue;
      }
      else if(i<(currentGen.getNumRows()-1) && j==0){//left edge
        cout << " i, j = " << i << "," << j << endl;
        cout << "Row1 = " << i << endl;
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
        cout << "Row2 = " << i << endl;
        cout << "Adjacent Cells = " << adjacentCells << endl;
        nextGen.changeLocation(i, j, newLocation(adjacentCells, i, j));
        cout << "Row3 = " << i << endl;
        cout << "changed new gen grid" << endl;
        continue;
      }
      else if(i<(currentGen.getNumRows()-1) && j==(currentGen.getNumCols()-1)){//right edge
        cout << " i, j = " << i << "," << j << endl;
        cout << "Row1 = " << i << endl;
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
        cout << "Row2 = " << i << endl;
        cout << "Adjacent Cells = " << adjacentCells << endl;
        nextGen.changeLocation(i, j, newLocation(adjacentCells, i, j));
        cout << "changed new gen grid" << endl;
        continue;
      }
      else if(i==(currentGen.getNumRows()-1) && j==0){ //bottom left corner
        cout << " i, j = " << i << "," << j << endl;
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
        cout << "Adjacent Cells = " << adjacentCells << endl;
        nextGen.changeLocation(i, j, newLocation(adjacentCells, i, j));
        continue;
      }
      else if(i == (currentGen.getNumRows()-1) && j<(currentGen.getNumCols()-1)){//bottom edge
        cout << " i, j = " << i << "," << j << endl;
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
        cout << "Adjacent Cells = " << adjacentCells << endl;
        nextGen.changeLocation(i, j, newLocation(adjacentCells, i, j));
        cout << "changed new gen grid" << endl;
        continue;
      }
      else if(i==(currentGen.getNumRows()-1) && j==(currentGen.getNumCols()-1)){//bottom right corner
        cout << " i, j = " << i << "," << j << endl;
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
        cout << "Adjacent Cells = " << adjacentCells << endl;
        nextGen.changeLocation(i, j, newLocation(adjacentCells, i, j));
        continue;
      }
      else if(i>0 && j>0 && i<(currentGen.getNumRows()-1) && j<(currentGen.getNumCols()-1)){ //eveything inbetween
        cout << " i, j = " << i << "," << j << endl;
        cout << ">>Row1 = " << i << endl;
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
        cout << ">>Row2 = " << i << endl;
        cout << "Adjacent Cells = " << adjacentCells << endl;
        nextGen.changeLocation(i, j, newLocation(adjacentCells, i, j));
        cout << "changed new gen grid" << endl;
        continue;
      }
      cout << "End column iteration" << endl;
      cout << "Col = " << j << endl;
    }
    cout << "End row iteration" << endl;
    cout << "Row = " << i << endl;
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
    cout << "newLocation row" << endl;
    return currentGen.getMyGrid()[row][col];
  }
  else{
    return '-';
  }
}
