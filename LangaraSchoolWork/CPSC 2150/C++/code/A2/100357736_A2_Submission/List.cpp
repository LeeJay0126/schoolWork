/*
Name:
Assignment #2, CPSC 2150 (expand code started by Gladys Monagan)
Do not post anywhere.
CPSC2150: fill in code and comment as needed
*/

#include "List.h"
#include <string>
#include <iostream>

using std::string;

// CPSC2150 define NOT_DEFINED, do not use 0 (!!!!!!!!!!) edit the code below
// with a value unlikely to occur in the list
const short List::NOT_DEFINED = -21921;

// for output (static variables)
// CPSC2150: nothing to do
const string List::START = string("{");
const string List::END = string("}");

// returns the value of the string that separates the output values
// CPSC2150: nothing to do
string List::sep() const
{
   return separator;
}

// if sep does not have at least one character, do nothing
// CPSC2150: nothing to do
void List::set_sep(string sep)
{
   if (sep.length() != 0)
      separator = sep;
}

// constructor with no arguments, makes an empty list
// CPSC2150: finish the constructor
// CPSC2150: the separator variable is initialized correctly
List::List() : separator(string(" "))
{
   head = nullptr;
}

// postcondition:
//   returns true if the list is empty, false otherwise
bool List::isEmpty() const
{
   // if (head == nullptr)
   // {
   //    std::cout << "hi" << std::endl;
   // }
   if (head == nullptr)
   {
      return true;
   }
   else
   {
      return false;
   }
}

void List::insert(short x)
{
   Node *temp;
   temp = insert(x, head);
   if (temp != head)
   {
      head = temp;
   }
}

// precondition:
//    p is sorted in ascending order
// postcondition:
//    x is inserted into p in order and the beginning of the list is returned
List::Node *List::insert(short x, Node *p)
{
   Node *start = p;
   Node *newNode = new Node;
   newNode->val = x;
   newNode->link = nullptr;

   if (p == nullptr)
   {
      return newNode;
   }

   if (start->val > x)
   {
      newNode->link = p;
      return newNode;
   }

   while (start->link != nullptr)
   {
      Node *next;
      next = start->link;
      if (start->val <= x && next->val >= x)
      {
         newNode->link = start->link;
         start->link = newNode;
         return p;
      }
      start = start->link;
   }

   start->link = newNode;
   newNode->link = nullptr;
   return p;
}

// calculate and return the number of elements in the list this->head
int List::length() const
{
   return length(head);
}

// return the number of elements in p
int List::length(const Node *p)
{
   Node *cursor = new Node;
   int answer = 0;

   if (p == nullptr)
   {
      return answer;
   }
   else
   {
      cursor->val = p->val;
      cursor->link = p->link;
      answer += 1;
   }
   // for (cursor->link = p->link; cursor != nullptr; cursor = cursor->link)
   //    ++answer;

   while (cursor->link != nullptr)
   {
      cursor = cursor->link;
      answer += 1;
   }

   return answer;
}

// postcondition:
//    return a copy of the linked list pointed to by p
List::Node *List::copyList(const Node *p)
{
   Node *newList = new Node;

   if (p == nullptr)
   {
      return newList;
   }
   else
   {
      newList->val = p->val;
      newList->link = copyList(p->link);

      return newList;
   }
}

// postcondition:
//    returns a new list with the odd positioned values of this->head
List List::odds() const
{
   List newList;

   if (head == nullptr)
   {
      return newList;
   };

   Node *trackNode;
   trackNode = head;

   Node *newNode = new Node;
   newNode->val = head->val;
   newNode->link = nullptr;
   newList.head = newNode;

   int count = 1;

   while (trackNode->link != nullptr)
   {
      count += 1;
      trackNode = trackNode->link;
      if (count % 2 == 1)
      {
         newList.insert(trackNode->val);
      }
   }

   return newList;
}

// postcondition:
//    returns a new list with the even positioned values of this->head
List List::evens() const
{
   List newList;

   if (head == nullptr)
   {
      return newList;
   };

   Node *trackNode;
   trackNode = head->link;

   Node *newNode = new Node;
   newNode->val = trackNode->val;
   newNode->link = nullptr;
   newList.head = newNode;

   int count = 2;

   while (trackNode->link != nullptr)
   {
      count += 1;
      trackNode = trackNode->link;
      if (count % 2 == 0)
      {
         newList.insert(trackNode->val);
      }
   }

   return newList;
}

bool List::removeAll(short x)
{
   Node *temp = head;
   Node *prev = head;
   Node *current = head;

   bool validator = false;

   if (head == nullptr)
   {
      return validator;
   }

   while (current != nullptr)
   {
      if (current->val == x)
      {
         if (current == head)
         {
            if (head->link == nullptr)
            {
               head = nullptr;
               validator = true;
            }
            else
            {
               head = head->link;
               validator = true;
            }
         }
         else
         {
            if (current->link != nullptr)
            {
               temp = current->link;
               prev->link = temp;
               delete current;
               current = temp;
               validator = true;
            }
            else
            {
               prev->link = nullptr;
               delete current;
               validator = true;
            }
         }
      }
      prev = current;
      current = current->link;
   }

   return validator;
}

bool List::search(short x) const
{
   return search(x, head);
}

bool List::search(short x, const Node *p)
{
   if (p == nullptr)
   {
      return false;
   }
   if (x == p->val)
   {
      return true;
   }
   if (x < p->val)
   {
      return false;
   }
   return search(x, p->link);
}

short List::first() const
{
   if (head == nullptr)
   {
      return List::NOT_DEFINED;
   };

   return head->val;
}

short List::last() const
{
   Node *temp;
   temp = head;

   if (head == nullptr)
   {
      return List::NOT_DEFINED;
   };

   while (temp->link != nullptr)
   {
      temp = temp->link;
   };

   return temp->val;
}

// postcondition:
//    outputs in the form
//       List::START
//       value list.sep()
//       value list.sep()
//       ...
//       value
//       List::END
//
//       an empty list is output
//       List::START
//       List::END
//
// CPSC2150: a stand-alone operator function, not a member function
// CPSC2150: the function has been started for you, it is not complete
std::ostream &operator<<(std::ostream &out, const List &list)
{
   out << List::START;
   List::Node *p = list.head;

   while (p != nullptr)
   {
      out << p->val;
      if (p->link != nullptr)
      {
         out << list.sep();
      }
      p = p->link;
   }

   out << List::END;
   return out;
}

// return true if all the elements of lfSide are equal and in the same
// order as those of rtSide
// CPSC2150: ignore the separator
// CPSC2150: a stand-alone operator function, not a member function
bool operator==(const List &lfSide, const List &rtSide)
{
   return List::equalLists(lfSide.head, rtSide.head);
}

// return true if at least one element of lfSide differs in value or order
// to those of rtSide
// CPSC2150: ignore the separator
// CPSC2150: a stand-alone operator function, not a member function
bool operator!=(const List &lfSide, const List &rtSide)
{
   bool res = List::equalLists(lfSide.head, rtSide.head);
   return (!res);
}

// CPSC2150: copy constructor
List::List(const List &other) : separator(other.separator)
{

   Node *newHead = new Node;
   newHead->val = other.head->val;
   newHead->link = nullptr;

   this->head = newHead;

   Node *temp = other.head->link;

   while (temp != nullptr)
   {
      this->insert(temp->val);
      temp = temp->link;
   }
}

// CPSC2150: overload the assignment operator

List &List::operator=(const List &other)
{

   this->set_sep(other.sep());

   delete this->head;

   if (other.head != nullptr)
   {

      Node *newHead = new Node;
      newHead->val = other.head->val;
      newHead->link = nullptr;

      this->head = newHead;

      if (other.head->link != nullptr)
      {
         Node *temp;
         temp = other.head->link;

         while (temp != nullptr)
         {
            this->insert(temp->val);
            temp = temp->link;
         }
      }
   }
}

// CPSC2150: destructor

List::~List()
{
   Node *temp;

   while (head != nullptr)
   {
      temp = head->link;
      delete head;
      head = temp;
   }

   delete temp;
}

bool List::equalLists(const Node *p, const Node *q)
{

   Node *first;
   Node *second;

   if (p->link != nullptr && q->link != nullptr)
   {
      first = p->link;
      second = p->link;
   }

   if (p->val != q->val || first->val != second->val)
   {
      return false;
   };

   while (first != nullptr)
   {
      if (first->val == second->val)
      {
         first = first->link;
         second = second->link;
      }
      else
      {
         return false;
      }
   };

   return true;
}

// postcondition:
//    all the nodes of p are returned to the heap
//    return the nullptr
List::Node *List::deleteList(Node *p)
{
   if (p->link == nullptr)
   {
      delete p;
      return nullptr;
   }

   Node *temp;
   while (p->link != nullptr)
   {
      temp = p->link;
      delete p;
      p = temp;
   }

   return p;
}

// copyright 2023 Gladys Monagan
