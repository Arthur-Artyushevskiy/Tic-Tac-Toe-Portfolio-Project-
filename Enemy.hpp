//
//  Enemy.hpp
//  Tic-Tac-Toe
//
//  Created by Arthur on 28/11/25.
//

#ifndef Enemy_hpp
#define Enemy_hpp

#include <stdio.h>
#include <iostream>
using namespace std;
class Enemy{
public:
    string name;
    string asciiArt;
    string specialAbilityName;
    double maxHealth;
    double health;
    double attack;
    double defense;
    
    Enemy(string name, double maxHealth, double attack, double defense, string art, string specialAbilityName){
        this->name = name;
        this->asciiArt = art;
        this-> maxHealth = maxHealth;
        this-> attack = attack;
        this-> health = maxHealth;
        this-> defense = defense;
        this-> specialAbilityName = specialAbilityName;
    }
    
    void displayStats();
    
    void takeDamage(int amount);
    
    bool isAlive();
    
    void ability_AcidSplash(std::vector<std::vector<char>> &matrix);
    
    void ability_RockBlock(std::vector<std::vector<char>> &matrix);
    
    void castPossession(std::vector<std::vector<char>> &matrix);
    
    void ability_SonarBlind(bool &isPlayerBlinded);
};



#endif /* Enemy_hpp */
