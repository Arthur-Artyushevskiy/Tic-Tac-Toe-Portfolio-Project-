//
//  Player.cpp
//  Tic-Tac-Toe
//
//  Created by Arthur on 24/11/25.
//

#include "Player.hpp"

void Player::displayStats(){
    cout << "========================================" << endl;
        cout << " HERO: " << name << " (" << className << ")" << endl;
        cout << asciiArt << endl << endl;
        cout << " HP: " << health << "/" << maxHealth << " | ATK: " << attack << " | DEF: " << defense << " |" << money <<"G" << endl;
        
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

void Player::heal(int amount){
   
    if(health > maxHealth){
        cout << "You tried to heal yourself, but there are no wounds." << endl;
        health = maxHealth;
    }
    else if(health + amount > maxHealth){
        cout << "You fully healed yourself with some leftovers." << endl;
        int neededHeal = maxHealth - health;
        health += neededHeal;
    }
    else{
        health += amount;
        cout << "You increased your health by " << amount << "HP." << endl;
    }
}

void Player::takeDamage(int amount){
  health = health - amount + defense;
    if(health < 0) health = 0;
    cout << "You took Damage of: " << amount << " points!" << endl;
}

bool Player::isAlive(){
    if(health == 0) return false;
    return true;
}

void Player::spendMoney(int amount){
    if(money - amount < 0){
       
        
    }
     money -= amount;
    
}
