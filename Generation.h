#include <iostream> //preprocessor directive
#include <fstream>

using namespace std;

class Generation{
  public:
    char** myGrid;
    int numCols;
    int numRows;
    Generation();
    Generation(int row, int col);
    ~Generation();
    void randomGrid();
    bool isEmpty(int row, int col);
    void printGen(); //prints the generation grid
    int getNumCols(); //accessor for columns
    int getNumRows(); //accessor for rows
    char** getMyGrid(); //accessor for the grid
    void changeLocation(int row, int col, char c);
    void setDimensions(int row, int col);
    bool emptyGen();
    void copyGen(Generation g1);
    void setMapFile(string fileName);
    bool compareGen(Generation last);
};
