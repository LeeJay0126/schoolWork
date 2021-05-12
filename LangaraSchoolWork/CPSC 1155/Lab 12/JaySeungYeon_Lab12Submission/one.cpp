//-------------------------------------------------------------
// Lab 12 C++ 2D Arrays
// CPP program for CPSC 1155 Lab 12 CPP
//
// Author: Jay Seung Yeon Lee  	 	 	 	Date: 2021 - 03 - 31
//-------------------------------------------------------------
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <iomanip>
void initialize(int array[][10]);
void display(int array[][10]);
int sum(int array[][10]);
int sumDiagonal(int array[][10]);
int sumColumn(int array[][10], int);
int largestSum(int array[][10]);
void shuffle(int array[][10]);
void transpose(int array[][10]);

using namespace std;

int main()
{
    const int ROW_SIZE = 10;
    const int COLUMN_SIZE = 10;
    int myMatrix[ROW_SIZE][COLUMN_SIZE];

    initialize(myMatrix);
    display(myMatrix);

    int sum2D = sum(myMatrix);
    cout << "Sum of all elements in this array is : " << sum2D << endl;

    int lastColumnSum = sumColumn(myMatrix, 9);
    cout << "The sum of the last column of myMatrix is: " << lastColumnSum << endl;

    int largestRow = largestSum(myMatrix);
    cout << "Largest sum of a row is at row " << largestRow << endl;

    shuffle(myMatrix);
    display(myMatrix);

    cout << endl;

    transpose(myMatrix);
    display(myMatrix);


}

void initialize(int array[][10])
{
    srand(time(0));
    int random;

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            random = (int)(rand() % 100);
            array[i][j] = random;
        }
    }
}

void display(int array[][10])
{
    for (int i = 0; i < 10; i++)
    {
        cout << "Row: " << left << setw(4) << i;
        for (int j = 0; j < 10; j++)
        {
            cout << left << setw(3) << array[i][j];
        }
        cout << endl;
    }
}

int sum(int array[][10])
{

    int sum = 0;

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            sum += array[i][j];
        }
    }

    return sum;
}

int sumDiagonal(int array[][10])
{

    int sum = 0;
    int j = 0;
    for (int i = 0; i < 10; i++)
    {
        sum += array[i][j];
        j++;
    }
    return sum;
}

int sumColumn(int array[][10], int column)
{

    int sum = 0;
    for (int i = 0; i < 10; i++)
    {
        sum += array[column][i];
    }

    return sum;
}

int largestSum(int array[][10])
{

    int sum = 0;
    int largest = 0;
    int largestRow = 0;
    for (int i = 0; i < 10; i++)
    {
        sum = 0;
        for (int j = 0; j < 10; j++)
        {
            sum += array[i][j];
        }
        if (i == 0)
        {
            largest = sum;
            largestRow = i;
        }
        else
        {
            if (largest < sum)
            {
                largest = sum;
                largestRow = i;
            }
        }
    }

    return largestRow;
}

void shuffle(int array[][10])
{
    srand(time(0));
    int rand1;
    int rand2;
    int temp;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            rand1 = (int)(rand() % 10);
            rand2 = (int)(rand() % 10);
            temp = array[i][j];
            array[i][j] = array[rand1][rand2];
            array[rand1][rand2] = temp;
        }
    }
}

void transpose(int array[][10]){

    int temp;
    for(int i = 0; i < 10; i++){
        for(int j = 0+i; j < 10 ; j++){
            temp = array[i][j];
            array[i][j] = array[j][i];
            array[j][i] = temp;
        }
    }

}
