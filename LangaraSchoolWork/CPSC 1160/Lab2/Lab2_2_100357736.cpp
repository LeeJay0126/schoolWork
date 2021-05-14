#include <iostream>
using namespace std;
void initialize(int array[], int arraySize);
void printFirstToLast(int array[], int arraySize);
void printLastToFirst(int array[], int arraySize);
void higherThanAverage(int array1[], int array2[], int average, int arraySize);
int sumOfInt(int array[], int arraySize);
void limitLessThanAverage(int array1[], int array2[], int average, int arraySize);

int main(){

    int array[8];

    initialize(array, 8);
    printFirstToLast(array,8);
    cout << endl;
    printLastToFirst(array,8);
    cout << endl;
    int sum = sumOfInt(array,8);
    cout << "Sum of all the integers in the array is " << sum << endl;
    
    int average = (sum / 8);

    int array1[8];
    limitLessThanAverage(array, array1, average, 8);
    cout << "Displaying all values less than average of the integers: " << endl;
    for(int i = 0 ; i < 8; i++){
        cout << array1[i] << "  ";
    }
    cout << endl;

    int array2[8];
    higherThanAverage(array, array2, average, 8);
    cout<< "Displaying all values over average of the integers : " << endl;
    for(int i = 0; i < 8; i++){
        cout << array2[i] << "  ";
    }

}

void initialize(int array[], int arraySize){
    
    cout << "Enter a number for your array : ";
    for(int i = 0; i < arraySize; i++){
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

int sumOfInt(int array[], int arraySize){

    int sum = 0;
    for(int i = 0; i < arraySize; i++){
        sum += array[i]; 
    }

    return sum;
}

void limitLessThanAverage(int array1[], int array2[], int average, int arraySize){

    for(int i = 0; i < arraySize; i++){
        if(array1[i] < average){
            array2[i] = array1[i];
        }else{
            array2[i] = 0;
        }
    }

}

void higherThanAverage(int array1[], int array2[], int average, int arraySize){
    
    for(int i = 0; i < arraySize; i++){
        if(array1[i] > average){
            array2[i] = array1[i];
        }else{
            array2[i] = 0;
        }
    }

}