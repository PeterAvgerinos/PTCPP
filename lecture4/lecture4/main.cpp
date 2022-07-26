//
//  main.cpp
//  lecture4
//
//  Created by Peter Augerinos on 25/7/22.
//

#include <iostream>
#include "objects.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    niceRectangle nr;
    nr.print(cout);
    
    niceRectangle nr2(2, 3, 1, "blue");
    nr2.print(cout);
    
    cout << "nr2 area = " << nr2.area() << "perimeter = " << nr2.perimeter() << endl;
    nr2.setA(5);
    cout << "nr2 area = " << nr2.area() << "perimeter = " << nr2.perimeter() << endl;

    
    cout << "------------------------------------------------------------" << endl;
    
    return 0;
}
