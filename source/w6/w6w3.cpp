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

    float getLength(){
        return point1.getDistance(point2);
    }
};