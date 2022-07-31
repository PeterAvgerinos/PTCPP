#include <__nullptr>
#include <iostream> 
#include <list>

using namespace std; 

class Polynomial { 
    protected: 
        class Term { 
            int exponent; 
            int coefficient;
            Term *next;
            Term(int exp, int coeff, Term *n): exponent(exp), coefficient(coeff), next(n) {}
            friend class Polynomial;
        };

        Term *the_front, *the_back;
        int the_size;
        
        void copy(const Polynomial &p) { 
            for (Term *t = the_front; t != nullptr; t = t->next) { 
                addTerm(t->exponent, t->coefficient);
            }
        }

        void purge() { 
            Term *p = the_front;
            while (p != nullptr)  {
                Term *q = p; 
                p = p->next;
                delete q;
            }
        }

    public:
        Polynomial() { 
            the_front = nullptr;
            the_back = nullptr; 
            the_size = 0;
        };

        Polynomial(const Polynomial &p) {
            the_front = nullptr;
            the_back = nullptr; 
            the_size = 0;
            copy(p);
        };

        ~Polynomial() { 
            purge();
        };

        Polynomial & operator = (const Polynomial &p) { 
            clear();
            copy(p);
            return *this;
        };

        void addTerm(int exp, int coeff) { 
            Term *p = new Term(exp, coeff, nullptr);
            Term *t = the_front; 
            while (p->exponent < t->exponent) { 
                t = t->next; 
            }
            p->next = t; 
        };

        double evaluate(double x) const { 
            Term *t = the_front;
            while (t->exponent != x) { 
                t = t->next;
            }
            return t->coefficient;
        };

        int size() { 
            return the_size;
        }
    
        void clear() { 
            purge();
            the_back = nullptr;
            the_front = nullptr; 
            the_size = 0;
        }

        friend Polynomial & operator + (const Polynomial &a, const Polynomial &b) {
            Polynomial *p = new Polynomial();
            for (Term *t = p->the_front; t != nullptr; t = t->next) { 
                p->addTerm(t->exponent, a.evaluate(t->coefficient) + b.evaluate(t->coefficient));
            }
            return *p;
        };

        friend Polynomial & operator * (const Polynomial &a, const Polynomial &b) { 
            Polynomial *p = new Polynomial();
            for (Term *t = p->the_front; t != nullptr; t= t->next) { 
                for (Term *y = p->the_front; y != nullptr; y = y->next) { 
                    p->addTerm(t->exponent, a.evaluate(t->coefficient) * b.evaluate(y->coefficient));
                }
            }
            return *p;
        };

        friend ostream & operator << (ostream &out, const Polynomial &p) { 
            for (Term *t = p.the_front; t != nullptr; t = t->next) { 
                out << t->coefficient << "x" << t->exponent;
            }
            return out;
        };

};
