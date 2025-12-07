
#include <iostream>
#include <string>
#include <vector>
#include "tic_tac_toe.hpp"
#include "Mini_Max.hpp"
#include <cctype>
#include "BattleTicTacToe.hpp"
#include "Player.hpp"
#include "Campaign.hpp"
#include "Enemy.hpp"
//#include "MiniMax.cpp"
using namespace std;


/*Time to turn our tic-tac-toe into a bigger game! You must use your previous portfolios' code for this, and you must do this in the same github repository.
 
 You are to create an entire campaign of battles for your player to go through. Battles can follow a set order, or be chosen randomly, but there must be a defined end so the player can win (e.g. after 10 battles)

 Requirement 1) At the start of the game, the player can choose a name for their character, and a class (Paladin or Alchemist)

 Requirement 2) The player should have stats. Health, attack, and defense.

 Requirement 3) There must be a story with a beginning and end. For example, the player is a knight going to face a dragon. The story should progress with each battle.

 Requirement 4) Each battle is against a different opponent, be they villain, monster, or obstacle. Each opponent has the same three stats as the player. When the player wins a match of tic-tac-toe, the opponent loses health equal to the player's attack minus the opponent's defense. When the opponent wins, the player loses health equal to the opponent's attack minus the player's defense. The player should play matches against the opponent until one of them runs out of health. If the opponent dies, the player continues in the campaign. If the player dies, they lose the game and the campaign restarts.

 Requirement 5) The opponents should all make their moves randomly.

 Requirement 6) In between battles, there should be some events. These might heal the player, or increase their stats (or lower them if you're mean... just not below 0!). At least one event should involve some player choice.

 Requirement 7) The final boss should have their own special ability that they randomly use.

 Requirement 8) The campaign should have at least 5 battles, and at least 3 in between events

 You must do two of the following choices

 Choice Requirement 1 (Branching Paths): The player can choose between multiple options at each step of the campaign. Their choices should result in different story outcomes. Some choices might be better than others, rewarding more stats or giving a happier ending.

 Choice Requirement 2 (Powerful Foes): Every foe you face should have their own special ability. The final boss should have more than one special ability.

 Choice Requirement 3 (Shopping): Encounters should award the player with money. Some of the events between battles should be shops, which allow the player to buy items with their money. Items might increase the player's stats or heal them.

 Choice Requirement 4 (Saving): The player's progress in the campaign should be saved in a file. This includes which step of the campaign they are at, as well as their health, attack, and defense (and gold if you're doing choice 3). If I close the game and start again, I should continue from where I was!


 Doing 3 of these choices will earn you 10 extra credit points. Doing all 4 will earn you 20 extra credit points.*/

int main(int argc, const char * argv[]) {
    //tic_tac_toe tac{'X', 'O'};
    //tac.run();
    //BattleTicTacToe battle{};
    //battle.runBattle();
    
    //Player pl{"bob", true};
    //pl.displayStats();
   
   
   
    std::string alchemist = R"(
                         ____ 
                        .'* *.'
                       __/_*_*(_
                      / _______ \
                     _\_)/___\(_/_ 
                    / _((\- -/))_ \
                    \ \())(-)(()/ /
                      ' \(((()))/ '
                    / ' \)).))/ ' \
                   / _ \ - | - /_  \
                  (   ( .;''';. .'  )
                  _\"__ /    )\ __"/_
                    \/  \   ' /  \/
                     .'  '...' ' )
                      / /  |  \ \
                     / .   .   . \
                    /   .     .   \
                   /   /   |   \   \
                 .'   /    b    '.  '.
            _.-'    /     Bb     '-. '-._ 
        _.-'       |      BBb       '-.  '-. 
        (________mrf\____.dBBBb.________)____)
    )";
    
    string paladin_art = R"(
         _,.
          ,` -.)
         ( _/-\\-._
        /,|`--._,-^|            ,
        \_| |`-._/||          ,'|
          |  `-, / |         /  /
          |     || |        /  /
           `r-._||/   __   /  /
       __,-<_     )`-/  `./  /
      '  \   `---'   \   /  /
          |           |./  /
          /           //  /
      \_/' \         |/  /
       |    |   _,^-'/  /
       |    , ``  (\/  /_
        \,.->._    \X-=/^
        (  /   `-._//^`
         `Y-.____(__}
          |     {__)
                () 
    )";
    
   
    Campaign cmp{};
    cmp.startCampaign();
   
    return 0;
}


