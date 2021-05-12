//-------------------------------------------------------------
// Assignment 5 C++ Functions
// CPP program for CPSC 1155 Assignment 5 Question 6
//
// Author: Jay Seung Yeon Lee  	 	 	 	Date: 2021 - 03 - 17
//-------------------------------------------------------------
#include <iostream>
#include <string>

using namespace std;
int reverse(int);
int isPalindrome(int, int);
string reverse(string);
int isPalindrome(string, string);

int main(){
    int reverseInt, resultInt, resultString;
    string reverseString;
    cout << "Enter your string: ";
    getline(cin , reverseString);
    
    string palinString;
    palinString = reverse(reverseString);
    resultString = isPalindrome(palinString, reverseString);

    if(resultString == 1){
        cout << "String is palindrome."<<endl;
    }else{
        cout << "String is not palindrome."<< endl;
    }


    cout << "Enter your integer: ";
    cin >> reverseInt;
    resultInt = reverse(reverseInt);

    int isPalin;
    isPalin = isPalindrome(reverseInt, resultInt);

    if(isPalin == 1){
        cout << "This number is palindrome.";
    }else{
        cout << "This number is not a palindrome.";
    }

    return 0;
}

int reverse(int number){
    
    int returnNumber =0;
    for(int i = number; i > 0; i/=10){
        returnNumber *= 10;
        returnNumber += i%10;
    }

    return returnNumber;
}

int isPalindrome(int number, int reverseNumber){
    if(number == reverseNumber){
        return 1;
    }
}

string reverse(string n){
    int num = n.length();
    string result = "";
    for(int i = num-1; i >= 0; i--){
        result += n[i];
    }
    return result;
}

int isPalindrome(string n, string m){
   int validator;
    if(n == m){
        validator = 1;
    }

    return validator;
}
