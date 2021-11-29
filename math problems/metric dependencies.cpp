#include <iostream>
using namespace std;
int main()
{
    double a;
    double b;
    double c;
    double a1;
    double b1;
    double hc;
    double r;
    double R;
    double mc;
    cout << "a=";
    cin >>a;
    cout << "b=";
    cin>>b;
    cout << "c=";
    cin>>c;
    a1=(a*a)/c;
    cout << "a1="<< a1<<endl;
    b1=(b*b)/c;
    cout << "b1=" << b1<<endl;
    hc=(a*b)/c;
    cout << "hc=" << hc<<endl;
    r=((a*b)/2)/((a+b+c)/2);
    cout << "r=" << r<<endl;
    R=c/2;
    cout << "R=" << R<<endl;
    mc=c/2;
    cout << "mc=" << mc<<endl;
    system("pause");
    return 0;
}

