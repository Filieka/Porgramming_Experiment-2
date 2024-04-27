#include<iostream>
using namespace std;

class Fraction{

private:
    int numerator, denominator;
public:
    Fraction():numerator(0),denominator(1){}
    Fraction(int n,int m):numerator(n){
        if(m==0){throw "divided by zero";}            
        denominator = m;
    }

    int getNumerator() const {
        return numerator;
    }

    int getDenominator() const {
        return denominator;
    }

    void setNumerator(int n) {
        numerator = n;
    }

    void setDenominator(int m) {
        if(m == 0)
        throw "divided by zero";
        denominator = m;
    }

    friend std::ostream& operator << (std::ostream& out, const Fraction &f) {
        if (f.denominator != 1)
            out << "[" << f.numerator << "/" << f.denominator << "]";
        else
            out << f.numerator;
        return out;
    }
    
};

int gcd(int a, int b){
        while(b!=0){
            int temp=b;
            b=a%b;
            a=temp;
        }
        return a;
}

Fraction operator+(const Fraction &f1,const Fraction &f2){
    int numerator=f1.getNumerator()*f2.getDenominator()+f2.getNumerator()*f1.getDenominator();
    int denominator=f1.getDenominator()*f2.getDenominator();
    int num=gcd(numerator,denominator);
    numerator/=num;
    denominator/=num;
    return Fraction(numerator,denominator);
}

Fraction operator-(const Fraction &f1,const Fraction &f2){
    int numerator=f1.getNumerator()*f2.getDenominator()-f2.getNumerator()*f1.getDenominator();
    int denominator=f1.getDenominator()*f2.getDenominator();
    int num=gcd(numerator,denominator);
    numerator/=num;
    denominator/=num;
    return Fraction(numerator,denominator);
}

bool operator==(const Fraction &f1,const Fraction &f2){
    int numerator=f1.getNumerator()*f2.getDenominator()-f2.getNumerator()*f1.getDenominator();
    return numerator==0;
}

int main(){
    int n1, n2, m1, m2;
    cin >> n1 >> m1 >> n2 >> m2;
    Fraction f1(n1, m1), f2(n2, m2);
    cout << (f1 + f2) << endl;
    cout << (f1 - f2) << endl;
    cout << (f1 == f2) << endl;
}