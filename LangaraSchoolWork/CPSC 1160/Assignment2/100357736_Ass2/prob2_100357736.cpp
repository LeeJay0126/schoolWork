#include <iostream>
#include <cstdlib>
#include <time.h>
#include <iomanip>
#include <string>
using namespace std;

const int ROW = 6;
const int COLUMN = 5;

void initialize(char matrix[][COLUMN],int row, int col);
void display(char matrix[][COLUMN], int row , int col);
string navigate(char matrix[][COLUMN], int row, int col, string input);
string user_input();
bool is_user_char(char cur, char user_char);
bool navigate(char matrix[ROW][COLUMN], int row, int column, string input, int idx);

int main(){
    
    char arr[ROW][COLUMN];
    
    initialize(arr,ROW,COLUMN);
    display(arr, ROW, COLUMN);
    string input = user_input();
    
    if(navigate(arr, ROW, COLUMN, input, 0)){
        cout << "Letters " << input << " are neighbours. ";
    }else{
        cout << "Letters " << input << " are not neightbours.";
    }
    
    return 0;
}

void initialize(char matrix[][COLUMN],int row, int col){
    
    srand(time(0));
    
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            matrix[i][j] = ('a' + rand()%('z'-'a'+1));
        }
    }
    
}

void display(char matrix[][COLUMN], int row , int col){
    cout << "================================" << endl;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cout << "| " << matrix[i][j] << " |" ;
        }
        cout<<endl;
    }
    cout << "================================" << endl;
}

string user_input(){
    cout << "Enter the word you want to navigate: " << endl;
    string input;
    cin >> input;
    
    return input;
}

bool is_user_char(char cur, char user_char){
    return cur == user_char;
}

bool search(char matrix[][COLUMN], char user_char , int row, int col){
    if(
        matrix[row+1][col] == user_char || 
        matrix[row][col+1] == user_char ||
        matrix[row+1][col+1] == user_char ||
        matrix[row-1][col-1] == user_char ||
        matrix[row-1][col] == user_char ||
        matrix[row][row-1] == user_char ||
        matrix[row+1][row-1] == user_char||
        matrix[row-1][col+1] == user_char
    ){
        return true;
    }
    return false;
}



bool navigate(char matrix[][COLUMN], int row, int col, string input, int idx){
    
    bool validator = false;
    
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(is_user_char(matrix[i][j], input[idx])){
               if(search(matrix,input[idx],i,j)){
                   validator = true;
                   if(input.length()-1 > idx){
                       navigate(matrix,row,col,input,idx+1);
                   }else{
                       break;
                   }
               }
            }
        }
    }
    return validator;
}