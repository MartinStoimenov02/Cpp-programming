#include <iostream>
using namespace std;
int CPN(int n)
{
	bool flag=true;
	for(int j=2; j<=n/2; j++)
	{
		if(n%j==0)
		{
			flag=false;
			break;
		}
	}
	return flag;
}
int main()
{
	int n1, n2; 
	bool flag; 
	cout<<"int two positive integers (and get the prime number between them): ";
	cin>>n1>>n2;
	cout<<"Prime number between "<<n1<<" and "<<n2<<" are: ";
	for(int i=n1+1; i<n2;i++)
	{
		flag=CPN(i);
		if (flag)
		cout<<i<<" ";
	}
	return 0;
}
