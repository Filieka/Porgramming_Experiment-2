#include<iostream>
#include<cmath>
using namespace std;

class Distance{
    public:
    double x1,y1,x2,y2;
    Distance(double a,double b,double c,double d){
        x1=a;
        y1=b;
        x2=c;
        y2=d;
    }

    void calculate(){
        double x,y;
        x=x1-x2;
        y=y1-y2;
        cout<<sqrt(x*x+y*y)<<endl;
    }
};

int main(){
    int times,i;
    double x1,y1,x2,y2;
    cin>>times;
    for(i=0;i<times;i++){
        cin>>x1>>y1>>x2>>y2;
        Distance distance(x1,y1,x2,y2);
        distance.calculate();
    }
}