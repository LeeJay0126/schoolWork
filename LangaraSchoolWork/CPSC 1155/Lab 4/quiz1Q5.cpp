//-------------------------------------------------------------
// quiz 1
// Question 5 for CPSC 1155 Quiz 1
//
// Author: Jay Seung Yeon Lee  	 	 	 	Date: 2021 - 01 - 28
//-------------------------------------------------------------

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{

    double x1;
    double x2;
    double y1;
    double y2;
    double distance;

    cout << "Enter the coordinates of the points (x1, y1) :";
    cin >> x1 >> y1;
    cout << "Enter the coordinates of the points (x2, y2) :";
    cin >> x2 >> y2;

    distance = pow((pow(x2-x1,2)+pow(y2-y1,2)),0.5);

    cout << "The distance between the two points is " << distance;

}