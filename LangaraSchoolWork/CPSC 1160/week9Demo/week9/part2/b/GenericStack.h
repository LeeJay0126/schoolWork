#ifndef STACK_H
#define STACK_H

template<typename T>
class Stack
{
  public:
    Stack(); // No-arg constructor
    Stack(const Stack&); // Copy constructor
    ~Stack(); // Destructor
    bool empty() const;
    T peek() const;
    void push(T value);
    T pop();
    int getSize() const;
  
  private:
    T* elements;
    int size;
    int capacity;
    void ensureCapacity();
};

#endif