//
//  Righteous_Player.hpp
//  specker
//
//  Created by Peter Augerinos on 25/7/22.
//

#ifndef Righteous_Player_hpp
#define Righteous_Player_hpp

#include <stdio.h>
#include <stdexcept>
#include <iostream>
#include "move.hpp"
#include "state.hpp"
#include "Player.hpp"

class Righteous_Player: public Player {
public:
    Righteous_Player (const std::string &n){
        player_type = "Righteous"
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
        int j = 0;
        while (s.getCoins(j) == 0){
            j++;
        }
        target_heap = j;
        target_coins = s.getCoins(j);
        for (int i= j + 1; i < s.getHeaps(); i++){
            if (target_coins > s.getCoins(i) && s.getCoins(i) > 0){
                target_heap = i;
                target_coins = s.getCoins(i);
            }
            Move RighteousObject(source_heap, source_coins/2, target_heap, source_coins/2 - 1);
            return RighteousObject;
        }
    };
    
private:
    std::string player_type;
};

#endif /* Righteous_Player_hpp */
