#include <iostream> //preprocessor directive

using namespace std;

class Intro{
  public:
    Intro(); //constructor
    ~Intro(); //destructor
    int configChoice;
    int modeChoice;
    int intermissionChoice;
    void askConfig();
    void askMode();
    void askIntermission();
    int getConfigChoice();
    int getmodeChoice();
    int getIntermissionChoice();
};
