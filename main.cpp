
#include <iostream>
#include <string>
#include <vector>
#include "tic_tac_toe.hpp"
#include "Mini_Max.hpp"
#include <cctype>
//#include "MiniMax.cpp"
using namespace std;
tic_tac_toe tac{};
void X_Move (){
    cout << "First Player (X): " << endl;
    
    cout << "Input row (1-3): ";
    cin >> tac.row;
    
    
    
    cout << "Input col (1-3): ";
    cin >> tac.col;
    
    cout << endl;
    
    tac.tic_change('X', tac.row , tac.col );
    
    tac.is_number_x();
    
    tac.is_digit_x();
    
    tac.num_bound_x();
    
    tac.O_space_check();
    
    
    tac.print();
    cout << endl;
    tac.win();
}

void O_Move(){
    cout << "Second Player (O): ";
    cout << endl;
    
    cout << "Input row (1-3): ";
    cin >> tac.row;
    
    
    cout << "Input col (1-3): ";
    cin >> tac.col;
    
    cout << endl;
    
    tac.tic_change('O', tac.row , tac.col );
    
    tac.is_number_o();
    
    tac.is_digit_o();
    
    tac.num_bound_o();
    
    tac.X_space_check();
    
    
    cout << endl;
    tac.win();
}

void result(){
    cout << "The Result is: ";
    if(tac.full() && tac.XWon == false && tac.OWon == false){
        cout << "Tie!" << endl;
    }
    else if (tac.XWon){
        cout << "X Won!" << endl;
    }
    else if(tac.OWon){
        cout << "O Won!" << endl;
    }
}

int difficulty(int diff){
    switch (diff) {
        case 1:
            return 75;
            break;
        case 2:
            return 50;
            break;
        case 3:
            return 25;
            break;
        case 4:
            return 0;
            break;
        default:
            break;
    }
    return 0;
}

int main(int argc, const char * argv[]) {
   
    string condition;
    cout << "Welcome to the TIC_TAC_TOE GAME!!!" << endl;
    cout << "Do you want to play with another human or a bot? (Human/Bot): ";
    cin>>condition;
    if(!(condition == "Human" || condition == "Bot")){
        while(!(condition == "Human" || condition == "Bot")){
            cout << "Choose only 'Human' or 'Bot'."<< endl;
            cout << "Do you want to play with another human or a bot? (Human/Bot): ";
            cin>>condition;
        }
    }
    
    if(condition == "Human"){
        while(!tac.full()){
            if(!tac.win()){
                tac.print();
                cout << endl;
                
                if(tac.OWon == 0){
                    X_Move();
                }
                else{
                    break;
                }
                
                if(tac.XWon == 0){
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
        tac.print();
        
        result();
        
   }
   else if (condition == "Bot"){
       
       cout << "Here is the list of difficulties: " << endl;
       cout << "1. Easy (75%)" << endl;
       cout << "2. Medium (50%)" << endl;
       cout << "3. Hard (25%)" << endl;
       cout << "4. IMPOSSIBLE (0%)" << endl;
       int option;
       cout << "Choose the difficulty you want to play (1-4): ";
       cin >> option;
       int diff_num = difficulty(option);
       
       while( !tac.full()){
           if(!tac.win()){
               tac.print();
               cout << endl;
               
                if(tac.OWon == 0){
                   X_Move();
                   
                if(tac.XWon == 0){
                       
                    Mini_Max bot;
                    bot.findBestMove(tac.matrix, diff_num);
                    tac.tic_change('O', bot.row, bot.col);
                    cout << endl;
                    tac.win();
                   
                    }
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
       tac.print();
       
       result();
     
    }
   
    return 0;
}


