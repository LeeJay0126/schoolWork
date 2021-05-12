//-------------------------------------------------------------
// Lab 4
// Question 5 for CPSC 1155 Lab 4
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

    int normalRoute;
    int bayBridge;
    int const RUSHHOUR_B = 45;
    int const REGULARHOUR_N = 40;
    int const RUSHHOUR_N = 60;
    int const REGULARHOUR_B = 30;
    int userInputRoute;
    int userInputHours;

    cout << "Are you travelling by normal route or Bay bridge? Enter 1 for normal route and 2 for bay bridge. : ";
    cin >> userInputRoute;
    cout << "Are you travelling during rush hour? Enter  1 if yes, 0 if not. : ";
    cin >> userInputHours;

    if (userInputRoute == 1){

    if (userInputHours == 1){
        cout << "Your travelling time will be " << RUSHHOUR_N << " minutes";
    }else{
        cout << "Your travelling time will be " << REGULARHOUR_N << " minutes";
    }

}else if (userInputRoute == 2){

     if (userInputHours == 1){
        cout << "Your travelling time will be " << RUSHHOUR_B << " minutes";
    }else{
        cout<< "Your travelling time will be " << REGULARHOUR_B << " minutes";
    }

}


}