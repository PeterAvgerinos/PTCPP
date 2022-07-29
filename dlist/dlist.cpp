#include <iostream>

using namespace std;

template <typename T>
class Container { 
    public:
    ~Container(){};
    virtual bool empty()const { return size() == 0;};
    virtual int size() const = 0;
    virtual void clear() = 0;
};

template <typename T> 
class list : public Container<T> {
    public: 
        list() : the_front(nullptr), the_back(nullptr), the_size(0) {} 
        list(const list &l) : the_front(nullptr), the_back(nullptr), the_size(0) {copy(l);}
        list & operator = (const list &l){
            clear();
            copy(l);
            return *this;
        };
        virtual ~dlist() override { purge(); }
        
        virtual void clear() override {
            purge();
            the_front = nullptr;
            the_back = nullptr; 
            the_size = 0; 
        } 

        void push_back(const T &x) { 
           node *p = new node(x, nullptr, the_back); 
           if (the_back != nullptr) the_back->next = p; 
           else the_front = p;
           the_back = p;
           ++the_size;
        };
        void push_front(T &x);
        void pop_back();
        void pop_front();

        T & front(){};
        T & back(){};



    private: 
        struct node { 
            int data;
            node *next, *prev;
            node(const T &x, node *n, node *p): data(x), next(n), prev(p) {};
        };

        node *the_front, *the_back; 
        int the_size;

        void copy(const list &l) { 
            for (node *p = l.the_front; p != nullptr; p = p->next){ 
                push_back(p->data);
            }
        }

        void purge() { 
            node *p = the_front; 
            while (*p != nullptr){
                node *q = p;
                p = p->next; 
                delete q; 
            }
        }

};
