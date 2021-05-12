#include <iostream>
using namespace std;
int main()
{
    
    int dollarInput;
    double const FIRST_CLASS_STAMP = 0.47;
    cout << "How many dollar bills are you inserting?: ";
    cin >> dollarInput;
    int firstClassStampNumber;
    firstClassStampNumber = dollarInput / FIRST_CLASS_STAMP;
    int pennyStampNumber;
    pennyStampNumber = (dollarInput * 100) % (int)(FIRST_CLASS_STAMP * 100);
    cout << "You can purchase " << firstClassStampNumber << " first class stamps and " << pennyStampNumber << " of penny stamps.";

}