#include<iostream>
#include<cmath>
using namespace std;

class Point{
    private:
    double x,y;

    public:

    Point(double a,double  b){
        x=a;
        y=b;
    }

    double getX(){
        return x;
    }

    double getY(){
        return y;
    }
};

class Segment{
    private:
    Point start,end;

    public:
    Segment(Point a,Point b):start(a),end(b){}

    double length(){
        double x,y;
        x=start.getX()-end.getX();
        y=start.getY()-end.getY();
        return sqrt(x*x+y*y);
    }

    Point getEnd(int i){
        if(i==0){
            return start;
        }
        return end;
    }

};