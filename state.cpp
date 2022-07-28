//
//  state.cpp
//  specker
//
//  Created by Peter Augerinos on 24/7/22.
//

#include "state.hpp"
#include <iostream>
#include <stdexcept>

State::State(int h, const int c[], int n){
    heaps = h;
    heap_coins = new int [heaps];
    number_of_players = n;
    tableau = new int [number_of_players];

    for (int i=0; i<=heaps; i++){
        heap_coins[i] = c[i];
    }

    for (int i=0; i<=number_of_players; i++){
        tableau[i] = 0;
    }
};


State::~State(){
    delete[] heap_coins;
    delete[] tableau;
    return;
};


void State::next(const Move &m) noexcept(false){
    if ((m.getSourceHeap() < heaps || m.getTargetHeap() < heaps) || (m.getSourceHeap() < 0 || m.getTargetHeap() < 0)){
        throw std::logic_error("Invalid Heap!");
    }
    else if ((m.getSourceCoins() > heap_coins[m.getSourceHeap()]) || (m.getSourceCoins() < 1 || m.getTargetCoins() < 0) || (m.getSourceCoins() < m.getTargetCoins())){
        throw std::logic_error("Invalid Coins");
    }
    else{
    heap_coins[m.getSourceHeap()] -= m.getSourceCoins();
    heap_coins[m.getTargetHeap()] += m.getTargetCoins();
    }
};


bool State::winning() const {
    int s = 0;
    for (int i=0; i < heaps; i++){
        if (heap_coins[i] != 0){
            s += getCoins(i);
        }
    }
    return not s;
};


int State::getHeaps() const {
    return heaps;
};


int State::getCoins(int h) const noexcept(false) {
    if (h < 0 || h > heaps) {
                    throw std::logic_error("Invalid heap number, enter a number between 1 and heaps!");
                    return 1;
    }
    else{
        return heap_coins[h];
    }
};


int State::getPlayers() const {
    return number_of_players;
};


int State::getPlaying() const {
    return *tableau ++4;
    };


std::ostream & operator << (std::ostream &out, const State &s){
    for (int i=0; i < s.getHeaps(); i++){
        if (i < s.getHeaps() - 1){
            out << s.getCoins(s.getHeaps()) << ", ";
        }
        else {
            out << s.getCoins(s.getHeaps());
        }
    }
    out << "with " << s.getPlaying() << "/" << s.getPlayers() << std::endl;
    return out;
};

