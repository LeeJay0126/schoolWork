// Name:
// Submit with Brightspace and do not post anywhere

#include <string>
#include <iostream>
#include "DException.h"
#include "D.h"

using std::string, std::cerr;

D::D()
{
   front = nullptr;
   back = nullptr;
}

bool D::isEmpty() const noexcept
{
   if (this->front == nullptr && this->back == nullptr)
   {
      return true;
   }
   else
   {
      return false;
   }
}

void D::addFront(int x)
{
   if (front == nullptr)
   {
      Node *temp = new Node();

      temp->val = x;
      temp->next = nullptr;
      temp->prev = nullptr;

      front = temp;
      back = temp;
   }
   else
   {
      Node *temp = front;
      Node *newFront = new Node();
      newFront->val = x;
      newFront->next = temp;
      newFront->prev = nullptr;

      temp->prev = newFront;

      front = newFront;
   }
}

void D::addBack(int x)
{

   if (front == nullptr)
   {
      Node *temp = new Node();

      temp->val = x;
      temp->next = nullptr;
      temp->prev = nullptr;

      front = temp;
      back = temp;
   }
   else
   {
      Node *temp = back;
      Node *newBack = new Node();
      newBack->val = x;
      newBack->next = nullptr;
      newBack->prev = temp;

      temp->next = newBack;

      back = newBack;
   }
}

// nothing to do for the 3 static variable initializations
const string D::FRONT = string("[");
const string D::BACK = string("]");
const string D::SEP = string(" ");

// front to back
std::ostream &operator<<(std::ostream &out, const D &d)
{
   // cerr << "-------------------------------> operator << is not implemented\n";
   out << D::FRONT;
   // D::Node* p = new D::Node();
   // p = d->next;
   // out << d->val << D::SEP;
   D::Node *p;
   p = d.front;
   while (p != nullptr)
   {
      out << p->val << D::SEP;
      p = p->next;
   }
   out << D::BACK;
   return out;
}

// back to front
std::ostream &operator>>(std::ostream &out, const D &d)
{
   // cerr << "-------------------------------> operator >> is not implemented\n";
   out << D::BACK;
   D::Node *p;
   p = d.back;
   while (p != nullptr)
   {
      out << p->val << D::SEP;
      p = p->prev;
   }
   out << D::FRONT;
   return out;
}

int D::length() const noexcept
{
   // cerr << "-------------------------------> length is not implemented\n";

   int res = 0;
   Node *count = front;

   if (front == nullptr)
   {
      return res;
   }

   while (count != nullptr)
   {
      count = count->next;
      res += 1;
   }

   return res;
}

int D::remFront()
{
   if (isEmpty())
   {
      throw DException("error cannot remove from an empty D");
   }
   // cerr << "-------------------------------> remFront is not implemented\n";

   int val = front->val;
   if (front->next != nullptr)
   {
      Node *temp = front->next;
      delete front;
      front = temp;
      front->prev = nullptr;
   }
   else
   {
      delete front;
      front = nullptr;
      back = nullptr;
   }
   return val;
}

int D::remBack()
{
   if (isEmpty())
   {
      throw DException("error cannot remove from an empty D");
   }
   // cerr << "-------------------------------> remBack is not implemented\n";

   int val = back->val;
   if (back->prev != nullptr)
   {
      Node *temp = back->prev;
      delete back;
      back = temp;
      back->next = nullptr;
   }
   else
   {
      delete back;
      front = nullptr;
      back = nullptr;
   }

   return val;
}

bool operator==(const D &dA, const D &dB)
{
   // cerr << "-------------------------------> operator == is not implemented\n";

   D::Node *aHead;
   aHead = dA.front;
   D::Node *dHead;
   dHead = dB.front;

   if (aHead == nullptr && dHead == nullptr)
   {
      return true;
   }
   else if (aHead->val != dHead->val)
   {
      return false;
   }

   while (aHead != nullptr)
   {
      if (aHead->next->val != dHead->next->val)
      {
         return false;
      }
      aHead = aHead->next;
      dHead = dHead->next;
   }

   return true;
}

D::~D()
{
   // cerr << "-------------------------------> destructor is not implemented\n";

   if (front != nullptr)
   {
      if (front == back)
      {
         delete front;
         front = nullptr;
         back = nullptr;
      }
      else
      {

         Node *temp = front->next;

         while (front->next != back)
         {
            delete front;
            front = temp;
            temp = front->next;
         }

         delete back;
      }
   }
}

D::D(const D &other)
{
   // cerr << "-------------------------------> copy constructor is not implemented\n";

   // initializing front node for new class D
   front = new Node();

   front->val = other.front->val;
   front->next = other.front->next;
   front->prev = nullptr;

   back = front;

   Node *temp = other.front->next;

   while (temp->next != nullptr)
   {
      addBack(temp->val);
   }

   // return newD;
}

D &D::operator=(const D &other)
{
   // cerr << "-------------------------------> overloaded operator = is not implemented\n";
   if (this != &other)
   {

      front = other.front;
      back = other.back;
   }
   return *this;
}
