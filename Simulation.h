#include <iostream> //preprocessor directive
#include "Generation.h"
using namespace std;

class Simulation{
  public:
    int generationNum;
    Generation currentGen;
    Generation nextGen;
    bool stopSim;
    Simulation();
    Simulation(Generation g);
    ~Simulation();
    void play(int modeChoice, int intermissionChoice);
    void classicMode();
    void doughnutMode();
    void mirrorMode();
    char newLocation(int adjacentCells, int row, int col);
    void copyGen();
};
