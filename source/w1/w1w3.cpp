#include<iostream>
#include<cmath>
using namespace std;

class Point{
private:
    double x=0,y=0;

public:
    void setX(double input){
        x=input;
    }

    void setY(double input){
        y=input;
    }

    double getX(){
        return x;
    }

    double getY(){
        return y;
    }
};
class Triangle{
    Point p1,p2,p3;
public:
    Triangle(double x1,double y1,double x2,double y2,double x3,double y3){
        p1.setX(x1);
        p1.setY(y1);
        p2.setX(x2);
        p2.setY(y2);
        p3.setX(x3);
        p3.setY(y3);
    }

    double calculate(double x1,double y1,double x2,double y2){
        double x,y;
        x=x1-x2;
        y=y1-y2;
        return sqrt(x*x+y*y);
    }

    double perimeter(){
        double sumOfAll;
        sumOfAll=calculate(p1.getX(),p1.getY(),p2.getX(),p2.getY());
        sumOfAll+=calculate(p3.getX(),p3.getY(),p2.getX(),p2.getY());
        sumOfAll+=calculate(p3.getX(),p3.getY(),p1.getX(),p1.getY());
        return sumOfAll;
    }
};

int main(){
    int times,i;
    double x1,y1,x2,y2,x3,y3;
    cin>>times;
    for(i=0;i<times;i++){
        cin>>x1>>y1>>x2>>y2>>x3>>y3;
        Triangle triangle(x1,y1,x2,y2,x3,y3);
        cout<<triangle.perimeter()<<endl;
    }

    return 0;
}