#include<iostream>
using namespace std;

class Point{
    public:
    double x,y;

    Point(double a,double  b){
        x=a;
        y=b;
        cout<<"("<<x<<", "<<y<<")"<<endl;
    }
};

int main(){
    int times,i;
    double x,y;
    cin>>times;
    for(i=0;i<times;i++){
        cin>>x>>y;
        Point point(x,y);
    }
}