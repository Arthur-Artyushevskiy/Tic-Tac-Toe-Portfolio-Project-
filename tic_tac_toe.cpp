
#include "tic_tac_toe.hpp"
#include <iostream>
#include <vector>
#include <cctype>
using namespace std;
// a helper method that allows the grid to change if a specific set of rules are not broken
bool tic_tac_toe::tic_change(char c, string row, string col){
    
    if(row.length() > 1 || col.length()>1){
        cout <<"OUT OF BOUNDS!!!" << endl;
        return false;
    }
    
    if(!isdigit(row[0]) || !isdigit(col[0])){
        cout << "USE NUMBERS FOR THE ROW ANS COL!!!" << endl;
        return false;
    }
    
    int i_row = (row[0] - '0') -1 ;
    int i_col = (col[0] - '0') - 1;
    
    if(i_row < 0 || i_row > 2){
        cout << "OUT OF BOUNDS!!!" << endl;
        return false;
    }
    if(i_col < 0 || i_col > 2){
        cout << "OUT OF BOUNDS!!!" << endl;
        return false;
    }
     
    if(matrix[i_row][i_col] == X || matrix[i_row][i_col] == O ){
        cout << "THIS SPACE IS ALREADY TAKEN, TRY OTHER ONE!!!" << endl;
        return false;
    }
    
    matrix[i_row][i_col] = c;
    return true;
}
// checks if one of the players won the game
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
// a helper method that returns true if the grid is full and false if not
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

// cheks if one of the players won game horizontally
bool tic_tac_toe::check_hor() {
    bool status{};
    for(int row {0}; row < matrix.size(); row++){
        if(matrix[row][0] != matrix[row][1]){
            status = false;
        }
        else if(matrix[row][1] == matrix[row][2]){
            if(matrix[row][2] == X){
                XWon = true;
                return true;
            }
            else if (matrix[row][2] == O){
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
// cheks if one of the players won game vertically
bool tic_tac_toe::check_ver(){
    bool status{};
    for(int col{0}; col < matrix[0].size(); col++){
        if(matrix[0][col] != matrix[1][col]){
           status = false;
        }
        else if(matrix[1][col] == matrix[2][col]){
            if(matrix[2][col] == X){
                XWon = true;
                return true;
            }
            else if (matrix[2][col] == O){
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
// checks the grid for the diagonals that start at the botto left
bool tic_tac_toe::check_diag_right(){
    if(matrix[2][0] != matrix[1][1]){
        return false;
    }
    else if(matrix[1][1] == matrix[0][2]){
        if(matrix[0][2] == X){
            XWon = true;
            return true;
        }
        else if (matrix[0][2] == O){
            OWon = true;
            return true;
        }
        else{
            return false;
        }
      
    }
    return false;
}
// check the grid for the diagnls that starts at the top left
bool tic_tac_toe::check_diag_left(){
    if(matrix[0][0] != matrix[1][1]){
        return false;
    }
    else if(matrix[1][1] == matrix[2][2]){
        if(matrix[2][2] == X){
            XWon = true;
            return true;
        }
        else if (matrix[2][2] == O){
            OWon = true;
            return true;
        }
        else{
            return false;
        }
        
    }
    return false;
}
//prints out the tic tac toe grid
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


// a helper method that allows the player 1 to start his move
void tic_tac_toe::X_Move (){
    cout << "First Player ("<< X <<"):" << endl;
    bool move_success = false;
    while(!move_success){
        cout << "Input row (1-3): " ;
        getline(cin, row);
       
        
        cout << "Input col (1-3): " ;
        getline(cin, col);
        
        cout << endl;
    
        move_success =  tic_change(X, row , col);
    }
  
    
    print();
    cout << endl;
    win();
}

// a helper method that allows the player 2 to start his move
void tic_tac_toe::O_Move(){
    cout << "Second Player ("<< O <<"):" << endl;
    cout << endl;
    
    bool move_success = false;
    while(!move_success){
        cout << "Input row (1-3): " ;
        getline(cin, row);
        
        
        cout << "Input col (1-3): " ;
        getline(cin, col);
      
        
        cout << endl;
    
        move_success =  tic_change(O, row , col);
    }
    
    cout << endl;
    win();
}

// a helper method that prints out the result of the game
void tic_tac_toe::result(){
    cout << "The Result is: ";
    if(full() && XWon == false && OWon == false){
        cout << "Tie!" << endl;
    }
    else if (XWon){
        cout << X << " Won!" << endl;
    }
    else if(OWon){
        cout << O << " Won!" << endl;
    }
}
// main method for this class that allows you to run the game using only one command
void tic_tac_toe::run(){
    string condition;
    cout << "Welcome to the TIC_TAC_TOE GAME!!!" << endl;
    cout << "Do you want to play with another human or a bot? (Human/Bot): ";
    getline(cin, condition);
    if(!(condition == "Human" || condition == "Bot")){
        while(!(condition == "Human" || condition == "Bot")){
            cout << "Choose only 'Human' or 'Bot'."<< endl;
            cout << "Do you want to play with another human or a bot? (Human/Bot): ";
            getline(cin, condition);
        }
    }
    
    if(condition == "Human"){
        while(!full()){
            if(!win()){
                print();
                cout << endl;
                
                if(OWon == 0){
                    X_Move();
                }
                else{
                    break;
                }
                
                if(XWon == 0){
                    O_Move();
                }
                else{
                    break;
                }
            }
            else{
                break;
            }
        }
        cout << endl;
        print();
        
        result();
        
    }
}
