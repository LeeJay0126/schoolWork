//-------------------------------------------------------------
// Assignment 5 C++ Functions
// CPP program for CPSC 1155 Assignment 5 Question 2
//
// Author: Jay Seung Yeon Lee  	 	 	 	Date: 2021 - 03 - 17
//-------------------------------------------------------------
#include <iostream>
#include <cctype>
#include <string>

using namespace std;

void printChars(char ch1, char ch2, int numberPerLine)
{

    if (ch1 < ch2)
    {

        int lineCount = 0;

        int d = ch1;
        int b = ch2;

        int diff = ch2 - ch1;

        for(int i = d; i <= b; i++){
            if(lineCount % numberPerLine == 0){
                cout << endl;
            }
            cout << ch1;
            cout << " ";
            ch1 += 1;
            lineCount++;
        }

        
    }
}

int main(){

    char firstCh, secondCh;
    int numPerLine;

    cout << "Enter first Character: ";
    cin >> firstCh;
    cout << "Enter second character: ";
    cin >> secondCh;
    cout << "Enter number per line: ";
    cin >> numPerLine;

    printChars(firstCh, secondCh, numPerLine );

}