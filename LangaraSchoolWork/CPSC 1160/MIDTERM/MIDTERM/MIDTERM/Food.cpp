#include <iostream>
#include "Food.h"
#include <string>
using namespace std;
    
    void Food::setFoodName(string foodName){
        this->foodName = foodName;
    }
    
    void Food::setServing(string serving){
        this->serving = serving;
    }
    
    void Food::operator-=(int subCal){
        this->calories = (calories - subCal);
    }
    
    void Food::setCalories(int calories){
        this->calories = calories;
    }
    
    string Food::getFoodName() const{
        return foodName;
    }
    
    string Food::getServing() const{
        return serving;
    }
    
    int Food::getCalories() const{
        return calories;
    }