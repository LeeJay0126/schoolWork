// Name:
// Student Number:
// Do not post anywhere.
// Started by Gladys Monagan, CPSC 2150

#ifndef SLIST_H
#define SLIST_H

#include <iostream>

/*
 * A skip list that keeps the values in ascending order.
 * It supports insertion into the skip list but no deletions.
 */
class SList
{
public:
   // create an empty list
   SList();

   // return true if the list is empty, false otherwise
   bool isEmpty() const;

   // insert an element in ascending order
   void insert(int x);

   //Sets the elements in top array again if the count changes
   void restate();

   // return the number of elements in the skip list
   int numberOfElements() const;

   // return true if x is found in the list, false otherwise
   bool search(int x) const;

   // delete/deallocate the skip list completely and reset to an empty list
   // getTopListOutput() is left as is
   void reset();

   SList &operator=(const SList &other);

   SList(const SList &other);

   ~SList();

   // output the list in ascending order with SList::SEP after each element
   // precondition:
   //    if setTopListOutput(true)
   //          has been called previously,
   //          all the elements of the top list are output
   //    if setTopListOutput(false)
   //          has been called previously (the default value)
   //          all the elements of the bottom list are output
   //
   // the empty list outputs nothing, not even SList::SEP
   friend std::ostream &operator<<(std::ostream &out, const SList &list);

   // string that separates the values of the list when outputting
   static const std::string SEP;

   // determines if the top list or the bottom list is output
   // postcondition:
   //    after setTopListOutput(true), the top list will be output
   //    after setTopListOutput(false), all the elements are output
   void setTopListOutput(bool topListDumping);

   // return true means that the top list will be be output
   // return false means that the top list will be be output
   bool getTopListOutput() const;

private:
   struct Node
   {
      Node *next;
      int val;
   };

   struct Node2
   {
      Node2 *next;
      Node *link;
      int val;
   };

   Node *ListOne;
   Node2 *ListTwo;
   int count;
   int square;
   int threshhold;
   bool toplist;
};
#endif // SLIST_H
