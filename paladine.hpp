
#ifndef paladine_hpp
#define paladine_hpp
#include <stdio.h>
#include <iostream>
#include "BattleTicTacToe.hpp"
#include "tic_tac_toe.hpp"
#include <string>
// a paladine archetype that is used for the second portfolio project
class paladine{
public:
    char X;
    char O;
   
    paladine(char X, char O){
        this->X =X;
        this-> O = O;
    }
    
        string print_choice(int count);
        void shift_mark(tic_tac_toe &grid, bool Player_1, int count);
        bool paladine_rules( string row, string col, string final_row, string final_col, bool special, int count,tic_tac_toe &grid);
    bool adjacent(int row1, int col1, int row2, int col2);
};
#endif /* paladine_hpp */
