
#include "alchemist.hpp"

// a helper function that allows the player to choose between two moves
string alchemist::print_choice(int count){
    string choice;
    cout << "Choose between two moves (1.regular/2.special): ";
    getline(cin, choice);
    while(!(choice == "1" || choice == "2")){
        cout << "Choose only 1 or 2."<< endl;
        cout << "Choose between two moves 1 or 2: ";
        getline(cin, choice);
    }
    while(count < 3 && choice != "1"){
      cout << "There are not enough marks to do your special move!" << endl;
        cout << "Choose between two moves 1 or 2: ";
        getline(cin, choice);
    }
    if(choice == "2"){
        cout << "Description of your special move: You can change the Mark to other one." << endl;
    }
    return choice;
}
// a special move that allows the player to switch two marks between each other
void alchemist::switch_mark(tic_tac_toe &grid ,bool Player_1, int count){
    string init_row;
    string init_col;
    string final_row;
    string final_col;
    
    
    cout << "Which Mark do you want to switch with?" << endl;
    
  
        bool move_success_1 = false;
        while(!move_success_1){
            cout << "Input first row (1-3): ";
            getline(cin, init_row);
            
            cout << "Input first col (1-3): ";
            getline(cin, init_col);
            
            cout << endl;
           
            cout << "Input second row (1-3): ";
            getline(cin,final_row);
            
            cout << "Input second col (1-3): ";
            getline(cin, final_col);
           
            if(Player_1){
                move_success_1 =  alchemist_rules( init_row, init_col, final_row, final_col, true, count, grid);
            }
            else{
                move_success_1 =  alchemist_rules( init_row, init_col, final_row, final_col, true, count, grid);
            }
        }
    
    
    grid.print();
}
// checks if the marks you want to swap are adjacent, if so, the game stops you from doing that
bool alchemist::adjacent(int row1, int col1,int row2,int col2){
    bool horizontal = (row1 == row2) && (abs(col2 - col1) == 1);
    bool vertical = (col1 == col2) && (abs(row2 - row1) == 1);
    
    return horizontal || vertical;
}
// a set of rules for the alchemist that prevents the player from abusing some game mechanics
bool alchemist::alchemist_rules( string init_row, string init_col, string final_row, string final_col, bool special, int count, tic_tac_toe &grid){
   
    if(init_row.length() > 1 || init_col.length()>1){
        cout <<"OUT OF BOUNDS!!!" << endl;
        return false;
    }
    
    if(!isdigit(init_row[0]) || !isdigit(init_col[0])){
        cout << "USE NUMBERS FOR THE ROW ANS COL!!!" << endl;
        return false;
    }
    
    i_init_row = (init_row[0] - '0') -1;
    i_init_col = (init_col[0] - '0') -1;
    
    i_final_row = (final_row[0] - '0') -1;
    i_final_col = (final_col[0] - '0') -1;
    
  
    
    if(i_init_row < 0 || i_init_row > 2){
        cout << "OUT OF BOUNDS!!!" << endl;
        return false;
    }
    if(i_init_col < 0 || i_init_col > 2){
        cout << "OUT OF BOUNDS!!!" << endl;
        return false;
    }
    if(special){
        
       if(grid.matrix[i_final_row][i_final_col] == ' ' || grid.matrix[i_init_row][i_init_col] == ' '){
            cout << "Can't switch the empty cells!" << endl;
            return false;
        }
        
        if(grid.matrix[i_final_row][i_final_col] == grid.matrix[i_init_row][i_init_col]){
                cout << "Can't switch the same mark!" << endl;
                return false;
        }
        
       
        if(adjacent(i_init_row, i_init_col, i_final_row, i_final_col)){
            cout << "Can't switch adjacent marks!" << endl;
            return false;
        }
    }
    
      char ch1;
      char ch2;
      ch1 =grid.matrix[i_init_row][i_init_col];
      ch2 =grid.matrix[i_final_row][i_final_col];
      grid.matrix[i_init_row][i_init_col] = ch2;
    grid.matrix[i_final_row][i_final_col] = ch1;
    return true;
}

