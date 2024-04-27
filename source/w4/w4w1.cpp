#include<iostream>
#include<string>
using namespace std;

class Anagram:public string{

private:
    string ori="";
public:
    bool operator==(const Anagram &str)const{
        string target=ori;
        int i;
        if(target.length()==str.getLength()){
            for(i=0;i<str.getLength();i++){
                if(target.find(str.getElement(i))!=string::npos){
                    target.erase(target.find(str.getElement(i)),1);
                    continue;
                }
                return false;
            }
            return true;
        }
        return false;
    }

    Anagram(string a){
        int i;
        for(i=0;i<a.length();i++){
            if(a[i]>='A'&&a[i]<='Z'){
                ori+=a[i]-'A'+'a';
            }
            else if(a[i]>='a'&&a[i]<='z'){
                ori+=a[i];
            }
        }
    }

    int getLength()const{
        return ori.length();
    }

    char getElement(int a)const{
        return ori[a];
    }

};

int main(){
    string buf;
    getline(cin,buf);
    Anagram a1(buf);
    getline(cin,buf);
    Anagram a2(buf);
    cout<<(a1==a2)<<endl;
    cout<<(a2==a1)<<endl;
}