
#ifndef BattleTicTacToe_hpp
#define BattleTicTacToe_hpp
#include <stdio.h>
#include <iostream>
#include <cctype>
#include <vector>
#include <string>
#include "tic_tac_toe.hpp"
#include "alchemist.hpp"
#include "paladine.hpp"
using namespace  std;
// a separate class that is made for the second portfolio project, allows you to play old version and new version
class BattleTicTacToe{
public:
    char mark_one;
    char mark_two;
    
    string Player_1_choice;
    string Player_2_choice;
    
    bool check_mark();
    bool string_rules(string word);
    void Battle();
    void runBattle();
    void choose_mark();
    bool battle_change(tic_tac_toe grid,char c, string row, string col);
    void XMove();
};


#endif /* BattleTicTacToe_hpp */
