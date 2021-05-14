#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    for (int i = 5; i <= 500; i+=5){
        
        cout << left << setw(5) << i;
        if(i%50 == 0){
            cout << endl;
        }
    }
}