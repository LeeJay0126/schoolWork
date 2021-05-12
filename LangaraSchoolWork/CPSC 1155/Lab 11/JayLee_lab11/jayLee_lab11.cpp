//-------------------------------------------------------------
// Lab 11 C++ Arrays
// CPP program for CPSC 1155 Lab 11 CPP
//
// Author: Jay Seung Yeon Lee  	 	 	 	Date: 2021 - 03 - 24
//-------------------------------------------------------------
#include <iostream>
#include <stdlib.h>
#include <time.h>
void initialize(int[], int);
void printArray(int[], int);
int largestArray(int[], int);
int smallestIndex(int[], int);
int largestIndex(int[], int);
void newArray(int[], int[], int);
void oldArray(int[], int);
int search(int[], int, int);

using namespace std;

int main()
{
    srand(time(0));

    const int SIZE = 10;
    int myList[SIZE];

    initialize(myList, SIZE);
    printArray(myList, SIZE);
    
    int largest;
    largest = largestArray(myList, SIZE);

    cout << endl;
    cout << "Largest element in this array is: " << largest;

    cout << endl;
    int smallest;
    smallest = smallestIndex(myList, SIZE);
    cout << "Smallest element in this array is: " << smallest;

    int index;
    index = largestIndex(myList, SIZE);
    cout << endl;
    cout<< "Largest Index of the largest element is : " << index<< endl;

    int newArr[SIZE];
    newArray(myList,newArr, SIZE);
    printArray(newArr, SIZE);
    cout << endl;

    oldArray(myList, SIZE);
    printArray(myList,SIZE);
    cout << endl;

    int randomNumber;
    randomNumber = rand()%21;
    int arraySearch;
    arraySearch = search(myList, SIZE, randomNumber);

    if(arraySearch == -1){
        cout << randomNumber << " is not included in the array";
    }else{
        cout << randomNumber << " is included in the array at index " << arraySearch;
    }

    return 0;
}

void initialize(int array[], int length)
{
    int number;
    for (int i = 0; i < length; i++)
    {
        number = rand() % 10;
        array[i] = number;
    }
}

void printArray(int array[], int length)
{

    cout << "{";
    for (int i = 0; i < length; i++)
    {
       cout << array[i] << " ";
    }
    cout << "}";
}

int largestArray(int array[], int length){

    int largest;
    for(int i = 0; i < length; i ++){
        if(i == 0){
            largest = array[i];
        }else{
            if(largest < array[i]){
                largest = array[i];
            }
        }
    }
    return largest;
}

int smallestIndex(int array[], int length){

    int smallest;
    int index;
    for(int i = 0; i < length; i++){
        if(i ==0){
            smallest = array[i];
            index = i;
        }else{
            if(smallest > array[i]){
                smallest = array[i];
                index = i;
            }
        }
    }
    return smallest;
}

int largestIndex(int array[], int length){
    int index;
    int number;
    for(int i = 0; i < length; i++){
        if(i == 0){
            index = i;
            number = array[i];
        }else{
            if(number <= array[i]){
                index = i;
                number = array[i];
            }
        }
    }
    return index;
}

void newArray(int array[], int newArr[], int length){

    for(int k = 0; k < length-1; k++){
        newArr[k] = array[k+1];
    }

    newArr[length-1] = array[0];

}

void oldArray(int array[], int length){

    int temp;
    temp = array[length-1];
    for(int i = length-1; i >= 0; i--){
        array[i] = array[i-1];
    }

    array[0] = temp;
}

int search(int array[], int length, int number){

    for(int i = 0; i < length; i++){
        if(array[i] == number){
            return i;
            break;
        }
    }

    return -1;
}