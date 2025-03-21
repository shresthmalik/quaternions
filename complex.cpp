#include <bits/stdc++.h>
using namespace std;

struct Complex{
    int a=0, b=0;
    Complex(){}
    Complex(int a, int b){
        this->a = a;
        this->b = b;
    }
};

Complex mul(Complex x, Complex y){
    Complex ans(0,0);
    ans.a = x.a * y.a  -  x.b * y.b  ;
    ans.b = x.a * y.b  +  x.b * y.a  ;
    return ans;
}

void printComplex(Complex c){
    cout<<c.a<<","<<c.b<<endl;
}

int main(){

    Complex x(2,1);
    Complex y(0,1);

    Complex ans = mul(x,y);
    printComplex(ans);

}