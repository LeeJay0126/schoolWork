#include "Player.h"
#include "Node.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>

template<typename T>
void pushData(T** n, string header[]);
template<typename T>
void readFile(T** head_ref, string filename, string header[]);
template<typename T>
void display(T * n);
template<typename T>
void assignTeams(T * n);

template<typename T>
void assignTeams(T * n){
    T p;
    int bucksPlayers = 0;
    int lakersPlayers = 0;
    int netsPlayers = 0;
    int warriorsPlayers = 0;
    
    while(n != nullptr){
       
        p = n->getElement();
        p.getElement().setTeam("this is a team");
        int assignment = rand() % 4 + 1;
        if(netsPlayers == bucksPlayers && lakersPlayers == bucksPlayers && warriorsPlayers == bucksPlayers){
            if(assignment == 1){
                p.getElement().setTeam("bucks");
                bucksPlayers ++;
            }
            if(assignment == 2){
                p.getElement().setTeam("lakers");
                lakersPlayers ++;
            }
            if(assignment == 3){
                p.getElement().setTeam("nets");
                netsPlayers ++;
            }
            if(assignment == 4){
                p.getElement().setTeam("warriors");
                warriorsPlayers ++;
            }
        }
        if(assignment == 1 && bucksPlayers <= lakersPlayers && bucksPlayers <= netsPlayers && bucksPlayers <= warriorsPlayers){
            p.getElement().setTeam("bucks");
            bucksPlayers++;
            
        }
        if(assignment == 2 && lakersPlayers <= bucksPlayers && lakersPlayers <= netsPlayers && lakersPlayers <= warriorsPlayers){
            p.getElement().setTeam("lakers");
            lakersPlayers++;
            
        }
        if(assignment == 3 && netsPlayers <= bucksPlayers && netsPlayers <= lakersPlayers && netsPlayers <= warriorsPlayers){
            p.getElement().setTeam("nets");
            netsPlayers++;
            
        }
        if(assignment == 4 && warriorsPlayers <= lakersPlayers && warriorsPlayers <= netsPlayers && warriorsPlayers <= bucksPlayers){
            p.getElement().setTeam("warriors");
            warriorsPlayers++;
            
        }
        cout << p.getElement().getName() << " " << p.getElement().getTeam() << " " << warriorsPlayers << endl;
        n = n->next;
    }
    cout << "bucks players " << bucksPlayers << " lakers players " << lakersPlayers << " nets players " << netsPlayers << " warriors players " << warriorsPlayers << endl;
    
}



template<typename T>
void display(T * n, string header[]){
    
    T p;
    
    cout <<left << setw(25) << header[0] << setw(5) << header[1] << setw(10) << header[2]<< setw(10) << header[3]<< setw(10) << header[4]<< setw(10) << header[5]<< setw(10) << header[6]<< setw(15) << header[7]<< setw(15) << header[8]<< setw(15) << header[9]<< setw(20) << header[10]<< setw(20) << header[11]<< setw(20) << header[12]<< setw(10) << header[13]<< setw(10) << header[14]<< setw(10) << header[15]<< setw(10) << header[16]<< setw(10) << header[17]<< setw(15) << header[18]<< setw(10) << header[19] << setw(10) << header[20] <<endl;

    cout << endl;
    
    while(n != nullptr){
        
        p = n->getElement();
        
        cout << left << fixed <<setprecision(2) << setw(25) << p.getElement().getName() << setw(5) << p.getElement().getFg() << setw(10) << p.getElement().getRebounds() << setw(10) << p.getElement().getAssists() << setw(10) <<  p.getElement().getSteals() << setw(10) << p.getElement().getBlocks() << setw(10) << p.getElement().getPoints() << setw(15) << p.getElement().getAllNba() << setw(15) << p.getElement().getAllNbaSecond() << setw(15) <<
        p.getElement().getAllNbaThird() << setw(20) << p.getElement().getAllNbaDefense() << setw(20) << p.getElement().getAllNbaDefenseSecond() << setw(20) << p.getElement().getAllNbaDefenseThird() << setw(10) << p.getElement().getAllStarMVP() << setw(10) << p.getElement().getROTY() << setw(10) << p.getElement().getDPOY() << setw(10) << p.getElement().getSMOTY() << setw(10) << p.getElement().getTMOTY() << setw(10) <<
        p.getElement().getScoringTitle() << setw(10) << p.getElement().getFMVP() << setw(10) << p.getElement().getMVP() << endl;
        
        
        n = n->next;
        
    }
    
    
}


template<typename T>
void readFile(T** head_ref,string filename, string header[]){
    
    ifstream input;
    input.open(filename);
    string line;
    int pos;
    
    Player player;
    int count = 0;
    double sum = 0;
    
    while(getline(input,line)){
        if(count == 0){
            
            pos = line.find(",");
            header[0] = line.substr(0,pos);
            line.erase(0,pos+1);
            
            cout << header[0] << endl;
                        
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
                        
            pos = line.find(",");
            header[8] = line.substr(0,pos);
            line.erase(0,pos+1);
                        
            pos = line.find(",");
            header[9] = line.substr(0,pos);
            line.erase(0,pos+1);
                        
            pos = line.find(",");
            header[10] = line.substr(0,pos);
            line.erase(0,pos+1);
                        
            pos = line.find(",");
            header[11] = line.substr(0,pos);
            line.erase(0,pos+1);
                        
            pos = line.find(",");
            header[12] = line.substr(0,pos);
            line.erase(0,pos+1);
                        
            pos = line.find(",");
            header[13] = line.substr(0,pos);
            line.erase(0,pos+1);
                        
            pos = line.find(",");
            header[14] = line.substr(0,pos);
            line.erase(0,pos+1);
                        
            pos = line.find(",");
            header[15] = line.substr(0,pos);
            line.erase(0,pos+1);
                        
            pos = line.find(",");
            header[16] = line.substr(0,pos);
            line.erase(0,pos+1);
                        
            pos = line.find(",");
            header[17] = line.substr(0,pos);
            line.erase(0,pos+1);
                        
            pos = line.find(",");
            header[18] = line.substr(0,pos);
            line.erase(0,pos+1);
                        
            pos = line.find(",");
            header[19] = line.substr(0,pos);
            line.erase(0,pos+1);
            
            
            header[20] = line;
            
            
            count++;
            
        }else{

            sum = 0;

            pos = line.find(",");
            player.setName(line.substr(0,pos));
            line.erase(0,pos+1);
                        
            pos = line.find(",");
            player.setFg(stod(line.substr(0,pos)));
            line.erase(0,pos+1);
                        
            pos = line.find(",");
            player.setRebounds(stod(line.substr(0,pos)));
            line.erase(0,pos+1);
                        
            pos = line.find(",");
            player.setAssists(stod(line.substr(0,pos)));
            line.erase(0,pos+1);
                        
            pos = line.find(",");
            player.setSteals(stod(line.substr(0,pos)));
            line.erase(0,pos+1);
            
            pos = line.find(",");
            player.setBlocks(stod(line.substr(0,pos)));
            line.erase(0,pos+1);
                        
            pos = line.find(",");
            player.setPoints(stod(line.substr(0,pos)));
            line.erase(0,pos+1);
                        
            pos = line.find(",");
            player.setAllNba(stoi(line.substr(0,pos)));
            line.erase(0,pos+1);
                        
            pos = line.find(",");
            player.setAllNbaSecond(stoi(line.substr(0,pos)));
            line.erase(0,pos+1);
            
            
                        
            pos = line.find(",");
            player.setAllNbaThird(stoi(line.substr(0,pos)));
            line.erase(0,pos+1);
                        
            pos = line.find(",");
            player.setAllDefense(stoi(line.substr(0,pos)));
            line.erase(0,pos+1);
                        
            pos = line.find(",");
            player.setAllDefenseSecond(stoi(line.substr(0,pos)));
            line.erase(0,pos+1);
                        
            pos = line.find(",");
            player.setAllDefenseThird(stoi(line.substr(0,pos)));
            line.erase(0,pos+1);
                        
            pos = line.find(",");
            player.setAllStarMVP(stoi(line.substr(0,pos)));
            line.erase(0,pos+1);
                        
            pos = line.find(",");
            player.setROTY(stoi(line.substr(0,pos)));
            line.erase(0,pos+1);
            
            pos = line.find(",");
            player.setDPOY(stoi(line.substr(0,pos)));
            line.erase(0,pos+1);
            
            pos = line.find(",");
            player.setSMOTY(stoi(line.substr(0,pos)));
            line.erase(0,pos+1);
                        
            pos = line.find(",");
            player.setTMOTY(stoi(line.substr(0,pos)));
            line.erase(0,pos+1);
                        
            pos = line.find(",");
            player.setScoringTitle(stoi(line.substr(0,pos)));
            line.erase(0,pos+1);
                        
            pos = line.find(",");
            player.setFMVP(stoi(line.substr(0,pos)));
            line.erase(0,pos+1);
            
            player.setMVP(stoi(line));
            
            sum += player.getPoints() * 2 * player.getFg();
            sum += player.getRebounds() * 4;
            sum += player.getAssists() * 4;
            sum += player.getSteals() * 5;
            sum += player.getBlocks() * 5;
        
            sum += player.getAllNba() * 50;
            sum += player.getAllNbaSecond() * 30;
            sum += player.getAllNbaThird() * 15;
        
            sum += player.getAllNbaDefense() * 50;
            sum += player.getAllNbaDefenseSecond() * 30;
            sum += player.getAllNbaDefenseThird() * 15;
        
            sum += player.getAllStarMVP() * 20;
            sum += player.getROTY() * 30;
            sum += player.getDPOY() * 50;
        
            sum += player.getSMOTY() * 30;
            sum += player.getTMOTY() * 20;
            sum += player.getScoringTitle() * 40;
            sum += player.getFMVP() * 150;
            sum += player.getMVP() * 100;
    
            player.setPlayerWorth(sum);
            
            pushData(head_ref,player);

        }

        
    }
    
    input.close();

}

template<typename T>
void pushData(T** head_ref, Player data){
    
    T * new_node = new T(data);
    
    new_node->next = (* head_ref);
    
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
    
}