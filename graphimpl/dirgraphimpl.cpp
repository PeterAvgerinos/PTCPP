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
        int Weigh;

    public:
        Edge();
        Edge(const int &d, const int &w): Destination(d), Weigh(w) {}
        Edge(const Edge &e): Destination(e.Destination), Weigh(e.Weigh) {}

        const int getDestination() const {
            return Destination;
        }

        void setDestination(const int &d) { 
           this->Destination = d; 
        }

        const int getWeight() const { 
            return Weigh;
        }

        void setWeight(const int &w) { 
            this->Weigh = w;
        }
};


class Vertex { 
    private:
        int ID;

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
        list<Edge> edgelist;
        Vertex();
        Vertex(const int &id): ID(id), edgelist() {}
        Vertex(const Vertex &v): ID(v.ID), edgelist() {copy(v.edgelist);}
        ~Vertex() {purge();}

        int getID() const { 
            return this->ID;
        }

        list<Edge> & getList() { 
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
                for (const auto &edge: vertices[id1].edgelist) {
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
                this->vertices.push_back(vertex);
            }           
        };

        void purge() {
            for (const auto &vertex: vertices) {
                this->vertices.pop_back();
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
                for (const auto &edge: vertices[vertex.getID()].edgelist) {
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
                for (const auto &edge: vertices[vertex.getID()].edgelist) {
                    if (edge.getDestination()==vertex.getID()) {
                        counts[i] += 1;
                        i++;
                    }
                }
            }
            return counts;
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
                this->vertices[id1].edgelist.push_back(e);
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

        bool Cycle(vector<int> &path) const { 
            if (path[0] == path[path.size() - 1]) { 
                return true;
            }
            return false;
        }


        friend ostream & operator << (ostream &out,Graph &g) { 
            for (const auto &vertex: g.vertices) {
                out << "Vertex: " << vertex.getID() << "has ";
                for (const auto &edge: g.vertices[vertex.getID()].getList()) {
                    out << edge.getDestination() << " ";
                }
                out << "edges" << endl;
            }
            return out;
        }
        
};

int main() { 
    Graph g;
    cout << g;
    Vertex a(0);
    Vertex b(1);
    Vertex c(2);
    Vertex d(3);
    g.addVertex(a);
    cout << g;
    g.addVertex(b);
    cout << g;
    g.addVertex(c);
    cout << g;
    g.addVertex(d);
    cout << g;
    g.addEdgebyID(0,1);
    g.addEdgebyID(0,2);
    g.addEdgebyID(1,2);
    g.addEdgebyID(2,3);
    g.addEdgebyID(3,0);
    cout << g;
    if (g.EulerCircuit()) cout << "Yes" << endl;
    if (g.EulerPath()) cout << "Yes" << endl;
}
