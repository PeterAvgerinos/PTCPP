//
//  game.cpp
//  specker
//
//  Created by Peter Augerinos on 25/7/22.
//

#include "game.hpp"
#include <stdio.h>
#include <stdexcept>
#include <iostream>
#include "Player.hpp"

Game::Game(int heaps, int players){
    game_heaps = heaps;
    game_players = players;
    int heap_coins = new int [heaps];
    current_heap = 0;
    current_player = 0;
    player_list = new Player*[players];
};

Game::~Game(){
    delete[] heap_coins;
    delete[] player_list;
};


void Game::AddHeap(int coins) throw(logic_error){
    if (current_heap > game_heaps){
        throw logic_error("all heaps are added");
    }
    else if (coins < 0){
        throw logic_error("coins must be a positive number");
    }
    else{
        heap_coins[currentheap++] = coins;
    }
};


void Game::AddPlayer(Player *player) throw(logic_error){
    if ( current_player > game_players){
        throw logic_error("all player are added")
    }
    else {
        player_list[current_player++] == player;
    }
};


void play(std::ostream &out) throw(logic_error){
    i = 0;
    State currentState(int game_heaps, int gameplayers);
    while(!currentState.winning()){
        
    }
};


int Game::getPlayers() const{
    return game_players;
};

const Player *Game::getPlayer(int p) const throw(logic_error){
    if (p > game_players) {
        throw logic_error("no such player in the game")
    }
    else {
        return player_list[p];
    }
};


