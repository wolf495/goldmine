#include <iostream>
using namespace std;
#include <string>
#ifndef BOXH
#define BOXH

class Box{
        public:
                Box();
                const bool getVisited();
                void setVisited(bool);
                void setGoldLost(int);
                int getGoldLost();
                const char getCharacter();
                void setCharacter(char);
        private:
                char character;
                int goldLost;
                bool selected;
};
#endif
