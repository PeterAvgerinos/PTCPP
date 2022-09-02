//
//  game.hpp
//  specker
//
//  Created by Peter Augerinos on 25/7/22.
//

#ifndef game_hpp
#define game_hpp

#include <stdio.h>
#include <stdexcept>
#include <iostream>
#include "Player.hpp"
#include "state.hpp"

class Game {
public:
    Game(int heaps, int player);
    ~Game();
    
    void AddHeap(int coins) throw(logic_error);
    void AddPlayer(Player *player) throw(logic_error);
    void play(std::ostream &out) throw(logic_error);
    
    int getPlayers() const;
    const Player *getPlayer(int p) const throw(logic_error);
    
private:
    int game_heaps, game_players, current_heap, current_player;
    int *heap_coins;
    Player **players_list;
    
}

#endif /* game_hpp */
