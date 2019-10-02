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
  //setDimensions(5,3);
}
Generation::~Generation()//destructor
{
  cout << "Generation deleted" << endl;
}

bool Generation::isEmpty(int row, int col){
  char a = myGrid[row][col];
  if(a == '-'){
    return true;
  }
  return false;
}

bool Generation::emptyGen(){
  for(int i = 0;i < numRows;++i){
    for(int j = 0;j < numCols;++j){
      if(myGrid[i][j] == 'X'){
        return false;
      }
    }
  }
  return true;
}

void Generation::setDimensions(int row, int col){
  myGrid = new char*[row];
  for(int i = 0;i < row;++i){
    myGrid[i] = new char[col];
  }
  numRows = row;
  numCols = col;
}

void Generation::randomGrid(){
  srand(time(NULL));
  int randomRows = (rand() % 5) + 5;
  int randomCol = (rand() % 5) + 5;
  //cout << "randomRows = " << randomRows << endl;
  //cout << "randomCol = " << randomCol << endl;
  numCols = randomCol;
  numRows = randomRows;
  double density = ((double)rand()/RAND_MAX)/2;
  //cout << "density = " << density << endl;
  int totalCells = (density*(randomRows*randomCol)); //calculates how many cells are in the conifguration based on density
  //cout << "totalCells = " << totalCells << endl;
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
  //cout << "end random" << endl;
}

void Generation::printGen(){
  cout << "printing" << endl;
  for(int i = 0;i < numRows;++i){
    for(int j = 0;j < numCols;++j){
      cout << myGrid[i][j];
    }
    cout << endl;
  }
  cout << "hello" << endl;
}

void Generation::copyGen(Generation g1){
  for(int i = 0;i<g1.getNumRows();++i){
    for(int j = 0;j<g1.getNumCols();++j){
      myGrid[i][j] = g1.getMyGrid()[i][j];
    }
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

void Generation::changeLocation(int row, int col, char c){
  cout << "changeLocation" << endl;
  myGrid[row][col] = c;
}

void Generation::setMapFile(string fileName){
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
        cout << "setDimensions" << endl;
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
  catch(ifstream::failure e){
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
