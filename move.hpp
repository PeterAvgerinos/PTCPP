//
//  move.hpp
//  specker
//
//  Created by Peter Augerinos on 24/7/22.
//

#ifndef move_hpp
#define move_hpp

#include <stdio.h>
#include <iostream>


class Move{
public:
    
    Move(int sh, int sc, int th, int tc);
    
    int getSourceHeap() const;
    int getSourceCoins() const;
    
    int getTargetHeap() const;
    int getTargetCoins() const;
    
    friend std::ostream & operator << (std::ostream &out, const Move &m);
    
private:
    int source_heap;
    int source_coins;
    int target_heap;
    int target_coins;

};

#endif /* move_hpp */
