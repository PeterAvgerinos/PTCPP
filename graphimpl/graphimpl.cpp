#include <iostream> 
#include <list>
#include <vector>

using namespace std; 

class Edge { 
    private: 
        int Destination; 

    public: 
        Edge();
        Edge(const Edge &e): Destination(e.Destination) {} 

        void setDestination(const int &d) {
        Destination = d;
        }

        int getDestination() { 
            return Destination;
        }
};


class Vertex {
    private:
        int ID;
        list<Edge> edgelist;

    public:
        Vertex();
        Vertex(const Vertex &v): ID(v.ID), edgelist(v.edgelist) {};
        ~Vertex(); 

        void setID(const int &id) { 
            ID = id;
        };

        int getID() { 
            return ID;
        };

};


class Graph { 
    private: 
        vector<Vertex> vertices;


    public: 
        Graph();
        Graph(const Graph &p);
        ~Graph();


};
