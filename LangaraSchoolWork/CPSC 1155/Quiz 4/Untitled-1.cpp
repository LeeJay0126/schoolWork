
#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;
string inputString();
bool checkDigit(string);

int main()
{
    string input;
    input = inputString();
    bool validator;
    validator = checkDigit(input);

    if(checkDigit){
        cout << "Valid string";
    }else{
        cout << "Not all digits";
    }

}

string inputString()
{
    int valid;
    string input;
    do
    {
        cout << "Enter a string up to 10 characters: ";
        cin >> input;
        if(input.length() > 10 || input.length() <= 0){
            valid = 0;
        }else{
            valid = 1;
        }
    }while(valid = 1);

    return input;
}

bool checkDigit(string input){

    for(int i = 0; i < input.length(); i++){
        char str = input.substr(i,1);
        if(str < '0' || str > '9'){
            return false;
        }
    }
    return true;
}