//
//  Mini_Max.hpp
//  Tic-Tac-Toe
//
//  Created by Arthur on 17/09/25.
//

#ifndef Mini_Max_hpp
#define Mini_Max_hpp
#include "tic_tac_toe.hpp"
#include <stdio.h>
#include <string>
using namespace std;

class Mini_Max{
public:
    string row, col;
    tic_tac_toe tac{};
    char player = 'X', opponent = 'O';
    bool isMoveLeft(std::vector<std::vector<char>> matrix);
    int evaluate(std::vector<std::vector<char>> b);
    int minimax(std::vector<std::vector<char>> matrix, int depth, bool isMax);
    void findBestMove(std::vector<std::vector<char>> matrix, int chance);
};
#endif /* Mini_Max_hpp */
