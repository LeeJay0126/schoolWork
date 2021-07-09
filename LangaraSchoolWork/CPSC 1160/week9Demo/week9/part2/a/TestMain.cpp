#include <iostream>
#include <string>
#include "GenericStack.h"
#include "GenericStack.cpp"     // include the .cpp if it has the template implementation
using namespace std;

int main()
{
  // Create a stack of int values
  Stack<int> intStack;
  for (int i = 0; i < 10; i++)
    intStack.push(i); // Push i into the stack

  while (!intStack.empty())
    cout << intStack.pop() << " ";
  cout << endl;

  // Create a stack of strings
  Stack<string> stringStack;
  stringStack.push("Chicago");
  stringStack.push("Denver");
  stringStack.push("London"); // Push London to the stack

  while (!stringStack.empty())
    cout << stringStack.pop() << " ";
  cout << endl;

  return 0;
}