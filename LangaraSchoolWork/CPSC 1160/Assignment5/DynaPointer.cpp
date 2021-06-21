
#include <iostream>
#include <string>
#include <time.h>
using namespace std;

int * addData(int *data,int *count);
void display(const int *data, int count);

int main() {
    int count=1;
    int *Origdata;

    srand(time(NULL));
    
    Origdata = new int[count];
    Origdata[0] = 10;
    
    for (int x=0; x < 5; x++) {
        Origdata = addData(Origdata, &count);
        display(Origdata,count);
    }
    
    
    return 0;
}

int * addData(int *data, int *count) {
    int value = (rand() %100)  + 1;
    cout << "The random value: " << value << ", current count is " << *count << endl;
    
    (*count)++ ;
    int *temp = new int[*count];
    
    for (int x=0 ; x < *count ; x++) {
        temp[x] = data[x];
    }
    
    
    temp[*count-1] = value;
    delete [] data;
    return temp;
    
    
    
    
}


void display(const int  * const data, int count) {
    for (int x=0 ; x < count; x++) {
        cout << data[x] << " " ;
    }
    cout << endl;
}