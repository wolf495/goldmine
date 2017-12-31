#include <iostream>
#include "GoldMine.h"
#include "Box.h"
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
 int main(){
    srand(time(NULL));
    bool play=true;
    string response;
    int select;
    bool invalid=true;
    system("clear");
    cout<<"------------------------------------------"<<endl;
    cout<<"RUNNING Alfredo's GoldMine Game [9/24/17]"<<endl;
    cout<<"------------------------------------------"<<endl;
    cout<<"For Dr.Polack -> enter '9' for 'Row' or 'Column'     else -> enter a single number for \"Row\" and \"Col\"       Do not enter characters, only numbers"<<endl;
    cout<<endl;
    cout<<"STORYLINE:   You enter your classroom timidly. Your teacher is Dr.Polack, and she likes to steal money from her students. She stole money from you and you are trying to get it back. Look around, maybe she dropped it in here."<<endl;
    cout<<endl;
    cout<<endl;
    
    
    while(play){
        GoldMine gameboard;
        gameboard.setGold();
        gameboard.setCoal();
        gameboard.setRainbow();
        gameboard.randomBoxes();
        invalid=true;
        int startingGold=gameboard.getGold();
        int chooseR;
        int chooseC;
        int error=0;
        cout<<"See OneTime Sneek peek? [yes][no]"<<endl;
        cin>>response;
        if(response=="yes"){gameboard.getRainbowLoc();gameboard.getCoalLoc();gameboard.getGoldLoc();}
        else{}
        
            while(gameboard.getGold()>0 && gameboard.didItEnd()==false){
                if(error>0){cout<<"Invalid Coordinate: Enter only(0-5)"<<endl;cout<<"...Game left unchanged..."<<endl;error--;}
                gameboard.printGoldMine();
                cout<<endl;
                cout<<"Last Move: ["<<chooseR<<","<<chooseC<<"]"<<endl;
                cout<<"Money Left: $"<<gameboard.getGold()<<endl;
                cout<<endl;
                cout<<"Enter a Row: ";
                cin>>select;
                if(select==9){break;}
                chooseR=select;
                cout<<"Enter a Column: ";
                cin>>select;
                if(select==9){break;}
                chooseC=select;
                
                if(chooseR<0 || chooseR>5 || chooseC<0 ||chooseC>5){error++;}
                else{
                    gameboard.revealSelection(chooseR,chooseC);
                    cout<<"[Press any NUMBER to continue]"<<endl;
                    cin>>select;
                }
                system("clear");
            }
            
        system("clear");
        cout<<"-----ENDING GAME-----"<<endl;
        
        if(select==9){
            play=false;
            cout<<"Dr.Polack Cheat Sheet"<<endl;
            cout<<endl;
            gameboard.cheat();
            gameboard.printGoldMine();
            cout<<endl;
            cout<<"Starting Gold: "<<startingGold<<endl;
            cout<<"Gold Now: "<<gameboard.getGold()<<endl;
            
            
        }
        else{
            while(invalid){
                gameboard.cheat();
                gameboard.printGoldMine();
                cout<<"Starting Gold: "<<startingGold<<endl;
                cout<<"Gold Now: "<<gameboard.getGold()<<endl;
                cout<<"Play again? [yes][no]"<<endl;
                cin>>response;
                if(response=="no"){play=false;invalid=false;}
                else if(response=="yes"){play=true;invalid=false;select=8;}
                else{cout<<"Invalid response"<<endl;cout<<"------------------"<<endl;}
            }
        system("clear");
        }   
    }
    
    
    
    cout<<"------------------------------------------"<<endl;
    cout<<"EXITING Alfredo's GoldMine Game [9/24/17]"<<endl;
    cout<<"------------------------------------------"<<endl;
     return 0;
 }