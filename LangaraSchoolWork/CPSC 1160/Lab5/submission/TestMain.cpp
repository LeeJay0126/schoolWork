#include "Stocks.h"
#include "FileUtil.h"
#include <iostream>
#include <iomanip>
using namespace std;

void display(string h[], int hsize, Stocks[], int size);

int main()
{
    const int SIZE = 10;
    const int HEADER_SIZE = 2;

    Stocks mystocks[SIZE];
    string header[HEADER_SIZE];

    FileUtility::openRead("lab5_data.csv", mystocks, SIZE, header, HEADER_SIZE);
    display(header, HEADER_SIZE, mystocks, SIZE);

    Stocks temp;
    for (int x = 0; x < SIZE; x++)
    {
        temp += mystocks[x];
    }
        cout << endl;
        cout << "Total price: " << temp.getPrice() << endl;
        
        cout << "Enter a price of a stock you are looking for : " ;
        double lookingPrice;
        cin >> lookingPrice;
        
        for(int j = 0; j < SIZE; j++){
            mystocks[j] == lookingPrice;
        }
        return 0;
    
}

void display(string h[], int hsize, Stocks data[], int size)
{
    for (int x = 0; x < hsize; x++)
    {
        cout << setw(15) << h[x];
    }
    cout << endl;
    for (int x = 0; x < size; x++)
    {
        cout << setw(15) << data[x].getStockName() << setw(15) << fixed << setprecision(2) << data[x].getPrice() << endl;
    }
}
