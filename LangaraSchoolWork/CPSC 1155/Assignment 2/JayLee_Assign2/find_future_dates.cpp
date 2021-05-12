//-------------------------------------------------------------
// Assignment 2 Selection Statements/ Random Numbers
// C++ prgram for Assignment 2 Question 4
//
// Author: Jay Seung Yeon Lee  	 	 	 	Date: 2021 - 02 - 02
//-------------------------------------------------------------

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{

    int dayToday;
    int dayFuture;

    cout << "Enter today's day: ";
    cin >> dayToday;
    cout << "Enter the number of days elapsed since today: ";
    cin >> dayFuture;

    dayFuture = dayFuture % 6;

    if (dayToday < 7 && dayFuture >= 0)
    {
        switch (dayToday)
        {

        case 0:
            switch (dayFuture)
            {
            case 0:
                cout << "Today is Sunday and the future day is Sunday";
                break;
            case 1:
                cout << "Today is Sunday and the future day is Monday";

                break;
            case 2:
                cout << "Today is Sunday and the future day is Tuesday";
                break;
            case 3:
                cout << "Today is Sunday and the future day is Wednesday";
                break;
            case 4:
                cout << "Today is Sunday and the future day is Thursday";
                break;
            case 5:
                cout << "Today is Sunday and the future day is Friday";
                break;
            case 6:
                cout << "Today is Sunday and the future day is Saturday";
                break;
            }

        case 1:
            switch (dayFuture)
            {
            case 0:
                cout << "Today is Monday and the future day is Sunday";
                break;
            case 1:
                cout << "Today is Monday and the future day is Monday";

                break;
            case 2:
                cout << "Today is Monday and the future day is Tuesday";
                break;
            case 3:
                cout << "Today is Monday and the future day is Wednesday";
                break;
            case 4:
                cout << "Today is Monday and the future day is Thursday";
                break;
            case 5:
                cout << "Today is Monday and the future day is Friday";
                break;
            case 6:
                cout << "Today is Monday and the future day is Saturday";
                break;
            }
        case 2:
            switch (dayFuture)
            {
            case 0:
                cout << "Today is Tuesday and the future day is Sunday";
                break;
            case 1:
                cout << "Today is Tuesday and the future day is Monday";

                break;
            case 2:
                cout << "Today is Tuesday and the future day is Tuesday";
                break;
            case 3:
                cout << "Today is Tuesday and the future day is Wednesday";
                break;
            case 4:
                cout << "Today is Tuesdayand the future day is Thursday";
                break;
            case 5:
                cout << "Today is Tuesday and the future day is Friday";
                break;
            case 6:
                cout << "Today is Tuesday and the future day is Saturday";
                break;
            }
        case 3:
            switch (dayFuture)
            {
            case 0:
                cout << "Today is Wednesday and the future day is Sunday";
                break;
            case 1:
                cout << "Today is Wednesdayand the future day is Monday";

                break;
            case 2:
                cout << "Today is Wednesday and the future day is Tuesday";
                break;
            case 3:
                cout << "Today is Wednesday and the future day is Wednesday";
                break;
            case 4:
                cout << "Today is Wednesday and the future day is Thursday";
                break;
            case 5:
                cout << "Today is Wednesday and the future day is Friday";
                break;
            case 6:
                cout << "Today is Wednesday the future day is Saturday";
                break;
            }
        case 4:
            switch (dayFuture)
            {
            case 0:
                cout << "Today is Thursday and the future day is Sunday";
                break;
            case 1:
                cout << "Today is Thursday and the future day is Monday";

                break;
            case 2:
                cout << "Today is Thursday and the future day is Tuesday";
                break;
            case 3:
                cout << "Today is Thursday and the future day is Wednesday";
                break;
            case 4:
                cout << "Today is Thursday and the future day is Thursday";
                break;
            case 5:
                cout << "Today is Thursday and the future day is Friday";
                break;
            case 6:
                cout << "Today is Thursday and the future day is Saturday";
                break;
            }
        case 5:
            switch (dayFuture)
            {
            case 0:
                cout << "Today is Friday and the future day is Sunday";
                break;
            case 1:
                cout << "Today is Friday and the future day is Monday";

                break;
            case 2:
                cout << "Today is Friday and the future day is Tuesday";
                break;
            case 3:
                cout << "Today is Friday and the future day is Wednesday";
                break;
            case 4:
                cout << "Today is Friday and the future day is Thursday";
                break;
            case 5:
                cout << "Today is Friday and the future day is Friday";
                break;
            case 6:
                cout << "Today is Friday and the future day is Saturday";
                break;
            }
        case 6:
            switch (dayFuture)
            {
            case 0:
                cout << "Today is Saturday and the future day is Sunday";
                break;
            case 1:
                cout << "Today is Saturday and the future day is Monday";

                break;
            case 2:
                cout << "Today is Saturday and the future day is Tuesday";
                break;
            case 3:
                cout << "Today is Saturday and the future day is Wednesday";
                break;
            case 4:
                cout << "Today is Saturday and the future day is Thursday";
                break;
            case 5:
                cout << "Today is Saturday and the future day is Friday";
                break;
            case 6:
                cout << "Today is Saturday and the future day is Saturday";
                break;
            }
        }
    }
    else if(dayToday >= 7){
        cout << "Invalid today's date. Today's date should be an integer between 0 - 6.";
    }else if(dayFuture < 0){
        cout << "Invalid future date. It must be positive.";
    }
}