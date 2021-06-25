#ifndef UTIL_H
#define UTIL_H

#include "Food.h"
#include <iostream>
using namespace std;

class Util{
    private:
    Food * addArray(Food * foods, int *count , string foodName, string foodServing, int calories, int index);
    void quickSort(Food * list, int first, int last);
    int partition(Food * list, int first, int last);
    
    public:
    Food * initialize(Food * foods, int * count);
    void quickSort(Food * arr, int arraySize);
    void displayAll(Food * foods, int count);
    int lowestCal(Food * foods, int count);
    void lowestCaloryArray(Food * foods, Food * newArr, int count);
    int numberOfLowestCal(Food * foods, int count , int lowestCal);
    void displayLow(Food * foods, int count);
    
};
#endif