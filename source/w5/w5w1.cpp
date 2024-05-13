#include<iostream>
#include<string>
using namespace std;

class Time{
public:
    int h,m,s;
    Time(){
        h=0;
        m=0;
        s=0;
    };
    Time(string a){
        h=stoi(a.substr(0,2));
        m=stoi(a.substr(3,2));
        s=stoi(a.substr(6,2));
    }
    string toString() const{
        string out="";
        if(h<10){
            out='0'+to_string(h);
        }
        else{
            out=to_string(h);
        }
        out+=':';
        if(m<10){
            out=out+'0'+to_string(m);
        }
        else{
            out+=to_string(m);
        }
        out+=':';
        if(s<10){
            out=out+'0'+to_string(s);
        }
        else{
            out+=to_string(s);
        }
        return out;
    }
    int operator-(const Time &other) const{
        int ans=0;
        ans+=60*60*(h-other.h);
        ans+=60*(m-other.m);
        ans+=s-other.s;
        ans=abs(ans);
        return ans;
    }
};