#include <iostream> 
#include <list>
#include <ostream>
#include <vector>
#include <iterator>

using namespace std; 

class Edge { 
    private: 
        int Destination; 

    public: 
        Edge();
        Edge(int d):Destination(d) {}
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

    public:
        list<Edge> edgelist;
        Vertex(): ID(0), edgelist() {};
        Vertex(const int &id):ID(id), edgelist() {}
        Vertex(Vertex &v): ID(v.ID), edgelist(v.edgelist) {};
        ~Vertex(); 

        void setID(int &id) { 
            ID = id;
        };

        int getID() { 
            return ID;
        };

};


class Graph { 
    private: 
        vector<Vertex> vertices;
        int N;
        int M;

        bool vertexExists(Vertex &v) { 
            for (auto iterator=vertices.begin(); iterator != vertices.end(); iterator++) { 
                if (v.getID() == (*iterator).getID()) { 
                    return true;
                }
            }
            return false;
        }

        bool vertexExistsbyID(const int &id) { 
            for (int i=0; i < vertices.size(); i++){ 
                if (id == vertices.at(i).getID()) { 
                    return true;
                }
            }
            return false; 
        }

        bool edgeExists(const int &id1,const int &id2) { 
                for (auto iterator=vertices.at(id1).edgelist.begin(); iterator != vertices.at(id1).edgelist.end(); iterator++) { 
                    if ((*iterator).getDestination() == id2) { 
                        return true;
                    }
                }            
                return false;
        }

        int Degree(Vertex &v) { 
            int count = 0;
            for (auto iterator=vertices.at(v.getID()).edgelist.begin(); iterator != vertices.at(v.getID()).edgelist.end(); ++iterator) {
                count++;
            }
            return count;
        }

    public: 
        Graph();
        Graph(Graph &p);
        ~Graph();

        void setN(const int &n) { 
            N = n;
        }

        void setM(const int &m) { 
            M = m;
        }
        
        const int getN() { 
            return N;
        }

        const int getM() {
            return M;
        }

        void addVertex(Vertex &v) { 
            if (vertexExists(v)) { 
                return;
            }
            else { 
                vertices.push_back(v);
            }
        }

        void addEdge(const int &id1, const int &id2) { 
            if (vertexExistsbyID(id1) && vertexExistsbyID(id2)) { 
                    if (!edgeExists(id1, id2)) { 
                        vertices.at(id1).edgelist.push_back(id2);
                        vertices.at(id2).edgelist.push_back(id1);
                    }
                }            
        }

        bool EulerCircuit(Vertex &v) { 
            for (auto iterator = vertices.begin(); iterator != vertices.end(); ++iterator) {
                if (this->Degree(*iterator)%2 == 0) {
                    continue;
                }
                else {
                    return false;
                }
            }
            return true;
        }

        bool EulerPath(Vertex &v) { 
            int count = 0;
            for (auto iterator = vertices.begin(); iterator != vertices.end(); ++iterator) {
                if (this->Degree(*iterator)%2 == 0) {
                    continue;
                }
                if (this->Degree(*iterator)%2 == 1) { 
                    count++;
                }
                else {
                    return false;
                }
            }
            if ((count == 0) || (count == 2)) { 
                return true;
            }
            return false;
        }
        
        friend ostream & operator << (ostream &out,Graph &g) { 
            for (auto iterator=g.vertices.begin(); iterator != g.vertices.end(); iterator++){ 
                out << (*iterator).getID();
                for (auto jiterator=(*iterator).edgelist.begin(); jiterator != (*iterator).edgelist.end(); jiterator++) {
                    out << (*jiterator).getDestination() << " ";
                }
                out << endl;
            }
            return out;
        }
};
