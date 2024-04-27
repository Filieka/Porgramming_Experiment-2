#include<iostream>
using namespace std;

class Speed{
    double km,hour;
public:
    Speed(double a,double b){
        km=a;
        hour=b;
    }

    double calculate(){
        double ans;
        ans=km/hour;
        return ans;
    }

};

int main(){
    double km,hour;
    cin>>km>>hour;
    Speed speed(km,hour);
    cout<<speed.calculate()<<endl;
}