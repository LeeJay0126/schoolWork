#include <iostream>
#include "MyStruct.h"
#include "CarInfo.h"
#include <string>
#include <fstream>
using namespace std;

void CarInfo::initialize(int size, Cars arr[]){

    ifstream input;
    string line;
    int index = 0;
    int pos;

    input.open("as4_data.csv");
    getline(input,line);

    while(getline(input,line)){

        pos = line.find(",");

        arr[index].make = line.substr(0,pos);
        line.erase(0,pos+1);

        pos = line.find(",");

        arr[index].year = stoi(line.substr(0,pos));
        line.erase(0,pos+1);

        pos = line.find(",");

        arr[index].available = stoi(line.substr(0,pos));
        line.erase(0,pos+1);

        index++;
        


    }

    input.close();



}

void rentCars(Cars list[], string maker, int yearMade, int rentNumber, int size){

    int moreCarsNeeded = 0;

    for(int i = 0; i < size; i++){
        if(list[i].make == maker && list[i].year == yearMade){
            if(list[i].available > 0){
                if(list[i].available - rentNumber >= 0){
                    list[i].available -= rentNumber;
                }else{
                    moreCarsNeeded = (list[i].available - rentNumber) * -1;
                    cout << "We need " << moreCarsNeeded << " more cars in stock to rent " << rentNumber << " of this car" << endl;
                }
            }else{
                cout << "We are out of stock for this car" << endl;
            }
        }else{
            cout << "We dont have a car with make " << maker << " year " << yearMade << endl;
        }
    }

}

void CarInfo::quickSort(Cars list[], int arraySize)
{
  quickSort(list, 0, arraySize - 1);
}

void CarInfo::quickSort(Cars list[], int first, int last)
{
  if (last > first)
  {
    int pivotIndex = partition(list, first, last);
    quickSort(list, first, pivotIndex - 1);
    quickSort(list, pivotIndex + 1, last);
  }
}

int CarInfo::partition(Cars list[], int first, int last)
{
  string pivot = list[first].make; // Choose the first element as the pivot
  int low = first + 1; // Index for forward search
  int high = last; // Index for backward search

  while (high > low)
  {
    // Search forward from left
    while (low <= high && list[low].make <= pivot)
      low++;

    // Search backward from right
    while (low <= high && list[high].make > pivot)
      high--;

    // Swap two elements in the list
    if (high > low)
    {
      string temp = list[high].make;
      list[high].make = list[low].make;
      list[low].make = temp;

      int tempYear = list[high].year;
      list[high].year = list[low].year;
      list[low].year = tempYear;

      int tempAvailable = list[high].available;
      list[high].available = list[low].available;
      list[low].available = tempAvailable;

    }
  }

  while (high > first && list[high].make >= pivot)
    high--;

  // Swap pivot with list[high]
  if (pivot > list[high].make)
  {
    list[first].make = list[high].make;
    list[high].make = pivot;
    return high;
  }
  else
  {
    return first;
  }
}

