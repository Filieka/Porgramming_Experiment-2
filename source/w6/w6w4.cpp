#include<iostream>
#include<cmath>
using namespace std;

class Point{
private:
    float x,y;

public:
    Point():x(0),y(0){}
    Point(float a,float b):x(a),y(b){}

    void printPoint(){
        cout<<"("<<x<<", "<<y<<")";
    }

    float getX(){
        return x;
    }

    float getY(){
        return y;
    }

    void setX(float in){
        x=in;
    }

    void setY(float in){
        y=in;
    }

    float getDistance(Point other){
        return (float)sqrt((x-other.getX())*(x-other.getX())+(y-other.getY())*(y-other.getY()));
    }
};
class Segment{
private:
    Point point1,point2;

public:
    Segment():point1(0,0),point2(0,0){}
    Segment(Point point3,Point point4){
        point1=point3;
        point2=point4;
    }
    Point getPoint1(){
        return point1;
    }

    Point getPoint2(){
        return point2;
    }

    float getLength(){
        return point1.getDistance(point2);
    }
};

class Shape{
private:
    Segment seg[10];
    int edgeCount;

public:
    Shape():edgeCount(0){};
    Shape(Segment *a, int n):edgeCount(n){
        if(edgeCount<3){
            throw invalid_argument("invalid_argument");
        }
        for(int i=0;i<edgeCount;i++){
            seg[i]=a[i];
        }
        if(a[0].getPoint1().getX()!= a[edgeCount-1].getPoint2().getX()||a[0].getPoint1().getY()!=a[edgeCount-1].getPoint2().getY()){
            throw invalid_argument("Segments do not form a closed path.");
        }
        /*for(int i=1;i<edgeCount;i++){
            if(a[i-1].getPoint2().getX()!=a[i].getPoint1().getX()||a[i-1].getPoint2().getY()!=a[i].getPoint1().getY()){
                throw invalid_argument("Segments are not connected.");
            }
        }*/
    }
    virtual float getArea() = 0;

    float getPerimeter(){
        float sum;
        for(int i=0;i<edgeCount;i++){
            sum+=seg[i].getLength();
        }
        return sum;
    }

    Segment &getSeg(int index)
    {
        return seg[index];
    }
};