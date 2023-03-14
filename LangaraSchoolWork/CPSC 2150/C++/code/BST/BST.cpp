// Name:

#include <iostream>
#include "BST.h"

///////////////////////////////////////////////////////////////////////////////
//

bool sameVals(const Node *p, const Node *q)
{
    int sizep = numNodes(p);
    int sizeq = numNodes(q);

    if (sizep != sizeq)
    {
        return false;
    }

    int *arrp = new int[sizep];
    int *arrq = new int[sizeq];

    toArray(arrp, 0, p);
    toArray(arrq, 0, q);

    sort(arrp, sizep);
    sort(arrq, sizeq);

    for (int i = 0; i < sizep; i++)
    {
        if (arrp[i] != arrq[i])
        {
            return false;
        }
    }

    return true;
}

void sort(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int toArray(int arr[], int index, const Node *p)
{
    if (p == nullptr)
    {
        return index;
    }
    arr[index] = p->val;
    index++;
    index = toArray(arr, index, p->left);
    index = toArray(arr, index, p->right);
    return index;
}

///////////////////////////////////////////////////////////////////////////////
bool heightBalanced(const Node *tree)
{
    if (tree == nullptr)
    {
        return true;
    }

    bool lhb = heightBalanced(tree->left);
    bool rhb = heightBalanced(tree->right);

    if (!(lhb && rhb))
    {
        return false;
    }

    int lh = height(tree->left);
    int rh = height(tree->right);

    if ((lh - rh >= -1 && lh - rh <= 0) || (lh - rh >= 0 && lh - rh <= 1))
    {
        return true;
    }

    return false;
}

int height(Node *tree)
{
    if (tree == nullptr)
    {
        return 0;
    }
    int lh = height(tree->left);
    int rh = height(tree->right);

    if (lh > rh)
    {
        return lh + 1;
    }

    return rh + 1;
}

int numNodes(const Node *tree)
{
    if (tree == nullptr)
    {
        return 0;
    }
    int lh = numNodes(tree->left);
    int rh = numNodes(tree->right);

    return lh + rh + 1;
}

int median(const Node *tree)
{
    int size = numNodes(tree);
    int *arr = new int[size];
    toArray(arr, 0, tree);
    
    return arr[size / 2];
}
