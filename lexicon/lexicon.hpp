#include <iostream> 
#include <string>

using namespace std; 

class lexicon { 
    private: 
        struct node { 
        string data;
        int count;
        node *left, *right, *parent;
        node(string d, int c, node *l, node *r, node *p): data(d), count(c), left(l), right(r), parent(p) {};
        };

        node *root;
        int size;

        void copy(node *t) { 
            if (t != nullptr) { 
                insert(t->data);
                t->count++;
                copy(t->left);
                copy(t->right);
            }
        }

        void purge(node *t) { 
            if (t != nullptr) { 
                purge(t->left);
                purge(t->right);
                delete t; 
                t->count--;
            }
        }

        static bool insert(node *p, const string &s) { 
            if (s < p->data) { 
                if ( p->left == nullptr)  {
                    p->left = new node(s, 1, nullptr, nullptr, p);
                    return true;
                }
                else {
                        return insert(p->left, s);
                }
            }
            else if (s > p->data){ 
                if (p->right == nullptr) { 
                    p->right = new node(s, 1, nullptr, nullptr, p);
                    return true;
                }
                else {
                    return insert(p->right, s);
                }
            }
            else { 
                p->count++;
                return true;
            }
            return false; 
        }

    public:
        lexicon(): root(nullptr), size(0) {};
        ~lexicon() { 
            purge(root);
        };

        void insert(const string &s) { 
            if (root == nullptr) { 
                root = new node(s, 1, nullptr, nullptr, nullptr);
                size++;
            }
            else if (insert(root, s)) { 
                size++;
            }
        };

        int lookup(const string &s) const;
        int depth(const string &s) const;
        void replace(const string &a, const string &b);

        friend ostream & operator << (ostream &out, const lexicon &l);


};
