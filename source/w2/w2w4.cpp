#include<iostream>
#include<cmath>
using namespace std;

class Calculate{
    private:
    int distance;

    public:
    Calculate(int km):distance(km){}

    int price(){
        float cost;
        if(distance>=200){
            distance-=200;
            cost=distance*0.9;
            cost+=240;
        }
        else{
            cost=distance*1.2;
        }
        return round(cost);
    }

};

int main(){
    int km;
    cin>>km;
    Calculate calculate(km);
    cout<<calculate.price()<<endl;
}