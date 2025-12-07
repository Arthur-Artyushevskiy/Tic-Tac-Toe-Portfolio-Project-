//
//  Player.hpp
//  Tic-Tac-Toe
//
//  Created by Arthur on 24/11/25.
//

#ifndef Player_hpp
#define Player_hpp
#include <stdio.h>
#include "alchemist.hpp"
#include "paladine.hpp"

class Player{
private:
   
    double maxHealth;
    
public:
    string asciiArt;
    string name;
    string className;
    double health;
    double defense;
    double attack;
    int money;
    Player(string name, string art, string className){
        this->name = name;
        this->className = className;
        this->asciiArt = art;
        money = 0;
        if(className == "Paladin" || className == "paladin"){
            maxHealth = 120;
            health = 120;
            attack = 40;
            defense = 10;
        }
        else if(className == "Alchemist" || className == "alchemist"){
            maxHealth = 100;
            health = 100;
            attack = 30;
            defense = 5;
        }
    }
    
    void displayStats();
    
    void heal(int amount);
    
    void takeDamage(int amount);
    
    bool isAlive();
    
    void spendMoney(int amount);
};


#endif /* Player_hpp */
