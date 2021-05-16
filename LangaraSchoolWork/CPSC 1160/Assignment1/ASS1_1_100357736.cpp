#include <iostream>
using namespace std;

const int SIZE = 4;
double sumColumn(const double m[][SIZE], int rowSize, int columnIndex);

int main(){
    
    double array[3][SIZE];

    cout << "Enter a 3-by-4 matrix row by row: " << endl;
    
    for(int i = 0; i < 3; i++){
       for(int j = 0; j < 4; j++){
           cin >> array[i][j];
       }
    }
    cout << endl;

    double sum;
    for(int k = 0; k < SIZE; k++){
        sum = sumColumn(array, 3, k);
        cout << "Sum of the elements at column " << k << " is " << sum << endl;
    }
    
    return 0;
}

double sumColumn(const double m[][SIZE], int rowSize, int columnIndex){
    double sum = 0.0;
    
    for(int i = 0; i < rowSize; i ++){
        sum += m[i][columnIndex];
    }

    return sum;
}
