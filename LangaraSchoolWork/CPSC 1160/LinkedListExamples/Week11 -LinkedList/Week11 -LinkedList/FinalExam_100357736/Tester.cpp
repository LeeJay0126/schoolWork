#include "Pokemon_100357736.h"
#include "LoadFile.h"
#include "Node.h"
#include <iostream>
#include <string>
#include <iomanip>

int main(){
    
    Node<Pokemon> * head = nullptr;
    string header[8];
    
    LoadFile<Pokemon> load;
    load.LoadCSV(&head, header);
    
}
