//
//  tic_tac_toe.hpp
//  Tic-Tac-Toe
//
//  Created by Arthur on 15/09/25.
//

#ifndef tic_tac_toe_hpp
#define tic_tac_toe_hpp

#include <stdio.h>
#include <vector>
using namespace std;
class tic_tac_toe{
public:
    std::vector<std::vector<char>> matrix{
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    
    bool XWon{};
    bool OWon{};
    bool Null{};
    string row{};
    string col{};
    
    void is_number_o();
    void is_number_x();
    void num_bound_x();
    void O_space_check();
    void is_digit_x();
    void num_bound_o();
    void is_digit_o();
    void X_space_check();
    
    void tic_change(char c, string row, string col);
    bool win();
    bool full() const;
    bool check_hor() ;
    bool check_ver() ;
    bool check_diag_right() ;
    bool check_diag_left() ;
    void print() const;
};

#endif /* tic_tac_toe_hpp */
