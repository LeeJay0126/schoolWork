#include <iostream>
#include <math.h>

using namespace std;

int main()
{

    int rows = 0;
    cout << "Enter your rows : ";
    cin >> rows;

    for (int i = 1; i <= rows; i++)
    {
        if (i % 2 == 0)
        {
            for (int j = rows; j >= 1; j--)
            {
                if (i < j)
                {
                    cout << " ";
                }
                else
                {
                    cout << "*";
                }
            }
            cout << endl;
        }else{
            for (int j = rows; j >= 1; j--)
            {
                if (i < j)
                {
                    cout << " ";
                }
                else
                {
                    cout << "+";
                }
            }
            cout << endl;
        }
       
    }
}