// Name: 
// Submit with Brightspace and do not post anywhere

#ifndef DLIST_H
#define DLIST_H

#include <iostream>
#include <string>
using std::string;

class D {
   public:
      D();
      bool isEmpty() const noexcept;
      void addFront(int x);
      void addBack(int x);
      friend std::ostream& operator << (std::ostream&, const D&);
      friend std::ostream& operator >> (std::ostream&, const D&);
      int length() const noexcept;
      int remFront();
      int remBack();
      friend bool operator == (const D& dA, const D& dB);
      ~D();
      D(const D&);
      D& operator = (const D&);
      // these three variables are initialized in the file D.cpp
      // you don't need to do anything, use the variables for output
      static const string BACK;
      static const string FRONT;
      static const string SEP;
   private:
      struct Node {
         Node* prev;
         int val;
         Node* next;
      };
      Node* front;
      Node* back;

      // static Node* deleteList(Node* p);




};
#endif  // DLIST_H


