#include<iostream>
#include<string>
using namespace std;

class System{
    private:
    string plate;

    public:
    System(string a):plate(a){}

    bool check(){
        if(plate.find('4')==plate.npos){
            return false;
        }
        return true;
    }

};

int main(){
    string plate;
    cin>>plate;
    System system(plate);
    if(system.check()){
        cout<<"Yes"<<endl;
        return 0;
    }
    cout<<"No"<<endl;
}