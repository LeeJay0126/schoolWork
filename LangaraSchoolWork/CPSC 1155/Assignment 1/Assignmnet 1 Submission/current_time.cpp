//-------------------------------------------------------------
// Lab 2: Elementary Programming
// C++ prgram for Lab 3 Question 7
//
// Author: Jay Seung Yeon Lee  	 	 	 	Date: 2021 - 01 - 21
//-------------------------------------------------------------

#include <iostream>
#include <string>
#include <time.h>
using namespace std;

int main()
{

    time_t timer;
    struct tm y2k = {0};
    int seconds;

    y2k.tm_hour = 0;
    y2k.tm_min = 0;
    y2k.tm_sec = 0;
    y2k.tm_year = 100;
    y2k.tm_mon = 0;
    y2k.tm_mday = 1;

    time(&timer);

    seconds = difftime(timer, mktime(&y2k));

    int year;
    int months;
    int days;
    int hours;
    int minutes;

    year = seconds/31536000;
    seconds = seconds % 31536000;
    months = seconds/ 2628000;
    seconds %= 2628000;
    days = seconds / 86400;
    seconds %= 86400;
    hours = seconds / 3600;
    seconds %= 3600;
    minutes = seconds / 60;
    seconds %= 60;


    cout << "Current time is : " << hours << ":" << minutes << ":" << seconds << " PST" << endl;

    int timeZoneOffSet;

    cout << "Enter the time zone offset to PST: ";
    cin >> timeZoneOffSet;

    hours += timeZoneOffSet;

    cout << "The current time in your time zone is : " << hours << ":" << minutes << ":" << seconds << " PST" << endl;

    

}