/* 
* Name:
* Student Number:
* Assignment #2, CPSC 2150 
* started by Gladys Monagan
* Do not post anywhere.

* CPSC2150 gives details of the assignment requirements
*/
#ifndef LLIST_H
#define LLIST_H
#include <string>
#include <iostream>

using std::string;

// The elements of List are kept in ascending, non-descending order
// insertion and deletion is based on value, NOT on position in the list

class  List {
   public:
      // create an empty list
      List();

      // return true if the list is empty, false otherwise
      bool isEmpty() const;

      // insert x in order 
      // precondition: 
      //    there is enough heap memory
      // postcondition: 
      //    the list has x in its proper position (based on the value of x)
      // CPSC2150: calls the overloaded function defined below
      // CPSC2150: no marks given for this function
      void insert(short x);

      // return the number of elements in the list
      // CPSC2150: calls the overloaded function defined below
      // CPSC2150: no marks given for this function
      int length() const;

      // search for x in the list
      // postcondition: 
      //    return true if x is found, false otherwise
      // CPSC2150: calls the overloaded function defined below
      bool search(short x) const;

      // return the first element of the list and 
      // return List::NOT_DEFINED if the list is empty
      short first() const;

      // return the last element of the list and 
      // return List::NOT_DEFINED if the list is empty
      short last() const;

      // first() returns NOT_DEFINED if the list is empty
      // last() returns NOT_DEFINED if the list is empty
      // CPSC2150: value needs to be defined in List.cpp
      static const short NOT_DEFINED;

      // make a new list consisting of the odd-positioned values of the list
      // the new list will have the 1st positioned value, the 3rd positioned
      // value, the 5th positioned value and so on for all the possible
      // odd-positioned values
      // (there is no 0th position in this description of the list)
      // Example: if this list has {11 22 33 44 55}, 
      // the list with odd-positioned values returned is {11 33 55}
      // the complexity of the function MUST be linear on length()
      // precondition: 
      //    there is enough heap memory
      // CPSC2150: calls the overloaded function defined below
      // CPSC2150: read implementation details
      List odds() const;

      // make a new list consisting of the even-positioned values of the list
      // the new list will have the 2nd positioned value, the 4th positioned
      // value, the 6th positioned value and so on for all the possible
      // even-positioned values
      // (there is no 0th position in this description of the list)
      // Example: if this list has {11 22 33 44 55}, 
      // the list with even-positioned values returned is {22 44}
      // the complexity of the function MUST be linear on length()
      // precondition: 
      //    there is enough heap memory
      // CPSC2150: calls the overloaded function defined below
      // CPSC2150: read implementation details
      List evens() const;

      // remove all the occurrence of x in the list (i.e. all the elements that
      // have x as the value: do NOT remove based on position)
      // postcondition:
      //    return true if at least one x was removed 
      //    and return false if no occurrences of x were removed
      // CPSC2150: calls an overloaded function defined below by you
      // CPSC2150: read implementation details
      bool removeAll(short x);

      // return true if the lfSide is equal to the rtSide 
      // meaning that the elements of both lists are equal and in the same order
      // and false otherwise
      // CPSC2150 ignore the separator (even though it's an instance variable)
      // CPSC2150: calls the function equalLists defined below
      friend bool operator == (const List& lfSide, const List& rtSide);

      // return true if the lfSide is not equal to the rtSide list, 
      // and false otherwise
      // CPSC2150 ignore the separator (even though it's an instance variable)
      friend bool operator != (const List& lfSide, const List& rtSide);
      
      // output the elements of the list in ascending order
      // (the list is always kept in ascending order)
      // for output use this format
      // -> List::START followed by
      // -> for each element: the element's value followed by sep()
      // -> except that the last element's value is NOT followed by sep()
      // -> List::END
      // an empty list is output as List::START List::END without any blanks
      // Example:
      //   3 elements would output "{41 36 999}" 
      // if List::START is "{" List::END is "}" and sep() is " "
      friend std::ostream& operator << (std::ostream&, const List&);

      // opening delimiter of the output, initialized to "{"
      static const string START;

      // closing delimiter of the output, initialized to "}"
      static const string END;

      // returns the string that is used as separator when outputting elements
      // initialized to a blank
      string sep() const;

      // sets the separator between output elements
      // if s.length() is 0, the separator is not modified
      void set_sep(string s);

      // copy constructor
      // precondition: 
      //    there is enough heap memory
      // CPSC2150: calls one or more functions defined below
      // CPSC2150: do not forget the separator
      List(const List&);

      // overloaded assignment operator
      // precondition: 
      //    there is enough heap memory
      // CPSC2150: calls one or more functions defined below
      // CPSC2150: do not forget the separator
      List& operator = (const List&);

      // destructor
      // CPSC2150: calls one or more functions defined below
      ~List();

      // CPSC2150: BONUS question
      // remove all the duplicates so that each value appears (in ascending
      // order) at most once
      // CPSC2150: calls the overloaded function defined below
      void simplify();

   private:
      // CPCSC2150: you must use the struct given here, leave it as private
      struct Node {
         short val;
         Node* link;
      };

      // CPSC2150: you CANNOT have a tail pointer for the list
      Node* head; // the beginning of the list

      // string that separates the values of the list when outputting
      // initialized in the constructor(s) 
      string separator;

      // insert x in order into the sorted linked list p
      // CPSC2150: insert is recursive
      // CPSC2150: no marks given for insert as the code was given in class
      // CPSC2150: so, yes, put "class notes" and use the code given if you want
      static Node* insert(short x, Node *p);

      // return the length of the list p
      // CPSC2150: length is recursive
      // CPSC2150: no marks given for length as the code was given in class
      // CPSC2150: so, yes, put "class notes" and use the code given if you want
      static int length(const Node *p);
      
      // search for x and return true if x is found in p, false otherwise
      // precondition: p is sorted in ascending order
      // CPSC2150: search is recursive
      static bool search(short x, const Node *p);
      
      // make a copy of p and return a pointer to the beginning of the list
      // CPSC2150: copyList is recursive
      static Node* copyList(const Node *p);

      // copy the odd positioned values of p returning a new list that is
      // in ascending order
      // CPSC2150: implementation details: odds is recursive 
      // CPSC2150: (or its overloaded function is recursive)
      // CPSC2150: you'll get at most half the marks if odds is iterative
      static Node* odds(Node* p);

      // copy the even positioned values of p returning a new list that is
      // in ascending order
      // CPSC2150: implementation details: evens is iterative
      // CPSC2150: you'll get at most half the marks if evens is recursive
      static Node* evens(Node* p);

      // remove and dispose of every node of p and return the nullptr
      static Node* deleteList(Node *p);

      // return true if all elements of p are identical to the elements of q,
      // and in the same order, false otherwise
      // CPSC2150: equalLists is recursive
      static bool equalLists(const Node* p, const Node *q);


      // CPSC2150: use your design for the overloaded function removeAll
      // CPSC2150: implementation details: the overloaded removeAll is recursive 
      // CPSC2150: (or its overloaded function removeAll is recursive)
      // CPSC2150: the recursive (helper function) of removeAll can have a loop
      // CPSC2150: you'll get at most half the marks if removeAll is iterative

      // CPSC2150: BONUS question
      static Node* simplify(Node* p);

      // CPSC2150: declare other functions below
      // you can declare other constructors too
      // you can overload the functions above as well

      // Return last node of the list with given head
      static Node* tailNode(Node *start);


};
 
#endif

// copyright 2023 Gladys Monagan

