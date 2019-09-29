#include <iostream> //preprocessor directive
#include "Generation.h"
using namespace std;

class Simulation{
  public:
    Simulation();
    Simulation(Generation g);
    ~Simulation();
    void play(int modeChoice, int intermissionChoice);
    void classicMode();
    void doughnutMode();
    void mirrorMode();
};
