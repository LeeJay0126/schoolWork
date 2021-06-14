#include <iostream>
#include "CarInfo.h"
#include <string>
#include <fstream>
using namespace std;

void CarInfo::setMake(string make){
  make = make;
}

void CarInfo::setYear(int year){
  year = year;
}

void CarInfo::setQuantity(int available){
  quantity = quantity;
}

int CarInfo::getYear(){
  return year;
}

string CarInfo::getMake(){
  return make;
}

int CarInfo::getQuantity(){
  return quantity;
}


