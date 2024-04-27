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

    Fraction operator+(const Fraction &other)const{
        int numerator=(*this).getNumerator()*other.getDenominator()+other.getNumerator()*(*this).getDenominator();
        int denominator=(*this).getDenominator()*other.getDenominator();
        int num=gcd(numerator,denominator);
        numerator/=num;
        denominator/=num;
        return Fraction(numerator,denominator);

    }

    Fraction operator-(const Fraction &other)const{
        int numerator=(*this).getNumerator()*other.getDenominator()-other.getNumerator()*(*this).getDenominator();
        int denominator=(*this).getDenominator()*other.getDenominator();
        int num=gcd(numerator,denominator);
        numerator/=num;
        denominator/=num;
        return Fraction(numerator,denominator);
    }

    Fraction operator*(const Fraction &other)const{
        int numerator=(*this).getNumerator()*other.getNumerator();
        int denominator=(*this).getDenominator()*other.getDenominator();
        int num=gcd(numerator,denominator);
        numerator/=num;
        denominator/=num;
        return Fraction(numerator,denominator);

    }

    Fraction operator/(const Fraction &other)const{
        int numerator=(*this).getNumerator()*other.getDenominator();
        int denominator=(*this).getDenominator()*other.getNumerator();
        int num=gcd(numerator,denominator);
        numerator/=num;
        denominator/=num;
        return Fraction(numerator,denominator);

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

    void display(){
        if (denominator != 1)
            cout << "(" << numerator << "/" << denominator << ")";
        else
            cout << "(" << numerator << ")";
    }

    friend std::ostream& operator << (std::ostream& out, const Fraction &f) {
        if (f.denominator != 1)
            out << "(" << f.numerator << "/" << f.denominator << ")";
        else
            out << "(" << f.numerator << ")";
        return out;
    }
    
    int gcd(int a, int b)const{
        while(b!=0){
            int temp=b;
            b=a%b;
            a=temp;
        }
        return a;
    }
};

int main(){
    Fraction a,b(8,9),c(2,6),d(5,16),e(90,17),f(655,136);
    a=(((b+c)-d)*e)/f;
    a.display();
    cout<<a;
}