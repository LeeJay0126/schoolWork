#include <iostream>
using namespace std;
void initialize(int array[], int arraySize);
void printFirstToLast(int array[], int arraySize);
void printLastToFirst(int array[], int arraySize);

int main(){

    int array[9];

    initialize(array, 9);
    printFirstToLast(array,9);
    cout << endl;
    printLastToFirst(array,9);

}

void initialize(int array[], int arraySize){
    
    for(int i = 0; i < arraySize; i++){
        cout << "Enter a number for your array : ";
        cin >> array[i];
    }

}

void printFirstToLast(int array[], int arraySize){

    for(int i = 0; i < arraySize; i++){
        cout << array[i] << "   ";
    }

}

void printLastToFirst(int array[], int arraySize){

    for(int i = arraySize -1; i >= 0; i-- ){
        cout << array[i] << "   ";
    }

}