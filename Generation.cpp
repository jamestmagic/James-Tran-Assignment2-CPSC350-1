#define _USE_MATH_DEFINES
#include "Generation.h"
#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
#include <cmath>
#include <time.h>

using namespace std;

char** myGrid; //pointer 2d array
int numRows = 0;
int numCols = 0;
Generation::Generation()//constructor
{
  myGrid = new char*[0];
  myGrid[0] = new char[0];
  numRows = 0;
  numCols = 0;
}
Generation::Generation(int row, int col){//overloaded constructor
  myGrid = new char*[row];
  numRows = row;
  numCols = col;
  for(int i = 0;i < numRows;++i){
    myGrid[i] = new char[numCols];
  }
}
Generation::~Generation()//destructor
{
}

bool Generation::isEmpty(int row, int col){ //returns true if given location is empty, false if occupied
  char a = myGrid[row][col];
  if(a == '-'){
    return true;
  }
  return false;
}

bool Generation::emptyGen(){ //returns true if the whole grid is empty, false if occupied
  for(int i = 0;i < numRows;++i){
    for(int j = 0;j < numCols;++j){
      if(myGrid[i][j] == 'X'){
        return false;
      }
    }
  }
  return true;
}

void Generation::setDimensions(int row, int col){ //sets dimensions for grid
  myGrid = new char*[row];
  for(int i = 0;i < row;++i){
    myGrid[i] = new char[col];
  }
  numRows = row;
  numCols = col;
}

void Generation::randomGrid(){ //creates random dimensions and density, places cells into grid randomly
  srand(time(NULL));
  int randomRows = (rand() % 5) + 5;
  int randomCol = (rand() % 5) + 5;
  numCols = randomCol;
  numRows = randomRows;
  double density = ((double)rand()/RAND_MAX)/2;
  int totalCells = (density*(randomRows*randomCol)) + 1; //calculates how many cells are in the conifguration based on density
  myGrid = new char*[numRows]; //sets new dimensions
  for(int i = 0;i < numRows;++i){
    myGrid[i] = new char[numCols];
  }
  while(totalCells > 0){
    for(int i = 0;i < numRows;++i){
      for(int j = 0;j < numCols;++j){
        int random = (rand() % 10) + 1; //random variable for giving a grid space a cell
        if(random <= 5 && totalCells > 0){ //50% chance it will be placed in the given spot
          myGrid[i][j] = 'X';
          --totalCells;;
        }
        else if(myGrid[i][j] != 'X'){
          myGrid[i][j] = '-';
        }
      }
    }
  }
}

void Generation::printGen(){ //prints grid into console
  for(int i = 0;i < numRows;++i){
    for(int j = 0;j < numCols;++j){
      cout << myGrid[i][j];
    }
    cout << endl;
  }
}

void Generation::copyGen(Generation g1){ //copies one grid to another
  for(int i = 0;i<g1.getNumRows();++i){
    for(int j = 0;j<g1.getNumCols();++j){
      myGrid[i][j] = g1.getMyGrid()[i][j];
    }
  }
}

int Generation::getNumRows(){ //access the row count
  return numRows;
}
int Generation::getNumCols(){ //access the column count
  return numCols;
}

char** Generation::getMyGrid(){ //access the 2d array
  return myGrid;
}

void Generation::changeLocation(int row, int col, char c){ //changes the location on grid to given char
  myGrid[row][col] = c;
}

void Generation::setMapFile(string fileName){ //translates info from map file and creates the grid
  try{
    ifstream readFile(fileName);
    string tempString;
    int lineNum = 0;
    int row;
    int col;
    int rowWrite = 0;
    //Generation mapGen;
    while(getline(readFile, tempString)){
      if(lineNum == 0){
        row = stoi(tempString);
      }
      else if(lineNum == 1){
        col = stoi(tempString);
        setDimensions(row, col);
      }
      else{
        for(int j = 0;j<numCols;++j){
          //cout << "changing location" << endl;
          myGrid[rowWrite][j] = tempString[j];
        }
        ++rowWrite;
      }
      ++lineNum;
    }
  }
  catch(ifstream::failure e){ //throws expection in case of ioexception
    cout << "Exception: Could not read or open file" << endl;
  }
}

bool Generation::compareGen(Generation last){ //returns true if the two generation are the same, false if not
  for(int i = 0;i<last.getNumRows();++i){
    for(int j = 0;j<last.getNumCols();++j){
      if(myGrid[i][j] != last.getMyGrid()[i][j]){
        return false;
      }
    }
  }
  return true;
}
