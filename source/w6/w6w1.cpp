#include<iostream>
using namespace std;

class PokerCard{
private:
    string suit;
    int face;

public:
    PokerCard(string s,int f)
    {
        suit = s;
        face = f;
    }
    friend ostream &operator<<(ostream &out, const PokerCard &p)
    {
        out<<"["<<p.face<<" of "<<p.suit<<"]";
        return out;
    }
    
    int toNum(char a){
        if(a=='s'){
            return 4;
        }
        if(a=='h'){
            return 3;
        }
        if(a=='d'){
            return 2;
        }
        if(a=='c'){
            return 1;
        }
        return 0;
    }
    
    int getFace(){
        if(face==1){
            return 14;
        }
        return face;
    }

    char getSuit(){
        return suit[0];
    }
    //Please finish the comparison operator override
    //compare face first, if the same then compare suit 
    //請完成比較運算子多載
    //先比較 face ， face 一樣再比較 suit
    //1 > 13 > 12 > 11 > 10 > 9 > 8 > 7 > 6 > 5 > 4 > 3 > 2
    //spade > heart > diamond > club
    bool operator>(PokerCard &b)
    {
        if(this->getFace()>b.getFace()){
            return true;
        }
        if(this->getFace()==b.getFace()&&this->toNum(getSuit())>b.toNum(b.getSuit())){
            return true;
        }
        return false;
    }
    bool operator<(PokerCard &b)
    {
        if(this->getFace()<b.getFace()){
            return true;
        }
        if(this->getFace()==b.getFace()&&this->toNum(getSuit())<b.toNum(b.getSuit())){
            return true;
        }
        return false;
    }
    bool operator==(PokerCard &b)
    {
        if(this->toNum(getSuit())==b.toNum(b.getSuit())&&this->getFace()==b.getFace()){
            return true;
        }
        return false;
    }
};

int main(){
    PokerCard A1("heart",1);
    PokerCard B2("club",4);
    cout<<B2<<endl;
    cout<<A1<<endl;
    cout<<(B2>A1)<<endl;
}