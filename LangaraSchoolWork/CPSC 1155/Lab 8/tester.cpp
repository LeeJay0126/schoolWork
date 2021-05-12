
#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;
    // Draw top triangle
    for (int left_stars = 0; left_stars < n; left_stars++)
    {
        for (int column = 0; column < 2 * n - 1; column++)
        {
            int first_star = n - 1 - left_stars;
            int last_star = n - 1 + left_stars;
            if (column < first_star || column > last_star)
            {
                cout << "-";
            }
            else
            {
                cout << "*";
            }
        }
        cout << endl;
    }
    // Draw bottom triangle
     for (int left_stars = n-2; left_stars >= 0; left_stars--)
    {
        for (int column = 0; column < 2 * n - 1; column++)
        {
            int first_star = n - 1 - left_stars;
            int last_star = n - 1 + left_stars;
            if (column < first_star || column > last_star)
            {
                cout << "-";
            }
            else
            {
                cout << "*";
            }
        }
        cout << endl;
    }
}

