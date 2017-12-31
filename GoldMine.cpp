#include "GoldMine.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
#ifndef GOLDMINECPP
#define GOLDMINECPP

//---
GoldMine::GoldMine(){
        srand(time(NULL));
        gold=rand()%401+500;
}
//---

void GoldMine::randomRowColumn(int &row,int &column){
        srand(time(NULL));
        rowr=rand()%6+0;
        colr=rand()%6+0;
        rowc=rand()%6+0;
        colc=rand()%6+0;
        if(rowr==rowc&&colr==colc){rowc=rand()%6+0;colc=rand()%6+0;}
        row=rand()%6+0;
        column=rand()%6+0;
        if((row==rowc&&column==colc)||(row==rowr&&column==colr)){row=rand()%6+0;column=rand()%6+0;}
}

void GoldMine::setMyBox(char c){gm[locrow][loccol].setCharacter(c);}

void GoldMine::setRainbow(){
        gm[rowr][colr].setCharacter('R');
}

void GoldMine::setGold(){
        randomRowColumn(rowg,colg);
        gm[rowg][colg].setCharacter('G');
}

void GoldMine::setCoal(){
        gm[rowc][colc].setCharacter('C');
}

string GoldMine::rainbowMessage(){
        string message="Wow, you saw Dr.Polack stash your money. It is in a black cauldron under a raindbow in the following region: ";
        string region="unknown";
        if(rowg>=3){
                region="Lower-";
                if(colg>=3){region=region+"Right";}
                else{region=region+"Left";}}
        else{
                region="Upper-";
                if(colg>=3){region=region+"Right";}
                else{region=region+"Left";}}
        return message+region+" ...I guess she\'s like a leprauchan or something.";
}

void GoldMine::revealSelection(int row, int column){
        bool visit=true;
        
        if(gm[row][column].getVisited()){cout<<"You already looked here dude. You must still be traumatized from last turn. [NO CHANGE]"<<endl;}
        else{
        gm[row][column].setVisited(visit);
        if(gm[row][column].getCharacter()=='-'){
                gold=gold-gm[row][column].getGoldLost();
                cout<<"Aw shit. Dr.Polack came up to you and cursed at you."<<endl; 
                cout<<"As you lay traumatized on the floor, picking up the shattered remains of your self-esteem,"<<endl; 
                cout<<"she steals $"<<gm[row][column].getGoldLost()<<" from you."<<endl;
                cout<<endl;
        }
        else if(gm[row][column].getCharacter()=='C'){
                gold=0;
                cout<<endl;
                cout<<"[COAL]"<<endl;
                cout<<"Dr.Polack had enough of you."<<endl;
                cout<<"She threw a piece of coal at you, took the rest of your wallet, and flunked you out of her class."<<endl; 
                cout<<"In hindsight, maybe you shouldn't have made a program poking fun at her."<<endl;
                cout<<endl;
        }
        else if(gm[row][column].getCharacter()=='R'){
                gold=gold-gm[row][column].getGoldLost();
                cout<<endl;
                cout<<"[RAINBOW]"<<endl;
                cout<<"you dropped $"<<gm[row][column].getGoldLost()<<" as you see Dr.Polack get up."<<endl;
                cout<<rainbowMessage()<<endl;
                cout<<endl;
        }
        
        else if(gm[row][column].getCharacter()=='G'){
                gold=1;
                cout<<endl;
                cout<<"[GOLD]"<<endl;
                cout<<"You find all the money Dr.Polack stole, however before you get a chance to stuff your pockets, She does a sick 360-No Scope-Tai-Kwan-Do-Karate Spin kick and rekts you."<<endl;
                cout<<"As you try to comprehend what the hell just happened to you, Dr.Polack commends your determination and perseverance."<<endl; 
                cout<<"She tosses a dollar bill ontop of you and says \"Don't spend it all in one place\""<<endl;     
                cout<<endl;
        }
                
        }
        
        
}

void GoldMine::printGoldMine(){
        int top=0;
        int side=0;
        cout<<"  0 1 2 3 4 5"<<endl;
        for(int i=0;i<6;i++){
        cout<<side<<" ";
                for(int j=0;j<6;j++){
                        if(gm[i][j].getVisited()==false){cout<<"* ";}
                        else{cout<<gm[i][j].getCharacter()<<" ";}
                }
        side++;        
        cout<<endl;
        }
}

void GoldMine::cheat(){
        bool cheat=true;
        for(int i=0;i<6;i++){
                for(int j=0;j<6;j++){
                        gm[i][j].setVisited(cheat);
                }
        }
        
        cout<<"Coal message: "<<endl;
                        cout<<"Dr.Polack had enough of you. She threw a piece of coal at you, took the rest of your wallet, and flunked you out of her class. In hindsight, maybe you shouldn't have made a program poking fun at her."<<endl;
        cout<<endl;
        cout<<"Rainbow message: "<<endl;
                        cout<<rainbowMessage()<<endl;
        cout<<endl;
        cout<<"Gold message: "<<endl;
                        cout<<"You find all the money Dr.Polack stole, however before you get a chance to stuff your pockets, She does a sick 360-No Scope-Tai-Kwan-Do-Karate Spin kick and rekts you."<<endl;
                        cout<<"As you try to comprehend what the hell just happened to you, Dr.Polack commends your determination and perseverance. She tosses a dollar bill ontop of you and says \"Don't spend it all in one place\""<<endl;                
        cout<<endl;
        cout<<"Nothing message: "<<endl;
                        cout<<"Aw shit. Dr.Polack came up to you and cursed at you. As you lay traumatized on the floor, picking up the shattered remains of your self-esteem, she steals $"<<"[GoldLost Variable]"<<" from you."<<endl;

}

void GoldMine::randomBoxes(){
        srand (time(NULL));
        int lose=rand() % 101 + 10;
        for(int i=0;i<6;i++){
                for(int j=0;j<6;j++){
                        gm[i][j].setGoldLost(lose);
                        lose=rand() % 101 + 10;
                }
        }
        
}

bool GoldMine::didItEnd(){
        bool out=false;;
        if(gm[rowc][colc].getVisited() || gm[rowg][colg].getVisited()){out=true;}
        return out;
}
void GoldMine::getRainbowLoc(){
        cout<<"R: "<<rowr<<" , "<<colr<<endl;}
void GoldMine::getCoalLoc(){
        cout<<"C: "<<rowc<<" , "<<colc<<endl;}
void GoldMine::getGoldLoc(){
        cout<<"G: "<<rowg<<" , "<<colg<<endl;}

#endif

