#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

// void swapPairsLeftToRight(int A[], int n)
// {
//     if (n > 1)
//     {
//         int temp;
//         temp = A[5- n];
//         A[5 - n] = A[5 - (n-1)];
//         A[5 - (n-1)] = temp;

//         swapPairsLeftToRight(A, n - 2);
//     }
// }

char toHexDecimal(int number)
{

    int n = number;

    switch (n)
    {
    case 10:
        n = 'A';
        break;
    case 11:
        n = 'B';
        break;
    case 12:
        n = 'C';
        break;
    case 13:
        n = 'D';
        break;
    case 14:
        n = 'E';
        break;
    case 15:
        n = 'F';
        break;
    case 16:
        n = 'G';
        break;
    }

    if (number < 10)
    {
        char m = n;
        return m;
    }

    return n;
}

int patternCounter(const string pattern, const string str, int counter, int strCount, int index, int validCount)
{
    cout << pattern[index] << "     " << str[strCount] << endl;
    if (index == pattern.length())
    {
        return counter;
    }
    if (pattern[index] == str[strCount])
    {
        if (strCount + 1 == str.length())
        {
            patternCounter(pattern, str, counter + 1, 0, index + 1, 0);
        }
        else
        {
            patternCounter(pattern, str, counter, strCount + 1, index + 1, validCount + 1);
        }
    }
    else
    {
        patternCounter(pattern, str, counter, 0, index + 1, 0);
    }

    return 0;
}

void insideInOrder(const string &pattern, int m, const string &str)
{

    int valid = patternCounter(pattern, str, 0, 0, 0, 0);
    cout << valid << endl;
    if (valid >= m)
    {
        cout << endl;
        cout << "Success!"
             << "";
    }
    else
    {
        cout << endl;
        cout << "fail!"
             << "";
    }
}

int main()
{
    insideInOrder("god save us all", 1, "go");
    // outputAsHex(ex);
}