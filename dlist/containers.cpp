#include <__nullptr>
#include <iostream>

using namespace std; 

template <typename T> 
class Container { 
    public: 
        virtual ~Container() {}
        virtual int size() const = 0; 
        virtual bool empty() const { return size() == 0; };
        virtual void clear() = 0;
};

template <typename T>
class Iterable { 
    public: 
        virtual Iterator<T> begin() = 0;
        virtual Iterator<T> end() = 0;
};

template <typename T>
class Iterator { 
    public: 
        Iterator (const Iterator &i) : impl(i.impl->clone()) {} ;
        ~Iterator() { delete impl; }
        T & operator *() { 
            return impl->access(); }
        };

        Iterator & operator ++() { 
            impl->advance();
            return *this;
        };

        Iterator operator ++ (int) { 
            Iterator result(*this);
            impl->advance();
            return result;
        };

        bool operator == (const Iterator &i) const { return impl->equal(*(i.impl)); };
        bool operator != (const Iterator &i) const { return !(*this == i); };

        class Impl { 
            public: 
                virtual ~Impl() {}
                virtual Impl *clone() const = 0;
                virtual T & access() const = 0;
                virtual void advance() = 0;
                virtual bool equal(const Impl &i) const = 0;
        };

        Iterator(Impl *i) : impl(i) {}

    private: 
        Impl *impl;
};
// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------

template <typename T>
class dlist: public Container<T> { 
    private: 
        struct node { 
        T data;
        node *next, *previous;
        node(const T &x, node *n, node *p) : data(x), next(n), previous(p) {};
        };

        node *the_front, *the_back;
        int the_size;

        void copy (const dlist &l) { 
            for (node *p = l.the_front; p!= nullptr; p = p->next) { 
                push_back(p->data);
            }
        }

        void purge() { 
            node *p = the_front;
            while (p != nullptr) { 
                node *q = p;
                p = p->next;
                delete q; 
            }

        }

    public: 
        dlist() : the_front(nullptr), the_back(nullptr), the_size(0) {} 
        dlist(const dlist &l) : the_front(nullptr), the_back(nullptr), the_size(0) {copy(l);}

        virtual ~dlist() override { purge(); }

        dlist & operator = (const dlist &l){
            clear();
            copy(l);
            return *this;
        };

        virtual int size() const override { return the_size;}; 
        virtual void clear() override{
            purge();
            the_front = nullptr; 
            the_back = nullptr; 
            the_size = 0; 
        }

        void push_back(const T &x) { 
            node *p = new node(x, nullptr, the_back);
            if (the_back != nullptr ) the_back->next = p;
            else the_front = p; 
            the_back = p;
            ++the_size;
        };

        void push_front(const T &x) { 
            node *p = new node(x, the_front, nullptr);
            if (the_front != nullptr ) the_front->previous = p;
            else the_back = p; 
            the_front = p;
            ++the_size;
        };

        void pop_back(){
            node *p = the_back;
            the_back = p->previous;
            if(the_back != nullptr) the_back->next = nullptr; 
            else the_front = nullptr; 
            delete p;
            --the_size; 
        };

        void pop_front() {
            node *p = the_front;
            the_front = p->next;
            if(the_front != nullptr) the_front->next = nullptr; 
            else the_back = nullptr; 
            delete p;
            --the_size; 
        }

        T & back() { return the_back->data;};
        T & front() { return the_front->data;};

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------
        
        class iterator {
            public: 
                iterator(const iterator &i): ptr(i.ptr) {}
                T & operator *() { return ptr->data; }
                iterator & operator ++ (int) {
                    iterator result(*this);
                    ptr = ptr->next;
                    return result; 
                }

                iterator & operator ++ () { ptr = ptr->next; return *this; }
                bool operator != ( const iterator &i) const { return ptr != i.ptr; }
                bool operator == ( const iterator &i) const { return ptr == i.ptr; }

            private: 
                node *ptr; 
                iterator(node *p): ptr(p) {}
                friend class dlist;

        };

        iterator begin() { return iterator(the_front); }
        iterator end() { return iterator(nullptr); }

        
};

// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------

template <typename T>
void print(dlist<T> &l) { 
    for (auto i = l.begin(); i != l.end(); ++i){ 
        cout << *i << " ";
    }
}




// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------

template <typename T>
class btree: public Container<T> { 
    private: 
        struct node { 
        T data;
        node *left, *right, *parent;
        node(const T &x, node *l, node *r, node *p) : data(x), left(l), right(r), parent(p) {}
        };

        node *root;
        int the_size;

        void copy (node *t) { 
            if (t != nullptr){
                insert(t->data);
                copy(t->left);
                copy(t->right);
            }
        }

        static void purge(node *t) { 
            if (t != nullptr){
                purge(t->left);
                purge(t->right);
                delete t;
            }
        }

        static bool insert(node *t, const T &x) { 
            if (x < t->data) {
                if (t->left == nullptr) { 
                    t->left = new node(x, nullptr, nullptr, t);
                    return true;
                }
                else { 
                    return insert(t->left, x);
                }
            }   
            else if (x > t->data) { 
                if (t->right == nullptr) { 
                    t->right = new node(x, nullptr, nullptr, t);
                    return true;
                }
                else { 
                    return insert(t->right, x);
                }
            }
            return false;
        }

        static node *leftdown(node *t) { 
            if (t == nullptr || t->left == nullptr) {
                return t;
            }
            else { 
                return leftdown(t->left);
            }
        }

        static node *leftup(node *t) { 
            if (t->parent != nullptr || t->parent->left == t) { 
                return t->parent;
            }
            else {
                return leftup(t->parent);
            }
        }


    public: 
        btree() : root(nullptr), the_size(0) {} 
        btree(const btree &t) : root(nullptr), the_size(0) {copy(t.root);}

        virtual ~btree() override { purge(root); }

        btree & operator = (const btree &t){
            clear();
            copy(t.root);
            return *this;
        };

        virtual int size() const override { return the_size;}; 
        virtual void clear() override{
            purge(root);
            root = nullptr; 
            the_size = 0; 
        }

        void insert(const T &x) { 
            if (root == nullptr) {
                root = new node(x, nullptr, nullptr, nullptr);
                ++the_size;
            }
            else if (insert(root, x)) {
                ++the_size;
            }
        };

        


// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------

        class iterator { 
             public:
                iterator(const iterator &i): ptr(i.ptr) {}
                T & operator *() { return ptr->data; }
                iterator & operator ++ (int) {
                    iterator result(*this);
                    ++(*this);
                    return result; 
                }

                iterator & operator ++ () {
                    if (ptr != nullptr) { 
                        if (ptr->right != nullptr) { 
                            ptr = leftdown(ptr->right);
                        }
                        else { 
                           ptr = leftup(ptr); 
                        }
                    }
                    return *this;
                }

                bool operator != ( const iterator &i) const { return ptr != i.ptr; }
                bool operator == ( const iterator &i) const { return ptr == i.ptr; }

            private: 
                node *ptr; 
                iterator(node *p): ptr(p) {}
                friend class btree;

        };

        iterator begin() { return iterator(leftdown(root)); }
        iterator end() { return iterator(nullptr); }

};        


template <typename T>
void print_tree(btree<T> &l) { 
    for (T &x: l) { 
        cout << " " << x;
    }
}
// -----------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------

int main() { 
    btree<int> t;
    int x[] = {5, 2, 8, 4, 1, 7, 6, 0, 9, 3};
    for (int i=0; i < 10; ++i) t.insert(x[i]);
    cout << t.size() << endl;
    print_tree(t);
    cout << endl;
    cout << t.size() << endl;
    print_tree(t);
    cout << endl;
    for (int &x: t) x+= 2;
    cout << t.size() << endl;
    print_tree(t);
    cout << endl;
    auto j = t.begin();
    ++j;
    ++j;
    cout << *j << endl; 
    cout << *(++j) << endl;
    cout << *j << endl; 


}
