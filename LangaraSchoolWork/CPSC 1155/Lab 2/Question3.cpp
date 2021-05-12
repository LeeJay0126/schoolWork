#include <iostream>
#include <string>
using namespace std;

/*
    This program computes the area of a wall with two windows.
    */

int main()
{
    int windows = 2;
    double window_width = 3;
    double wall_height = 8;
    double wall_width = 4;
    double window_height = 4;
    /*
    Dimensions of the wall and 
    number and dimensions of the windows 
    */
    double area = wall_width * wall_height;
    area = area - windows * window_width * window_height;
    // Computation and display of the result
    cout << "Area of wall with 2 windows is: " << area;
}