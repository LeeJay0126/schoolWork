#include <iostream>
#include <fstream>
#include <iomanip> 
#include "Queue.h"
#include "Person.h"

#include <string>
using namespace std;

void readFile(Queue<Person>*,string filename , string header[]) ;

template<typename T>
void printQueue(Queue<T>& queue)
{
  while (queue.getSize() > 0)
    cout << queue.dequeue() << " ";
  cout << endl;
}

template<typename T>
void printQueue(Queue<T>& n, string header[]) {
    cout << "\nPrinting the data..." << endl;
    Person p;
    
    cout << setw(20) << header[0] << setw(15) << header[1] << endl;
    while (n.getSize() > 0) {
        p = n.dequeue();
        cout << setw(20) << p.name << setw(15) << p.car << endl;
    }
    cout << endl;
} 


int main()
{
  // Queue of int values
  Queue<int> intQueue;
  for (int i = 0; i < 10; i++)
    intQueue.enqueue(i); // Add i to the queue

  printQueue(intQueue);

  // Queue of strings
  Queue<string> stringQueue;
  stringQueue.enqueue("New York");
  stringQueue.enqueue("Boston");
  stringQueue.enqueue("Denver");

  printQueue(stringQueue);

  // ==========================
  Queue<Person> pQueue;
  string header[2];
    
  readFile(&pQueue,"car_data.csv", header);
  printQueue(pQueue,header);
  return 0;
}

void readFile(Queue<Person>* q_ref, string filename, string header[])  {
    ifstream input;
    input.open(filename);
    string line;
    int pos;
    
    
    // get header
    getline(input,line);
    pos = line.find(",");
    header[0] = line.substr(0,pos);
    header[1] = line.substr(pos+1);
    
    // get data
    Person p;
    while(getline(input,line)) {
        pos = line.find(",");    
        p.name = line.substr(0,pos);
        p.car = line.substr(pos+1);
        
        q_ref->enqueue(p);
    }
    
   
    
    input.close();
    
}