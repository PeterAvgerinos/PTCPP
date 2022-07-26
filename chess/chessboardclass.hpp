//
//  chessboardclass.hpp
//  chess
//
//  Created by Peter Augerinos on 26/7/22.
//

#ifndef chessboardclass_hpp
#define chessboardclass_hpp

#include <stdio.h>
#include <iomanip>

using namespace std;

class ChessBoardArray {
public:
    
    int **arr;
    string **color;
    
    ChessBoardArray(unsigned size = 0, unsigned base = 0){
        bsize = size;
        bbase = base;
        for (int i=0; i < bsize; i++){
            arr = new int *[bsize];
            color = new string *[bsize];
        }
        for (int i=0; i < bsize; i++){
            arr[i] = new int [bsize];
            color[i] = new string [bsize];
        }
        for (int i=0; i < bsize; i++){
            for (int j=0; j < bsize; j++){
                arr[i][j] = 0;
                if (i % 2 == 0){
                    if (j % 2 == 1){
                        color[i][j] = "white";
                    }
                    else{
                        color[i][j] = "black";
                    }
                }
                else {
                    if (j % 2 == 1){
                        color[i][j] = "white";
                    }
                    else{
                        color[i][j] = "black";
                    }
                }
                
            }
        }
    };
    
    ChessBoardArray(const ChessBoardArray &a){
        bsize = a.bsize;
        bbase = a.bbase;
        for (int i=0; i < bsize; i++){
            arr = new int *[bsize];
            color = new string *[bsize];
        }
        for (int i=0; i < bsize; i++){
            arr[i] = new int [bsize];
            color[i] = new string [bsize];
        }
        for (int i=0; i < bsize; i++){
            for (int j=0; j < bsize; j++){
                arr[i][j] = a.arr[i][j];
                color[i][j] = a.color[i][j];
            }
        }
    };
    
    ~ChessBoardArray(){
        for (int i=0; i < bsize; i++){
            delete[] arr[i];
            delete[] color[i];
        }
        delete [] arr;
        delete [] color;
        
    };
    
    ChessBoardArray & operator = (const ChessBoardArray &a){
        static ChessBoardArray w(a.bsize, a.bbase);
        for (int i=0; i < bsize; i++){
            for (int j=0; j < bsize; j++){
                w.arr[i][j] = a.arr[i][j];
                w.color[i][j] = a.color[i][j];
            }
        }
        return w;
    };
    
    int & select(int i, int j){
        return arr[i][j];
    };
    
    int select(int i, int j) const{
        return arr[i][j];
    };
    
//    const Row operator [](int i){
//        return *arr[i];
//    };
//    const ConstRow operator [](int i) const{
//        return *arr[i];
//    };
    
    friend ostream & operator << (ostream &out, ChessBoardArray &a){
        for (int i=0; i < a.bsize; i++){
            for (int j=0; j < a.bsize; j++){
                out << a.arr[i][j] << a.color[i][j];
            }
            out << endl;
        }
        return out;
    };
    
    
protected:
    class Row {
    public:
        Row(ChessBoardArray &a, int i){
            index = i;
            for (int i=0; i < a.bsize; i++){
                *arr[i] = *a.arr[i];
            }
        };
        
        int & operator [](int i){
            return *arr[index];
        };
        
    private:
        int index;
        int **arr;
        
    };
    
    class ConstRow {
    public:
        ConstRow(ChessBoardArray &a, int i){
            index = i;
            for (int i=0; i < a.bsize; i++){
                *arr[i] = *a.arr[i];
            }
        };
        int & operator [](int i) const{
            return *arr[index];
        };
        
    private:
        int index;
        int **arr;
        
    };
    
    
    
private:
    int bsize;
    int bbase;
    
    
    
    
    
};

#endif /* chessboardclass_hpp */
