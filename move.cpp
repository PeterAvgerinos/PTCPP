//
//  move.cpp
//  specker
//
//  Created by Peter Augerinos on 24/7/22.
//

#include "move.hpp"
#include <iostream>

Move::Move(int sh, int sc, int th, int tc){
    source_heap = sh;
    source_coins = sc;
    target_heap = th;
    target_coins = tc;
};

int Move::getSourceHeap() const {
    return source_heap;
}

int Move::getSourceCoins() const {
    return source_coins;
}

int Move::getTargetHeap() const {
    return target_heap;
}

int Move::getTargetCoins() const {
    return target_coins;
}

std::ostream & operator << (std::ostream &out, const Move &m){
    if (m.getTargetCoins()){
        out << "takes " << m.getSourceCoins() << "out of " << m.getSourceHeap() << "and puts " << m.getTargetCoins() << "in " << m.getTargetHeap() << std::endl;
    }
    else {
        out << "takes " << m.getSourceCoins() << "out of " << m.getSourceHeap() << "and puts nothing " << std::endl;
    }
    return out;
};
