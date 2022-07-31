#include <iostream>
#include "polynomial2.hpp"

int main() {
Polynomial p; // 0 p.addTerm(1, 3); // 3x
p.addTerm(2, 1); // x^2
p.addTerm(0, -1); // -1
Polynomial q(p); // x^2 + 3x - 1
q.addTerm(1, -3); // -3x
cout << "P(x) = " << p << endl;
cout << "P(1) = " << p.evaluate(1) << endl;
cout << "Q(x) = " << q << endl;
cout << "Q(1) = " << q.evaluate(1) << endl;
cout << "(P+Q)(x) = " << p+q << endl;
cout << "(P*Q)(x) = " << p*q << endl;
}

