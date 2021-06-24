#include <iostream>
#include <string>
#include <fstream>
#include "players.h"
#include "util.h"

using namespace std;
void display(Players *players, int count);


int main(){

    int count = 0;
    int maxCount = 0;
    
    Util util;
    Players *players = new Players[count];
    players = util.initialize(players, &count);
    Players *maxCareerPlayers = new Players[maxCount];
    maxCareerPlayers = util.listOfMaxCareerPlayers(players, count, &maxCount);
    
    int input = 0;
    
    while(!(input == 3)){
        cout << "Enter 1 to display all players, 2 for the player with longest career, and 3 to exit:  ";
        cin >> input;
        switch (input){
            case 1:
                util.display(players,count);
                util.outPutCSV(players,count);
                util.outPutTxT(players,count);
                break;
            case 2:
                util.displayMax(maxCareerPlayers, maxCount);
                break;
            
            default:
                cout << "Please enter an integer between 1 and 3 " << endl;
                
        }
    }
    
    
}

