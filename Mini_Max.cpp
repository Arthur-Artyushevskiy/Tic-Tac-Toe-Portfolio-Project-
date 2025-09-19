//
//  Mini_Max.cpp
//  Tic-Tac-Toe
//
//  Created by Arthur on 17/09/25.
//
#include <iostream>
#include <string>
#include <random>
#include "Mini_Max.hpp"
using namespace std;
bool Mini_Max::isMoveLeft(std::vector<std::vector<char>> matrix){
    for (int row = 0; row < 3;  row++){
        for (int col = 0; col < 3; col++){
            if(matrix[row][col] == ' '){
                return true;
            }
        }
    }
    return false;
}

int Mini_Max::evaluate(std::vector<std::vector<char>> b)
{
    // Checking for Rows for X or O victory.
    for (int row = 0; row<3; row++)
    {
        if (b[row][0]==b[row][1] && b[row][1]==b[row][2])
        {
            if (b[row][0]=='X')
                return +10;
            else if (b[row][0]=='O')
                return -10;
        }
    }
    
    // Checking for Columns for X or O victory.
    for (int col = 0; col<3; col++)
    {
        if (b[0][col]==b[1][col] && b[1][col]==b[2][col])
        {
            if (b[0][col]=='X')
                return +10;
            else if (b[0][col]=='O')
                return -10;
        }
    }
    
    // Checking for Diagonals for X or O victory.
    if (b[0][0]==b[1][1] && b[1][1]==b[2][2])
    {
        if (b[0][0]=='X')
            return +10;
        else if (b[0][0]=='O')
            return -10;
    }
    if (b[0][2]==b[1][1] && b[1][1]==b[2][0])
    {
        if (b[0][2]=='X')
            return +10;
        else if (b[0][2]=='O')
            return -10;
    }
    
    // Else if none of them have won then return 0
    return 0;
}

int Mini_Max::minimax(std::vector<std::vector<char>> matrix, int depth, bool isMax){
    int score = evaluate(matrix);
    
    
    if(score == 10){
        return score - depth;
    }
    
    if(score == -10){
        return score + depth;
    }
    
    if(isMoveLeft(matrix) == false){
        return 0;
    }
    
    if(isMax){
        int best = -1000;
        
        for(int row = 0; row < 3; row++){
            for(int col =0; col < 3; col++){
                if(matrix[row][col] == ' '){
                    matrix[row][col] = player;
                    
                    best = max(best, minimax(matrix, depth + 1, !isMax));
                    
                    matrix[row][col] = ' ';
                }
            }
        }
        return best;
    }
    
    else{
        
        int best = 1000;
        
        for(int row = 0; row < 3; row++){
            for(int col =0; col < 3; col++){
                if(matrix[row][col] == ' '){
                    matrix[row][col] = opponent;
                    
                    best = min(best, minimax(matrix, depth + 1, !isMax));
                    
                    matrix[row][col] = ' ';
                }
            }
        }
        return best;
    }
}

void Mini_Max::findBestMove(std::vector<std::vector<char>> matrix, int chance){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(1, 100);
    
    if(distrib(gen) > chance){
        
        int bestVal = -1000;
        
        row = '0';
        col = '0';
        
        for(int row_m = 0; row_m < 3; row_m++){
            for(int col_m =0; col_m < 3; col_m++){
                if(matrix[row_m][col_m] == ' '){
                    
                    matrix[row_m][col_m] = player;
                    
                    
                    
                    
                    int moveVal;
                    moveVal = minimax(matrix, 0, false);
                    
                    
                    
                    matrix[row_m][col_m] = ' ';
                    
                    if(moveVal > bestVal){
                        
                        row = row_m + 1 + '0';
                        col = col_m + 1+ '0';
                        bestVal = moveVal;
                        
                    }
                }
            }
        }
        
    }
    else{
        std::vector<std::pair<int, int>> availableMoves;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (matrix[i][j] == ' ') {
                    availableMoves.push_back({i, j});
                }
            }
        }
        
        // Pick a random move from the available options
        if (!availableMoves.empty()) {
            std::uniform_int_distribution<> moveDist(0, availableMoves.size() - 1);
            int randomIndex = moveDist(gen);
            row = availableMoves[randomIndex].first + 1 +'0';
            col = availableMoves[randomIndex].second + 1 +'0';
        }
        
    }
}
