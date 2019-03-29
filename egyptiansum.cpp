#include<iostream>
#include<vector>

using namespace std;

long gcd(long, long);
long lcm(long, long);

class Fraction{
    long a, b;
public:
    Fraction(){}

    Fraction(long a, long b){
        this->a = a;
        this->b = b;
    }
    //getter methods for members
    long geta(){
        return a;
    }

    long getb(){
        return b;
    }

    friend istream& operator>>(istream& in,  Fraction& fr){
        in>>fr.a>>fr.b;
        return in;
    }

    friend ostream & operator<<(ostream &out, Fraction &fr){
        out<<fr.a<<"/"<<fr.b;
        return out;
    }
};

//Takes a vector of Fractions and return additon as Fraction 
Fraction AddFractions(vector<Fraction> &vfr){
    if(vfr.size()<1){
        return Fraction(0, 0);
    }else if(vfr.size()==1){
        return Fraction(vfr[0].geta(), vfr[0].getb());
    }
    long l=lcm(vfr[0].getb(), vfr[1].getb());
    for(long i=2; i<vfr.size(); i++){
        l=lcm(l, vfr[i].getb());
    }
    long s=0;
    for(long i=0; i<vfr.size(); i++){
        s+=(l/vfr[i].getb())*vfr[i].geta();
    }
    long g=gcd(s, l);
    return Fraction(s/g, l/g);
}

class EgyptianFr{
    vector<Fraction> list;
    Fraction sum;
public:
    EgyptianFr(){
        sum = Fraction(0 ,1);
    }
    EgyptianFr(long n){
        list.resize(n);
        long b;
        for(int i=0;i<n;i++){
            cin>>b;
            list[i]=Fraction(1, b);
        }
        sum=AddFractions(list);
    }

    vector<Fraction> GetList(){
        return list;
    }

    Fraction GetSum(){
        return sum;
    }
};

long gcd(long x, long y){
    long r;
    while(y!=0){
		r=x%y;
		x=y;
		y=r;
	}
    return x;
}

long lcm(long x, long y){
    return (x*y)/gcd(x, y);
}

int main(){
    long n,t;
    cin>>t;
    while(t--){
        cin>>n;
        EgyptianFr egfr(n);
        vector<Fraction> list = egfr.GetList();
        for (Fraction fr : list){
            cout<<fr<<" + ";
        }
        Fraction res =  egfr.GetSum();
        cout<<" = "<<res<<res<<endl;    
    }
}