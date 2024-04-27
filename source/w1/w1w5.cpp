#include<iostream>
using namespace std;

class Judge{
    int a,b,c,d;
public:
    Judge(int v,int x,int y,int z){
        a=v;
        b=x;
        c=y;
        d=z;
    }

    int getMax1(){
        if(a>b){
            return a;
        }
        return b;
    }

    int getMin1(){
        if(a>b){
            return b;
        }
        return a;
    }

    int getMax2(){
        if(c>d){
            return c;
        }
        return d;
    }

    int getMin2(){
        if(c>d){
            return d;
        }
        return c;
    }

    bool judge(){
        if(getMax1()<=getMin2()||getMax2()<=getMin1()){
            return false;
        }
        return true;        
    }

};

int main(){
    int a,b,c,d;

    cin>>a>>b>>c>>d;
    Judge judge(a,b,c,d);
    if(judge.judge()){
        cout<<"overlay"<<endl;
        return 0;
    }
    cout<<"no overlay"<<endl;
}