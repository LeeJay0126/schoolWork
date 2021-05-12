//-------------------------------------------------------------
// Lab 2: Elementary Programming
// C++ prgram for Lab 2 Question 7 
//
// Author: Jay Seung Yeon Lee  	 	 	 	Date: 2021 - 01 - 13
//-------------------------------------------------------------

#include <iostream>
#include <string>
using namespace std;

 int main(){

     double rectHeight;
     double rectWidth;
     double area;
     double perimeter;
     cout << "What is the height of the rectangle?: ";
     cin >> rectHeight;
     cout << "What is the width of the rectangle?: ";
     cin >> rectWidth;
     area = rectWidth * rectHeight;
     perimeter = rectHeight * 2 + rectWidth * 2;
     cout << "The area is: " << area << " and perimeter is: " << perimeter;
     

 }