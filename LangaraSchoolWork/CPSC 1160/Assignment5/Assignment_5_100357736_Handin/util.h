#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <string>
#include "players.h"
using namespace std;

class Util{
    private:
    int index;
    int pos;
    string line;
    int playerId;
    string lastName;
    string firstName;
    string name;
    int firstYear;
    int lastYear;
    Players * addPlayer(Players *original,int *count, string name, int firstYear, int lastYear, int index);
    void quickSort(Players * arr, int first, int last);
    int partition(Players * arr, int first, int last);
    Players * addNumberOfMaxPlayers(Players * players, int *maxCount, int count, int max, int index,int firstYear,int lastYear,string name);
    int returnMaxCareer(Players * players, int count);
    
    public:
    Players * initialize(Players *players,int *count);
    void quickSort(Players * arr, int arraySize);
    void display(Players *players, int count);
    void outPutCSV(Players * players,int count);
    Players * listOfMaxCareerPlayers(Players * players, int count,int * maxCount);
    void displayMax(Players * players, int maxCount);
    void outPutTxT(Players * players, int count);
    
};
#endif