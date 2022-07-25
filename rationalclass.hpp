//
//  rationalclass.hpp
//  rational1
//
//  Created by Peter Augerinos on 22/7/22.
//

#ifndef rationalclass_hpp
#define rationalclass_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

class Rational {
    
public:
    Rational();
    
    void setRational(int a, int b);
    
    Rational add(Rational r);
    
    Rational sub(Rational r);
    
    Rational mul(Rational r);
    
    Rational div(Rational r);
    
    void printRational();
    
    friend Rational operator / (Rational const &a, Rational const &b);

    friend Rational operator * (Rational const &a, Rational const &b);
    
    friend Rational operator + (Rational const &a, Rational const &b);
    
    friend Rational operator - (Rational const &a, Rational const &b);
    
    friend ostream & operator << (ostream &out, Rational const &a);
    
private:
    int nom;
    int den;
    
    int gcd(int a, int b){
        int result = min(a, b); // Find Minimum of a nd b
           while (result > 0) {
               if (a % result == 0 && b % result == 0) {
                   break;
               }
               result--;
           }
           return result; // return gcd of a nd b
    }
};

#endif /* rationalclass_hpp */
