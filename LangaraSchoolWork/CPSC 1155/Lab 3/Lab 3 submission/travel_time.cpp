//-------------------------------------------------------------
// Lab 2: Elementary Programming
// C++ prgram for Lab 3 Question 6
//
// Author: Jay Seung Yeon Lee  	 	 	 	Date: 2021 - 01 - 21
//-------------------------------------------------------------

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{

    double distanceX;
    double distanceY;
    double speedRoad;
    double speedTerrain;
    double roadSegment;

    cout << "Enter distance to the item on the X axis in km: ";
    cin >> distanceX;
    cout << "Enter distance to the item on the Y axis in km: ";
    cin >> distanceY;
    cout << "Enter speed of the machine on the road in km/h: ";
    cin >> speedRoad;
    cout << "Enter speed of the machine on the terrain in km/h: ";
    cin >> speedTerrain;
    cout << "Enter the road segment length in km: ";
    cin >> roadSegment;
    

    double segmentTime1;
    double segmentTime2;
    double terrainSegment;
    double totalTime;

    segmentTime1 = roadSegment / speedRoad;
    terrainSegment = sqrt(pow(distanceY - roadSegment, 2) + pow(distanceX, 2));
    segmentTime2 = terrainSegment / speedTerrain;
    totalTime = segmentTime1 + segmentTime2;

    cout << "Total time used for the machine to reach the item is: " << fixed << setprecision(2) << totalTime;

}