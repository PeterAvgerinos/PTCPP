#include <iostream> 

using namespace std;

class Board { 
    protected:
    class Row {
        public: 
            Row(Board &a, int i);
            int & operator [] (int i) const;

    }; 
    
    class ConstRow {
        public:
            ConstRow(Board &a, int i);
            int & operator [] (int i) const;

    };
    
    public:
        Board (unsigned size = 0, unsigned base = 0){
            bsize = size; 
            bbase = base;
            arr = new int *[size];
            color = new string *[size];
            for (int i=0; i < size; i++){
                for(int j=0; j < size; j++){
                    if ((i+j) % 2 != 0){
                        color[i][j] = "white\n";
                        arr[i][j]=bbase;
                        bbase++;}
                    else{
                        color[i][j] = "black\n";
                        arr[i][j]=0;
                    }
                }
            }

        };


        Board (const Board &a){
            bsize = a.bsize;
            bbase = a.bbase;
            arr = a.arr;
            color = a.color;
        };


        ~Board(){
            delete [] arr;
            delete [] color;
        };


        Board & operator = (const Board &a){
        Board w;
        w.bsize = a.bsize;
        w.bbase = a.bbase; 
        w.arr = a.arr;
        w.color = a.color;
        return w;

        };

        int & select(int i, int j){

        };
        int select(int i, int j) const;
        
        const Row operator [](int i);
        const ConstRow operator [](int i) const;

        friend ostream & operator << (ostream &out, const Board &a);

    private:
        int bsize; 
        int bbase;
        int **arr;
        string **color;

        unsigned int loc(int i, int j) const throw(out_of_range);


};

