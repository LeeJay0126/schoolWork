#include "LinkedList.h"
#include <iostream>
using namespace std;

void display (const LinkedList&);


int main() {
    srand(time(0));
    Node *temp;
    LinkedList theList;
  
    int val;
    for (int x = 0 ; x < 4; x++ ){
        val = rand()%100;;
        theList.addFirst(val);
        
        cout << val << " "; 
    }
    
    cout << endl;
    display(theList);
    
    cout << endl;
    cout << "First element " << theList.getFirst() << endl;
    cout << "Delete first element " << theList.removeFirst() << endl;
    
    
    display(theList);
   
    return 0;
}


void display (const LinkedList &list) {
    cout << "\nPrinting the data..." << endl;
    //
    for (int i = 0; i < list.getSize() ; i++)
    {
        cout << list.get(i) << " ";
    }
    cout << endl;
} 
