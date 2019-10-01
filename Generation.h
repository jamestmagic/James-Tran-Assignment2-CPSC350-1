#include <iostream> //preprocessor directive

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
    int getNumCols();
    int getNumRows();
    char** getMyGrid();
    void changeLocation(int row, int col, char c);
    void setDimensions(int row, int col);
    bool emptyGen();
};
