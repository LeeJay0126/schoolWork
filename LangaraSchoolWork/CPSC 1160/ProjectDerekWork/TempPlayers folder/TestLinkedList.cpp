#include "Player.h"
#include "Node.h"
#include "PlayerUtil.cpp"
#include <iostream>
#include <iomanip>
#include <string>

int main(){
    
    Node<Player> *head = nullptr;
    string header[21];
    
    cout << "head's address : " << &head << endl;
    
    readFile(&head, "NbaPlayers.csv",header);
    assignTeams(head);
    
    return 0;
    
    
}