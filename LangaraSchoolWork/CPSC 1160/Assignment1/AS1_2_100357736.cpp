#include <iostream>
using namespace std;
string binaryNumber(int number);
void convertHT(string binary);

int main(){

    int input = 0;

    cout << "Enter a number between 0 and 511: ";
    cin >> input;

    if(input >= 0 && input <= 511){
       
        string binary = binaryNumber(input);
        convertHT(binary);

    }else{
        cout << "Error! You did not enter a number between 0 and 511!";
    }

}

string binaryNumber(int number){

    string output = "";
    int maxDivide = 256;
    for(int i = 0; i < 9; i++){
        if(number/maxDivide >= 1){
            output = output + "1";
            number %= maxDivide;
        }else{
            output = output + "0";
        }
        maxDivide /= 2;
    }

    return output;
}

void convertHT(string binary){

    for(int i = 0; i < binary.length(); i++){
        if(binary[i] == '0'){
            binary[i] = 'H';
        }else{
            binary[i] = 'T';
        }
    }

    for(int k = 0; k < binary.length(); k++){
        
        if(k % 3 == 0){
            cout << endl;
        }

        cout << binary[k] << "  ";

    }


}

