//-------------------------------------------------------------
// Assignment 2 Selection Statements/ Random Numbers
// C++ prgram for Assignment 2 Question 8
//
// Author: Jay Seung Yeon Lee  	 	 	 	Date: 2021 - 02 - 02
//-------------------------------------------------------------
#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;

int main(){

    srand(time(0));
    int choice;
    int odds1;
    int odds2;
    int odds3;

    odds1 = rand() % 5;
    odds2 = rand() % 2;
    odds3 = rand() % 20;

    cout << "You are a lone traveler in the woods. Suddenly, a bandit appears in front of you demanding you to give him all your money \n. You have the following choices: \n";
    cout << "1. Try to flee. \n";
    cout << "2. Fight! \n";
    cout << "3. Try to persuade him that robbery is bad, and he is better than that. \n";
    cout << "Please enter your choice (1,2,3): ";

    cin >> choice;

    switch(choice){

        case 1: 
            switch(odds1){
                case 0: cout << "You have successfully fleed!";
                break;
                default: cout << "You failed to flee and died";
                break;
            }break;
        case 2:
            switch(odds2){
                case 0: cout << "You have managed to defeat the bandit!";
                break;
                default: cout << "You lost in a battle and died";
                break;
            }break;
        case 3:
            switch(odds3){
                case 0: cout << "You successfully pursuaded the bandit!";
                break;
                default: cout << "You failed to pursuade the bandit and died";
                break;
            }break;
        default: 
            cout << "invalid input";
            break;

    }


    


}