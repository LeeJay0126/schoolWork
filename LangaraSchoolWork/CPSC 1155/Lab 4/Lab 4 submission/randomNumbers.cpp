//-------------------------------------------------------------
// Lab 4: Selection Statements/ Rnadom Numbers
// Question 4 for CPSC 1155 Lab 4
//
// Author: Jay Seung Yeon Lee  	 	 	 	Date: 2021 - 01 - 27
//-------------------------------------------------------------

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){

srand(time(0));
int i = rand();

cout << i << endl;
cout << RAND_MAX << endl;

srand(time(0));
int j = rand() % 2;
cout << j << endl;

srand(time(0));
int k = 1 + rand() % 6;
cout << k << endl;


/*

a. I'm getting 41 as my answer repeatedly.
b. 32767
c.
  firsttry: 28564
  secondtry: 28629
  thirdtry:  28678

*/
}
