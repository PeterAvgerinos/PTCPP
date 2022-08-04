#include <iostream>
#include <vector>
#include <string>

using namespace std; 

class Road { 
    private:
        string Destination;
        int Weight;

    public:
        Road(): Destination(), Weight(0) {}
        Road(const string &d, const int &w): Destination(d), Weight(w) {}
        Road(const Road &r): Destination(r.Destination), Weight(r.Weight) {}

        void setDestination(const string &d) { 
            this->Destination = d;
        }

        void setWeight(const int &w) {
            this->Weight = w;
        }

        const string & getDestination() {
            return this->Destination;
        }

        const int & getWeight() {
            return this->Weight;
        }

};

class City {
    private: 


    public:
};
