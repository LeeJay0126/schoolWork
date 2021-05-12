//-------------------------------------------------------------
// Assignment 2 Selection Statements/ Random Numbers
// C++ prgram for Assignment 2 Question 7
//
// Author: Jay Seung Yeon Lee  	 	 	 	Date: 2021 - 02 - 02
//-------------------------------------------------------------
#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>
using namespace std;

int main()
{

    srand(time(0));
    int suit;
    int rank;

    suit = rand() % 4;
    rank = rand() % 13;

    switch (suit)
    {

    case 0:
        switch (rank)
        {
        case 0:
            cout << "The card you played is Ace of Hearts";
            break;
        case 1:
            cout << "The card you played is 2 of Hearts";
            break;
        case 2:
            cout << "The card you played is 3 of Hearts";
            break;
        case 3:
            cout << "The card you played is 4 of Hearts";
            break;
        case 4:
            cout << "The card you played is 5 of Hearts";
            break;
        case 5:
            cout << "The card you played is 6 of Hearts";
            break;
        case 6:
            cout << "The card you played is 7 of Hearts";
            break;
        case 7:
            cout << "The card you played is 8 of Hearts";
            break;
        case 8:
            cout << "The card you played is 9 of Hearts";
            break;
        case 9:
            cout << "The card you played is 10 of Hearts";
            break;
        case 10:
            cout << "The card you played is Jack of Hearts";
            break;
        case 11:
            cout << "The card you played is Queen of Hearts";
            break;
        case 12:
            cout << "The card you played is King of Hearts";
            break;
        }
        break;

    case 1:
        switch (rank)
        {
        case 0:
            cout << "The card you played is Ace of Spades";
            break;
        case 1:
            cout << "The card you played is 2 of Spades";
            break;
        case 2:
            cout << "The card you played is 3 of Spades";
            break;
        case 3:
            cout << "The card you played is 4 of Spades";
            break;
        case 4:
            cout << "The card you played is 5 of Spades";
            break;
        case 5:
            cout << "The card you played is 6 of Spades";
            break;
        case 6:
            cout << "The card you played is 7 of Spades";
            break;
        case 7:
            cout << "The card you played is 8 of Spades";
            break;
        case 8:
            cout << "The card you played is 9 of Spades";
            break;
        case 9:
            cout << "The card you played is 10 of Spades";
            break;
        case 10:
            cout << "The card you played is Jack of Spades";
            break;
        case 11:
            cout << "The card you played is Queen of Spades";
            break;
        case 12:
            cout << "The card you played is King of Spades";
            break;
        }
        break;

    case 2:
        switch (rank)
        {
        case 0:
            cout << "The card you played is Ace of Clubs";
            break;
        case 1:
            cout << "The card you played is 2 of Clubs";
            break;
        case 2:
            cout << "The card you played is 3 of Clubs";
            break;
        case 3:
            cout << "The card you played is 4 of Clubs";
            break;
        case 4:
            cout << "The card you played is 5 of Clubs";
            break;
        case 5:
            cout << "The card you played is 6 of Clubs";
            break;
        case 6:
            cout << "The card you played is 7 of Clubs";
            break;
        case 7:
            cout << "The card you played is 8 of Clubs";
            break;
        case 8:
            cout << "The card you played is 9 of Clubs";
            break;
        case 9:
            cout << "The card you played is 10 of Clubs";
            break;
        case 10:
            cout << "The card you played is Jack of Clubs";
            break;
        case 11:
            cout << "The card you played is Queen of Clubs";
            break;
        case 12:
            cout << "The card you played is King of Clubs";
            break;
        }
        break;

    case 3:
        switch (rank)
        {
        case 0:
            cout << "The card you played is Ace of Jack";
            break;
        case 1:
            cout << "The card you played is 2 of Jack";
            break;
        case 2:
            cout << "The card you played is 3 of Jack";
            break;
        case 3:
            cout << "The card you played is 4 of Jack";
            break;
        case 4:
            cout << "The card you played is 5 of Jack";
            break;
        case 5:
            cout << "The card you played is 6 of Jack";
            break;
        case 6:
            cout << "The card you played is 7 of Jack";
            break;
        case 7:
            cout << "The card you played is 8 of Jack";
            break;
        case 8:
            cout << "The card you played is 9 of Jack";
            break;
        case 9:
            cout << "The card you played is 10 of Jack";
            break;
        case 10:
            cout << "The card you played is Jack of Jack";
            break;
        case 11:
            cout << "The card you played is Queen of Jack";
            break;
        case 12:
            cout << "The card you played is King of Jack";
            break;
        }
        break;
    }
}