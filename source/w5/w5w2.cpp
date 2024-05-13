#include<iostream>
using namespace std;

class Date {
public:
    int y,m,d;
    int list[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    Date(){
        y=1900;
        m=1;
        d=1;
    }
    Date(string a){
        y=stoi(a.substr(0,4));
        m=stoi(a.substr(5,2));
        d=stoi(a.substr(8,2));
    };
    string toString() const{
        string out="";
        if(y<10){
            out="000"+to_string(y);
        }
        else if(y<100){
            out="00"+to_string(y);
        }
        else if(y<1000){
            out="0"+to_string(y);
        }
        else{
            out=to_string(y);
        }
        out+='/';
        if(m<10){
            out=out+'0'+to_string(m);
        }
        else{
            out+=to_string(m);
        }
        out+='/';
        if(d<10){
            out=out+'0'+to_string(d);
        }
        else{
            out+=to_string(d);
        }
        return out;
    };
    int operator-(const Date &other) const{
        int th,ot,i;
        th=365*y+(y-1)/4-(y-1)/100+(y-1)/400;
        if(m>2&&((y%4==0&&y%100!=0)||(y%400==0))){th++;}
        for(i=1;i<m;i++){
            th+=list[i];
        }
        th+=d;
        ot=365*other.y+(other.y-1)/4-(other.y-1)/100+(other.y-1)/400;
        if(other.m>2&&((other.y%4==0&&other.y%100!=0)||(other.y%400==0))){ot++;}
        for(i=1;i<other.m;i++){
            ot+=list[i];
        }
        ot+=other.d;
        return abs(th-ot);
    }
};

int main(){
    string a,b;
    cin>>a>>b;
    Date i(a);
    Date j(b);
    cout<<i.toString()<<endl<<j.toString()<<endl;
    cout<<i-j<<endl;
}