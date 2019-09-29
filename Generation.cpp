#define _USE_MATH_DEFINES
#include "Generation.h"
#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
#include <cmath>
#include <time.h>

using namespace std;

char** myGrid;
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
  cout << "object deleted" << endl;
}

bool isEmpty(int row, int col){
  if(myGrid[row][col] == '-'){
    return true;
  }
  return false;
}

void Generation::randomGrid(){
  srand(time(NULL));
  int randomRows = (rand() % 5) + 5;
  int randomCol = (rand() % 5) + 5;
  cout << "randomRows = " << randomRows << endl;
  cout << "randomCol = " << randomCol << endl;
  numCols = randomCol;
  numRows = randomRows;
  double density = ((double)rand()/RAND_MAX)/2;
  cout << "density = " << density << endl;
  int totalCells = (density*(randomRows*randomCol)); //calculates how many cells are in the conifguration based on density
  cout << "totalCells = " << totalCells << endl;
  myGrid = new char*[numRows];
  for(int i = 0;i < numRows;++i){
    myGrid[i] = new char[numCols];
  }
  while(totalCells > 0){
    for(int i = 0;i < numRows;++i){
      for(int j = 0;j < numCols;++j){
        int random = (rand() % 10) + 1; //random variable for giving a grid space a cell
        if(random <= 5 && totalCells > 0){
          myGrid[i][j] = 'X';
          --totalCells;;
        }
        else if(myGrid[i][j] != 'X'){
          myGrid[i][j] = '-';
        }
      }
    }
  }
  cout << "end random" << endl;
}

void Generation::printGen(){
  cout << "pinting" << endl;
  for(int i = 0;i < numRows;++i){
    for(int j = 0;j < numCols;++j){
      cout << myGrid[i][j];
    }
    cout << endl;
  }
}

int Generation::getNumRows(){
  return numRows;
}
int Generation::getNumCols(){
  return numCols;
}

char** Generation::getMyGrid(){
  return myGrid;
}
