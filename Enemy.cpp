//
//  Enemy.cpp
//  Tic-Tac-Toe
//
//  Created by Arthur on 28/11/25.
//

#include "Enemy.hpp"

void Enemy::displayStats(){
    cout << "========================================" << endl;
        cout << " ENEMY: " << name  << endl;
        cout << " HP: " << health << "/" << maxHealth << " | ATK: " << attack << " | DEF: " << defense << endl;
    cout << asciiArt << endl;
        // Visual Health Bar
        cout << " [";
        int bars = health / 10;
        for(int i=0; i<10; i++) {
            if(i < bars) cout << "#";
            else cout << " ";
        }
        cout << "]" << endl;
        cout << "========================================" << endl;
}

void Enemy::takeDamage(int amount){
  health -= amount - defense;
    if(health < 0) health = 0;
    cout << name << " took " << amount << " points of damage!" << endl;
}

bool Enemy::isAlive(){
    if(health == 0) return false;
    return true;
}

void Enemy::ability_AcidSplash(std::vector<std::vector<char>> &matrix) {
    cout << ">>> THE SLIME USES ACID SPLASH! One of your marks dissolves!" << endl;
    
    // Find all spots where the player (X) has moved
    vector<pair<int, int>> playerMoves;
    for(int row=0; row<3; row++) {
        for(int col=0; col<3; col++) {
            if(matrix[row][col] == 'X') {
                playerMoves.push_back({row, col});
            }
        }
    }
    
    // If the player has marks, remove one randomly
    if(!playerMoves.empty()) {
        int idx = rand() % playerMoves.size();
        matrix[playerMoves[idx].first][playerMoves[idx].second] = ' ';
    }
}
// this method can lead to errors where the loop will get stucked and no one will be able to win
void Enemy::ability_RockBlock(std::vector<std::vector<char>> &matrix) {
    cout << ">>> THE GOLEM USES ROCK BLOCK! A boulder falls on the grid!" << endl;
    
    // Find all empty spots
    vector<pair<int, int>> emptySpots;
    for(int row=0; row<3; row++) {
        for(int col=0; col<3; col++) {
            if(matrix[row][col] == ' ' ) {
                emptySpots.push_back({row, col});
            }
        }
    }
    
    // Place a rock '#'
    if(!emptySpots.empty()) {
        int idx = rand() % emptySpots.size();
        matrix[emptySpots[idx].first][emptySpots[idx].second] = '#';
    }
}

void Enemy::castPossession(std::vector<std::vector<char>> &matrix) {
    // 1. Check if ability is ready (cooldown logic)
    
    // 2. Find all spots where the player has an 'X'
    vector<pair<int, int>> playerSpots;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if (matrix[i][j] == 'X') {
                playerSpots.push_back({i, j});
            }
        }
    }

    // 3. If player has marks, steal one
    if (!playerSpots.empty()) {
        int randomIndex = rand() % playerSpots.size();
        int r = playerSpots[randomIndex].first;
        int c = playerSpots[randomIndex].second;

        matrix[r][c] = 'O'; // Turn X into O
        cout << "The Necromancer casts POSSESSION! Your mark at " << r << "," << c << " belongs to him now!" << endl;
    }
}

void Enemy::ability_SonarBlind(bool &isPlayerBlinded) {
    if (!isPlayerBlinded) {
        cout << ">>> THE CAVE BAT SCREECHES! 'SONAR BLIND'!" << endl;
        cout << ">>> Your vision goes dark. You must guess your next move." << endl;
        isPlayerBlinded = true;
    } else {
        cout << ">>> The Bat screeches, but you are already blinded." << endl;
    }
}
