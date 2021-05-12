//-------------------------------------------------------------
// Assignment 6 C++ Arrays
// CPP program for CPSC 1155 Assignment 6 Question 1
//
// Author: Jay Seung Yeon Lee  	 	 	 	Date: 2021 - 03 - 31
//-------------------------------------------------------------
#include <iostream>
#include <time.h>
#include <cstdlib>
char characterGenerator(char, char);

using namespace std;

int main()
{
    srand(time(0));

    char array[10];
    array[0] = characterGenerator('A', 'Z');
    array[1] = characterGenerator('A', 'Z');
    array[2] = characterGenerator('0', '9');
    array[3] = characterGenerator('0', '9');
    array[4] = characterGenerator('!', '/');
    array[5] = characterGenerator('a', 'z');
    array[6] = characterGenerator('a', 'z');
    array[7] = characterGenerator('a', 'z');
    array[8] = characterGenerator('a', 'z');
    array[9] = characterGenerator('a', 'z');

    int random;
    char temp;

    for (int i = 0; i < 10; i++)
    {
        random = (int)(rand() % 10);
        temp = array[i];
        array[i] = array[random];
        array[random] = temp;
    }

    for(int j = 0; j < 10; j++){
        cout << array[j];
    }

}

char characterGenerator(char char1, char char2)
{
    char character;

    character = char1 + (rand() % (char2 - char1 + 1));
    
    return character;
}