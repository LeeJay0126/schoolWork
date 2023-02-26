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
    L1Tail = nullptr;
    ListTwo = nullptr;
    L2Tail = nullptr;
    count = 0;
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
        ListOne->prev = nullptr;
        ListOne->next = nullptr;
        L1Tail = ListOne;

        count += 1;
    }
    else
    {
        bool val = false;
        Node *node = ListOne;
        Node *prev = ListOne;

        while (val == false)
        {
            Node *newN = new Node();
            newN->next = nullptr;
            newN->prev = nullptr;
            newN->val = x;

            if (node == nullptr)
            {
                prev->next = newN;
                newN->prev = prev;
                L1Tail = newN;
                val = true;
            }

            if (node->val >= x)
            {
                if (node == ListOne)
                {
                    newN->next = ListOne;
                    ListOne->prev = newN;
                    ListOne = newN;
                    val = true;
                }
                else
                {
                    Node *temp;
                    temp = node->prev;
                    temp->next = newN;
                    newN->prev = temp;
                    newN->next = node;
                    node->prev = newN;
                    val = true;
                }
            }
            count += 1;
            prev = node;
            node = node->next;
        }
    }

    // if (count % 2 == 0 && count != 0)
    // {
    //     restate();
    // }
}

void SList::restate()
{
    bool val = false;
    Node *node = ListOne;
    int counter = 0;

    while (val == false)
    {

        if (node->next == nullptr)
        {
            val = true;
        }

        if (counter % 2 == 0 && counter != 0)
        {
            Node2 *temp = new Node2();
            temp->val = node->val;
            temp->prev = nullptr;
            temp->next = nullptr;
            temp->link = node;

            if (L2Tail == nullptr)
            {
                L2Tail = temp;
                val = true;
            }
            else
            {
                L2Tail->next = temp;
                temp->prev = L2Tail;
                L2Tail = temp;
                val = true;
            }
        }

        if (node->next == nullptr)
        {
            val = true;
        }

        node = node->next;
        counter += 1;
    }
}

int SList::numberOfElements() const
{
    int counter = 0;
    Node2 *temp = L2Tail;

    while (temp != nullptr)
    {
        counter += 1;
        temp = temp->next;
    }
    return counter;
}

bool SList::search(int x) const
{
    Node2 *temp = ListTwo;
    Node *address = nullptr;
    Node2 *helper;

    if (ListOne == nullptr)
    {
        return false;
    }

    if (temp == nullptr || temp->val >= x)
    {
        address = ListOne;
    }

    while (temp != nullptr)
    {
        if (temp->next == nullptr && x >= L2Tail->val)
        {
            address = L2Tail->link;
            break;
        }
        else
        {
            helper = temp->next;
            if (helper == nullptr)
            {
                address = temp->link;
                break;
            }
            else
            {
                if (x >= temp->val && x <= helper->val)
                {
                    address = temp->link;
                    break;
                }
            }
        }
        temp = temp->next;
    }

    while (address != nullptr)
    {
        if (address->val == x)
        {
            return true;
        }
        else
        {
            address = address->next;
        }
    }

    return false;
}

void SList::reset()
{

    while (ListTwo != nullptr)
    {
        if (ListTwo->next == nullptr)
        {
            delete ListTwo;
            ListTwo = nullptr;
        }
        else
        {
            Node2 *temp = ListTwo->next;
            delete ListTwo;
            ListTwo = temp;
        }
    }

    while (ListOne != nullptr)
    {
        if (ListOne->next == nullptr)
        {
            delete ListOne;
            ListOne = nullptr;
        }
        else
        {
            Node *temp = ListOne->next;
            delete ListOne;
            ListOne = temp;
        }
    }

    delete L1Tail;
    L1Tail = nullptr;
    delete L2Tail;
    L2Tail = nullptr;
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
        ListOne->prev = nullptr;
        ListOne->next = nullptr;
        L1Tail = ListOne;

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
        L1Tail = other.L1Tail;
        L2Tail = other.L2Tail;
        count = other.count;
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