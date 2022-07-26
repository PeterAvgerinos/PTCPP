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
            for (const auto &Destination: r) { 
                this->roadlist.push_back(Destination);
            }
        }

        void purge() { 
            for (const auto &road: roadlist) { 
                this->roadlist.pop_back();
            }
        }

    public:
        City(): Name(), roadlist() {}
        City(const string &name): Name(name), roadlist() {}
        City(const City &c): Name(c.Name),roadlist() {copy(c.roadlist);}
        ~City() { purge(); }

        const string & getName() const {
            return this->Name;
        }

        vector<Road> & getRoadlist() {
            return this->roadlist;
        }

        void setName(const string &name) { 
            this->Name = name;
        }

        void setRoadlist(const vector<Road> &r) {
            purge();
            for (const auto &road: r) { 
                this->roadlist.push_back(road);
            }
        }
};

class Network { 
    private:
        vector<City> cities;

        void copy(const vector<City> &c) { 
            purge();
            for (const auto &city: c) { 
               this->cities.push_back(city); 
            }
        }

        void purge() { 
            for (const auto &city: this->cities) { 
                this->cities.pop_back();
            }
        }

        bool CityExists(const City &c) { 
            for (const auto &city: this->cities) {
                if (c.getName() == city.getName()) {
                    return true;
                }
            }
            return false;
        }

        bool CityExistsbyName(const string &c) { 
            for (const auto &city: cities) {
                if (c == city.getName()) {
                    return true;
                }
            }
            return false;
        }
    
        bool RoadExists(const string &d1, const string &d2) {
            if (CityExistsbyName(d1) && CityExistsbyName(d2)) { 
                for (const auto &road: cities.getName(d1).getRoadlist()) {

            }
        }
    public:
        Network():cities() {}
        Network(const vector<City> &c):cities() { copy(c);}
        ~Network() {purge();}

        void addCity(const City &c) { 
            if (!CityExists(c)) { 
                this->cities.push_back(c);
            }
        }

        void addRoad(const Road &r) { 
            if (!RoadExists(r)) {
                
            }
        }

};
