//-------------------------------------------------------------
// Lab 2: Elementary Programming
// C++ prgram for Lab 3 Question 7
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

    double bowBackDist;
    double stiffness;
    double arrowMass;
    double velocity;
    double potentialEnergy;
    double KineticEnergy;

    cout << "Enter the pull back distance of bow in m: ";
    cin >> bowBackDist;
    cout << "Enter the stiffness of bow in N/m: ";
    cin >> stiffness;
    cout << "Enter the arrow's mass in g: ";
    cin >> arrowMass;

    potentialEnergy = (0.5*stiffness*pow(bowBackDist,2));
    KineticEnergy = potentialEnergy;
    velocity = sqrt((KineticEnergy*2)/arrowMass);
    cout << "The velocity of arrow right after release is " << fixed << setprecision(2) << velocity << " m/s";

}