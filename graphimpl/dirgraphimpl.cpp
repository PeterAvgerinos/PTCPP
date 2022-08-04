#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>
#include <stack>

using namespace std; 


class Edge { 
    private: 
        int Destination;

    public:
        Edge();
        Edge(const int &d): Destination(d) {}
        Edge(const Edge &e): Destination(e.Destination) {}

        const int getDestination() const {
            return Destination;
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
            for (const auto &Destination: e) { 
                this->edgelist.push_back(Destination);
            }
        }

        void purge() {
            for (const auto &edge: edgelist) { 
                edgelist.pop_front();
            }
        }

    public:
        Vertex();
        Vertex(const int &id): ID(id), edgelist() {}
        Vertex(const Vertex &v): ID(v.ID), edgelist() {copy(v.edgelist);}
        ~Vertex() {purge();}

        int getID() const { 
            return this->ID;
        }

        const list<Edge> & getList() const { 
            return edgelist;
        }

        void setID(const int &id) { 
            this->ID = id;
        }

        void setList(const list<Edge> &l) {
            purge();
            for (const auto &edge: l) { 
                edgelist.push_back(edge);
            }
        }

};


class Graph { 
    private: 
        vector<Vertex> vertices;
        
        bool VertexExists(Vertex &v) { 
            for (const auto &vertex: vertices) { 
                if (vertex.getID() == v.getID()) { 
                    return true;
                }
            }
            return false; 
        }


        bool VertexExistsbyID(const int &id) {
            for (const auto &vertex: vertices) { 
                if (vertex.getID() == id) {
                    return true;
                }
            }
            return false;
        };

        const bool EdgeExistsbyID(const int &id1, const int &id2) {
            if (VertexExistsbyID(id1) && VertexExistsbyID(id2)) { 
                for (const auto &edge: vertices[id1].getList()) {
                    if (edge.getDestination() == id2){
                        return true;
                    }                    
                }
            }
            return false;
        }

        void copy(const vector<Vertex> &v){ 
            purge();
            for (const auto &vertex: v) {
                vertices.push_back(vertex);
            }           
        };

        void purge() {
            for (const auto &vertex: vertices) {
                vertices.pop_back();
            }
        }

        const int VertexAmount() {
            int count = 0; 
            for (const auto &vertex: vertices) {
                count++;
            }
            return count;
        }

        const vector<int> inDegree() {
            vector<int> counts;
            for (int i=0; i < VertexAmount(); ++i) { 
                counts[i] = 0;
            }
            for (const auto &vertex: vertices) {
                int i=0;
                for (const auto &edge: vertices[vertex.getID()].getList()) {
                    counts[i] += 1;
                    i++;
                }
            }
            return counts;
        }

        const vector<int> outDegree() {
            vector<int> counts;
            for (int i=0; i < VertexAmount(); ++i) {
                counts[i] = 0;
            }
            for (const auto &vertex: vertices) {
                int i=0;
                for (const auto &edge: vertices[vertex.getID()].getList()) {
                    if (edge.getDestination()==vertex.getID()) {
                        counts[i] += 1;
                        i++;
                    }
                }
            }
            return counts;
        }

        const bool CycleSearch(const int &id1, const int &id2) { 
            vector<bool> visited; 
            vector<int> recStack;
            recStack.push_back(id1);
            for (int i = 0; i < VertexAmount(); i++) {
                visited[i] = false;
            }
            int i = 0;
            for (const auto &vertex: vertices) { 
                visited[i] = true;
                recStack.push_back(vertex);
                i++;
                for (const auto &edge: vertices[vertex.getID()].getList()) { 
                    if (visited[edge.getDestination()] == false) {
                        recStack[vertex.getID()].push_back[vertex.getID()];
                        if (recStack[0].getID() == recStack[VertexAmount() - 1].getID()) { 
                            return true;
                        }
                    }
                }
                return false;
            }
        }

    public:
        Graph(): vertices() {} 
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
                Edge e(id2);
                vertices[id1].getList().push_back(e);
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

        bool Cycle() { 
            return CycleSearch();
        }


        friend ostream & operator << (ostream &out,Graph &g) { 
            for (const auto &vertex: g.vertices) {
                out << vertex.getID();
                for (const auto &edge: g.vertices[vertex.getID()].getList()) {
                    out << edge.getDestination();
                }
                out << endl;
            }
            return out;
        }
        
};

int main() {
    Vertex a(0);
    Vertex b(1);
    Vertex c(2);
    Graph g;
    g.addVertex(a);
    g.addVertex(b);
    g.addVertex(c);
    g.addEdgebyID(0,1);
    g.addEdgebyID(1,2);
    g.addEdgebyID(2,0);
    g.EulerCircuit();
    g.EulerPath();
    cout << g;
}
