//
//  objects.hpp
//  lecture4
//
//  Created by Peter Augerinos on 25/7/22.
//

#ifndef objects_hpp
#define objects_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

class unreal_rectangle : public runtime_error {
public:
    unreal_rectangle(): runtime_error("invalid rectangle!"){};
};

class Rectangle {
public:
    Rectangle(): a(0), b(0) {};
    Rectangle(double A, double B){
        try {
            a = A;
            b = B;
            if (a < 0 || b < 0) throw unreal_rectangle();
        }
        catch(unreal_rectangle &e){
            cout << e.what() << endl;
            a= a < 0 ? 0 : a;
            b= b < 0 ? 0 : b;
        }
        
    };
    
    double A(){return a;};
    double B(){return b;};
    void setA(double A){
        try {
            a = A;
            if (a < 0) throw unreal_rectangle();
        }
        catch(unreal_rectangle &e){
            cout << e.what() << endl;
            a = 0;
        }
    };
    
    void setB(double B){
        try {
            b = B;
            if (b < 0) throw unreal_rectangle();
        }
        catch(unreal_rectangle &e){
            cout << e.what() << endl;
            b = 0;
        }
    };
    
    double perimeter(){return 2*(a+b);};
    double area(){return a*b;};
    virtual void print(ostream &out){
        out << "[a = " << a << " b = " << b << " perimeter = " << perimeter() << " area = " << area() << "]\n";
    };
    
    friend ostream & operator << (ostream &out, Rectangle r){
        out << "[a = " << r.a << " b = " << r.b << " perimeter = " << r.perimeter() << " area = " << r.area() << "]\n";
        return out;
    };
    
    
protected:
    double a; double b;
};


class Formatting {
public:
    Formatting(): lineWidth(0), lineColor("transparent") {};
    Formatting(int W, string C): lineWidth(W), lineColor(C) {};
    
    void setWidth(int W){lineWidth = W;};
    void setColor(string C){lineColor = C;};
    
    virtual void print(ostream &out){
        out << "[w = " << lineWidth << " c = " << lineColor << "]\n";
    }
    
    friend ostream &operator << (ostream &out, Formatting d){
        out << "[w = " << d.lineWidth << " c = " << d.lineColor << "]\n";
        return out;
    };
    
    
protected:
    int lineWidth;
    string lineColor;
    
};


class niceRectangle: public Rectangle, public Formatting {
public:
    niceRectangle(): Rectangle(), Formatting() {};
    niceRectangle(double A, double B, int W, string C): Rectangle(A, B), Formatting(W, C) {};
    void print(ostream &out) override {
        out << "(nr)" << a << " by " << b << " area = " << area() << " perimeter = " << perimeter() << " linecolor = " << lineColor << " linewidth = " << lineWidth << endl;
    };
    
    friend ostream &operator << (ostream &out, niceRectangle r) {
        out << "(nr)" << r.a << " by " << r.b << " area = " << r.area() << " perimeter = " << r.perimeter() << " linecolor = " << r.lineColor << " linewidth = " << r.lineWidth << endl;
        return out;
    };

    
};

#endif /* objects_hpp */
