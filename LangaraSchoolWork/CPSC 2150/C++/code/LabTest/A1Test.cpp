#include <iostream>
#include <iomanip>
#include <cstdlib>

void swapPairsLeftToRight(int A[], int n)
{
    if (n > 1)
    {
        int temp;
        temp = A[5- n];
        A[5 - n] = A[5 - (n-1)];
        A[5 - (n-1)] = temp;

        swapPairsLeftToRight(A, n - 2);
    }
}

int main()
{
    int array[] = {1,2,3,4,5};

    std::cout << "Your numbers are: ";
    for (int i = 0; i < 5; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    swapPairsLeftToRight(array, 5);

    std::cout << "Your swapped numbers are: ";
    for (int i = 0; i < 5; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}