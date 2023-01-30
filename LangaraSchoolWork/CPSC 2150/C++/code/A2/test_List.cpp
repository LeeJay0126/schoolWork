/* 
* Assignment #2, CPSC 2150, Test Program
* Gladys Monagan
* Testing does not depend on google test
* Do not post anywhere
* Does not test the class List completely (far from it!!!!!!) note even close
* hardwired a blank instead of using sep()
*/
#include "List.h"
#include "List.cpp"
#include <iostream>
#include <string>
using std::cout, std::cin, std::endl, std::string;

void testOverloadedAssignmentOp() {
   List a;
   a.insert(2);
   a.insert(1);

   List b;
   b.insert(3);
   b = a;

   cout << "\na and b should be identical (as well as the internal representation)\n";
   cout << "a = " << a << endl;
   cout << "b = " << b << endl;
   cout << b << endl;

   cout << "\ninsert into b a few elements\n";
   b.insert(14);
   b.insert(11);
   b.insert(13);
   b.insert(12);
   cout << "\na and b differ now\n";
   cout << "expected a = {1 2}\n";
   cout << a << endl;
   cout << "expected b = {1 2 11 12 13 14}\n";
   cout << b << endl;
}

// test copy constructor, pass list by value
// the values of the list being passed is hardcoded to be {11 22 33 55}
void testCopyConstructor(List other) {
   cout << "\n\tinside of the function testCopyConstructor ... copy made\n\t";
   cout << other << endl;
   cout << "\n\tremove 22 from the copy \n";
   if (!other.removeAll(22)) {
      cout << "\tERROR: removed 22 should have returned true\n";
   }
   cout << "\tremove 11 from the copy \n";
   if (!other.removeAll(11)) {
      cout << "\tERROR: removed 11 should have returned true\n";
   }
   cout << "\tremove 55 from the copy \n";
   if (!other.removeAll(55)) {
      cout << "\tERROR: removed 55 should have returned true\n";
   }
   cout << "\tinsert 22 to the copy \n";
   other.insert(22);
   cout << "\texpecting {22 33} -- inside of the function \n\t";
   cout << other << endl;
   cout << "\n\treturning from the function testCopyConstructor\n";
}

// test insert into the list
void testInsert(List& a, short x, string result) {
   cout << endl; 
   a.insert(x);
   cout << "inserted '" << x << "' expecting: " << result << "\n";
   cout << a << endl; 
}

// see if removing x from the List a is correct
void testRemove(List& a, short x, string result) {
   cout << endl;
   if (a.removeAll(x)) {
      cout << "removed '" << x << "' expecting: " << result << "\n";
   }
   else {
      cout << "ERROR: removed '" << x << "' should have returned true\n";
   }
   cout << a << endl ;
}

void testSearch(List& a, short x, bool expectedValue) {
   cout << endl;
   cout << "searching for " << x << " in " << a;
   if (expectedValue) {
      if (a.search(x))
         cout << " search as expected";
      else
         cout << " NOT search which is an ERROR!!!!";
   }
   else {
      if (!a.search(x))
         cout << " NOT search as expected";
      else
         cout << " search which is an ERROR!!!!";
   }
   cout << endl;
}


////////////////////////////////////////////////////////////////////////////////
// assumes that List::START is "{", List::END is "}" sep() is " "
////////////////////////////////////////////////////////////////////////////////
int main() {
   // use the default constructor
   List a;
   cout << "expecting {}\n";
   cout << a << endl;
   
   // 1 new list is an empty list
   cout << endl;
   if (a.isEmpty())
      cout << "a is empty as expected\n";
   else
      cout << "ERROR: a should have been empty\n";

   // insert into an empty list
   testInsert(a, 3, "{3}");
   testInsert(a, 2, "{2 3}");
   testInsert(a, 1, "{1 2 3}");

   testSearch(a, 1, true);
   testSearch(a, 2, true);
   testSearch(a, 3, true);

   // test remove from middle of list
   testRemove(a, 2, "{1 3}");
   // remove 1 from the beginning of the list
   testRemove(a, 1, "{3}");
   // remove 3 as the single element
   testRemove(a, 3, "{}");

   // remove a middle element of the list
   testInsert(a, 22, "{22}");
   testInsert(a, 11, "{11 22}");
   testInsert(a, 33, "{11 22 33}");
   testInsert(a, 55, "{11 22 33 55}");
   testInsert(a, 44, "{11 22 33 44 55}");

   // copy constructor
   List b = List(a);
   testRemove(a, 44, "{11 22 33 55}");
   cout << endl;
   if (b == a)
      cout << "oh my! a and b are ebual but a should no longer have 44\n";
   else
      cout << "a and b are different as expected\n";
   // look for a removed element
   testSearch(a, 44, false);
  
   // test the copy constructor
   cout << "\nbefore the copy constructor is called\n";
   cout << a << endl;
   testCopyConstructor(a);   
   cout << "\nafter the copy constructor the original is still\n";
   cout << a << endl;
  
   // remove 11 from original
   testRemove(a, 11, "{22 33 55}");

   testOverloadedAssignmentOp();

   // the destructors are called as a and b go out of scope
  
   return 0;
}

// copyright 2023 Gladys Monagan

