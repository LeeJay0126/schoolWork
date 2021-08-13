#ifndef LOADFILE_H
#define LOADFILE_H
#include "Pokemon_100357736.h"
#include "Node.h"
#include <iostream>
#include <string>
using namespace std;

class LoadFile{
    
    public:
        LoadFile();
        void operator<<(Pokemon n);
        void LoadCSV(Pokemon** head, string header[]);
    
    private:
        void pushData(Pokemon** head_ref, Pokemon data);
};

#endif