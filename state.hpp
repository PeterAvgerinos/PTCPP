//
//  state.hpp
//  specker
//
//  Created by Peter Augerinos on 24/7/22.
//

#ifndef state_hpp
#define state_hpp

#include <stdio.h>
#include <iostream>
#include <stdexcept>
#include "move.hpp"

class State {
public:
    State(int h, const int c[], int n);
    ~State();
    
    void next(const Move &m) noexcept(false);
    bool winning() const;
    
    int getHeaps() const;
    int getCoins(int h) const noexcept(false);
    
    int getPlayers() const;
    int getPlaying() const;
    
    friend std::ostream & operator << (std::ostream &out, const State &s);
    
    
private:
    int heaps;
    int *heap_coins;
    int number_of_players;
    int *tableau;
    
};

#endif /* state_hpp */
