#include <iostream>
#include <fstream>
#include <iomanip> 
#include "PQueue.h"
#include "Person.h"

#include <string>
using namespace std;

void readFile(PQueue<Person>*,string filename , string header[]) ;

template<typename T>
void printQueue(PQueue<T>& queue)
{
  cout << "======================" << endl;
  while (queue.getSize() > 0)
    cout << queue.dequeue() << " ";
  cout << endl;
}

template<typename T>
void printQueue(PQueue<T>& n, string header[]) {
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
  srand(time(NULL));
  int priority;
  
  // Queue of int values
  PQueue<int> intQueue;
  for (int i = 0; i < 10; i++) {
    priority = (rand() % 15) + 1;
    cout << "Priority = " << priority << ", value of i = " << i << endl;
    intQueue.enqueue(i,priority); // Add i to the queue
  }

  
  printQueue(intQueue);

  // Queue of strings
  PQueue<string> stringQueue;
  stringQueue.enqueue("New York",2);
  stringQueue.enqueue("Boston",3);
  stringQueue.enqueue("Denver",1);

  printQueue(stringQueue);

  // ==========================
  PQueue<Person> pQueue;
  string header[2];
    
  readFile(&pQueue,"car_data.csv", header);
  printQueue(pQueue,header);
  return 0;
}

void readFile(PQueue<Person>* q_ref, string filename, string header[])  {
    ifstream input;
    input.open(filename);
    string line;
    int pos;
    int priority;
    
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
        priority = (rand() % 15) + 1;
        cout << "Priority = " << priority << ", p.name = " << p.name << endl;
        q_ref->enqueue(p,priority);
    }
    
   
    
    input.close();
    
}