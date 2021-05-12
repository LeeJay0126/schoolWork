#include <string>
#include <iostream>
#include <cctype>
#include <ctime>
#include <math.h>
#include <cstdlib>

using namespace std;

int main(){
  cout << "Enter a string : ";
  string s;
  string result;
  getline(cin, s);

  for(int i = 0; i < s.length();i++){
    
    if((s[i]>='a'&&s[i]<='z')||(s[i]<='Z'&&s[i]>='A')){
      if(s[i]==toupper(s[i])){
        s[i] = tolower(s[i]);
        result+=s[i];
      }else{
        s[i] = toupper(s[i]);
        result += s[i];
      }
    }else if(s[i]>='0'&&s[i]<='9'){
      s[i] = s[i];
      result+=s[i];
      }else{
      s[i] = '*';
      result+= s[i];
    }
    
  }
  cout << result;
}