//-------------------------------------------------------------
// Assignment 4 Loops
// CPP program for CPSC 1155 Assignment 4 Question 3
//
// Author: Jay Seung Yeon Lee  	 	 	 	Date: 2021 - 03 - 03
//-------------------------------------------------------------
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

int main(){

    srand(time(0));

    int n;
    n = (rand()%200)+1;
    int answer;
    int guess = 0;
    int count = 0;

    cout << "A number is generated, make a guess: ";
    do{
        cin >> guess;
        if(guess < 1 || guess > 200){
            cout << "Invalid input, try again!";
            count++;
            answer=1;
        }
        if(guess >n){
            cout << "Your guess is too big, make a guess: ";
            answer = 1;
            count++;
        }else if(guess == n){
            cout << "You got it right! It took " << count << " times to get the correct answer.";
            answer = 2;
        }else{
            cout << "Your guess is too small, make a guess: ";
            count++;
            answer=1;
        }

    }while(answer == 1);

}