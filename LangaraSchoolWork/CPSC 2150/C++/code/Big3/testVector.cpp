// code to demo big 3 for CPSC 2150 by Gladys Monagan
// Do not post anywhere

#include "Vector.h"
#include <iostream>

using std::cout, std::endl;

Vector f() {
   Vector v;
   v.append(1);
   cout << "supposedly calling the copy constructor but the compiler might optimize\n";
   return v;
}

int main() {
   Vector v;
   cout << "empty vector v = " << v << endl;
   Vector u(5);
   u.append(1);
   u.append(2);
   u.append(3);
   cout << "u with 1 2 3 in vector\tu = " << u << endl;
   {
      Vector w;
      for (int i = 1; i < 6; i++) {
         w.append(-i);
      }
      cout << "a vector that will go out of scope w = " << w << endl;
      // calls the destructor
   }
   // won't compile because w is out of scope
   // Vector a(w);
   // another way of calling the copy constructor
   Vector a = u;
   cout << "a copied from u,\ta = " << a << endl;
   
   a.append(4);
   a.append(5);
   cout << "a independent from u,\ta = " << a << endl;
   cout << "u is still as before,\tu = " << u << endl;
   v = a;
   cout << "v was assigned a,\tv = " << v << endl;

   Vector b = f();
   cout << "b[0] = " << b[0] << endl;
   return 0;
}

// copyright 2023 Gladys Monagan
