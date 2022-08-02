#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>

using namespace std; 

class Edge { 
    private: 
        int Destination;

    public:
        Edge();
        Edge(const int &d): Destination(d) {}
        Edge(const Edge &e): Destination(e.Destination) {}

        int getDestination() {
            return this->Destination;
        }

        void setDestination(const int &d) { 
           this->Destination = d; 
        }
};

class Vertex { 
    private:
        int ID;
        list<Edge> edgelist;

        void copy(const list<Edge> &e) { 
            for (auto iterator = e.begin(); iterator != e.end(); ++iterator) { 
                this->edgelist.push_back(*iterator);
            }
        }

        void purge() {
            for (auto iterator = this->edgelist.begin(); iterator != this->edgelist.end(); ++iterator) { 
                this->edgelist.pop_front();
            }
        }

    public:
        Vertex();
        Vertex(const int &id): ID(id), edgelist() {}
        Vertex(const Vertex &v): ID(v.ID), edgelist() {copy(v.edgelist);}
        ~Vertex() {purge();}

        int getID() { 
            return this->ID;
        }

        list<Edge> getList() { 
            return edgelist;
        }

        void setID(const int &id) { 
            this->ID = id;
        }

        void setList(const list<Edge> &l) {
            purge();
            for (auto iterator = l.begin(); iterator != l.end(); ++iterator) { 
                this->edgelist.push_back(*iterator);
            }
        }

};

class Graph { 
    private: 
        vector<Vertex> vertices;

        bool VertexExistsbyID(const int &id) {
            for (auto iterator = vertices.begin(); iterator != vertices.end(); ++iterator) { 
                if ((*iterator).getID() == id) {
                    return true;
                }
            }
            return false;
        };

        bool EdgeExistsbyID(const int &id1, const int &id2) {
            if (VertexExistsbyID(id1) && VertexExistsbyID(id2)) { 
                for (auto iterator = vertices.at(id1).getList().begin(); iterator != vertices.at(id1).getList().end(); ++iterator) {
                    
                }
            }
        }

        void copy(const vector<Vertex> &v);

        void purge();

    public:
        Graph(); 
        Graph(const vector<Vertex> &v); 
        Graph(const Graph &g);
        ~Graph();

        void addVertex(const Vertex &v);
        void addVertexbyID(const int &id);

        void addEdgebyID(const int &id1, const int &id2);

        bool EulerCircuit();

        bool EulerPath();

        friend ostream & operator << (ostream &out, const Graph &g);
        
};
