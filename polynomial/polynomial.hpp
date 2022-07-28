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
#include <list>

using namespace std;

class Polynomial{
protected:
    class Term {
    protected:
        int exponent;
        int coefficient;
        Term *next;
        Term(int exp, int coeff, Term *n){
            exponent = exp;
            coefficient = coeff;
            next = n;
        };
        friend class Polynomial;
    };
public:
    Polynomial(){
        polynomial = {0};
        it = polynomial.begin();
    };
    
    Polynomial(const Polynomial &p){
        polynomial = p.polynomial;
        it = p.it;
    };
    
    ~Polynomial();
    
    Polynomial & operator = (const Polynomial &p){
        static Polynomial w;
        w.polynomial = p.polynomial;
        w.it = p.it;
        return w;
    };
    
    void addTerm(int expon, int coeff){
        Term a(expon, coeff, nullptr);
        polynomial.insert(it, a);
    }
        
    friend ostream & operator << (ostream &out, const Polynomial &p){
      return out;          
    };      
    
private:
    list<class Temp> polynomial;
    list<int>::iterator it;
    
};


#endif /* polynomial_hpp */
