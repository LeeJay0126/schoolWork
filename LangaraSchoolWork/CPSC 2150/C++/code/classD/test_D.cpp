/* 
  Testing ONLY a few methods and operators from D
  Does not use google test 
  Not a particularly elegant test program
  Author: Gladys Monagan.
  Do not post anywhere.
*/
#include "D.h"
#include <iostream>
#include <string>
#include "DException.h"

using std::cout, std::endl;

// test the operator << 
void output_front_to_back_addBack() {
   cout << "front to back operator << \n";
   D d;
   cout << "actual    " << d;
   cout << "\nexpecting "
      << D::FRONT
      << D::BACK;
   cout << endl;
   d.addBack(11);
   cout << "actual    " << d;
   cout << "\nexpecting "
      << D::FRONT
      << 11 << D::SEP
      << D::BACK;
   cout << endl;
   d.addBack(22);
   cout << "actual    " << d; 
   cout << "\nexpecting "
      << D::FRONT
      << 11 << D::SEP
      << 22 << D::SEP
      << D::BACK;
   cout << endl;
   d.addBack(33);
   cout << "actual    " << d; 
   cout << "\nexpecting "
      << D::FRONT
      << 11 << D::SEP
      << 22 << D::SEP
      << 33 << D::SEP
      << D::BACK;
   cout << endl << endl;
}

// test the operator << 
void output_front_to_back_addFront() {
   cout << "front to back operator << \n";
   D d;
   d.addFront(66);
   cout << "actual    " << d;
   cout << "\nexpecting "
      << D::FRONT
      << 66 << D::SEP
      << D::BACK
      << endl;
   d.addFront(77);
   cout << "actual    " << d; 
   cout << "\nexpecting "
      << D::FRONT
      << 77 << D::SEP
      << 66 << D::SEP
      << D::BACK;
   cout << endl;
   d.addFront(8);
   cout << "actual    " << d; 
   cout << "\nexpecting "
      << D::FRONT
      << 8 << D::SEP
      << 77 << D::SEP
      << 66 << D::SEP
      << D::BACK;
   cout << endl;
   d.addFront(99);
   cout << "actual    " << d; 
   cout << "\nexpecting "
      << D::FRONT
      << 99 << D::SEP
      << 8 << D::SEP
      << 77 << D::SEP
      << 66 << D::SEP
      << D::BACK;
   cout << endl << endl;
}

// test the operator >>
void output_back_to_front_addBack() {
   cout << "back to front operator >> \n";
   D d;
   cout << "actual    " >> d;
   cout << "\nexpecting "
      << D::BACK
      << D::FRONT;
   cout << endl;
   d.addBack(-11);
   cout << "actual    " >> d;
   cout << "\nexpecting "
      << D::BACK
      << -11 << D::SEP
      << D::FRONT;
   cout << endl;
   d.addBack(-22);
   cout << "actual    " >> d;
   cout << "\nexpecting "
      << D::BACK
      << -22 << D::SEP
      << -11 << D::SEP
      << D::FRONT;
   cout << endl;
   d.addBack(-33);
   cout << "actual    " >> d;
   cout << "\nexpecting "
      << D::BACK
      << -33 << D::SEP
      << -22 << D::SEP
      << -11 << D::SEP
      << D::FRONT;
   cout << endl;
   d.addBack(-4);
   cout << "actual    " >> d;
   cout << "\nexpecting "
      << D::BACK
      << -4 << D::SEP
      << -33 << D::SEP
      << -22 << D::SEP
      << -11 << D::SEP
      << D::FRONT;
   cout << endl << endl;
}

// test the operator >>
void output_back_to_front_addFront() { 
   cout << "back to front operator >> \n";
   D d;
   d.addFront(77);
   cout << "actual    " >> d;
   cout << "\nexpecting "
      << D::BACK
      << 77 << D::SEP
      << D::FRONT;
   cout << endl;
   d.addFront(-88);
   cout << "actual    " >> d;
   cout << "\nexpecting "
      << D::BACK
      << 77 << D::SEP
      << -88 << D::SEP
      << D::FRONT;
   cout << endl;
   d.addFront(99);
   cout << "actual    " >> d;
   cout << "\nexpecting "
      << D::BACK
      << 77 << D::SEP
      << -88 << D::SEP
      << 99 << D::SEP
      << D::FRONT;
   cout << endl << endl;
}

// test the operator << 
void output_front_to_back_addBack_addFront() {
   cout << "front to back operator << \n";
   D d;
   d.addBack(11);
   d.addFront(22);
   d.addFront(33);
   d.addBack(44);
   cout << "actual    " << d; 
   cout << "\nexpecting "
      << D::FRONT
      << 33 << D::SEP
      << 22 << D::SEP
      << 11 << D::SEP
      << 44 << D::SEP
      << D::BACK;
   cout << endl << endl;
}

void output_back_to_front_addBack_addFront() {
   cout << "back to front operator >> \n";
   D d;
   d.addBack(11);
   d.addFront(22);
   d.addFront(33);
   d.addBack(44);
   cout << "actual    " >> d; 
   cout << "\nexpecting "
      << D::BACK
      << 44 << D::SEP
      << 11 << D::SEP
      << 22 << D::SEP
      << 33 << D::SEP
      << D::FRONT;
   cout << endl << endl;
}

int main() {
   output_front_to_back_addBack();
   output_front_to_back_addFront();
   output_back_to_front_addBack();
   output_back_to_front_addFront();
   output_front_to_back_addBack_addFront();
   output_back_to_front_addBack_addFront();
   return 0;
}

// copyright 2023 Gladys Monagan

