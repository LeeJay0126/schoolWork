#include <iostream>
#include <string>
#include "CarInfo.h"
#include "Customers.h"
#include "Util.h"
using namespace std;

void Util::initialize(int size, CarInfo arr[]){

    ofstream input;
    string line;
    int index = 0;
    int pos;

    input.open("as4_data.csv");
    getline(input,line);

    while(getline(input,line)){

        int year;
        int available;
        string make;
        
        //arr[index].setMake(line.substr(0,pos));
        pos = line.find(",");

        arr[index].setMake(line.substr(0,pos));
        line.erase(0,pos+1);

        pos = line.find(",");

        arr[index].setYear(stoi(line.substr(0,pos)));
        line.erase(0,pos+1);

        pos = line.find(",");

        arr[index].setQuantity(stoi(line.substr(0,pos)));
        line.erase(0,pos+1);

        index++;
        
        
        


    }

    input.close();



}

void Util::rentCars(CarInfo list[], string maker, int yearMade, int rentNumber, int size){

    int moreCarsNeeded = 0;

    for(int i = 0; i < size; i++){
        if(list[i].getCarMake() == maker && list[i].getCarYear() == yearMade){
            if(list[i].getQuantity() > 0){
                if(list[i].getQuantity() - rentNumber >= 0){
                    list[i].setQuantity(list[i].getQuantity() - rentNumber);
                    
                }else{
                    moreCarsNeeded = (list[i].getQuantity() - rentNumber) * -1;
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

void Util::quickSort(CarInfo list[], int arraySize)
{
  quickSort(list, 0, arraySize - 1);
}

void Util::quickSort(Cars list[], int first, int last)
{
  if (last > first)
  {
    int pivotIndex = partition(list, first, last);
    quickSort(list, first, pivotIndex - 1);
    quickSort(list, pivotIndex + 1, last);
  }
}

int Util::partition(CarsInfo list[], int first, int last)
{
  string pivot = list[first].getMake(); // Choose the first element as the pivot
  int low = first + 1; // Index for forward search
  int high = last; // Index for backward search

  while (high > low)
  {
    // Search forward from left
    while (low <= high && list[low].getMake() <= pivot)
      low++;

    // Search backward from right
    while (low <= high && list[high].getMake() > pivot)
      high--;

    // Swap two elements in the list
    if (high > low)
    {
      string temp = list[high].getMake();
      list[high].getMake() = list[low].getMake();
      list[low].getMake() = temp;

      int tempYear = list[high].getYear();
      list[high].setYear(list[low].getYear());
      list[low].setYear(tempYear);

      int tempQuantity = list[high].getQuantity();
      list[high].setQuantity(list[low].getQuantity());
      list[low].setQuantity(tempQuantity);

    }
  }

  while (high > first && list[high].getMake() >= pivot)
    high--;

  // Swap pivot with list[high]
  if (pivot > list[high].getMake())
  {
    list[first].setMake(list[high].getMake());
    list[high].setMake(pivot);
    return high;
  }
  else
  {
    return first;
  }
}

void Util::quickSort(Customers list[], int arraySize)
{
  quickSort(list, 0, arraySize - 1);
}

void Util::quickSort(Customers list[], int first, int last)
{
  if (last > first)
  {
    int pivotIndex = partition(list, first, last);
    quickSort(list, first, pivotIndex - 1);
    quickSort(list, pivotIndex + 1, last);
  }
}

int Util::partition(Customers list[], int first, int last)
{
  string pivot = list[first].getCarMake(); // Choose the first element as the pivot
  int low = first + 1; // Index for forward search
  int high = last; // Index for backward search

  while (high > low)
  {
    // Search forward from left
    while (low <= high && list[low].getCarMake() <= pivot)
      low++;

    // Search backward from right
    while (low <= high && list[high].getCarMake() > pivot)
      high--;

    // Swap two elements in the list
    if (high > low)
    {
      string temp = list[high].getCarMake();
      list[high].setCarMake(list[low].getCarMake());
      list[low].setCarMake(temp);

      int tempYear = list[high].getCarYear();
      list[high].setCarYear(list[low].getCarYear());
      list[low].setCarYear(tempYear);

      int tempQuantity = list[high].getQuantity();
      list[high].setQuantity(list[low].getQuantity());
      list[low].setQuantity(quantity);

      string dateRented = list[high].getDate();
      list[high].dateRented = list[low].dateRented;
      list[low].dateRented = dateRented;
      
      string firstName = list[high].firstName;
      list[high].firstName = list[low].firstName;
      list[low].firstName = firstName;

      string lastName = list[high].lastName;
      list[high].lastName = list[low].lastName;
      list[low].lastName = lastName;

      string date = list[high].getDate();
      list[high].setDate(list[low].getDate());
      list[low].setDate(getDate());


    }
  }

  while (high > first && list[high].getCarMake() >= pivot)
    high--;

  // Swap pivot with list[high]
  if (pivot > list[high].getCarMake())
  {
    list[first].setCarMake(list[high].getCarMake());
    list[high].setCarMake( pivot);
    return high;
  }
  else
  {
    return first;
  }
}

void getDateRented(string firstName, string lastName, string carMake, string dateRented, int carYear, int quantity){
    
    ofstream input;
    string line;
    
    line = firstName +"," + lastName + "," + carMake + "," + carYear + "," + quantity + "," + dateRented;
    
    input.open("customers.csv");
    
    input << line;
    
    ofstream.close();
    
    
    
}