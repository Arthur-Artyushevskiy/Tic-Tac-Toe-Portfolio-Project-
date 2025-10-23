
#include "BattleTicTacToe.hpp"
#include <string>
// a helper function that allows the player to choose a mark he wants to play
void BattleTicTacToe::choose_mark(){
    string first;
    string second;
    
    cout << "Player 1: Choose your Mark: ";
    getline(cin, first);
    
    while(string_rules(first)){
        cout << "Can't use numbers as marks and your mark should be only one character!"<< endl;
        cout << "Player 1: Choose your Mark: ";
        getline(cin, first);
    }
    
    

    mark_one = first[0];
    
    
    cout << "Player 2: Choose your Mark: ";
    getline(cin, second);
    while(string_rules(second)){
        cout << "Can't use numbers as marks and your mark should be only one character!"<< endl;
        cout << "Player 2: Choose your Mark: ";
        getline(cin, second);
    }
    mark_two = second[0];
    
    
    
}
// a helper functon for the choose_mark fucntion. It has a certain set of rules that prevenst the player from breaking certain mechanics
bool BattleTicTacToe::string_rules(string word){
    
    if(word.length() > 1){
        return true;
    }
    
    for(int i{0}; i < word.length(); i++){
        if(isdigit(word[i])){
           return true;
        }
    }
    return false;
}

// a main methos that is used to run the game
void BattleTicTacToe::Battle(){
    
    string condition;
    cout << "Welcome to the TIC_TAC_TOE GAME!!!" << endl;
    cout << "Choose your game mode (regular/battle): ";
    cin>>condition;
    cin.ignore();
    while(!(condition == "regular" || condition == "battle")){
        cout << "Choose only 'regular' or 'battle'."<< endl;
        cout << "Choose your game mode (regular/battle): ";
        cin>>condition;
        cin.ignore();
    }
    
    // if player wants to play the regular game, then he can choose 'regular'
    if(condition == "regular"){
        
        tic_tac_toe tac{'X', 'O'};
        tac.run();
        
    }
    // otherwise if player wants to play a battle version then he can choose 'battle'
    else{
        choose_mark();
        tic_tac_toe battle{mark_one, mark_two};
        alchemist al {mark_one, mark_two};
        paladine pl {mark_one, mark_two};
        string first_player;
        string second_player;
        
        cout << "PLAYER 1:" << endl;
        
        cout << "1. Alchemist; Special Ability: You can change the Mark to other one." << endl;
        cout << "2. Paladine; Special Ability: You can push the Mark one tile. " << endl;
        cout << "Choose your character:";
        getline(cin, first_player);
        
        while(first_player != "1" && first_player != "2"){
            cout << "Invalid: type either 1 or 2!" << endl;
        
            cout << "1. Alchemist; Special Ability: You can change the Mark to other one." << endl;
            cout << "2. Paladine; Special Ability: You can push the Mark one tile. " << endl;
            cout << "Choose your character:";
            getline(cin, first_player);
        }
        
        cout << "PLAYER 2:" << endl;
        
        cout << "1. Alchemist; Special Ability: You can change the Mark to other one." << endl;
        cout << "2. Paladine; Special Ability: You can push the Mark one tile. " << endl;
        cout << "Choose your character:";
        getline(cin, second_player);
        
        while(second_player != "1" && second_player != "2"){
            cout << "Invalid: type either 1 or 2!" << endl;
        
            cout << "1. Alchemist; Special Ability: You can change the Mark to other one." << endl;
            cout << "2. Paladine; Special Ability: You can push the Mark one tile. " << endl;
            cout << "Choose your character:";
            getline(cin, second_player);
        }
        
        tic_tac_toe tac{'X', 'O'};
        while(!battle.full()){
            static int count = 0;
            if(battle.win()){
                count = 0;
            }
            count++;
            if(!battle.win()){
                battle.print();
                cout << endl;
                // the first player starts the game
                cout << "Player 1:" << endl;
                // if the player chooses the alchemist
                if(first_player == "1"){
                    
                    Player_1_choice = al.print_choice(count);
                    
                    if(battle.OWon == 0 && Player_1_choice == "1"){
                        battle.X_Move();
                    }
                    else if(battle.OWon == 0 && Player_1_choice == "2"){
                        
                        al.switch_mark(battle,true, count);
                    }
                    else{
                        break;
                    }
                }
                // if the player chooses the paladine
                else{
                    Player_1_choice = pl.print_choice(count);
                    // if player chooses a regular move
                    if(battle.OWon == 0 && Player_1_choice == "1"){
                        battle.X_Move();
                    }
                    // if player chooses a special move
                    else if(battle.OWon == 0 && Player_1_choice == "2"){
                        
                        pl.shift_mark(battle,true, count);
                    }
                    // stops the game if player 1 lost
                    else{
                        break;
                    }
                }
                battle.win(); // updates the game state to determine who won tha game
                if(battle.OWon == 1){ // if player 2 won the game then it stops
                    break;
                }
                else if(battle.XWon == 1){ // if player 1 won the game then it stops
                    break;
                }
                // the second player starts his move here:
                cout << "Player 2:" << endl;
                // if player 2 chooses the alchemist
                if(second_player == "1"){
                   
                    Player_2_choice = al.print_choice(count); // prints the player's choice between 'regular' and 'special' move
                    if(battle.XWon == 0 && Player_2_choice == "1"){ // if player 2 chooses a regular move and did not lose
                        battle.O_Move();
                    }
                    else if(battle.XWon == 0 && Player_2_choice == "2"){ // if player 2 chooses a special move and did not lose
                        al.switch_mark(battle,false, count);
                    }
                    else{
                        break;
                    }
                }
                // if player 2 chooses a paladine
                else{
                    Player_2_choice = pl.print_choice(count);
                    if(battle.XWon == 0 && Player_2_choice == "1"){// if player 2 chooses a regular move and did not lose
                        battle.O_Move();
                    }
                    else if(battle.XWon == 0 && Player_2_choice == "2"){ // if player 2 chooses a special move and did not lose
                        pl.shift_mark(battle,false, count);
                    }
                    else{
                        break;
                    }
                }
            }
            else{
                break;
            }
        }
        cout << endl;
        battle.print();
        
        battle.result();
    }
    
}
// a helper method that runs the game and asks the player if we want to continue to play the game.
void BattleTicTacToe::runBattle(){
    string check;
    
    do{
        Battle();
        cout << "Do you want to continue the game? (yes/no)"<< endl;
        cout << "Answer:";
        getline(cin, check);
        while(!(check=="yes" || check =="no")){
            cout << "Type either yes or no: ";
            getline(cin, check);
        }
    }while(check == "yes");
}
