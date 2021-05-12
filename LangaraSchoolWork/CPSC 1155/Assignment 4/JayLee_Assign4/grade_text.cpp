//-------------------------------------------------------------
// Assignment 4 Loops
// CPP program for CPSC 1155 Assignment 4 Question 2
//
// Author: Jay Seung Yeon Lee  	 	 	 	Date: 2021 - 03 - 03
//-------------------------------------------------------------
#include <iostream>
#include <string>
#include <math.h>
#include <fstream>


using namespace std;

int main()
{

    int grade, minimumGrade;

    ifstream input;
    input.open("grade.txt");
    for (int i = 0; i < 5; i++)
    {
        cin >> grade;
        if (i == 0)
        {
            minimumGrade = grade;
        }
        else
        {
            if (minimumGrade > grade)
            {
                minimumGrade = grade;
            }
        }
    }
    input.close();
    cout << "The minimum grade is " << minimumGrade;
}