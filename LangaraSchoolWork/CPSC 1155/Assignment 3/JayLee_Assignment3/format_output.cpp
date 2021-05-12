//-------------------------------------------------------------
// Assignment 3 Math, Characters, Strings, and Files
// C++ prgram for Assignment 3 Question 7
//
// Author: Jay Seung Yeon Lee  	 	 	 	Date: 2021 - 02 - 20
//-------------------------------------------------------------
#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <cctype>
#include <iomanip>
using namespace std;

int main()
{

    srand(time(0));

    string name1, name2, name3;

    cout << "Enter your name 1 : ";
    getline(cin, name1);
    cout << "Enter your name 2 : ";
    getline(cin, name2);
    cout << "Enter your name 3 : ";
    getline(cin, name3);

    char randomChar1 = static_cast<char>('A' + rand() % ('Z' - 'A' + 1));
    char randomChar2 = static_cast<char>('A' + rand() % ('Z' - 'A' + 1));
    char randomChar3 = static_cast<char>('A' + rand() % ('Z' - 'A' + 1));
    char randomChar4 = static_cast<char>('A' + rand() % ('Z' - 'A' + 1));
    char randomChar5 = static_cast<char>('A' + rand() % ('Z' - 'A' + 1));
    char randomChar6 = static_cast<char>('A' + rand() % ('Z' - 'A' + 1));
    char randomChar7 = static_cast<char>('A' + rand() % ('Z' - 'A' + 1));
    char randomChar8 = static_cast<char>('A' + rand() % ('Z' - 'A' + 1));
    char randomChar9 = static_cast<char>('A' + rand() % ('Z' - 'A' + 1));

    char randomDigit1 = static_cast<char>('0' + rand() % ('9' - '0' + 1));
    char randomDigit2 = static_cast<char>('0' + rand() % ('9' - '0' + 1));
    char randomDigit3 = static_cast<char>('0' + rand() % ('9' - '0' + 1));
    char randomDigit4 = static_cast<char>('0' + rand() % ('9' - '0' + 1));
    char randomDigit5 = static_cast<char>('0' + rand() % ('9' - '0' + 1));
    char randomDigit6 = static_cast<char>('0' + rand() % ('9' - '0' + 1));
    char randomDigit7 = static_cast<char>('0' + rand() % ('9' - '0' + 1));
    char randomDigit8 = static_cast<char>('0' + rand() % ('9' - '0' + 1));
    char randomDigit9 = static_cast<char>('0' + rand() % ('9' - '0' + 1));

    char firstId[7] = {randomChar1, randomChar2, randomChar3, '-', randomDigit1, randomDigit2, randomDigit3};
    char secondId[7] = {randomChar4, randomChar5, randomChar6, '-', randomDigit4, randomDigit5, randomDigit6};
    char thirdId[7] = {randomChar7, randomChar8, randomChar9, '-', randomDigit7, randomDigit8, randomDigit9};

    cout << "|" << left << setw(12) << "Name"
         << "|" << left << setw(20) << name1 << "|" << left << setw(20) << name2 << "|" << left << setw(20) << name3 << "|"
         << endl;
    cout << "|" << left << setw(12) << "ID"
         << "|" << left << setw(20) << firstId << "|" << left << setw(20) << secondId << "|" << left << setw(20) << thirdId << "|";
}