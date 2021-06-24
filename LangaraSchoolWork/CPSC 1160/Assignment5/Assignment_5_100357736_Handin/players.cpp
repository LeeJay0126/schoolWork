#include <iostream>
#include "players.h"
#include <string>
#include <fstream>
using namespace std;

int Players::getCareer() const{
    return career;
}

void Players::setCareer(int start, int finish){
    int careerLength = finish - start;
    this->career = careerLength; // this in C++ is a pointer, this in Java is an object 
}

string Players::getName() const {
    return name;
}

void Players::operator+=(string name){
    this->name = name;
}

void Players::setId(int id){
    this->id = id;
}

int Players::getId() const{
    return id;
}

int Players::getFirstYear() const{
    return firstYear;
}

int Players::getLastYear() const{
    return lastYear;
}

void Players::operator+=(int firstYear){
    this->firstYear = firstYear;
}

void Players::setLastYear(int lastYear){
    this->lastYear = lastYear;
}