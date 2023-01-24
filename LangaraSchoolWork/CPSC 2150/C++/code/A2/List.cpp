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
const short List::NOT_DEFINED = 0;

// for output (static variables)
// CPSC2150: nothing to do
const string List::START = string("{");
const string List::END   = string("}");

// returns the value of the string that separates the output values
// CPSC2150: nothing to do
string List::sep() const {
   return separator;
}

// if sep does not have at least one character, do nothing
// CPSC2150: nothing to do
void List::set_sep(string sep) {
   if (sep.length() != 0)
      separator = sep;
}

// constructor with no arguments, makes an empty list
// CPSC2150: finish the constructor
// CPSC2150: the separator variable is initialized correctly
List::List() : separator(string(" ")) {



}

// postcondition:
//   returns true if the list is empty, false otherwise
bool List::isEmpty() const {



}


void List::insert(short x) {



}

// precondition:
//    p is sorted in ascending order
// postcondition:
//    x is inserted into p in order and the beginning of the list is returned
List::Node* List::insert(short x, Node* p) {




}


// calculate and return the number of elements in the list this->head
int List::length() const {
   return length(this->head);
}


// return the number of elements in p
int List::length(const Node* p) {




}



// postcondition:
//    return a copy of the linked list pointed to by p
List::Node* List::copyList(const Node* p) {
 


}


// postcondition:
//    returns a new list with the odd positioned values of this->head
List List::odds() const {






}


// postcondition:
//    returns a new list with the even positioned values of this->head
List List::evens() const {




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
std::ostream& operator << (std::ostream& out, const List& list) {
   out << List::START;
   List::Node* p = list.head;




   out << List::END;
   return out;
}

// return true if all the elements of lfSide are equal and in the same
// order as those of rtSide
// CPSC2150: ignore the separator
// CPSC2150: a stand-alone operator function, not a member function
bool operator == (const List& lfSide, const List& rtSide) {





}

// return true if at least one element of lfSide differs in value or order
// to those of rtSide
// CPSC2150: ignore the separator
// CPSC2150: a stand-alone operator function, not a member function
bool operator != (const List& lfSide, const List& rtSide) {





}

// CPSC2150: copy constructor 
List::List(const List& other): separator(other.separator) {






}

// CPSC2150: overload the assignment operator

List& List::operator = (const List& other) {






}

// CPSC2150: destructor

List::~List(){




}

bool List::equalLists(const Node* p, const Node *q) {






}

// postcondition:
//    all the nodes of p are returned to the heap
//    return the nullptr
List::Node* List::deleteList(Node* p) {





}


// copyright 2023 Gladys Monagan
