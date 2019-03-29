#include<iostream>
#define lli long long int

using namespace std;

lli gcd(lli x, lli y){
    lli r;
    while(y!=0){
		r=x%y;
		x=y;
		y=r;
	}
    return x;
}

class fraction{
    lli a, b;
public:
    fraction(){}
    
    fraction(lli a, lli b){
        this->a = a;
        this->b = b;
    }

    fraction operator+(fraction const &fr){
        lli x=fr.a * this->b + fr.b * this->a, y= fr.b * this->b;
        lli g=gcd(x, y);
        return fraction(x/g, y/g);
    }

    friend istream& operator>>(istream& in,  fraction& fr){
        in>>fr.a>>fr.b;
    }

    friend ostream & operator<<(ostream &out, fraction &fr){
        out<<fr.a<<"/"<<fr.b;
    }

};

int main(){
    fraction fr1, fr2, fr3;
    cout<<"Enter two fractions: ";
    cin>>fr1>>fr2;
    fr3=fr1+fr2;
    cout<<fr1<<" + "<<fr2<<" = "<<fr3<<endl;
}