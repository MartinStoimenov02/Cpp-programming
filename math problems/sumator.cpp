#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int a,b,c;
	cout<<"a=";
	cin>>a;
	cout<<"b=";
	cin>>b;
	c=a+b;
	cout<<setw(10)<<a<<endl;
	cout<<setw(10)<<"+"<<endl;
	cout<<setw(10)<<b<<endl;
	cout<<setw(10)<<"="<<endl;
	cout<<setw(10)<<c<<endl;
	return 0;
}
