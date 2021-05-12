//-------------------------------------------------------------
// Assignment 6 C++ Arrays
// CPP program for CPSC 1155 Assignment 6 Question 4
//
// Author: Jay Seung Yeon Lee  	 	 	 	Date: 2021 - 03 - 31
//-------------------------------------------------------------
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <iomanip>
#include <string>
using namespace std;
void arrayMethod(int array[]);
void asterisks(string array[], int array2[]);

int main()
{

    srand(time(0));

    int myArray[10];
    arrayMethod(myArray);

    string asterisksArray[10];
    asterisks(asterisksArray, myArray);

    cout << left << setw(25) << "Element" << left << setw(25) << "Value" << left << setw(25) << "Histogram" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << left << setw(25) << i <<  left << setw(25) << myArray[i] << left << setw(25) << asterisksArray[i] << endl;
    }
}

void arrayMethod(int array[])
{

    for (int i = 0; i < 10; i++)
    {
        array[i] = (int)(1 + (rand() % 20));
    }
}

void asterisks(string array[], int array2[])
{
    string result = "";
    for (int i = 0; i < 10; i++)
    {
        result = "";
        for(int j = 0; j < array2[i]; j++){
            result += "*";
        }
        array[i] = result;
    }
}