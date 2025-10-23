
#ifndef tic_tac_toe_hpp
#define tic_tac_toe_hpp

#include <stdio.h>
#include <vector>
#include <string>
using namespace std;
// an old tic_tac_toe class that allows the player to play an older version of the game
class tic_tac_toe{
public:
    std::vector<std::vector<char>> matrix{
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    
  tic_tac_toe(char X, char O){
        this->X = X;
        this->O = O;
    }
    
    char X{'X'};
    char O{'O'};
    bool XWon{};
    bool OWon{};
    bool Null{};
    string row{};
    string col{};
    
    
    
    
    bool tic_change(char c, string row, string col);
    bool win();
    bool full() const;
    bool check_hor() ;
    bool check_ver() ;
    bool check_diag_right() ;
    bool check_diag_left() ;
    void print() const;
    void X_Move();
    void run();
    void O_Move();
    void result();
};

#endif /* tic_tac_toe_hpp */
