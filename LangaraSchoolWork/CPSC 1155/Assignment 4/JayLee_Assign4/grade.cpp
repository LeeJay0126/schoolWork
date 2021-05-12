//-------------------------------------------------------------
// Assignment 4 Loops
// CPP program for CPSC 1155 Assignment 4 Question 1
//
// Author: Jay Seung Yeon Lee  	 	 	 	Date: 2021 - 03 - 03
//-------------------------------------------------------------
#include <iostream>
#include <string>
#include <iomanip>
#include <math.h>

using namespace std;

int main()
{

    cout << "Enter the grades: ";
    int grade, grades, maximumGrade;
    int validator;
    double average;
    int count = 0;
    bool done = false;
    string gradeList = "";

    cout << "Enter the grade(Enter -1 when done): ";

    do
    {
        cin >> grade;
        if (grade < -1)
        {
            cout << "Grade can not be less than 0. ";
        }
        else
        {
            if (grade == -1){
                validator = 2;
            }
            else
            {
                validator = 1;
                grades += grade;
                count++;
                if (maximumGrade < grade)
                {
                    maximumGrade = grade;
                }
                else
                {
                    maximumGrade = maximumGrade;
                }
            }
        }
    } while (validator == 1);

    average = grades / count;
    cout<<grades<<endl;
    cout << "The maximum grade is " << maximumGrade << " and the average is " <<fixed<<setprecision(2)<< average;
}