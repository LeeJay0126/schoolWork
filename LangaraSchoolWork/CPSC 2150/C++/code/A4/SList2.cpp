// Name: Jay Lee
// CPSC 2150, Assignment #5

#include "SList.h"
#include <cassert>
#include <iostream>

// separates the elements when using the operator <<
const std::string SList::SEP = std::string(" ");

SList::SList()
{
    ListOne = nullptr;
    ListTwo = nullptr;
    count = 0;
    square = 1;
    threshhold = 1;
    toplist = false;
}

bool SList::isEmpty() const
{
    if (count == 0)
    {
        return true;
    }
    return false;
}

void SList::insert(int x)
{
    if (count == 0)
    {
        ListOne = new Node();
        ListOne->val = x;
        ListOne->next = nullptr;
    }
    else
    {
        Node *newNode = new Node();
        newNode->val = x;
        newNode->next = nullptr;

        Node *temp;
        temp = ListOne;
        bool flag = false;

        if (x <= temp->val)
        {
            newNode->next = temp;
            ListOne = newNode;
        }
        else
        {
            while (temp->next != nullptr)
            {
                Node *next = temp->next;
                if (x >= temp->val && x <= next->val)
                {
                    temp->next = newNode;
                    newNode->next = next;
                    flag = true;
                }
            }
            if (flag == false)
            {
                temp->next = newNode;
            }
        }
    }
    count += 1;

    if (square == threshhold)
    {
        restate();
        square += 1;
        threshhold = square * square;
    }
}

void SList::restate()
{
    if (ListTwo != nullptr)
    {
        if (ListTwo->next == nullptr)
        {
            delete ListTwo;
            ListTwo = nullptr;
        }
        else
        {
            Node2 *temp;
            temp = ListTwo;
            while (ListTwo != nullptr)
            {
                temp = ListTwo->next;
                delete ListTwo;
                ListTwo = temp;
            }
        }
    }

    ListTwo = new Node2();
    Node *anchor = ListOne;
    ListTwo->val = anchor->val;
    ListTwo->next = nullptr;
    Node2 *current = ListTwo;

    if (anchor->next != nullptr)
    {
        for (int i = 1; i < count; i++)
        {
            if (i % square == 0)
            {
                Node2 *temp = new Node2();
                temp->val = anchor->val;
                temp->link = anchor;
                current->next = temp;
                current = temp;
            }
            anchor = anchor->next;
        }
    }
}

int SList::numberOfElements() const
{
    return count;
}

bool SList::search(int x) const
{
    Node2 *anchor;
    Node2 *prev;
    Node *address;
    address = nullptr;
    prev = ListTwo;
    anchor = ListTwo;

    if (anchor == nullptr)
    {
        return false;
    }

    if (anchor->val >= x)
    {
        return false;
    }

    while (anchor != nullptr)
    {
        if (x <= anchor->val)
        {
            address = prev->link;
        }
        prev = anchor;
        anchor = anchor->next;
    }

    if (address == nullptr)
    {
        address = prev->link;
    }

    while (address != nullptr)
    {
        if (address->val == x)
        {
            return true;
        }
    }

    return false;
}

void SList::reset()
{

    if (ListTwo != nullptr)
    {
        if (ListTwo->next == nullptr)
        {
            delete ListTwo;
            ListTwo = nullptr;
        }
        else
        {
            Node2 *temp;
            temp = ListTwo;
            while (ListTwo != nullptr)
            {
                temp = ListTwo->next;
                delete ListTwo;
                ListTwo = temp;
            }
        }
    }

    if (ListOne != nullptr)
    {
        if (ListOne->next == nullptr)
        {
            delete ListOne;
            ListOne = nullptr;
        }
        else
        {
            Node *temp;
            temp = ListOne;
            while (ListOne != nullptr)
            {
                temp = ListOne->next;
                delete ListOne;
                ListOne = temp;
            }
        }
    }
    count = 0;
}

void SList::setTopListOutput(bool topListDumping)
{
    if (topListDumping == true)
    {
        toplist = true;
    }
    else
    {
        toplist = false;
    }
}

bool SList::getTopListOutput() const
{
    if (toplist == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}

SList::~SList()
{
    reset();
    toplist = false;
}

SList::SList(const SList &other)
{
    if (other.ListOne != nullptr)
    {
        Node *L1Head;
        L1Head = other.ListOne->next;

        ListOne = new Node();
        ListOne->val = other.ListOne->val;
        ListOne->next = nullptr;

        while (L1Head != nullptr)
        {
            insert(L1Head->val);
            L1Head = L1Head->next;
        }
        toplist = other.toplist;
    }
}

SList &SList::operator=(const SList &other)
{
    if (this != &other)
    {
        toplist = other.toplist;
        ListOne = other.ListOne;
        ListTwo = other.ListTwo;
        count = other.count;
        square = other.square;
        threshhold = other.threshhold;
    }

    return *this;
}

std::ostream &operator<<(std::ostream &out, const SList &list)
{
    if (list.toplist)
    {
        SList::Node2 *temp;
        temp = list.ListTwo;
        while (temp != nullptr)
        {
            out << temp->val << SList::SEP;
            temp = temp->next;
        }
    }
    else
    {
        SList::Node *temp;
        temp = list.ListOne;
        while (temp != nullptr)
        {
            out << temp->val << SList::SEP;
            temp = temp->next;
        }
    }

    return out;
}