
#ifndef alchemist_hpp
#define alchemist_hpp
#include <stdio.h>
#include <iostream>
#include "archetype.hpp"
#include "BattleTicTacToe.hpp"
#include "tic_tac_toe.hpp"
#include <string>
#include <cmath>
using namespace std;
class alchemist{//an archetype that is able to switch two marks between eachother
public:
    char X;
    char O;
    int i_init_row;
    int i_init_col;
    int i_final_row;
    int i_final_col;
    alchemist(char X, char O){
        this->X =X;
        this-> O = O;
    }
    
        string print_choice(int count);
        void switch_mark(tic_tac_toe &grid, bool Player_1, int count);
        bool alchemist_rules( string row, string col, string final_row, string final_col, bool special, int count, tic_tac_toe &grid);
    bool adjacent(int row1, int col1, int row2, int col2);
};


#endif /* alchemist_hpp */
