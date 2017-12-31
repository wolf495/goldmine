#include "Box.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
#ifndef BOXCPP
#define BOXCPP
//---
Box::Box(){
        srand (time(NULL));
        character='-';
        goldLost=rand() % 100 + 10;
        selected=false;
}
//---
const bool Box::getVisited(){return selected;}
void Box::setVisited(bool visit){selected=visit;}
int Box::getGoldLost(){return goldLost;}
void Box::setGoldLost(int amount){goldLost=amount;}
const char Box::getCharacter(){return character;}
void Box::setCharacter(char special){character=special;}



#endif
