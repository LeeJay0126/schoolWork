#include <iostream>
#include <string>

using namespace std;

int main(){

    string s, t;
    getline (cin,s);
    int size = s.size();
    int mid = size / 2;
    t += s[mid];
    if(!(size%2)){
        t = s[mid - 1]+t;
    }
    cout << t;
}