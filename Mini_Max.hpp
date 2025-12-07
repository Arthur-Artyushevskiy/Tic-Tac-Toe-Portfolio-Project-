
#ifndef Mini_Max_hpp
#define Mini_Max_hpp
#include "tic_tac_toe.hpp"
#include <stdio.h>
#include <string>
using namespace std;

class Mini_Max{
public:
    string row, col;
    char player = 'O', opponent = 'X';
    
    bool isMoveLeft(const vector<vector<char>>& matrix);
    int evaluate(const vector<vector<char>>& b);
    int minimax(vector<vector<char>>& matrix, int depth, bool isMax);
    void findBestMove(vector<vector<char>>& matrix, int chance);
};
#endif /* Mini_Max_hpp */
