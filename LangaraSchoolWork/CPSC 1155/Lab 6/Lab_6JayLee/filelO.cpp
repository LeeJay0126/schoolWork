//-------------------------------------------------------------
// CPSC 1155 Lab 6 Math, Charactersm Strings, Files
// Question 4 of Lab 6
//
// Author: Jay Seung Yeon Lee  	 	 	 	Date: 2021 - 02 - 10
//-------------------------------------------------------------
#include <iostream>
#include <string>
#include <cmath>
#include <cctype>
#include <iomanip>
#include <fstream>
using namespace std;

int main(){

    ofstream grades;
    grades.open("grades.txt");
    grades << "75" << " "<< "89" << " " << "90" << endl;
    grades.close();

    string score1, score2, score3;
    ifstream input;
    input.open("grades.txt");
    input >> score1 >> score2 >> score3;
    cout << score1 << score2 << score3;
    input.close();
    
}