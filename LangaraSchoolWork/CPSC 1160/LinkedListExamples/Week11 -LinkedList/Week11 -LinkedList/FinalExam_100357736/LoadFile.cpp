#include "Pokemon_100357736.h"
#include "LoadFile.h"
#include "Node.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

LoadFile::LoadFile(){
    
}

void LoadFile::LoadCSV(Pokemon** head, string header[]){
    
    ifstream input;
    input.open("pokemon.csv");
    string line;
    int pos;
    
    Pokemon pokemon;
    int count = 0;
    
    while(getline(input,line)){
        if(count == 0){
            
            pos = line.find(",");
            header[0] = line.substr(0,pos);
            line.erase(0,pos+1);
            
            pos = line.find(",");
            header[1] = line.substr(0,pos);
            line.erase(0,pos+1);
            
            pos = line.find(",");
            header[2] = line.substr(0,pos);
            line.erase(0,pos+1);
            
            pos = line.find(",");
            header[3] = line.substr(0,pos);
            line.erase(0,pos+1);
            
            pos = line.find(",");
            header[4] = line.substr(0,pos);
            line.erase(0,pos+1);
            
            pos = line.find(",");
            header[5] = line.substr(0,pos);
            line.erase(0,pos+1);
            
            pos = line.find(",");
            header[6] = line.substr(0,pos);
            line.erase(0,pos+1);
            
            pos = line.find(",");
            header[7] = line.substr(0,pos);
            line.erase(0,pos+1);
            
            count ++;
            
        }else{
            
            pos = line.find(",");
            pokemon.setName(line.substr(0,pos));
            line.erase(0,pos+1);
            
            pos = line.find(",");
            pokemon.setTotal(stoi(line.substr(0,pos)));
            line.erase(0,pos+1);
            
            pos = line.find(",");
            pokemon.setHp(stoi(line.substr(0,pos)));
            line.erase(0,pos+1);
            
            pos = line.find(",");
            pokemon.setAttack(stoi(line.substr(0,pos)));
            line.erase(0,pos+1);
            
            pos = line.find(",");
            pokemon.setDefence(stoi(line.substr(0,pos)));
            line.erase(0,pos+1);
            
            pos = line.find(",");
            pokemon.setAtkSpeed(stoi(line.substr(0,pos)));
            line.erase(0,pos+1);
            
            pos = line.find(",");
            pokemon.setSpDefence(stoi(line.substr(0,pos)));
            line.erase(0,pos+1);
            
            pos = line.find(",");
            pokemon.setSpeed(stoi(line.substr(0,pos)));
            line.erase(0,pos+1);
            
            pushData(head, pokemon);
        }
        
        
        
    }
    
    input.close();
    
}

void LoadFile::pushData(Pokemon** head_ref, Pokemon data){
    
    Pokemon* new_node = new Pokemon(data);
    
    new_node->next = (* head_ref);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
    
}