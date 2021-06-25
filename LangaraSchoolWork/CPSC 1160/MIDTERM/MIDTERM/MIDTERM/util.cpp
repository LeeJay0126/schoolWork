#include <iostream>
#include "Food.h"
#include "util.h"
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;


Food * Util::initialize(Food * foods, int *count){
    
    string foodName;
    string foodServing;
    string stringCalories;
    int calories;
    
    
    ifstream input;
    int index = 0;
    string line;
    int pos;
    
    input.open("foodAndCalories.csv");
    getline(input,line);
    
    while(getline(input,line)){
        
        (*count)++;
        
        pos = line.find(",");
        
        foodName = line.substr(0,pos);
        line.erase(0,pos+1);
        
        pos = line.find(",");
        
        foodServing = line.substr(0,pos);
        line.erase(0,pos+1);
        
        pos = line.find(" ");
        calories = stoi(line.substr(0,pos));
        
        foods = addArray(foods, count, foodName, foodServing, calories, index);
        
        index ++;
        
    }
    
    return foods;
    
}

Food * Util::addArray(Food * foods, int *count , string foodName, string foodServing, int calories, int index){
    
    Food * temp = new Food[*count];
    
    for(int i = 0; i < index; i++){
        temp[i].setFoodName(foods[i].getFoodName());
        temp[i].setServing(foods[i].getServing());
        temp[i].setCalories(foods[i].getCalories());
    }
    
    temp[index].setCalories(calories);
    temp[index].setServing(foodServing);
    temp[index].setFoodName(foodName);
    
    delete[] foods;
    return temp;
    
}

//Reference from assignment 5
void Util::quickSort(Food * arr, int arraySize)
{
  quickSort(arr, 0, arraySize - 1);
}

void Util::quickSort(Food * list, int first, int last)
{
  if (last > first)
  {
    int pivotIndex = partition(list, first, last);
    quickSort(list, first, pivotIndex - 1);
    quickSort(list, pivotIndex + 1, last);
  }
}

int Util::partition(Food * list, int first, int last)
{
  string pivot = list[first].getFoodName();
  // Choose the first element as the pivot
  int pivotInd = first;
  int low = first + 1; // Index for forward search
  int high = last; // Index for backward search

  while (high > low)
  {
    // Search forward from left
    while (low <= high && list[low].getFoodName() <= pivot)
      low++;

    // Search backward from right
    while (low <= high && list[high].getFoodName() > pivot)
      high--;

    // Swap two elements in the list
    if (high > low)
    {
      int temp = list[high].getCalories();
      list[high].setCalories(list[low].getCalories());
      list[low].setCalories(temp);

      string tempName = list[high].getFoodName();
      list[high].setFoodName(list[low].getFoodName());
      list[low].setFoodName(tempName);

      string tempServing = list[high].getServing();
      list[high].setServing(list[low].getServing());
      list[low].setServing(tempServing);

    }
  }

  while (high > first && list[high].getFoodName() >= pivot)
    high--;

  // Swap pivot with list[high]
  if (pivot > list[high].getFoodName())
  {
    pivotInd = high;
    list[first].setFoodName(list[high].getFoodName());
    list[high].setFoodName(pivot);
    list[first].setCalories(list[high].getCalories());
    list[first].setServing(list[high].getServing());
    list[high].setServing(list[pivotInd].getServing());
    list[high].setCalories(list[pivotInd].getCalories());
    
    return high;
  }
  else
  {
    return first;
  }
}

void Util::displayAll(Food * foods,int count){
    
    quickSort(foods, count);
    for(int i = 0; i < count; i ++){
        cout << left << setw(25) << foods[i].getFoodName() << setw(20) << foods[i].getServing() << setw(10) << foods[i].getCalories() << endl; 
    }
    
}

int Util::lowestCal(Food * foods, int count){
    
    int temp = 100;
    
    for(int i = 0; i < count; i++){
        if(temp > foods[i].getCalories()){
            temp = foods[i].getCalories();
        }
    }
    return temp;
}

int Util::numberOfLowestCal(Food * foods, int count , int lowestCal){
    
    int lowest = 0;
    
    for(int i = 0; i < count ; i ++){
        if(foods[i].getCalories() == lowestCal){
            lowest++;
        }
    }
    return lowest;
}

void Util::lowestCaloryArray(Food * foods, Food * newArr, int count){
    
    int lowest = lowestCal(foods, count);
    
    for(int i = 0; i < count; i ++){
        if(foods[i].getCalories() == lowest){
            newArr[i].setCalories(foods[i].getCalories());
            newArr[i].setFoodName(foods[i].getFoodName());
            newArr[i].setServing(foods[i].getServing());
            cout << newArr[i].getCalories() << "    " << newArr[i].getFoodName() << "   " << newArr[i].getServing() <<endl;
        }
    }
    
}

void Util::displayLow(Food * foods,int count){
    
    for(int i = 0; i < count; i++){
        cout << left << setw(20) << foods[i].getFoodName() << setw(20) << foods[i].getServing() << setw(10) << foods[i].getCalories() << endl;
    }
    
}