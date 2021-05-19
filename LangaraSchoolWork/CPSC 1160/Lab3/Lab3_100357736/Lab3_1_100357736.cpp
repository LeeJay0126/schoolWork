#include <iostream>
using namespace std;
long long factorial(int);

int main(){
    cout << "Enter a non-negative integer: ";
    int n;
    cin >> n;
    cout << "Factorial of " << n << " is " << factorial(n);

    return 0;
}

long long factorial(int n){

    long long fact = 1;
    for(int i = n; n > 0; n--){
        fact *= n;
    }
    return fact;
}