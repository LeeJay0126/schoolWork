#include <fstream>
#include "FileUtil.h"
#include <iostream>
#include <string>

using namespace std;

void FileUtility::openRead(string name, Stocks data[], int  size, string header[], int h_size){
    ifstream input;
    string line;

    input.open(name);

    getline(input, line);
    for(int x = 0, pos; x<h_size;x++){
        pos = line.find(",");
        header[x]=line.substr(0,pos > 0 ? pos: line.length());
        line.erase(0,pos+1);
    }

    int index = 0;
    int pos;
    string sname;
    double prc;

    while (getline(input,line) && index < size){
        pos = line.find(",");
        sname = line.substr(0,pos);
        prc = stod(line.substr(pos+2));

        data[index] = Stocks(sname,prc);
        index++;
    }
    input.close();
}