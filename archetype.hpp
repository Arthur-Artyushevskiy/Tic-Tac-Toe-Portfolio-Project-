

#ifndef archetype_hpp
#define archetype_hpp
#include <stdio.h>
// an archetype virtual function that I did not use :(
class archetype{
    virtual void special_move() const = 0;
    virtual std::string print_choice() const = 0;
};
#endif /* archetype_hpp */
