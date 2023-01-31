// code to demo big 3 for CPSC 2150 by Gladys Monagan
// Do not post anywhere
#ifndef VECTOR_H 
#define VECTOR_H

#include <iostream>

class Vector {
   public:
      // default constructor
      Vector();

      // create an array with capacity=len empty slots
      // if len < 0, capacity is set to 0
      Vector(int len);

      // return the number of elements
      int length() const;

      // appends x to the end of the array
      // the only way to insert into the vector
      void append(int x); 

      // supports v[i] = x and x = v[i]
      // a range error will produce the ultimate punishment
      int & operator[] (int i);

      // output in the order in which they are in the array 
      // from first to last in this format:
      //    -> the character '{' followed by a blank
      //    -> for each element: the element's value followed by a blank
      //    -> the character '}'
      // Example: 3 elements would output "{ 41 36 999 }" 
      friend std::ostream& operator << (std::ostream&, const Vector&);

      // copy constructor
      // we assuming that there is enough heap memory to make a copy
      Vector(const Vector&);

      // overloaded assignment operator
      // we assuming that there is enough heap memory to make a copy
      Vector& operator = (const Vector&);

      // destructor
      ~Vector();     
   private:
      // actual capacity of array 
      int capacity;
      // the array
      int *A; 
      // number of elements stored ( n <= capacity )
      int n;

      // copy into capacity, into n, and into A
      // allocating space for A
      void copyIntoInstanceVariables(int, const int*, int);
};
#endif

// copyright 2023 Gladys Monagan


