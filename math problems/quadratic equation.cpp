#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    double a;
    double b;
    double c;
    double D;
    double X1;
    double X2;
    cout << "a=";
    cin>> a;
    cout << "b=";
    cin>> b;
    cout << "c=";
    cin>> c;
    D=(b*b)-4*a*c;
    if(D>0)
    {
            X1=(-b+sqrt(D))/(2*a);
            cout << "X1=" << X1<<endl;
            X2=(-b-sqrt(D))/(2*a);
            cout << "X2="<< X2<<endl;
    }    
        if (D==0)
            {
                X1=(-b)/(2*a);
                cout << "X1=" << X1<<endl;
                X2=(-b)/(2*a);
                cout << "X2="<< X2<<endl;
            }    
            if (D<0)
            {
                    cout << "D<0! incorect input!"<<endl;
            }
            system("pause");
    return 0;
}

