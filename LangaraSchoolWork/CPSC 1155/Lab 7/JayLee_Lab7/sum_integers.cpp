#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main(){

    int numberOfIntegers;
    int integers;

    cout << "Enter the number of integers: ";
    cin >> numberOfIntegers;
    cout << "Enter " << numberOfIntegers << " integers: ";
    int i = 0;
    int integerValue;
    int integerValueSum = 0;
    int integerAverage = 0;

    while(i < numberOfIntegers){
        cin >> integerValue;
        integerValueSum += integerValue;
        i++;
    }
    integerAverage = integerValueSum / numberOfIntegers;

    cout << "The sum of integers is " << integerValueSum << endl;
    cout << "The average of integers is " <<fixed<<setprecision(4)<< integerAverage;

}