//
//  Spartan_Player.hpp
//  specker
//
//  Created by Peter Augerinos on 25/7/22.
//

#ifndef Spartan_Player_hpp
#define Spartan_Player_hpp

#include <stdio.h>
#include <stdexcept>
#include <iostream>
#include "move.hpp"
#include "state.hpp"
#include "Player.hpp"

class Spartan_Player: public Player {
public:
    Spartan_Player (const std::string &n){
        player_type = "Spartan"
    };
    
    virtual const std::string & getType() const override{
        return player_type;
    };
    
    virtual Move play(const State &s) override{
        int source_heap = 0;
        int source_coins = 0;
        for (int i=0; i < s.getHeaps(); i++){
            if (source_coins < s.getCoins()){
                source_heap = i;
                source_coins = s.getCoins();
            }
        }
        Move SpartanObject(source_heap, 1, 0, 0);
        return SpartanObject;
    };
    
private:
    std::string player_type;
};

#endif /* Spartan_Player_hpp */
