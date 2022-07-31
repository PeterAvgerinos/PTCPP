#include <iostream> 

using namespace std; 

class lexicon { 
    private: 


    public:
        lexicon();
        ~lexicon();

        void insert(const string &s);
        int lookup(const string &s) const;
        int depth(const string &s) const;
        void replace(const string &a, const string &b);

        friend ostream & operator << (ostream &out, const lexicon &l);


}
