#include<iostream>
#include<w5w1.cpp>
#include<w5w2.cpp>
using namespace std;


class DateTime:public Date,public Time{
public:
    DateTime():Date(),Time(){}
    DateTime(string a):Date(a.substr(0,10)),Time(a.substr(11,8)){}

    string toString(){
        return Date::toString()+' '+Time::toString();
    }

};
