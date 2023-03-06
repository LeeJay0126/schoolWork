#include <iomanip>
#include <iostream>
#include <math.h>
#include <string>
#include <chrono>
#include "Merge.h"

using namespace std;

void ascending()
{
    Merge case1;

    // ascending order
    cout << fixed << setprecision(4) << left;
    int bigTrial = 1000;
    int smallTrial = 100;

    cout << setw(15) << "Merge Sort" << setw(15) << "1000 times" << setw(15) << "2000 times" << setw(15) << "4000 times" << setw(15) << "8000 times" << endl;

    // 1000 times
    for (int i = 0; i < 500; i++)
    {
        case1.insert(true, i);
    }

    for (int i = 500; i < 1000; i++)
    {
        case1.insert(false, i);
    }

    double asc1000 = case1.repeatingMerge(bigTrial);

    case1.reset();

    for (int i = 0; i < 1000; i++)
    {
        case1.insert(true, i);
    }

    for (int i = 1000; i < 2000; i++)
    {
        case1.insert(false, i);
    }

    double asc2000 = case1.repeatingMerge(bigTrial);

    case1.reset();

    for (int i = 0; i < 2000; i++)
    {
        case1.insert(true, i);
    }

    for (int i = 2000; i < 4000; i++)
    {
        case1.insert(false, i);
    }

    double asc4000 = case1.repeatingMerge(smallTrial);

    case1.reset();

    for (int i = 0; i < 4000; i++)
    {
        case1.insert(true, i);
    }

    for (int i = 4000; i < 8000; i++)
    {
        case1.insert(false, i);
    }

    double asc8000 = case1.repeatingMerge(smallTrial);

    cout << setw(15) << "Ascending" << setw(15) << asc1000 << setw(15) << asc2000 << setw(15) << asc4000 << setw(15) << asc8000 << endl;
}

int main()
{
    Merge case1;
    // ascending();
    case1.insert(true, 1);
    case1.insert(true, 2);
    case1.insert(false, 3);
    case1.insert(false, 4);

    double po = case1.repeatingMerge(3);

    cout << po << endl;
    return 0;
}