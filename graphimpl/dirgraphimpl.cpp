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

        void setList(list<Edge> &l) {
            purge();
            for (auto iterator = l.begin(); iterator != l.end(); ++iterator) { 
                this->edgelist.push_back(*iterator);
            }
        }


};


class Graph { 
    private: 
        vector<Vertex> vertices;

        bool VertexExists(Vertex &v) { 
            for (auto iterator = vertices.begin(); iterator != vertices.end(); ++iterator) { 
                if ((*iterator).getID() == v.getID()) { 
                    return true;
                }
            }
            return false; 
        }


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
                    if ((*iterator).getDestination() == id2){
                        return true;
                    }                    
                }
            }
            return false;
        }

        void copy(const vector<Vertex> &v){ 
            purge();
            for (auto iterator = v.begin(); iterator != v.end(); ++iterator) {
                vertices.push_back(*iterator);
            }           
        };

        void purge() {
            for (auto iterator = vertices.end(); iterator != vertices.begin(); --iterator) {
                vertices.pop_back();
            }
        }

        int VertexAmount() {
            int count = 0; 
            for (auto iterator = vertices.begin(); iterator != vertices.end(); iterator ++){
                count++;
            }
            return count;
        }

        vector<int> inDegree() {
            vector<int> counts;
            for (int i=0; i < VertexAmount(); ++i) { 
                counts[i] = 0;
            }
            for (auto iterator = vertices.begin(); iterator != vertices.end(); ++iterator) {
                int i=0;
                for (auto jiterator = (*iterator).getList().begin(); jiterator != (*iterator).getList().end(); ++jiterator) {
                    counts[i] += 1;
                    i++;
                }
            }
            return counts;
        }

        vector<int> outDegree() {
            vector<int> counts;
            for (int i=0; i < VertexAmount(); ++i) {
                counts[i] = 0;
            }
            for (auto iterator = vertices.begin(); iterator != vertices.end(); ++iterator) {
                int i=0;
                for (auto jiterator = (*iterator).getList().begin(); jiterator != (*iterator).getList().end(); ++jiterator) {
                    if ((*jiterator).getDestination()==(*iterator).getID()) {
                        counts[i] += 1;
                        i++;
                    }
                }
            }
            return counts;
        }

    public:
        Graph(); 
        Graph(const vector<Vertex> &v) {copy(v);}; 
        Graph(const Graph &g) {copy(g.vertices);}
        ~Graph(){purge();}

        void addVertex(Vertex &v) {
            if (!VertexExists(v)){ 
                this->vertices.push_back(v);
            }
        }

        void addVertexbyID(const int &id) {
            if (!VertexExistsbyID(id)) {
                Vertex v(id);
                this->vertices.push_back(v);
            }
        }
            

        void addEdgebyID(const int &id1, const int &id2) {
            if (!EdgeExistsbyID(id1, id2)) { 
                this->vertices.at(id1).getList().push_back(id2);
            }
        }

        bool EulerCircuit(){
            vector<int> count;
            for (int i=0; i < VertexAmount(); ++i) {
                count[i] = 0;
            }
            if (!(inDegree() == count && outDegree() == count )) { 
                if (inDegree() == outDegree()) {
                    return true;
                }
            }
            return false; 
        }

        bool EulerPath() { 
            int count1 = 0;
            int count2 = 0;
            int count3 = 0;
            for (int i = 0; i < VertexAmount(); ++i) {
                if (outDegree()[i] - inDegree()[i] == 1) {
                    count1++;
                }
                else if (inDegree()[i] - outDegree()[i] == 1){
                    count2++;
                }
                else if (inDegree()[i] == outDegree()[i]) {
                    count3++;
                }
            }
            if (count1 == count2 == 1 && count3 == VertexAmount() - 2) { 
                return true;
            }
            return false;
        }

        friend ostream & operator << (ostream &out, const Graph &g);
        
};
