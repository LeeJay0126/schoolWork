#include "Holiday.h"
#include <iostream>
#include<cstdlib>
using namespace std;

// g++ DayOfYear.cpp Holiday.cpp TestMain.cpp -o TestHoliday


int main( )
{
    Holiday h(2, 14, true);
    cout << "Testing the class Holiday.\n";
    h.output( );
    
    return 0;
}


