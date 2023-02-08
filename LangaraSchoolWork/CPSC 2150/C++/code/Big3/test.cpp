#include <iostream>

using namespace std;

void h(int x, int y, int n)
{
    if (n == 0)
    {
        cout << "n=0" << std::endl;
        return;
    }
    h(x - 1, y + 1, n - 1);
    cout << "n=" << n << " " << x << " " << y << std::endl;
    h(y - 1, x + 1, n - 1);
}

int main(){
    h(5,5,3);
}