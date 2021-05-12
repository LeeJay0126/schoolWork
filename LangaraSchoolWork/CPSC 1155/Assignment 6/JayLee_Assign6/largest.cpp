//-------------------------------------------------------------
// Assignment 6 C++ Arrays
// CPP program for CPSC 1155 Assignment 6 Question 5
//
// Author: Jay Seung Yeon Lee  	 	 	 	Date: 2021 - 03 - 31
//-------------------------------------------------------------
#include <iostream>
#include <iomanip>
using namespace std;
void locateLargest(const double a[][4], int location[]);
void printMethod(const double a[][4]);

int main()
{

    const int ROW = 4;
    const int COLUMN = 3;

    double array[COLUMN][ROW];

    cout << "Enter a 3 * 4 two dimensional array: ";

    for (int i = 0; i < COLUMN; i++)
    {
        for (int j = 0; j < ROW; j++)
        {
            cin >> array[i][j];
        }
    }

    int locationArray[2];

    printMethod(array);
    locateLargest(array, locationArray);

    cout << "The location of the largest element is at (" << locationArray[0] << ", " << locationArray[1] << ")";
}

void locateLargest(const double a[][4], int location[])
{

    int greatestRow = 0;
    int greatestColumn = 0;
    double greatest = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (i == 0 && j == 0)
            {
                greatestRow = 0;
                greatestColumn = 0;
                greatest = a[0][0];
            }
            else
            {
                if (a[i][j] > greatest)
                {
                    greatest = a[i][j];
                    greatestColumn = i;
                    greatestRow = j;
                }
            }
        }
    }

    location[0] = greatestColumn;
    location[1] = greatestRow;
}

void printMethod(const double a[][4])
{

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << left << setw(5) << a[i][j] << "    ";
        }
        cout << endl;
    }
}