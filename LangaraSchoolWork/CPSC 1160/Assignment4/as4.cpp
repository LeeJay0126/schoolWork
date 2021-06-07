#include <iostream>
#include "MyStruct.h"
#include <string>
#include <fstream>
using namespace std;

void initialize(int size, string array[]);

void initialize(int size, Cars arr[]){

    ifstream input;
    string line;
    int index = 0;
    int pos;

    input.open("as4_data.csv");
    getline(input,line);

    while(getline(input,line)){

        pos = line.find(",");

        arr[index].make = line.substr(0,pos);
        line.erase(0,pos+1);

        pos = line.find(",");

        arr[index].year = stoi(line.substr(0,pos));
        line.erase(0,pos+1);

        pos = line.find(",");

        arr[index].available = stoi(line.substr(0,pos));
        line.erase(0,pos+1);

        
        


    }



}

// ifstream input;
//     string line;
//     int pos;
//     int index = 0;

//     input.open("Employee_Data.csv");
//     while (getline(input, line))
//     {
//         if (index == 0)
//         {
//             index++;
//         }
//         else
//         {
//             pos = line.find(",");

//             e[index - 1].id = stoi(line.substr(0, pos));
//             line.erase(0, pos + 1);

//             pos = line.find(",");

//             e[index - 1].firstName = line.substr(0, pos);
//             line.erase(0, pos + 1);

//             pos = line.find(",");

//             e[index - 1].lastName = line.substr(0, pos);
//             line.erase(0, pos + 1);

//             pos = line.find(",");

//             e[index - 1].gender = line.substr(0, pos);
//             line.erase(0, pos + 1);

//             pos = line.find(",");
//             e[index - 1].department = line.substr(0, pos);
//             line.erase(0, pos + 1);

//             pos = line.find(",");
//             e[index - 1].salary = stod(line.substr(1, pos));

//             index++;
//         }
//     }
//     input.close();