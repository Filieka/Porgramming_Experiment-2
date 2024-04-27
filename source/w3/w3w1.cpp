#include<iostream>
#include<string>
using namespace std;

class Digit{
    private:
    int digit;
    public:
    Digit(int d = 0) : digit(d % 10) {}
    void setDigit(int d) { digit = d % 10; }
    int getDigit() const {return digit;}
};

class Integer{ //class Integer represent a poistive integer
    private:
    Digit value[1000];
    string str;
    public:
    Integer();
    Integer(string n):str(n){
        int i;
        for(i=0;i<str.length();i++){
            if(!(str[i]>='0'&&str[i]<='9')){
                str=str.substr(0,i);
                break;
            }
        }
    }

    bool notZero(string target)const{
        int i;
        for(i=0;i<target.length();i++){
            if(target[i]!='0'){
                return true;
            }
        }
        return false;
    }

    void displayInBase(int base)const{
        if(stoi(str.substr(0,1))==0){
            cout<<"0";
            return;
        }
        string original=str,display="",temp="",remainder="",lest="",list="0123456789ABCDEF";
        int num,i,j=0;
        while(notZero(original)){
            while(original.length()>8){
                temp=remainder+original.substr(0,7);
                original=original.substr(7,original.length()-1);
                num=stol(temp);
                i=temp.length()-remainder.length()-to_string(num/base).length();
                remainder=to_string(num%base);                
                while(i>0&&!(lest.empty())){lest+='0';i--;}
                lest+=to_string(num/base);
            }
            temp=remainder+original;
            display=list[stol(temp)%base]+display;
            i=original.length()-to_string(stol(temp)/base).length();
            while(i>0&&!(lest.empty())){lest+='0';i--;}
            original=lest+to_string(stol(temp)/base);
            remainder="";
            lest="";           
        }
        if(!notZero(original)&&original.length()>1){
            display+=original;
        }
        cout<<display;
    } 
  
};

/*int main(){
    string in;
    int j;
    cin>>in;
    Integer i(in);
    for(j=2;j<=16;j++){
        i.displayInBase(j);
        cout<<endl;
    }

}*/