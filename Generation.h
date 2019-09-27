#include <iostream> //preprocessor directive

using namespace std;

class Generation{
  public:
    char** myGrid;
    Generation();
    Generation(int row, int col);
    ~Generation();
    void printGen(); //prints the generation in whatever

};
