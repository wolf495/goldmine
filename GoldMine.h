#include <iostream>
using namespace std;
#include "Box.h"
#include <string>
#ifndef GOLDMINEH
#define GOLDMINEH

class GoldMine{
        public:
                GoldMine();
                void randomRowColumn(int &row,int &column);
                void setMyBox(char);
                void setRainbow();
                void setGold();//sets box location to 'G'/also calls randomRowColumn, which spreads out gold,coal,rainbow locations randomly
                void setCoal();
                void getRainbowLoc();//prints location of rainbow
                void getGoldLoc();//prints location of gold
                void getCoalLoc();//prints location of coal
                string rainbowMessage();
                void revealSelection(int, int);
                void printGoldMine();
                int getGold(){return gold;};
                void cheat();// prints information for grading
                void randomBoxes();//box Gold values are randomly set
                bool didItEnd();//checks if gold or coal was found
        private:
                Box gm[6][6];
                int gold;
                int locrow;
                int loccol;
                int rowg;
                int colg;
                int rowr;
                int colr;
                int rowc;
                int colc;
};
#endif
