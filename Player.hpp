//
//  Player.hpp
//  specker
//
//  Created by Peter Augerinos on 24/7/22.
//

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include <stdexcept>
#include <iostream>
#include "move.hpp"
#include "state.hpp"
#include "Greedy_Player.hpp"
#include "Spartan_Player.hpp"
#include "Sneaky_Player.hpp"
#include "Righteous_Player.hpp"

class Player {
public:
    
    Player (const std::string &n){
        player_name = n;
    };
    
    virtual ~Player(){
        player_name.clear();
    };
    
    virtual const std::string & getType() const = 0;
    
    virtual Move play(const State &s) = 0;
    
    friend std::ostream & operator << (std::ostream &out, const Player &player){
        out << player.getType() << "player" << player_name << std::endl;
        return out;
    };

protected:
    std::string player_name;
};
#endif /* Player_hpp */
