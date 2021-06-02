#include "Holiday.h"
#include <iostream>
using namespace std;


Holiday::Holiday( ) : date(1, 1), parkingEnforcement(false)
{/*Intentionally empty*/}

Holiday::Holiday(int month, int day, bool theEnforcement) 
                    : date(month, day), parkingEnforcement(theEnforcement)
{/*Intentionally empty*/}

void Holiday::output( )
{
    date.output( );
    cout << endl;
    if (parkingEnforcement)
        cout << "Parking laws will be enforced.\n";
    else
        cout << "Parking laws will not be enforced.\n";
}
