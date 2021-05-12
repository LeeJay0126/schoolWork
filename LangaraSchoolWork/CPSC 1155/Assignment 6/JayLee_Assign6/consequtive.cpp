//-------------------------------------------------------------
// Assignment 6 C++ Arrays
// CPP program for CPSC 1155 Assignment 6 Question 6
//
// Author: Jay Seung Yeon Lee  	 	 	 	Date: 2021 - 03 - 31
//-------------------------------------------------------------
#include <iostream>

using namespace std;
bool isConsecutiveFour(int [][4], int);

int main(){
    
    int numbers = 0;
    cout << "Enter the number of values: ";
    cin >> numbers;
    int array[10][4];
    int j = 0;
    int k= 0;
    cout << "Enter the values: ";
    for(int i = 0; i < numbers; i++){
        if((i+1)%4 == 0){
            j++;
            k = 0;
        }
        cin >> array[j][k];
        cout << array[j][k] << endl;
        k++;
    }

    bool result = isConsecutiveFour(array, numbers);

    if(result == true){
        cout << "The list has consecutive fours";
    }else{
        cout << "The list has no consecutive fours";
    }

    return 0;

}

bool isConsecutiveFour(int values [][4], int number){
    int x = 0;
    int y = 0;
    int lastNumber = 0;
    int count = 0;
    for(int i = 1; i <= number; i++){
        x = i / 4;
        y = i % 4;
        if(i == 1){
            lastNumber = values[x][y];
            count++;
            cout << count << "  " << values[x][y] << "  " << lastNumber << i <<  endl;
        }else{
            if(lastNumber == values[x][y]){
                count++;
                cout << count << "  " << values[x][y] << "  " << lastNumber <<i<<  endl;
            }else{
                lastNumber = values[x][y];
                count = 0;
                cout << count << "  " << values[x][y] << "  " << lastNumber << i << endl;
            }
        }
        if(count == 4){
            return true;
        }
    }
    return false;
}