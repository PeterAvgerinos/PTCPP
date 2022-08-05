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

        const string & getDestination() const {
            return this->Destination;
        }

        const int & getWeight() {
            return this->Weight;
        }

};

class City {
    private: 
        string Name; 
        vector<Road> roadlist;

        void copy(const vector<Road> &r) { 
            for (const auto &road: r) { 
                this->roadlist.push_back(road);
            }
        }

        void purge() { 
            for (const auto &road: roadlist) { 
                this->roadlist.pop_back();
            }
        }

    public:
        City(): Name(), roadlist() {}
        City(const string &n, const vector<Road> &r): Name(n) {copy(r);}
        ~City() { purge(); }
};

class Network { 
    private:


    public:

};
