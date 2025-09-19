//
//  tic_tac_toe.cpp
//  Tic-Tac-Toe
//
//  Created by Arthur on 15/09/25.
//

#include "tic_tac_toe.hpp"
#include <iostream>
#include <vector>
#include <cctype>
using namespace std;
void tic_tac_toe::tic_change(char c, string row, string col){
    
    if(row.length() > 1 || col.length()>1){
        cout <<"OUT OF BOUNDS!!!" << endl;
        return;
    }
    
    if(!isdigit(row[0]) || !isdigit(col[0])){
        cout << "USE NUMBERS FOR THE ROW ANS COL!!!" << endl;
        return;
    }
    
    int i_row = row[0] - '0';
    int i_col = col[0] - '0';
    
    i_row -= 1;
    i_col -= 1;
    
    if(i_row < 0 || i_row > 2){
        cout << "OUT OF BOUNDS!!!" << endl;
        return;
    }
    if(i_col < 0 || i_col > 2){
        cout << "OUT OF BOUNDS!!!" << endl;
        return;
    }
     
    if(matrix[i_row][i_col] == 'X' || matrix[i_row][i_col] == 'O' ){
        cout << "THIS SPACE IS ALREADY TAKEN, TRY OTHER ONE!!!" << endl;
        return;
    }
    
    matrix[i_row][i_col] = c;
   
    
    
}
bool tic_tac_toe::win(){
        if(check_hor()){
            return true;
        }
        if(check_ver()){
            return true;
        }
        if(check_diag_left()){
            return true;
        }
        if(check_diag_right()){
            return true;
        }
        return false;
    }
    
bool tic_tac_toe::full()const{
    for(int row {0}; row < matrix.size(); row++){
        for (int col{0}; col < matrix[0].size(); col++) {
            if(matrix[row][col] == ' '){
                return false;
            }
        }
        
    }
    return true;
}

bool tic_tac_toe::check_hor() {
    bool status{};
    for(int row {0}; row < matrix.size(); row++){
        if(matrix[row][0] != matrix[row][1]){
            status = false;
        }
        else if(matrix[row][1] == matrix[row][2]){
            if(matrix[row][2] == 'X'){
                XWon = true;
                return true;
            }
            else if (matrix[row][2] == 'O'){
                OWon = true;
                return true;
            }
            else{
                return false;
            }
           
        }
    }
    return status;
}

bool tic_tac_toe::check_ver(){
    bool status{};
    for(int col{0}; col < matrix[0].size(); col++){
        if(matrix[0][col] != matrix[1][col]){
           status = false;
        }
        else if(matrix[1][col] == matrix[2][col]){
            if(matrix[2][col] == 'X'){
                XWon = true;
                return true;
            }
            else if (matrix[2][col] == 'O'){
                OWon = true;
                return true;
            }
            else{
                return false;
            }
            
        }
    }
    return status;
}

bool tic_tac_toe::check_diag_right(){
    if(matrix[2][0] != matrix[1][1]){
        return false;
    }
    else if(matrix[1][1] == matrix[0][2]){
        if(matrix[0][2] == 'X'){
            XWon = true;
            return true;
        }
        else if (matrix[0][2] == 'O'){
            OWon = true;
            return true;
        }
        else{
            return false;
        }
      
    }
    return false;
}

bool tic_tac_toe::check_diag_left(){
    if(matrix[0][0] != matrix[1][1]){
        return false;
    }
    else if(matrix[1][1] == matrix[2][2]){
        if(matrix[2][2] == 'X'){
            XWon = true;
            return true;
        }
        else if (matrix[2][2] == 'O'){
            OWon = true;
            return true;
        }
        else{
            return false;
        }
        
    }
    return false;
}

void tic_tac_toe::print() const{
    cout << "  1     2     3" << endl;
    for(int row {0}; row < matrix.size(); row++){
        cout << row + 1;
        for (int col{0}; col < matrix[0].size(); col++) {
            
            cout<< "| " << matrix[row][col] << " |" << " ";
        }
        cout << endl;
    }
}

void tic_tac_toe::num_bound_x(){
    while((((row[0] -'0') > 3) || ((col[0] - '0') > 3))){
        cout << "Input row (1-3): ";
        cin >> row;
        
        
        
        cout << "Input col (1-3): ";
        cin >> col;
        
        
        tic_change('X', row, col);
        cout << endl;
        //cout << "Here is the punishment!" << endl;
    };
}

void tic_tac_toe::O_space_check(){
    while(matrix[(row[0] -'0') - 1][(col[0] -'0') - 1] == 'O'){
       cout << "Input row (1-3): ";
       cin >> row;
       
       
       
       cout << "Input col (1-3): ";
       cin >> col;
       
       
       tic_change('X', row, col);
       cout << endl;
       //cout << "Here is the punishment!" << endl;
   }
}
void tic_tac_toe::is_digit_x(){
    while((!isdigit(row[0]) && !isdigit(col[0]))){
        cout << "Input row (1-3): ";
        cin >> row;
        
        
        
        cout << "Input col (1-3): ";
        cin >> col;
        
        
        tic_change('X', row, col);
        cout << endl;
        //cout << "Here is the punishment!" << endl;
    };
}

void tic_tac_toe::num_bound_o(){
    while((((row[0] -'0') > 3) || ((col[0] - '0') > 3))){
        cout << "Input row (1-3): ";
        cin >> row;
        
        
        
        cout << "Input col (1-3): ";
        cin >> col;
        
        
        tic_change('O', row, col);
        cout << endl;
        //cout << "Here is the punishment!" << endl;
    };
}

void tic_tac_toe::is_digit_o(){
    while((!isdigit(row[0]) && !isdigit(col[0]))){
        cout << "Input row (1-3): ";
        cin >> row;
        
        
        
        cout << "Input col (1-3): ";
        cin >> col;
        
        
        tic_change('O', row, col);
        cout << endl;
        //cout << "Here is the punishment!" << endl;
    };
}

void tic_tac_toe::X_space_check(){
    while(matrix[(row[0] -'0') - 1][(col[0] -'0') - 1] == 'X'){
       cout << "Input row (1-3): ";
       cin >> row;
       
       
       
       cout << "Input col (1-3): ";
       cin >> col;
       
       
       tic_change('O', row, col);
       cout << endl;
       //cout << "Here is the punishment!" << endl;
   }
}

void tic_tac_toe::is_number_x(){
    while((row.length() > 1 || col.length()>1)){
        cout << "Input row (1-3): ";
        cin >> row;
        
        
        
        cout << "Input col (1-3): ";
        cin >> col;
        
        
        tic_change('X', row, col);
        cout << endl;
        //cout << "Here is the punishment!" << endl;
    };
}

void tic_tac_toe::is_number_o(){
    while((row.length() > 1 || col.length()>1)){
        cout << "Input row (1-3): ";
        cin >> row;
        
        
        
        cout << "Input col (1-3): ";
        cin >> col;
        
        
        tic_change('O', row, col);
        cout << endl;
        //cout << "Here is the punishment!" << endl;
    };
}
