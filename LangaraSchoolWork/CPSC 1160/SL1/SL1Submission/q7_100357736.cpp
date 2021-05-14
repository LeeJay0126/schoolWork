// Jay Seung Yeon Lee
#include <iostream>
#include <iomanip>
using namespace std;

void displayPage(char p[3][3]);
int RowValidatorO(char p[3][3]);
int RowValidatorX(char p[3][3]);
int ColumnValidatorO(char p[3][3]);
int ColumnValidatorX(char p[3][3]);
int rightLeftDiagonalO(char p[3][3]);
int rightLeftDiagonalX(char p[3][3]);
int leftRightDiagonalO(char p[3][3]);
int leftRightDiagonalX(char p[3][3]);
int XValidator(char p[3][3]);
int OValidator(char p[3][3]);

int main(){
    char matrix[3][3];
    
    int count = 1;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            matrix[i][j] = '0' + count;
            count ++;
        }
    }
      cout << matrix << endl;
    int i = 0;
    int validator = 0;
    int player = 0;
    char OorX = '.';
    
    displayPage(matrix);
    
    while((i < 9) && validator == 0){
       
        if(i % 2 == 0){
            player = 0;
        }else{
            player = 1;
        }
        
        if(player == 0){
            cout << "Player1, Where do you want to place your O? : ";
            cin >> OorX;
        }else{
            cout << "Player2, Where do you want to place your X? : ";
            cin >> OorX;
        }
        
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(matrix[i][j] == OorX){
                    if(player == 0){
                        matrix[i][j] = 'O';
                    }else{
                        matrix[i][j] = 'X';
                    }
                }
            }
        }
        
        displayPage(matrix);
        
        cout << endl;
        
        i++;
        
        if(i == 9){
            cout << "It is a tie!" << endl;
        }
        
        if(XValidator(matrix) > 0){
            cout << "Player 2 Wins!" << endl;
            validator = 2;
        }else if(OValidator(matrix) > 0){
            cout << "Player1 Wins!" << endl;
            validator = 2;
        }
        
    }
}

void displayPage(char p[3][3]){
  
    for(int i = 0; i < 3; i ++){
        for(int j = 0; j < 3; j++){
            cout << left << setw(5) << p[i][j];
        }
        cout << endl;
    }
    
}

int RowValidatorO(char p[3][3]){
    //Row checker
    int count = 0;
    for(int i = 0; i < 3; i++){
        count = 0;
        for(int j = 0; j < 3; j++){
            if(p[i][j] == 'O'){
                count++;
            }
            
            if(count >= 3){
                return 1;
            }
        }
    }
    return 0;
}

int RowValidatorX(char p[3][3]){
    //Row checker
    int count = 0;
    for(int i = 0; i < 3; i++){
        count = 0;
        for(int j = 0; j < 3; j++){
            if(p[i][j] == 'X'){
                count++;
            }
            
            if(count >= 3){
                return 1;
            }
        }
    }
    return 0;
}

int ColumnValidatorO(char p[3][3]){
    //Column Checker
    int count = 0;
    for(int i = 0; i < 3; i++){
        count = 0;
        for(int j = 0; j < 3; j++){
            if(p[j][i] == 'O'){
                count++;
            }
            
            if(count >= 3){
                return 1;
            }
            
        }
    }
    return 0;
}

int ColumnValidatorX(char p[3][3]){
    //Column Checker
    int count = 0;
    for(int i = 0; i < 3; i++){
        count = 0;
        for(int j = 0; j < 3; j++){
            if(p[j][i] == 'X'){
                count++;
            }
            
            if(count >= 3){
                return 1;
            }
            
        }
    }
    return 0;
}

int leftRightDiagonalO(char p[3][3]){
    //major diagonal checker
    int count = 0;
    
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(i == j){
                if(p[i][j] == 'O'){
                    count ++;
                }
            }
        }
    }
    
    if(count >= 3){
        return 1;
    }
    
    return 0;
}

int leftRightDiagonalX(char p[3][3]){
    //major diagonal checker
    int count = 0;
    
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(i == j){
                if(p[i][j] == 'X'){
                    count ++;
                }
            }
        }
    }
    
    if(count >= 3){
        return 1;
    }
    
    return 0;
}

int rightLeftDiagonalO(char p[3][3]){
    int count = 0;
    int score = 0;
    
    for(int i = 2; i >= 0; i--){
        if(p[score][i] == 'O'){
            count++;
        }
        score++;
    }
    
    if(count >= 3){
        return 1;
    }
    
    return 0;
}

int rightLeftDiagonalX(char p[3][3]){
    int count = 0;
    int score = 0;
    
    for(int i = 2; i >= 0; i--){
        if(p[score][i] == 'X'){
            count++;
        }
        score++;
    }
    
    if(count >= 3){
        return 1;
    }
    
    return 0;
}

int XValidator(char p[3][3]){
    
    int number = RowValidatorX(p);
    int number1 = ColumnValidatorX(p);
    int number2 = leftRightDiagonalX(p);
    int number3 = rightLeftDiagonalX(p);
    
    int sum = number + number1 + number2 + number3;
    
    if(number > 0){
        return 1;
    }else{
        return 0;
    }
    
    
}

int OValidator(char p[3][3]){
    
    int number = RowValidatorO(p);
    int number1 = ColumnValidatorO(p);
    int number2 = leftRightDiagonalO(p);
    int number3 = rightLeftDiagonalO(p);
    
    int sum = number + number1 + number2 + number3;
    
    if(sum > 0){
        return 1;
    }else{
        return 0;
    }
    
    
}


