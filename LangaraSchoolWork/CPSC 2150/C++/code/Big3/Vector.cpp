// code to demo big 3 for CPSC 2150 by Gladys Monagan
// Do not post anywhere
#include "Vector.h"
#include <cstdlib> // exit
#include <iostream>

Vector::Vector() : capacity(0), A(nullptr), n(0)
{
}

Vector::Vector(int len)
{
   if (len < 0)
   {
      len = 0;
      A = nullptr;
   }
   else
   {
      A = new int[len];
   }
   capacity = len;

   n = 0;
}

int Vector::length() const
{
   return n;
}

std::ostream &operator<<(std::ostream &out, const Vector &vector)
{
   const char DELIMITER = ' ';
   out << '{' << DELIMITER;
   for (int i = 0; i < vector.n; i++)
   {
      out << vector.A[i] << DELIMITER;
   }
   out << '}';
   return out;
}

// ultimate punishment with a polite message before calling it quits
int &Vector::operator[](int i)
{
   if (i < 0 || i >= n)
   {
      std::cerr << i << " is not a valid subscript\n";
      std::cerr << "subscript is out of range\n";
      exit(1);
   }
   return A[i];
}

// insert into the vector and grow the array as needed
void Vector::append(int x)
{
   if (n == capacity)
   { // enlarge A by 50%
      capacity = capacity + capacity / 2 + 1;
      int *B = new int[capacity];
      for (int i = 0; i < n; i++)
         B[i] = A[i];
      if (A != nullptr)
         delete[] A;
      A = B;
   }
   A[n++] = x;
}

// code that is used both in the copy constructor and in the overloaded
// assignment operator
void Vector::copyIntoInstanceVariables(
    int other_capacity, const int *other_A, int other_n)
{
   this->capacity = other_capacity;
   this->n = other_n;
   if (this->capacity == 0)
   {
      this->A = nullptr;
   }
   else
   {
      this->A = new int[this->capacity];
      for (int i = 0; i < n; i++)
      {
         this->A[i] = other_A[i];
      }
   }
}

// copy constructor
// precondition:
//   there is enough heap memory to make a full copy
Vector::Vector(const Vector &other)
{
#ifndef NDEBUG
   std::cerr << "copy constructor on duty &&&&&&\n";
#endif
   copyIntoInstanceVariables(other.capacity, other.A, other.n);
}

// overloaded the assignment operator
// precondition:
//   there is enough heap memory to make a full copy
Vector &Vector::operator=(const Vector &other)
{
#ifndef NDEBUG
   std::cerr << ">>>>>>>>>>>>>> the overloaded assignment operator\n";
#endif
   // when explaining we use this first
   // if (this == &other)
   //    return *this;

   // better:
   // if (this != &other) {
   //    // prevent a memory leak
   //    delete [] A;
   //
   //    // code is duplicated, same as in copy constructor: bad idea
   //    capacity = other.capacity;
   //    if (capacity == 0) {
   //       A = nullptr;
   //    }
   //    else {
   //       A = new int[capacity];
   //       n = other.n;
   //       for (int i = 0; i < n; i++) {
   //          A[i] = other.A[i];
   //       }
   //    }
   // }
   // return *this;
   if (this != &other)
   {
      delete[] A;
      copyIntoInstanceVariables(other.capacity, other.A, other.n);
   }
   return *this;
}

// destructor
Vector::~Vector()
{
#ifndef NDEBUG
   std::cerr << "*********** calling the destructor\n";
#endif
   delete[] this->A;
   // optional:
   this->A = nullptr;
}

// copyright 2023 Gladys Monagan
