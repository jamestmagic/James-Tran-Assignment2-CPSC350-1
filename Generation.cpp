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
Generation::Generation()//constructor
{
  myGrid = new char*[0];
  myGrid[0] = new char[0];
}
Generation::Generation(int row, int col){//overloaded constructor
  myGrid = new char*[row];
  for(int i = 0;i < row;++i){
    myGrid[i] = new char[col];
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
