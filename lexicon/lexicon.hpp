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

        node * search(node *root, const string &s) const { 
            while (root != nullptr) { 
                if (root->data == s) { 
                    return root;
                }
                else if (root->data < s) { 
                    root = root->left;
                }
                else { 
                    root = root->right;
                }
            }
            return nullptr;
        }

        int searchd(node *root, const string &s) const { 
            int depth = 0;
            while (root != nullptr) { 
                if (root->data == s) { 
                    return depth;
                }
                else if (root->data < s) { 
                    root = root->left;
                    depth++;
                }
                else { 
                    root = root->right;
                    depth++;
                }
            }
            return -1;
        }

        void search_delete(node *root, const string &s) const { 
            while (root != nullptr) { 
                if (root->data == s) { 
                    delete root; 
                }
                else if (root->data < s) { 
                    root = root->left;
                }
                else { 
                    root = root->right;
                }
            }
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

        int lookup(const string &s) const { 
            if (search(root, s) != nullptr) { 
                return root->count;
            }
            return 0;
        };

        int depth(const string &s) const { 
            return searchd(root, s);
        };

        void replace(const string &a, const string &b) { 
            if (lookup(a) == 0) { 
                return;
            }
            else { 
                search_delete(root, a);
                if (lookup(b) == 0) { 
                    insert(b);
                    search(root, b)->count = 1;
                }
                else { 
                    search(root, b)->count++;
                }
            }
        };

        friend ostream & operator << (ostream &out, const lexicon &l) { 
            node * temp; 
            temp = l.root;
            while (temp != nullptr) { 
                out << temp->data << " " << temp->count << endl;
                if (temp->left != nullptr) { 
                    temp = temp->left;
                }
                else { 
                    temp = temp->right;
                }
            }
            return out;
        };


};
