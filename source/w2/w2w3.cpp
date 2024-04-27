#include<iostream>
using namespace std;

class Path{
    private:
    Segment *base;
    double total=0;
    int num;

    public:
    Path(Segment *a,int b):base(a),num(b){
        check();
        getLength();
    }

    void check(){
        int i,j,count=0;
        for(i=0;i<num-1;i++){
            if(!(base[i].getEnd(1).getX()==base[i+1].getEnd(0).getX()&&base[i].getEnd(1).getY()==base[i+1].getEnd(0).getY())){
                cout<<"-1"<<endl;
                exit(0);
            }
        }

        for(i=0;i<num;i++){
            for(j=0;j<i-1;j++){
                if(base[i].getEnd(1).getX()==base[j].getEnd(0).getX()&&base[i].getEnd(1).getY()==base[j].getEnd(0).getY()){
                    cout<<"-1"<<endl;
                    exit(0);
                }
            }
        }
    }

    void getLength(){
        int i;
        for(i=0;i<num;i++){
            total+=base[i].length();
        }
        cout<<total<<endl;
    }

};
