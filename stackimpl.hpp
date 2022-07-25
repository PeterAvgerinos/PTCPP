//
//  stackimpl.hpp
//  stackdemo
//
//  Created by Peter Augerinos on 22/7/22.
//

#ifndef stackimpl_hpp
#define stackimpl_hpp

#include <stdio.h>
#include <ostream>

using namespace std;

template <typename T>

class poop {
    
public:
    
    poop(int size);
    
    poop(const poop &s);
    
    ~poop();
    
    const poop<T> & operator =(const poop &s){
        this->top = s.top;
        for(int i=0; i < this->stacksize; i++){
            this->arr[i] = s.arr[i];
        }
        return *this;
    };
    
    bool isEmpty ();
    
    bool isFull ();
    
    void push(const T &x);
    
    T pop();
    
    int size();
    
    friend ostream & operator << (ostream &out, const poop &s){
        out << "[";
        if (s.top > -1 and s.top <= s.stacksize){
            for (int i=0; i < s.top; i++){
                out << s.arr[i] << " ";
            }
            out << "]";
            return out;
        }
        out << "]";
        return out;
    };
    
private:
    int top;
    int stacksize;
    T *arr;

};

template <typename T>
poop<T>::poop(int size){
    this->top = -1;
    this->stacksize = size;
    this->arr = new T[this->stacksize];
};

template <typename T>
poop<T>::~poop(){
    
}

template <typename T>
poop<T>::poop(const poop &s){
    this->top = s.top;
    this->stacksize = s.stacksize;
    if (s.top > -1 and s.top <= this->stacksize){
    for(int i=0; i < this->top; i++){
        this->arr[i] = s.arr[i];
    }}
};

template <typename T>
bool poop<T>::isEmpty(){
    if (top == -1){
        return true;
    }
    else {
        return false;
    }
}

template <typename T>
bool poop<T>::isFull(){
    if (top == 4){
        return true;
    }
    else {
        return false;
    }
}


template <typename T>
void poop<T>::push(const T &x){
    if (this->top == 4){
        cout << "Overflow" << endl;
    }
    else {
        this->top++;
        this->arr[this->top] = x;
    }
}

template <typename T>
T poop<T>::pop(){
    if(this->top == -1){
        return NULL;
    }
    else{
        return arr[this->top];
        this->arr[this->top] = NULL;
        this->top--;
    }
};

template <typename T>
int poop<T>::size(){
    return this->top;
}




#endif /* stackimpl_hpp */
