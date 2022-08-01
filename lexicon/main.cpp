#include <iostream>
#include "lexicon.hpp"

using namespace std; 

int main() { 
    lexicon l;
    l.insert("the");
    l.insert("boy");
    l.insert("and");
    l.insert("the");
    l.insert("wolf");
    cout << l.lookup("the") << endl;
    cout << l.depth("and") << endl;
    cout << l;
    l.replace("boy", "wolf");
    cout << l;
    cout << l.depth("and");
}
