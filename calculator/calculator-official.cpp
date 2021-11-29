#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	double a,b,c;
	char d;
	label:
	cin>>a;
	cin>>d;
	cin>>b;
	if (d=='+')
	{
		c=a+b;
	}
	if (d=='-')
	{
		c=a-b;
	}
	if (d=='*')
	{
		c=a*b;
	}
	if (d=='/')
	{
		c=a/b;
	}
		if (d=='^')
	{
		c=pow(a,b);
	}
		if (d=='s')
	{
		c=pow(a,1/b);
	}
		cout<<"="<<c<<endl;
		goto label;
		system("pause")
	return 0;
}
