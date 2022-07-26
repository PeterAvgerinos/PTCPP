//
//  polynomial.hpp
//  polynomial
//
//  Created by Peter Augerinos on 26/7/22.
//

#ifndef polynomial_hpp
#define polynomial_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

class Polynomial {
protected:
    
    
public:
    Polynomial(){
        
    };
    Polynomial(const Polynomial &p);
    ~Polynomial();
    
    Polynomial & operator = (const Polynomial &p);
    
    void addTerm(int expon, int coeff);
    double evaluate(double x);
    
    friend Polynomial operator + (const Polynomial &p, const Polynomial &q);
    friend Polynomial operator * (const Polynomial &p, const Polynomial &q);
    
    friend ostream & operator << (ostream &out, const Polynomial &p);
    
    
    
private:
    int degree;
    int coefficient;
    
};

#endif /* polynomial_hpp */
