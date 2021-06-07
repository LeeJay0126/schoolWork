#include <iostream>
#include <string>
#include "swapLib.h"
using namespace std;

int main(){
    
    SwapUtil su;
    
    // swapping two integers
    int a = 10 ;
    int b = 20 ;
    cout << "a = " << a << ", b = " << b << endl;
    su.swap(&a,&b);
    cout << "a = " << a << ", b = " << b << " -- after calling swap -- " << endl;
    
    
    // swapping two strings
    string s1 = "Johnny" ;
    string s2 = "Matrix" ;
    cout << "s1 = " << s1 << ", s2 = " << s2 << endl;
    su.swap(&s1,&s2);
    cout << "s1 = " << s1 << ", s2 = " << s2 <<" -- after calling swap -- " << endl;
    
    
    // swapping two double
    double d1 = 30.5 ;
    double d2 = 123 ;
    cout << "d1 = " << d1 << ", d2 = " << d2 << endl;
    su.swap(&d1,&d2);
    cout << "d1 = " << d1 << ", d2 = " << d2 <<" -- after calling swap -- " << endl;
    return 0;
}
