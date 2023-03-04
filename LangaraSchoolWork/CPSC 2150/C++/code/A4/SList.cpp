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
        Node *prev;
        temp = ListOne;
        prev = ListOne;

        if (x <= temp->val)
        {
            newNode->next = temp;
            ListOne = newNode;
        }
        else
        {
            while (temp != nullptr)
            {
                if (temp->next == nullptr)
                {
                    if (temp->val <= x)
                    {
                        temp->next = newNode;
                        break;
                    }
                    else
                    {
                        prev->next = newNode;
                        newNode->next = temp;
                    }
                }
                else if (x <= temp->val)
                {
                    prev->next = newNode;
                    newNode->next = temp;
                    break;
                }
                prev = temp;
                temp = temp->next;
            }
        }
    }
    count += 1;
    // std::cout << ListOne->val << std::endl;

    restate();
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

    if (count == threshhold)
    {
        square += 1;
        threshhold = (square + 1) * (square + 1);
    }

    ListTwo = new Node2();
    Node *anchor = ListOne;
    ListTwo->val = anchor->val;
    ListTwo->next = nullptr;
    ListTwo->link = ListOne;
    Node2 *current;
    current = ListTwo;

    if (anchor->next != nullptr)
    {
        anchor = anchor->next;
    }

    for (int i = 1; i < count; i++)
    {
        if (i % square == 0 && i != 0)
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

    if (anchor == nullptr || anchor->val > x)
    {
        return false;
    }

    while (anchor != nullptr)
    {
        if (x == anchor->val)
        {
            return true;
        }
        if (anchor->next == nullptr)
        {
            if (anchor->val >= x)
            {
                address = prev->link;
            }
            else
            {
                address = anchor->link;
            }
        }
        else if (x <= anchor->val)
        {
            address = prev->link;
            // std::cout << address->val << std::endl;
            break;
        }
        prev = anchor;
        anchor = anchor->next;
    }
    // std::cout << address->val << std::endl;
    while (address != nullptr)
    {
        if (address->val == x)
        {
            return true;
        }
        address = address->next;
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
    bool top = list.getTopListOutput();
    if (top)
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
    // out << list.count;
    return out;
}
