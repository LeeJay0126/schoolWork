#include "LinkedList.h"
#include <iostream>
using namespace std;

LinkedList::LinkedList() {
    head = nullptr;
    tail = nullptr;
    size = 0 ;
}

LinkedList::~LinkedList() {
    cout << "Deallocating" << endl;
    clear(); 
}

void LinkedList::addFirst(int e) {
    Node *temp = new Node(e);
    temp->next = head;
    head = temp;
    size++;
    
    if (tail == nullptr)
        tail = head;
}


int LinkedList::getSize() const
{
  return size;
}

void LinkedList::clear()
{
  while (head != nullptr)
  {
    Node* temp = head;
    head = head->next;
    delete temp;
  }

  tail = nullptr;
  size = 0;
}


int LinkedList::get(int index) const {

  if (index < 0 || index > size - 1)
    throw "Out of range"; 

  Node* current = head;
  for (int i = 0; i < index; i++)
    current = current->next;

  return current->getElement();
  
}

int LinkedList::getFirst() const
{
  if (size == 0)
    throw "Index out of range";
  else
    return head->getElement();
}



int LinkedList::removeFirst()
{
  if (size == 0)
    throw "No elements in the list";
  else
  {
    Node* temp = head;
    head = head->next;
    
    if (head == nullptr) 
        tail = nullptr;
    size--;
    int element = temp->getElement();
    delete temp;
    
   
    return element;
  }
}

void LinkedList::add(int index, const int e)
{
  if (index == 0)
    addFirst(e);
  else if (index >= size)
    addLast(e);
  else
  {
    Node<T>* current = head;
    for (int i = 1; i < index; i++)
      current = current->next;
    Node<T>* temp = current->next;
    current->next = new Node<T>(e);
    (current->next)->next = temp;
    size++;
  }
}
/*
      
      
    

        void add(int index, Node) ;
      
    private:
        Node * head;
        Node * tail;
        int size;
        
};
*/
