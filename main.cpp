//
//  main.cpp
//  rational1
//
//  Created by Peter Augerinos on 22/7/22.
//

#include <iostream>
#include <ostream>
#include "rationalclass.hpp"

using namespace std;

int main() {
    
    Rational a;
    a.setRational(1, 2);
    Rational b;
    b.setRational(3, 4);
    Rational c;
    c.setRational(5, 6);
    Rational w;
    w = a + b;
    cout << w << endl;
    cout << a << "should still be 1/2" << endl;

    return 0;
}
