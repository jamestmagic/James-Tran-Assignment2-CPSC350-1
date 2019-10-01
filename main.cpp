#define _USE_MATH_DEFINES
#include "Intro.h"
//#include "Generation.h"
#include "Simulation.h"
#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
#include <cmath>
#include <time.h>

using namespace std;

int main(int argc, char** argv){


  // Intro intro;
  // intro.askConfig();
  // intro.askMode();
  // intro.askIntermission();
  // if(intro.getConfigChoice() == 2){
  //
  // }
  Generation g;
  g.randomGrid();
  g.printGen();
  Simulation *s = new Simulation(g);
  s->play(1, 2);
}
