#ifndef FOOD_H
#define FOOD_H

#include <iostream>
#include <string>
using namespace std;

class Food{
    
    private:
    
    string foodName;
    string serving;
    int calories;
    
    
    
    public:
    
    void setFoodName(string food);
    void setServing(string serving);
    void operator-=(int calories);
    string getFoodName() const;
    string getServing() const;
    int getCalories() const;
    void setCalories(int calories);
    
    
    
};
#endif