#include <iomanip>
#include <iostream>
#include <math.h>
#include <string>
#include <chrono>

using namespace std;

// class notes (quickSort algorithm given with the assignment) used
int partition(int A[], int low, int high)
{
    int pivot = A[low];
    while (low < high)
    {
        // gap is now at A[low]
        while (low < high && A[high] >= pivot)
        {
            high--;
        }
        A[low] = A[high];
        // gap is now at A[high]
        while (low < high && A[low] <= pivot)
        {
            low++;
        }
        A[high] = A[low];
    }
    A[low] = pivot;
    // return index of the pivot
    return low;
}
void quickSort(int A[], int low, int high)
{
    if (low >= high)
    {
        return;
    }
    if (low + 1 == high)
    {
        if (A[low] > A[high])
        {
            int tmp = A[low];
            A[low] = A[high];
            A[high] = tmp;
        }
        return;
    }
    int pivotIndex = partition(A, low, high);
    quickSort(A, low, pivotIndex - 1);
    quickSort(A, pivotIndex + 1, high);
}

void quickSort(int A[], int n)
{
    quickSort(A, 0, n - 1);
}

int main()
{
    // ascending array initialization
    // We will be making a reference of this array and reuse it through out the experiment
    // But for ascending arrays we don't have to do that.
    int ascArray[8000];
    for (int asc = 0; asc < 8000; asc++)
    {
        ascArray[asc] = asc;
    }

    cout << fixed << setprecision(4) << left;

    cout << setw(15) << "Quick Sort" << setw(15) << "1000 times" << setw(15) << "2000 times" << setw(15) << "4000 times" << setw(15) << "8000 times" << endl;
    int bigTrial = 1000;
    int smallTrial = 100;

    // finding 1000 iteration average time with big trial
    auto start = std::chrono::steady_clock::now();

    for (int i = 0; i < bigTrial; i++)
    {
        quickSort(ascArray, 1000);
    }

    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> diff = (end - start) / bigTrial;

    // finding 2000 iteration average time with big trial
    auto start2 = std::chrono::steady_clock::now();

    for (int i = 0; i < bigTrial; i++)
    {
        quickSort(ascArray, 2000);
    }

    auto end2 = std::chrono::steady_clock::now();
    std::chrono::duration<double> diff2 = (end2 - start2) / bigTrial;

    // finding 4000 iteration average time with small trial
    auto start3 = std::chrono::steady_clock::now();

    for (int i = 0; i < smallTrial; i++)
    {
        quickSort(ascArray, 4000);
    }

    auto end3 = std::chrono::steady_clock::now();
    std::chrono::duration<double> diff3 = (end3 - start3) / smallTrial;

    // finding 8000 iteration average time with small trial
    auto start4 = std::chrono::steady_clock::now();

    for (int i = 0; i < smallTrial; i++)
    {
        quickSort(ascArray, 8000);
    }

    auto end4 = std::chrono::steady_clock::now();
    std::chrono::duration<double> diff4 = (end4 - start4) / smallTrial;

    cout << setw(15) << "Ascending" << setw(15) << diff.count() << setw(15) << diff2.count() << setw(15) << diff3.count() << setw(15) << diff4.count() << endl;

    // Descending array
    // Resets array after every sort in descending order

    // initialize array
    int desc[8000];
    // set diff to 0 ever time
    double desc1000 = 0;

    // for 1000 iterations, with big trial
    for (int i = 0; i < bigTrial; i++)
    {
        int j = 0;
        for (int i = 999; i >= 0; i--)
        {
            desc[i] = j;
            j++;
        }
        start = std::chrono::steady_clock::now();
        quickSort(desc, 1000);
        end = std::chrono::steady_clock::now();
        diff = end - start;
        desc1000 += diff.count();
    }

    desc1000 /= bigTrial;

    int j = 0;
    for (int i = 999; i >= 0; i--)
    {
        desc[i] = j;
        j++;
    }

    double desc2000 = 0;

    // for 2000 iterations, with big trial
    for (int i = 0; i < bigTrial; i++)
    {
        j = 0;
        for (int i = 1999; i > 0; i--)
        {
            desc[i] = j;
            j++;
        }
        start = std::chrono::steady_clock::now();
        quickSort(desc, 1999);
        end = std::chrono::steady_clock::now();
        diff = end - start;
        desc2000 += diff.count();
    }

    desc2000 /= bigTrial;

    j = 0;
    for (int i = 1999; i > 0; i--)
    {
        desc[i] = j;
        j++;
    }

    double desc4000 = 0;

    // for 4000 iterations, with small trial
    for (int i = 0; i < smallTrial; i++)
    {
        j = 0;
        for (int i = 3999; i > 0; i--)
        {
            desc[i] = j;
            j++;
        }
        start = std::chrono::steady_clock::now();
        quickSort(desc, 3999);
        end = std::chrono::steady_clock::now();
        diff = end - start;
        desc4000 += diff.count();
    }

    desc4000 /= smallTrial;

    j = 0;
    for (int i = 3999; i > 0; i--)
    {
        desc[i] = j;
        j++;
    }

    double desc8000 = 0;

    // for 2000 iterations, with big trial
    for (int i = 0; i < smallTrial; i++)
    {
        j = 0;
        for (int i = 7999; i > 0; i--)
        {
            desc[i] = j;
            j++;
        }
        start = std::chrono::steady_clock::now();
        quickSort(desc, 7999);
        end = std::chrono::steady_clock::now();
        diff = end - start;
        desc8000 += diff.count();
    }

    desc8000 /= smallTrial;

    j = 0;
    for (int i = 7999; i > 0; i--)
    {
        desc[i] = j;
        j++;
    }

    cout << setw(15) << "Descending" << setw(15) << desc1000 << setw(15) << desc2000 << setw(15) << desc4000 << setw(15) << desc8000 << endl;

    return 0;
}