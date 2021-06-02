
#ifndef HOLIDAY_H
#define HOLIDAY_H

#include "DayOfYear.h"
using namespace std;

class Holiday
{
    public:
        Holiday( );//Initializes to January 1 with no parking enforcement
        Holiday(int month, int day, bool theEnforcement);
        void output( );
    private:
        DayOfYear date;
        bool parkingEnforcement;//true if enforced
};


#endif