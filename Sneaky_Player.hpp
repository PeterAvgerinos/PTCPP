//
//  Sneaky_Player.hpp
//  specker
//
//  Created by Peter Augerinos on 25/7/22.
//

#ifndef Sneaky_Player_hpp
#define Sneaky_Player_hpp

#include <stdio.h>
#include <stdexcept>
#include <iostream>
#include "move.hpp"
#include "state.hpp"
#include "Player.hpp"

class Sneaky_Player: public Player {
public:
    Sneaky_Player (const std::string &n){
        player_type = "Sneaky"
    };
    
    virtual const std::string & getType() const override{
        return player_type;
    };
    
    virtual Move play(const State &s) override{
        int j=0;
        while (s.getCoins(j) == 0){
            j++;
        }
        int source_heap = j;
        int source_coins = s.getCoins(j);
        for (int i= j + 1; i < s.getHeaps(); i++){
            if (source_course > s.getCoins(i) && s.getCoins(i) > 0){
                source_heap = i;
                source_coins = s.getCoins(i);
            }
        }
        Move SneakyObject(source_heap, source_coins, 0, 0);
        return SneakyObject;
    };
    
private:
    std::string player_type;
};

#endif /* Sneaky_Player_hpp */
