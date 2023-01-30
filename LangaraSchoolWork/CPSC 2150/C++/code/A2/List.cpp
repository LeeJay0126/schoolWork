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
}

// postcondition:
//   returns true if the list is empty, false otherwise
bool List::isEmpty() const
{
   if (head == NULL)
   {
      return true;
   };

   return false;
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
   Node *newNode;
   newNode->val = x;

   if (start->val > x)
   {
      newNode->link = p;
      return newNode;
   }

   while (start->link != nullptr)
   {
      if (start->val <= x && start->link->val >= x)
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

// List::Node *List::tailNode(Node *start)
// {
//    Node *temp;
//    temp = start;
//    if (temp->val == NULL)
//    {
//       return temp;
//    };
//    while (temp->link != NULL)
//    {
//       temp = temp->link;
//    };
//    return temp;
// }

// calculate and return the number of elements in the list this->head
int List::length() const
{
   return length(head);
}

// return the number of elements in p
int List::length(const Node *p)
{
   const Node *cursor;
   int answer;

   answer = 0;
   for (cursor = p; cursor != NULL; cursor = cursor->link)
      ++answer;

   return answer;
}

// postcondition:
//    return a copy of the linked list pointed to by p
List::Node *List::copyList(const Node *p)
{
   Node *newList;

   if (p == NULL)
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
   List newList = List();

   if (head == NULL)
   {
      return newList;
   };

   Node *newNode;
   newNode = head;

   newList.head = head;

   int count = 1;

   while (newNode->link != nullptr)
   {
      count += 1;
      newNode = newNode->link;
      if (count % 2 == 1)
      {
         newList.insert(newNode->val);
      }
   }

   return newList;
}

// postcondition:
//    returns a new list with the even positioned values of this->head
List List::evens() const
{
   List newList = List();

   if (head == NULL)
   {
      return newList;
   };

   Node *newNode;
   newNode = head;

   newList.head = head;

   int count = 1;

   while (newNode->link != nullptr)
   {
      count += 1;
      newNode = newNode->link;
      if (count % 2 == 0)
      {
         newList.insert(newNode->val);
      }
   }

   return newList;
}

bool List::removeAll(short x)
{
   Node *temp = head;
   Node *prev = head;
   if (head->val == x)
   {
      temp = head->link;
      delete head;
      head = prev;
   }
   while (temp->link != nullptr)
   {
      if (temp->val == x)
      {
         
      }
   }
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
   List res;
   res.head = other.head;
   Node *init = other.head;

   while (init->link != nullptr)
   {
      res.insert(init->val);
      init = init->link;
   }
}

// CPSC2150: overload the assignment operator

List &List::operator=(const List &other)
{

   List res;

   res.set_sep(other.sep());
   res.head = other.head;
   Node *temp;
   temp = other.head;

   if (temp == NULL)
   {
      return res;
   }

   while (temp->link != nullptr)
   {
      res.insert(temp->val);
      temp = temp->link;
   }

   return res;
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
   if (p->val != q->val || p->link != q->link)
   {
      return false;
   };

   Node *first;
   first = p->link;
   Node *second;
   second = p->link;

   while (first != NULL)
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
