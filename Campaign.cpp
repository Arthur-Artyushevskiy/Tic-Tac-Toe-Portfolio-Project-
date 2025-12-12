
#include "Campaign.hpp"
using namespace std;

void Campaign::clearScreen(){
    for(int i{0}; i < 20; i++) cout << endl;
}

void Campaign::waitForEnter(){
    cout << "\n(Press Enter to continue...)";
    //cin.ignore();
    cin.get();
    cout << endl;
}

int Campaign::difficultyChance(){
    switch (difficulty) {
        case 1:
            return 70;
            break;
        case 2:
            return 60;
            break;
        case 3:
            return 50;
            break;
        default:
            break;
    }
    return 90;
}

void Campaign::takeDamage(tic_tac_toe & game, Enemy & enemy){
    if(game.XWon == 1){
        enemy.takeDamage(hero->attack);
        enemy.displayStats();
    }
    else if(game.OWon == 1){
        hero->takeDamage(enemy.attack);
        hero->displayStats();
    }
}

bool Campaign::eventDarkKnightInteraction() {
    clearScreen();
    cout << "You defeat the Dark Knight! He falls to one knee, breathing heavily." << endl;
    cout << "His helmet shatters, revealing a weary human face." << endl;
    cout << "'I... I was controlled... please... end it...'" << endl;
    cout << endl;
    cout << "1. FINISH HIM (He is too dangerous. Take his gold.)" << endl;
    cout << "2. SPARE HIM (Offer him redemption. He might help you.)" << endl;
    
    string choice;
    cout << "Make your choice (1 or 2): ";
    getline(cin, choice);
    while(choice != "1" && choice != "2") {
        cout << "Choose 1 or 2: ";
        getline(cin, choice);
    }
    
    if (choice == "1") {
        cout << "You strike the final blow. You take 50 Gold from his corpse." << endl;
        hero->money += 50;
        return false; // Did not get True Ending item
    } else {
        cout << "You sheathe your weapon and offer a hand." << endl;
        cout << "The Knight weeps. 'Thank you... take this. It is the only thing the Necromancer fears.'" << endl;
        cout << ">>> YOU RECEIVED THE AMULET OF LIGHT! <<<" << endl;
        return true; // Unlocked True Ending
    }
}

void Campaign::startCampaign(){
    string difficulty;
    bool gameWon = false;
    // Track the "True Ending" condition
    bool hasAmuletOfLight = false;

    cout << "Welcome to RPG Tic Tac Toe Game!" << endl;
    waitForEnter();
    while(!gameWon){
        cout << " 1. Easy \n 2. Medium \n 3. Hard \n Choose a difficulty level(1-3):";
        getline(cin , difficulty);
        
        while(difficulty != "1" && difficulty != "2" && difficulty != "3" ){
            cout << endl <<"Choose only options from 1 to 3." << endl;
            cout << " 1. Easy \n 2. Medium \n 3. Hard \n Choose a difficulty level(1-3):";
            getline(cin , difficulty);
        }
        this->difficulty = difficulty[0] - '0';
        
        // --- CHARACTER CREATION ---
        Player hero_player = Player("####", alchemist_art, "alchemist");
        cout << "Alchemist Player " << endl << endl;
        hero_player.displayStats();
        cout << "1. Alchemist; Special Ability: You can change the Mark to other one." << endl;
        
        cout << "Paladin Player " << endl << endl;
        hero_player = Player("####", paladin_art, "paladin");
        hero_player.displayStats();
        cout << "2. Paladine; Special Ability: You can push the Mark one tile. " << endl;
        
        cout << endl << "Choose Your Player Type (1,2): ";
        string archetype;
        getline(cin, archetype);
        
        while(archetype != "1" && archetype != "2"){
            cout << "Invalid: type either 1 or 2!" << endl;
            cout << "Choose your character:";
            getline(cin, archetype);
        }
        
        string player_name;
        cout << endl << "Choose Your Player Name: ";
        getline(cin, player_name);
        while(player_name == ""){
            cout << "Can't put an empty name!" << endl;
            getline(cin, player_name);
        }
        
        if(archetype == "1") hero_player = Player(player_name, alchemist_art, "alchemist");
        else hero_player = Player(player_name, paladin_art, "paladin");
        
        hero = &hero_player;
        if(hero->className == "alchemist" || hero->className == "Alchemist" ){
            hero->asciiArt = alchemist_art;
        } else {
            hero->asciiArt = paladin_art;
        }
        
        clearScreen();
        
        
        
        
        // --- STORY START ---
        cout << king << endl;
        cout << "The King approaches you." << endl;
        cout << "'Sir " << hero->name << ", the Necromancer has returned.'" << endl;
        cout << "'Your choices will determine the fate of our kingdom.'" << endl;
        waitForEnter();
        
        // --- BATTLE 1: Slime ---
        cout << "At the castle gates, a Gelatinous Cube blocks the way!" << endl;
        waitForEnter();
        Enemy slime("Gelatinous Cube", 50, 15, 2, slime_art, "Acid Spit");
        if(!startBattle(slime)) continue;
        
        // --- BRANCH 1: Forest (Strength) vs Cave (Resilience) ---
        // This choice now affects STATS, giving the player a strategic decision.
        bool tookForestPath = firstEventBranch();
        
        Enemy* secondEnemy;
        if(tookForestPath) {
            // FOREST PATH: Harder hit, Reward = Attack
            cout << "The Dark Forest is overgrown and hostile." << endl;
            secondEnemy = new Enemy("Goblin Scout", 70, 20, 5, forest_goblin_art, "Swiftness");
        } else {
            // CAVE PATH: Spookier, Reward = Defense
            cout << "The Damp Cave is quiet... too quiet." << endl;
            secondEnemy = new Enemy("Cave bat", 60, 20, 0, cave_bat_art, "Screech");
        }
        
        if(!startBattle(*secondEnemy)) { delete secondEnemy; continue; }
        
        // REWARD DISTRIBUTION FOR BRANCH 1
        if(tookForestPath){
            cout << "\nIn the Goblin's camp, you find a Whetstone! (ATK +5)" << endl;
            hero->attack += 5;
        } else {
            cout << "\nIn the Bat's nest, you find an Ancient Buckler! (DEF +5)" << endl;
            hero->defense += 5;
        }
        hero->displayStats();
        waitForEnter();
        delete secondEnemy;
        
        // --- EVENT 2: Rest ---
        eventRest();
        
        // --- BATTLE 3: Orc ---
        cout << "An Orc Warrior guards the bridge!" << endl;
        Enemy orc("Orc Warrior", 100, 30, 10, orc_art, "Block");
        if(!startBattle(orc)) continue;
        
        // --- BRANCH 2: Urban (Greed/Power) vs Rural (Preparation) ---
        bool tookUrbanPath = secondEventBranch();
        
        if(tookUrbanPath){
            cout << "As you approach the Urban City, you spot the entrance." << endl;
            cout << town_entrance << endl;
            waitForEnter();
            clearScreen();
            cout << "You arrive at the Urban City. The gear here is top-tier, but expensive." << endl;
            eventShop(true); // Urban shop
        } else {
            cout << "You arrive at the Rural Village. The people are kind and potions are cheap." << endl;
            eventShop(false); // Rural shop
        }
        waitForEnter();
        
        // --- BATTLE 4: Dark Knight ---
        cout << "You stand before the Black Fortress. The Fallen Knight awaits." << endl;
        Enemy knight("Dark Knight", 120, 40, 15, dark_knight_art, "Parry");
        if(!startBattle(knight)) continue;
        
        // --- BRANCH 3: THE MAJOR MORAL CHOICE ---
        // Replaces eventMystery with a story-defining moment
        hasAmuletOfLight = eventDarkKnightInteraction();
        waitForEnter();
        
        cout << "\nYou reach the final chamber." << endl;
        waitForEnter();
        
        // --- BATTLE 5: BOSS ---
        //Enemy boss("THE NECROMANCER", 200, 50, 20, necromancer_art, "Resurrect");
        Enemy boss("THE NECROMANCER", 200, 50, 20, necromancer_art, "Resurrect");
        if(startBattle(boss)) {
            clearScreen();
            cout << "****************************************" << endl;
            cout << "          VICTORY!" << endl;
            
            // --- DYNAMIC ENDING ---
            if(hasAmuletOfLight) {
                // TRUE ENDING
                cout << "Using the Amulet of Light, you purge the darkness from the land completely!" << endl;
                cout << "The Necromancer's soul is purified, not destroyed." << endl;
                cout << "You return to the King not just as a warrior, but as a savior." << endl;
                cout << "ENDING: THE GUARDIAN OF LIGHT (Best Ending)" << endl;
            } else {
                // NORMAL ENDING
                cout << "The Necromancer falls, his body turning to ash." << endl;
                cout << "However, a cold wind still blows. The curse is broken, for now..." << endl;
                cout << "You saved the kingdom, but the darkness may return." << endl;
                cout << "ENDING: A HOLLOW VICTORY (Normal Ending)" << endl;
            }
            cout << "****************************************" << endl;
            gameWon = true;
        }
    }
}

bool Campaign::startBattle(Enemy enemy){
    cout << "A WILD " << enemy.name << " APPEARED!" << endl;
    enemy.displayStats();
    cout<< endl << "VS" << endl;
    hero->displayStats();
    waitForEnter();
    bool isPlayerBlinded = false;
    int parry_count = 0;
    while(hero->isAlive() && enemy.isAlive()){
        tic_tac_toe game{X, O};
        Mini_Max bot;
        static int count = 0;
        if(count > 0){
            count = 0;
        }
        while(!game.full()){
            count++;
            if(!game.win()){
               if(!isPlayerBlinded) game.print();
                cout << endl;
                game.win();
                if(game.OWon == 0){
                    if (isPlayerBlinded) {
                            cout << "\n=== YOU ARE BLINDED! ===" << endl;
                            
                            // 1. PRINT BLIND GRID (Shows '?' everywhere)
                            cout << "   1   2   3" << endl;
                            for (int i = 0; i < 3; i++) {
                                cout << " " << i + 1 << " [?] [?] [?]" << endl;
                            }

                            
                            string row_str, col_str;
                            cout << "Input row (1-3): " ;
                            getline(cin, row_str);
                       
                        
                            cout << "Input col (1-3): " ;
                            getline(cin, col_str);
                        
                             cout << endl;
                            
                            
                            int row = row_str[0] - '0' - 1;
                            int col = col_str[0] - '0' - 1;

                           
                            if (row >= 0 && row < 3 && col >= 0 && col < 3) {
                                if (game.matrix[row][col] != ' ') {
                                   
                                    cout << ">>> THUD! You bumped into an existing mark!" << endl;
                                    cout << ">>> TURN SKIPPED!" << endl;
                                   
                                } else {
                                    
                                    cout << ">>> You luckily found an empty spot!" << endl;
                                    game.matrix[row][col] = 'X';
                                }
                            } else {
                                cout << ">>> You stumbled out of bounds! Turn wasted." << endl;
                            }

                            isPlayerBlinded = false; // Blindness wears off after the attempt
                        }
                    else{
                        bool Player1 = true;
                        if(hero->className == "Paladin" || hero->className == "paladin"){
                            paladine paladinPlayer = paladine(X, O);
                            
                            string Player_1_choice = paladinPlayer.print_choice(count);
                            // if player chooses a regular move
                            if(Player_1_choice == "1"){
                                game.X_Move();
                            }
                            // if player chooses a special move
                            else if(Player_1_choice == "2"){
                                paladinPlayer.shift_mark(game,Player1, count);
                            }
                            // stops the game if player 1 lost
                        }
                        else if(hero->className == "Alchemist" || hero->className == "alchemist"){
                            alchemist alchemPlayer = alchemist(X, O);
                            
                            string Player_1_choice = alchemPlayer.print_choice(count);
                            
                            if( Player_1_choice == "1"){
                                game.X_Move();
                            }
                            else if( Player_1_choice == "2"){
                                alchemPlayer.switch_mark(game,Player1, count);
                            }
                        }
                    }
                    
                    
                }
                game.win();
                if(game.XWon == 0){
                    cout << enemy.name << " is thinking..." << endl;
                    
                    cout << "Current Board:" << endl;
                    
                    Mini_Max bot;
                    if((rand() % 100 > difficultyChance()) && enemy.name != "THE NECROMANCER"){ // depends on the diffficulty 1. 10% 2. 20% 3. 30%
                        if (enemy.specialAbilityName == "Swiftness") {
                            // First Move
                            bot.findBestMove(game.matrix, difficultyChance());
                            game.tic_change('O', bot.row, bot.col);
                            
                            // Second Move (only if game isn't over)
                            if (!game.win() && !game.full()) {
                                cout << ">>> GOBLIN THROWS MUD!" << endl;
                                bot.findBestMove(game.matrix, 100);
                                game.tic_change('~', bot.row, bot.col);
                                
                            }
                            cout << endl;
                        }
                        else if(enemy.specialAbilityName == "Acid Spit"){
                            enemy.ability_AcidSplash(game.matrix);
                            cout << endl;
                        }
                        else if(enemy.specialAbilityName == "Screech"){
                            enemy.ability_SonarBlind(isPlayerBlinded);
                            bot.findBestMove(game.matrix, difficultyChance());
                            game.tic_change('O', bot.row, bot.col);
                            cout << endl;
                        }
                        else if(enemy.specialAbilityName == "Block"){
                            enemy.ability_RockBlock(game.matrix);
                            bot.findBestMove(game.matrix, 100);
                            game.tic_change('O', bot.row, bot.col);
                            cout << endl;
                        }
                        else if(enemy.specialAbilityName == "Parry"){
                            bot.findBestMove(game.matrix, difficulty);
                            game.tic_change('O', bot.row, bot.col);
                            cout << endl;
                        }
                        game.win();
                    }
                    else if(enemy.name == "THE NECROMANCER" && rand() % 100 > difficultyChance() + 25){
                        enemy.castPossession(game.matrix);
                        cout << endl;
                        game.win();
                    }
                    else{
                        bot.findBestMove(game.matrix, difficulty);
                        game.tic_change('O', bot.row, bot.col);
                        cout << endl;
                        game.win();
                    }
                    
                }
                else{
                    break;
                }
            }
            else{
                break;
            }
            
        }
        cout << endl;
        
        game.print();
        
        game.result();
        
        waitForEnter();
        
        clearScreen();
        
        
        if(enemy.specialAbilityName == "Parry" && (rand() % 100 > difficultyChance()) && parry_count < 3){
            parry_count++;
            cout << "The Dark Knight parried your attack!" << endl;
            cout << "He attacks YOU!" << endl;
            hero->takeDamage(enemy.attack - 10);
            hero->displayStats();
            
        }
        else{
            // if the enemy is not a dark knight then either the enemy or player
            takeDamage(game, enemy);
        }
        
        if(enemy.name == "THE NECROMANCER" && game.OWon == 1){
            hero->takeDamage(enemy.attack);
            
            int healAmount = enemy.attack / 2;
            enemy.health += healAmount;
            
            if(enemy.health > enemy.maxHealth) enemy.health = enemy.maxHealth;
            
            cout << "The Necromancer drains your soul! He deals " << enemy.attack
            << " damage and heals for " << healAmount << " HP!" << endl;
        }
        // the hero takes the damage if the enemy is not a dark paladin and not the nectomancer then the hero takes damage
        //takeDamage(game, enemy);
        
    }
    if(hero->isAlive()) {
        cout << "You defeated " << enemy.name << "!" << endl;
       
        if(enemy.name == "Gelatinous Cube") hero->money += 10;
        else if(enemy.name == "Goblin Scout" || enemy.name == "Cave bat") hero->money += 15;
        else if(enemy.name == "Orc Warrior") hero->money += 30;
        return true;
    }else
    {
        cout << "You have fallen in battle..." << endl;
        cout << "GAME OVER" << endl;
        return false;
    }
    return enemy.isAlive();
}

bool Campaign::firstEventBranch(){
    clearScreen();
    cout << forest_split << endl;
    cout << "The path splits ahead." << endl;
    cout << "1. The Dark Forest (Known for Goblin ambushes)" << endl;
    cout << "2. The Damp Cave (Echoes with screeching)" << endl;
    cout << "Choose your path (1 or 2): ";
    string choice;
    getline(cin, choice);
    while(choice != "1" && choice != "2") {
        cout << "Choose 1 or 2: ";
        getline(cin, choice);
    }
    return (choice == "1");
}

bool Campaign::secondEventBranch(){
    clearScreen();
    cout << train_station << endl;
    cout << "You arrive at a train station. You can choose between two options." << endl;
    cout << "1. The Urban City (Known For Expensive Weapons)" << endl;
    cout << "2. The Rural Village (Known For Powerful Potions )" << endl;
    cout << "Choose your path (1 or 2): ";
    string choice;
    getline(cin, choice);
    while(choice != "1" && choice != "2") {
        cout << "Choose 1 or 2: ";
        getline(cin, choice);
    }
    return (choice == "1");
}

void Campaign::eventRest(){
    clearScreen();
    cout << "You find a campfire safe from monsters." << endl;
    cout << "You rest and recover health." << endl;
    hero->heal(50);
    waitForEnter();
}

void Campaign::eventMystery(){
    clearScreen();
    cout << "You find a mysterious chest!" << endl;
    cout << "1. Open it" << endl;
    cout << "2. Leave it (It might be trapped)" << endl;
    string choice;
    getline(cin, choice);
        
    if(choice == "1") {
        int luck = rand() % 2;
        if(luck == 0) {
            cout << "It was a trap! You take 10 damage." << endl;
            hero->takeDamage(10);
        }
        else{
            if(hero->className == "paladin" || hero->className == "Paladin"){
                cout << "You found a Magic Sword! Attack increased!" << endl;
                hero->attack += 20;
            }
            else if(hero->className == "alchemist" || hero->className == "Alchemist"){
                cout << "You found a Talisman! Attack increased!" << endl;
                hero->attack += 10;
            }
        }
        
    }
    else {
        cout << "Better safe than sorry." << endl;
    }
    waitForEnter();
}

void Campaign::eventShop(bool isUrbanArea){
    string choice{};
    vector itemList{"Healing Potion", "Attack Potion", "Defense Potion", "Strong Defense Potion", "First Aid Kit", "Mystery Staff","Durable Armor", "Strong Sword"};
    map<string, unsigned int> ruralProductCounts;

    ruralProductCounts["1"] = 10;
    ruralProductCounts["2"] = 20;
    ruralProductCounts["3"] = 15;
    ruralProductCounts["4"] = 30;
    ruralProductCounts["5"] = 0;
    
    map<string, unsigned int> urbanProductCounts;
    urbanProductCounts["1"] = 20;
    urbanProductCounts["2"] = 50;
    urbanProductCounts["3"] = 40;
    urbanProductCounts["4"] = 50;
    urbanProductCounts["5"] = 0;
    
    if(!isUrbanArea){
        
        cout << rural_shop << endl;
        cout << endl << "Your Current Balance: " << hero->money << "G"<<  endl;
        cout << "The shop offers this options: "<< endl;
        cout << "1. " << itemList[0] << " (Heals 20HP): 10G 2. " << itemList[1] << ": (ATK 10) 20G 3. " << itemList[2] << " (DEF 5): 15G 4. " << itemList[3] << " (DEF 30): 30G" << " 5. Exit the Shop." <<endl;
        cout << "Choose one of the options (1-5): ";
        getline(cin, choice);
        
        bool incorrectInput = choice != "1" && choice != "2" && choice != "3" && choice != "4" && choice != "5";
        bool negativeMoney = hero->money < 0;
        if(!incorrectInput){
            hero->spendMoney(ruralProductCounts[choice]);
           
            negativeMoney = hero->money < 0;
            hero->money += ruralProductCounts[choice];
        }
        else{
            hero->spendMoney(ruralProductCounts["4"]);
            negativeMoney = hero->money < 0;
            hero->money += ruralProductCounts["4"];
        }
       
       
    while(negativeMoney || incorrectInput){
        
        while( choice != "1" && choice != "2" && choice != "3" && choice != "4" && choice != "5"){
            cout << endl << "Invalid input.";
            cout << "Choose one of the options (1-5): ";
            getline(cin, choice);
        }
        incorrectInput = choice != "1" && choice != "2" && choice != "3" && choice != "4" && choice != "5";
        
        hero->spendMoney(ruralProductCounts[choice]);
        negativeMoney = hero->money < 0;
        
        while(hero->money < 0){
            hero->money += ruralProductCounts[choice];
            cout << endl << "Can't have negative money!" << endl;
            cout << "Choose one of the options (1-5): ";
            getline(cin, choice);
            
            hero->spendMoney(ruralProductCounts[choice]);
        }
        incorrectInput = choice != "1" && choice != "2" && choice != "3" && choice != "4" && choice != "5";
        negativeMoney = hero->money < 0;
        }
        
        hero->spendMoney(ruralProductCounts[choice]);
        
        int num_choice = choice[0] - '0';
        
        switch (num_choice) {
            case 1:
                hero->health += 20;
                break;
            case 2:
                hero->attack += 10;
                break;
            case 3:
                hero->defense += 5;
                break;
            case 4:
                hero->defense += 10;
                break;
            default:
                break;
        }
    }
    else{
        cout << "You entered an urban market in hopes of finding something good!" << endl;
        cout << town_shop << endl;
        cout << endl << "Your Current Balance: " << hero->money << "G"<<  endl;
        cout << "The shop offers this options: "<< endl;
        
        cout << "1. " << itemList[4] << " (Heals 40HP): 20G 2. " << itemList[5] << " (ATK 20): 50G 3. " << itemList[6] << " (DEF 20): 40G 4. " << itemList[7] << " (ATK 20): 50G" << " 5. Exit the Shop." << endl;
        
        cout << "Choose one of the options (1-5): ";
        getline(cin, choice);
        
       
       
        bool incorrectInput = choice != "1" && choice != "2" && choice != "3" && choice != "4" && choice != "5";
        bool negativeMoney = hero->money < 0;
        if(!incorrectInput){
            hero->spendMoney(ruralProductCounts[choice]);
            negativeMoney = hero->money < 0;
            hero->money += urbanProductCounts[choice];
        }
        else{
            hero->spendMoney(ruralProductCounts["4"]);
            negativeMoney = hero->money < 0;
            hero->money += ruralProductCounts["4"];
        }
       
       
    while(negativeMoney || incorrectInput){
        while( choice != "1" && choice != "2" && choice != "3" && choice != "4" && choice != "5"){
            cout << endl << "Invalid input.";
            cout << "Choose one of the options (1-5): ";
            getline(cin, choice);
        }
        incorrectInput = choice != "1" && choice != "2" && choice != "3" && choice != "4" && choice != "5";
        
        hero->spendMoney(ruralProductCounts[choice]);
        negativeMoney = hero->money < 0;
        
        while(hero->money < 0){
            hero->money += ruralProductCounts[choice];
            cout << endl << "Can't have negative money!" << endl;
            cout << "Choose one of the options (1-5): ";
            getline(cin, choice);
            
            hero->spendMoney(ruralProductCounts[choice]);
        }
        incorrectInput = choice != "1" && choice != "2" && choice != "3" && choice != "4" && choice != "5";
        negativeMoney = hero->money < 0;
        }
        
        
        
        int num_choice = choice[0] - '0';
        
        switch (num_choice) {
            case 1:
                hero->health += 40;
                break;
            case 2:
                hero->attack += 20;
                break;
            case 3:
                hero->defense += 20;
                break;
            case 4:
                hero->attack += 20;
                break;
            default:
                break;
        }
    }
}
