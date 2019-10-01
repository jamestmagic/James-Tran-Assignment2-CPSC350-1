#define _USE_MATH_DEFINES
#include "Intro.h"
#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
#include <cmath>
#include <time.h>

using namespace std;


Intro::Intro()//constructor
{

}
Intro::~Intro()//destructor
{
  cout << "object deleted" << endl;
}

int configChoice = 0;
int modeChoice = 0;
int intermissionChoice = 0;
int finalChoice = 0; //18 possible permutations for the choices of config,mode, and intermission


void Intro::askConfig(){ //asks the user for configuration
  while(configChoice != 1 && configChoice != 2){
    cout << "What kind of configuration would you like to use?" <<endl;
    cout << "1. Random" << endl;
    cout << "2. Specified Flat" << endl;
    cin >> configChoice;
    if(configChoice != 1 && configChoice != 2){
      cout << "Please enter a valid configuration choice." << endl;
    }
  }
}

void Intro::askMode(){
  while(modeChoice != 1 && modeChoice != 2 && modeChoice != 3){
    cout << "In which boundary mode would you like to run?(Enter # of choice)" << endl;
    cout << "1. Classic" << endl;
    cout << "2. Doughnut" << endl;
    cout << "3. Mirror" << endl;
    cin >> modeChoice;
    if(modeChoice != 1 && modeChoice != 2 && modeChoice != 3){
      cout << "Please enter a valid mode choice." << endl;
    }
  }
}

void Intro::askIntermission(){
  while(intermissionChoice != 1 && intermissionChoice != 2 && intermissionChoice != 3){
    cout << "What kind of intermission would you like between each generation?(Enter # of choice)" << endl;
    cout << "1. Brief Pause" << endl;
    cout << "2. Press Enter" << endl;
    cout << "3. Output generations to a file" << endl;
    cin >> intermissionChoice;
    if(intermissionChoice != 1 && intermissionChoice != 2 && intermissionChoice != 3){
      cout << "Please enter a valid intermission choice." << endl;
    }
  }
}

int Intro::getConfigChoice(){
  return configChoice;
}

int Intro::getmodeChoice(){
  return modeChoice;
}

int Intro::getIntermissionChoice(){
  return intermissionChoice;
}
