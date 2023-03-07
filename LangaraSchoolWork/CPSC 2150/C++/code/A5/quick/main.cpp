#include <iomanip>
#include <iostream>
#include <math.h>
#include <string>
#include <chrono>

using namespace std;

struct Node
{
    int val;
    Node *next;
};

int bigTrial = 1000;
int smallTrial = 100;

// Common Node Functions
Node *mergeHead = nullptr;
Node *insertHead = nullptr;

Node *cons(int x, Node *node)
{
    Node *p = new Node();
    p->val = x;
    p->next = node;

    return p;
}

void addToBeginningM(Node *&p, int x)
{
    Node *temp = p;
    temp = cons(x, temp);
    mergeHead = temp;
}

void addToBeginningI(Node *&p, int x)
{
    Node *temp = p;
    temp = cons(x, temp);
    insertHead = temp;
}

void addToEnd(Node *&p, int x)
{
    if (p == nullptr)
    {
        p = cons(x, nullptr);
    }
    else
    {
        Node *newNode = cons(x, nullptr);
        Node *temp;
        temp = p;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void destruct(Node *&p)
{
    Node *q;
    q = p;
    if (p != nullptr)
    {
        while (p != nullptr)
        {
            q = p->next;
            delete p;
            p = q;
        }
    }
}

// Quick Sort Section
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

void displayQuickSort()
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
        for (int k = 999; k >= 0; k--)
        {
            desc[k] = j;
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
    for (int k = 999; k >= 0; k--)
    {
        desc[k] = j;
        j++;
    }

    double desc2000 = 0;

    // for 2000 iterations, with big trial
    for (int i = 0; i < bigTrial; i++)
    {
        j = 0;
        for (int k = 1999; k > 0; k--)
        {
            desc[k] = j;
            j++;
        }
        start = std::chrono::steady_clock::now();
        quickSort(desc, 2000);
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
        for (int k = 3999; k > 0; k--)
        {
            desc[k] = j;
            j++;
        }
        start = std::chrono::steady_clock::now();
        quickSort(desc, 4000);
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
        quickSort(desc, 8000);
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

    int random[8000];
    // for 1000 iterations
    double rand1000 = 0;
    for (int i = 0; i < bigTrial; i++)
    {
        for (int k = 0; k < 1000; k++)
        {
            random[k] = rand();
        }
        start = std::chrono::steady_clock::now();
        quickSort(random, 1000);
        end = std::chrono::steady_clock::now();
        diff = end - start;
        rand1000 += diff.count();
    }
    rand1000 /= bigTrial;

    // for 2000 iterations
    double rand2000 = 0;
    for (int i = 0; i < bigTrial; i++)
    {
        for (int k = 0; k < 2000; k++)
        {
            random[k] = rand();
        }
        start = std::chrono::steady_clock::now();
        quickSort(random, 2000);
        end = std::chrono::steady_clock::now();
        diff = end - start;
        rand2000 += diff.count();
    }
    rand2000 /= bigTrial;
    // for 4000 iterations
    double rand4000 = 0;
    for (int i = 0; i < smallTrial; i++)
    {
        for (int k = 0; k < 4000; k++)
        {
            random[k] = rand();
        }
        start = std::chrono::steady_clock::now();
        quickSort(random, 4000);
        end = std::chrono::steady_clock::now();
        diff = end - start;
        rand4000 += diff.count();
    }
    rand4000 /= smallTrial;
    // for 8000 iterations
    double rand8000 = 0;
    for (int i = 0; i < smallTrial; i++)
    {
        for (int k = 0; k < 8000; k++)
        {
            random[k] = rand();
        }
        start = std::chrono::steady_clock::now();
        quickSort(random, 8000);
        end = std::chrono::steady_clock::now();
        diff = end - start;
        rand8000 += diff.count();
    }
    rand8000 /= smallTrial;

    cout << setw(15) << "Random" << setw(15) << rand1000 << setw(15) << rand2000 << setw(15) << rand4000 << setw(15) << rand8000 << endl;
}

// Merge Sort Section;
// Used class notes

Node *merge(Node *p, Node *q)
{
    if (p == nullptr)
    {
        if (q == nullptr)
        {
            return nullptr;
        }
        else
        {
            return cons(q->val, merge(nullptr, q->next));
        }
    }
    else if (q == nullptr)
    {
        return merge(q, p);
    }
    if (p->val <= q->val)
    {
        return cons(p->val, merge(p->next, q));
    }
    else
    {
        return cons(q->val, merge(p, q->next));
    }
}

void displayMerge()
{
    // Ascending
    Node *p = nullptr;
    Node *q = nullptr;

    cout << fixed << setprecision(4) << left;
    cout << endl;
    cout << setw(15) << "Merge Sort" << setw(15) << "1000 times" << setw(15) << "2000 times" << setw(15) << "4000 times" << setw(15) << "8000 times" << endl;

    for (int i = 0; i < 500; i++)
    {
        addToEnd(p, i);
    }

    for (int i = 500; i < 1000; i++)
    {
        addToEnd(q, i);
    }

    double asc1 = 0;
    auto start = std::chrono::steady_clock::now();
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> diff = (end - start);

    for (int i = 0; i < bigTrial; i++)
    {

        start = std::chrono::steady_clock::now();
        mergeHead = merge(p, q);
        end = std::chrono::steady_clock::now();
        diff = end - start;
        asc1 += diff.count();
    }

    asc1 /= bigTrial;

    destruct(p);
    destruct(q);
    destruct(mergeHead);

    for (int i = 0; i < 1000; i++)
    {
        addToEnd(p, i);
    }

    for (int i = 1000; i < 2000; i++)
    {
        addToEnd(q, i);
    }

    double asc2 = 0;

    for (int i = 0; i < bigTrial; i++)
    {

        start = std::chrono::steady_clock::now();
        mergeHead = merge(p, q);
        end = std::chrono::steady_clock::now();
        diff = end - start;
        asc2 += diff.count();
    }

    asc2 /= bigTrial;

    destruct(p);
    destruct(q);
    destruct(mergeHead);

    for (int i = 0; i < 2000; i++)
    {
        addToEnd(p, i);
    }

    for (int i = 2000; i < 4000; i++)
    {
        addToEnd(q, i);
    }

    double asc3 = 0;

    for (int i = 0; i < smallTrial; i++)
    {

        start = std::chrono::steady_clock::now();
        mergeHead = merge(p, q);
        end = std::chrono::steady_clock::now();
        diff = end - start;
        asc3 += diff.count();
    }

    asc3 /= smallTrial;

    destruct(p);
    destruct(q);
    destruct(mergeHead);

    for (int i = 0; i < 4000; i++)
    {
        addToEnd(p, i);
    }

    for (int i = 4000; i < 8000; i++)
    {
        addToEnd(q, i);
    }

    double asc4 = 0;

    for (int i = 0; i < smallTrial; i++)
    {

        start = std::chrono::steady_clock::now();
        mergeHead = merge(p, q);
        end = std::chrono::steady_clock::now();
        diff = end - start;
        asc4 += diff.count();
    }

    asc4 /= smallTrial;

    cout << setw(15) << "Ascending Sort" << setw(15) << asc1 << setw(15) << asc2 << setw(15) << asc3 << setw(15) << asc4 << endl;
}

int main()
{
    displayQuickSort();
    displayMerge();

    return 0;
}