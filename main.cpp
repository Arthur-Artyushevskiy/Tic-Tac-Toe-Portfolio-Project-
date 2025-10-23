
#include <iostream>
#include <string>
#include <vector>
#include "tic_tac_toe.hpp"
#include "Mini_Max.hpp"
#include <cctype>
#include "BattleTicTacToe.hpp"
//#include "MiniMax.cpp"
using namespace std;



/* the difficulty helper function that helps to set the difficulty for the bot
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
*/
int main(int argc, const char * argv[]) {
    //tic_tac_toe tac{'X', 'O'};
    //tac.run();
    BattleTicTacToe battle{};
    battle.runBattle();
    
    
    /* The old code for the previous portfolio project (extra credit)
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
     
     */
    return 0;
}


