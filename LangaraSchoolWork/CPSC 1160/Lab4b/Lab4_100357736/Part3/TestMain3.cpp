// filename: TestMain3.cpp

#include "SortLib.h"
#include "MyStruct.h"

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

void display(string msg, MyData [], int);

int main()
{
  SortUtil su;
  
  const int SIZE = 9;
  MyData data[SIZE];
  
  // populating with dummy data
   srand (time(NULL));
   for (int i = 0; i < SIZE; i++) {
     data[i].id = i + 1 ;
     data[i].codeName = "Agent ";
     data[i].codeName += 'A' + (rand()%26) ;
     data[i].codeName += 'A' + (rand()%26) ;
   }

  display("Before", data, SIZE); 
 
  su.quickSort(data, SIZE);
  display("After", data, SIZE); 
  
 
  return 0;
}  

void display(string msg, MyData data[], int size) {
  cout << msg << endl;
  for (int i = 0; i < size; i++)
    cout << data[i].codeName << " : " << data[i].id << endl;

  cout << endl;
}
