#include<iostream>
using namespace std;

class Point{
    private:
    float x,y;

    public:

    Point(float a,float  b){
        x=a;
        y=b;
    }

    float getX(){
        return x;
    }

    float getY(){
        return y;
    }
};

int main(){
    int times,i;
    float x,y;
    cin>>times;
    for(i=0;i<times;i++){
        cin>>x>>y;
        Point point(x,y);
        cout<<"("<<point.getX()<<", "<<point.getY()<<")"<<endl;

    }
}