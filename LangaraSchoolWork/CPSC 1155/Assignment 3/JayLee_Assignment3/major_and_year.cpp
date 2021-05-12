//-------------------------------------------------------------
// Assignment 3 Math, Characters, Strings, and Files
// C++ prgram for Assignment 3 Question 5
//
// Author: Jay Seung Yeon Lee  	 	 	 	Date: 2021 - 02 - 20
//-------------------------------------------------------------
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{

    string characterInput;
    char character1;
    char character2;

    cout << "Enter two characters: ";
    cin >> characterInput;
    character1 = characterInput[0];
    character2 = characterInput[1];
    string faculty;
    string studentYear;

    switch (character1)
    {
    case 'M':
        faculty = "Mathmatics";
        switch (character2)
        {
        case '1':
            studentYear = "Freshman";
            cout << faculty << "    " << studentYear;
            break;
        case '2':
            studentYear = "Sophomore";
            cout << faculty << "    " << studentYear;
            break;
        case '3':
            studentYear = "Junior";
            cout << faculty << "    " << studentYear;
            break;
        case '4':
            studentYear = "Information Technology";
            cout << faculty << "    " << studentYear;
            break;
        default:
            cout << "Invalid status code";
            break;
        }
        break;
    case 'C':
        faculty = "Computer Science";
        switch (character2)
        {
        case '1':
            studentYear = "Freshman";
            cout << faculty << "    " << studentYear;
            break;
        case '2':
            studentYear = "Sophomore";
            cout << faculty << "    " << studentYear;
            break;
        case '3':
            studentYear = "Junior";
            cout << faculty << "    " << studentYear;
            break;
        case '4':
            studentYear = "Information Technology";
            cout << faculty << "    " << studentYear;
            break;
        default:
            cout << "Invalid status code";
            break;
        }
        break;
    case 'I':
        faculty = "Information Technology";
        switch (character2)
        {
        case '1':
            studentYear = "Freshman";
            cout << faculty << "    " << studentYear;
            break;
        case '2':
            studentYear = "Sophomore";
            cout << faculty << "    " << studentYear;
            break;
        case '3':
            studentYear = "Junior";
            cout << faculty << "    " << studentYear;
            break;
        case '4':
            studentYear = "Information Technology";
            cout << faculty << "    " << studentYear;
            break;
        default:
            cout << "Invalid status code";
            break;
        }
        break;
    default:
        cout << "Invalid major code";
        
        break;
    }

}