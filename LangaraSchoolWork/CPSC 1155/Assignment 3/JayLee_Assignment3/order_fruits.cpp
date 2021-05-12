//-------------------------------------------------------------
// Assignment 3 Math, Characters, Strings, and Files
// C++ prgram for Assignment 3 Question 2
//
// Author: Jay Seung Yeon Lee  	 	 	 	Date: 2021 - 02 - 20
//-------------------------------------------------------------
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main(){

    string firstFruit, secondFruit, thirdFruit;
    cout << "Enter the first fruit: ";
    cin >> firstFruit;
    cout << "Enter the second fruit: ";
    cin >> secondFruit;
    cout << "Enter the third fruit: ";
    cin >> thirdFruit;

    char fruitFirst = toupper(firstFruit[0]);
    char fruitSecond = toupper(secondFruit[0]);
    char fruitThird = toupper(thirdFruit[0]);
    char temp = ' ';
    string stringTemp = "";

    cout << fruitFirst;
    
    if(fruitFirst < fruitSecond){

        temp = fruitFirst;
        fruitFirst = fruitSecond;
        fruitSecond = temp;
        
        stringTemp = firstFruit;
        firstFruit = secondFruit;
        secondFruit = stringTemp;

    }
    if(fruitSecond < fruitThird){

        temp = fruitSecond;
        fruitSecond = fruitThird;
        fruitThird = temp;

        stringTemp = secondFruit;
        secondFruit = thirdFruit;
        thirdFruit = stringTemp;

    }
      if(fruitFirst < fruitSecond){

        temp = fruitFirst;
        fruitFirst = fruitSecond;
        fruitSecond = temp;

        stringTemp = firstFruit;
        firstFruit = secondFruit;
        secondFruit = stringTemp;

    }
    

    cout << "The three fruits in an alphabetical descending order are " << firstFruit << " , " << secondFruit << " , " << thirdFruit << " . ";

}