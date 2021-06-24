#ifndef PLAYERS_H
#define PLAYERS_H

#include <iostream>
#include <string>
using namespace std;

class Players{
    
    private:
    
    int career;
    int id;
    string name;
    int firstYear;
    int lastYear;
    
    
    
    public:
    
    int getCareer() const;
    void setCareer(int start, int finish);
    string getName() const;
    void operator+=(string name);
    void setId(int id);
    int getId() const;
    void operator+=(int firstYear);
    int getFirstYear() const;
    void setLastYear(int lastYear);
    int getLastYear() const;
    void display(Players *players, int count);
    
    
};
#endif