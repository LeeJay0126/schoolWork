#ifndef FILEUTIL_H
#define FILEUTIL_H

#include <string>
#include "Stocks.h"

using namespace std;

class FileUtility{
    public:
    static void openRead(string, Stocks [], int size, string h[], int h_size);

    private:

};
#endif