#include <iostream>
#include "players.h"
#include "util.h"
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;


Players * Util::initialize(Players *players, int *count){
    
    ifstream input;
    int index = 0;
    
    input.open("NBA-playerlist.csv");
    getline(input,line);
   
    while(getline(input,line)){
        
        (*count)++;
     
        pos = line.find(",");
        
        playerId = stoi(line.substr(0,pos));
        line.erase(0,pos+1);
        
        pos = line.find(",");
        
        firstName = line.substr(0,pos);
        line.erase(0,pos+1);
        
        
        pos = line.find(",");
        
        lastName = line.substr(0,pos);
        line.erase(0,pos+1);
                
        pos = line.find(",");
        
        firstYear = stoi(line.substr(0,pos));
        line.erase(0,pos+1);
                
        pos = line.find(",");
        
        lastYear = stoi(line.substr(0,pos));
        line.erase(0,pos+1);
        
        name = firstName + " " + lastName;
        
        
        players = addPlayer(players,count,name,firstYear,lastYear,index);
        
        index++;

    }
    quickSort(players, *count);
    return players;
}

Players * Util::addPlayer(Players *original,int *count, string name, int firstYear, int lastYear, int index){
    
    Players *temp = new Players[*count];
    
    for(int i = 0; i < index; i++){
        temp[i]+=original[i].getName();
        temp[i].setCareer(original[i].getFirstYear(),original[i].getLastYear());
        temp[i].setId(original[i].getId());
        temp[i].setLastYear(original[i].getLastYear());
        temp[i]+=original[i].getFirstYear();
    }

        temp[index]+=name;
        temp[index].setCareer(firstYear,lastYear);
        temp[index].setId(playerId);
        temp[index].setLastYear(lastYear);
        temp[index]+=firstYear;
    
    delete[] original;
    return temp;
    
}

void Util::display(Players *players, int count){
    for(int i = 0; i < count; i++){
        cout << left << setw(5) << players[i].getId() << setw(30) << players[i].getName() << setw(10) << players[i].getFirstYear() << setw(10) << players[i].getLastYear() << endl; 
    }
}


void Util::quickSort(Players * arr, int arraySize)
{
  quickSort(arr, 0, arraySize - 1);
}

void Util::quickSort(Players * list, int first, int last)
{
  if (last > first)
  {
    int pivotIndex = partition(list, first, last);
    quickSort(list, first, pivotIndex - 1);
    quickSort(list, pivotIndex + 1, last);
  }
}

int Util::partition(Players * list, int first, int last)
{
  int pivot = list[first].getFirstYear(); // Choose the first element as the pivot
  int low = first + 1; // Index for forward search
  int high = last; // Index for backward search

  while (high > low)
  {
    // Search forward from left
    while (low <= high && list[low].getFirstYear() <= pivot)
      low++;

    // Search backward from right
    while (low <= high && list[high].getFirstYear() > pivot)
      high--;

    // Swap two elements in the list
    if (high > low)
    {
      int temp = list[high].getFirstYear();
      list[high]+=list[low].getFirstYear();
      list[low]+=temp;

      int tempYear = list[high].getLastYear();
      list[high].setLastYear(list[low].getLastYear());
      list[low].setLastYear(temp);

      int tempId = list[high].getId();
      list[high].setId(list[low].getId());
      list[low].setId(temp);
      
      string tempName = list[high].getName();
      list[high]+=list[low].getName();
      list[low]+=tempName;

    }
  }

  while (high > first && list[high].getFirstYear() >= pivot)
    high--;

  // Swap pivot with list[high]
  if (pivot > list[high].getFirstYear())
  {
    list[first]+=(list[high].getFirstYear());
    list[high]+=pivot;
    return high;
  }
  else
  {
    return first;
  }
}

void Util::outPutCSV(Players * players,int count){
    
    ofstream myfile;
    myfile.open("MyNBA.csv");
    myfile << "Id,Name,Debut Year, Retired Year \n";
    for(int i = 0; i < count; i++){
        myfile << players[i].getId() << "," << players[i].getName() << "," << players[i].getFirstYear() << "," << players[i].getLastYear() << "\n";
    }
    myfile.close();
    
    
}

void Util::outPutTxT(Players * players, int count){
  
  ofstream myfile;
  myfile.open("MyNBA.txt");
  myfile <<left <<  setw(10) << "Id" << setw(30) << "Name"<< setw(10) << "Debut Year" << setw(10) << "Retired Year \n";
  for(int i = 0; i < count ; i ++){
    myfile << left<< setw(10) << players[i].getId() << setw(30) << players[i].getName()<< setw(10) << players[i].getFirstYear() << setw(10) <<players[i].getLastYear() <<"\n";
  }
  myfile.close();
  
}

int Util::returnMaxCareer(Players * players, int count){
  int temp = 0;
  for(int i = 0; i < count; i++){
    players[i].setCareer(players[i].getFirstYear(),players[i].getLastYear());
    if(temp < players[i].getCareer()){
      temp = players[i].getCareer();
    }
  }
  return temp;
}

Players * Util::listOfMaxCareerPlayers(Players * players, int count, int * maxCount){
  
  int max = returnMaxCareer(players,count);
  Players * maxPlayers = new Players[*maxCount];
  int index = 0;
  string name;
  int startYear;
  int lastYear;
  
  for(int i = 0; i < count; i++){
    if(players[i].getCareer() == max){
    
    name = players[i].getName();
    startYear = players[i].getFirstYear();
    lastYear = players[i].getLastYear();
    
    
    (*maxCount)++;
     maxPlayers = addNumberOfMaxPlayers(maxPlayers, maxCount, count, max, index, firstYear, lastYear, name);
     index ++;
    }
  }
  
  return maxPlayers;
  
}

Players * Util::addNumberOfMaxPlayers(Players * players, int *maxCount, int count, int max, int index,int firstYear,int lastYear,string name){

  Players * temp = new Players [*maxCount];
    
    if(index > 0){
      for(int j = 0; j < index; j++){       
        temp[j].setCareer(players[j].getFirstYear(),players[j].getLastYear());
        temp[j]+=players[j].getName();
      }
    }
   
    temp[index].setCareer(firstYear, lastYear);
    temp[index]+=name;
   
  
  delete[] players;
  return temp;
  
}


void Util::displayMax(Players * players, int maxCount){
  cout << "Player(s) with longest career" <<endl;
  cout << left << setw(30) << "NAME" << setw(10) << "CAREER LENGTH" << endl;
  for(int i = 0; i < maxCount; i++){
    cout << left << setw(30) << players[i].getName() << setw(10) << players[i].getCareer() << endl;
  }
}