//-------------------------------------------------------------
// Lab 2: Elementary Programming
// C++ prgram for Lab 2 Question 4 
//
// Author: Jay Seung Yeon Lee  	 	 	 	Date: 2021 - 01 - 13
//-------------------------------------------------------------

#include <iostream>
#include <string>
using namespace std;

int main(){

    float discountItem;
    float regularPriceItem;
    cin >> discountItem;
    cin >> regularPriceItem;
    discountItem = discountItem * 0.8;
    float price;
    float totalPrice;
    price = discountItem + regularPriceItem;
    totalPrice = price * 1.12;
    cout << totalPrice;

}