#define _USE_MATH_DEFINES
#include "Intro.h"
#include "Simulation.h"
#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
#include <cmath>
#include <time.h>

using namespace std;

int main(int argc, char** argv){

  Generation g; //initial generation
  Intro intro;
  string mapFileName;
  intro.askConfig();
  intro.askMode();
  intro.askIntermission();
  if(intro.getConfigChoice() == 1){ //creates a random grid configuration prompted by user
    g.randomGrid();
  }
  else if(intro.getConfigChoice() == 2){ //asks the user for filename and creates grid
    cout << "Please enter the name of the file" << endl;
    cin >> mapFileName;
    g.setMapFile(mapFileName);
  }
  Simulation *s = new Simulation(g);
  s->play(intro.getModeChoice(), intro.getIntermissionChoice()); //all operations
}
