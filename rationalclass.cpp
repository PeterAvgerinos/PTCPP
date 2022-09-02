//
//  rationalclass.cpp
//  rational1
//
//  Created by Peter Augerinos on 22/7/22.
//

#include "rationalclass.hpp"
#include <iostream>

using namespace std;

Rational::Rational(){
    
};

void Rational::setRational(int a, int b){
    this->nom = a;
    this->den = b;
};

Rational Rational::add(Rational r){
    Rational w;
    w.den = gcd(this->den, r.den);
    w.nom = w.den*this->nom + w.den*r.nom;
    return w;
}

Rational Rational::sub(Rational r){
    Rational w;
    w.den = gcd(this->den, r.den);
    w.nom = w.den*this->nom - w.den*r.nom;
    return w;
}

Rational Rational::mul(Rational r){
    Rational w;
    w.den = this->den*den;
    w.nom = this->nom*r.nom;
    return w;
}

Rational Rational::div(Rational r){
    Rational w;
    w.nom = this->nom*r.den;
    w.den = this->den*r.nom;
    return w;
}

void Rational::printRational(){
    cout << this->nom << "/" << this->den << endl;
};

Rational operator +(Rational const &a, Rational const &b){
    Rational w;
    w.den = a.den*b.den;
    w.nom = a.nom*b.den + b.nom*a.den;
    return w;
}

Rational operator -(Rational const &a, Rational const &b){
    Rational w;
    w.den = a.den*b.den;
    w.nom = a.nom*b.den - b.nom*a.den;
    return w;
}

Rational operator *(Rational const &a, Rational const &b){
    Rational w;
    w.den = a.den*b.den;
    w.nom = a.nom*b.nom;
    return w;
}

Rational operator /(Rational const &a, Rational const &b){
    Rational w;
    w.nom = a.nom*b.den;
    w.den = a.den*b.nom;
    return w;
}

ostream & operator << (ostream &out, Rational const &a){
    out << a.nom << "/" << a.den << " ";
    return out;
}

