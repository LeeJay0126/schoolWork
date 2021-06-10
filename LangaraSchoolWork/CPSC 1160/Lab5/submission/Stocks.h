#ifndef STOCKS_H
#define STOCKS_H

#include <string>
using namespace std;

class Stocks{

    public:
        Stocks();
        Stocks(string, double);

        void setStockName(string);
        void setPrice(double);
        string getStockName() const;
        double getPrice() const;
        void Stocks::operator==(double samePrice)

        void operator+=(Stocks);

    private:
        string stockName;
        double price;

};
#endif