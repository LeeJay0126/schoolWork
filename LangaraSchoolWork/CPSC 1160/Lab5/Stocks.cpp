#include "Stocks.h"
#include <iostream>

Stocks::Stocks(){
    setStockName("");
    setPrice(0);
}

Stocks::Stocks(string s, double d){
    setStockName(s);
    setPrice(d);
}

void Stocks::setStockName(string s){
    stockName = s;
}

void Stocks::setPrice(double p){
    price = p;
}

string Stocks::getStockName() const{
    return stockName;
}

double Stocks::getPrice() const{
    return price;
}

void Stocks::operator+=(Stocks stk){

    cout <<"============================" << endl;
    cout << stockName<<" : " << price << endl;
    cout << stk.getStockName() << " : " << stk.getPrice() << endl;

    stockName += stk.getStockName() + " , "; 
    price += stk.getPrice();
}