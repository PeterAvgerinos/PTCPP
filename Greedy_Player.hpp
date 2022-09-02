//
//  Greedy_Player.hpp
//  specker
//
//  Created by Peter Augerinos on 25/7/22.
//

#ifndef Greedy_Player_hpp
#define Greedy_Player_hpp

#include <stdio.h>
#include <stdexcept>
#include <iostream>
#include "move.hpp"
#include "state.hpp"
#include "Player.hpp"

class Greedy_Player: public Player {
public:
    Greedy_Player (const std::string &n){
        player_type = "Greedy"
    };
    
    virtual const std::string & getType() const override{
        return player_type;
    };
    
    virtual Move play(const State &s) override{
        int source_heap = 0;
        int source_coins = 0;
        for (int i=0; i < s.getHeaps(); i++){
            if (source_coins < s.getCoins(i)){
                source_coins = s.getCoins(i);
                source_heap = i;
            }
        }
        Move GreedyObject(source_heap,source_coins, 0, 0);
        return GreedyObject;
    };

    
private:
    std::string player_type;
};

#endif /* Greedy_Player_hpp */
