#include<iostream>
#include<string>
using namespace std;

class Palindrome{
    private:
    unsigned int base,inverse;
    int count=0;

    public:
    Palindrome(unsigned int a):base(a){
        change();
        add();
        while(check()){
            change();
            add();
        }
        cout<<count<<" "<<base<<endl;
    }

    void change(){
        string temp=to_string(base),out(temp.length(),' ');
        int i=temp.length()-1,j=0;
        for(;i>=0;i--){
            out[j]=temp[i];
            j++;
        }
        inverse=stoi(out);

    }
    
    void add(){
        base+=inverse;
        count++;
    }

    bool check(){
        string target=to_string(base);
        int i=0,j=target.length()-1;
        for(;i<=target.length();i++){
            if(target[i]!=target[j]){
                return true;
            }
            j--;
        }
        return false;
    }


};

int main(){
    unsigned int base;
    int i;
    int time;
    cin>>time;
    for(i=0;i<time;i++){
        cin>>base;
        Palindrome palindrome(base);
    }

}
    