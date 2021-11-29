#include<iostream>
using namespace std;
int main()
{
	double a, b, c, d, e, f, g, h, i, j, k, l, m;
	cout<<"osnovna zaplata:";
	cin>>a;
	cout<<"rozhdenna godina:";
	cin>>b;
	cout<<"stazh:";
	cin>>c;
	cout<<"parichni nagradi(1):";
	cin>>d;
	cout<<"parichni nagradi(2):";
	cin>>e;
	cout<<"parichna nagrada(with %):";
	cin>>l;
	f=((c*0.6)*a)/100;
	cout<<"klas prosluzheno vreme:"<<f<<endl;
	m=(l*a)/100;
	cout<<"parichna nagrada(3):"<<m<<endl;
	g=a+f+d+e+m;
	cout<<"brutna zaplata:"<<g<<endl;
	if(b>=1960)
	{
			h=(g*13.78)/100;
			cout<<"socialna osigurovka:"<<h<<endl;
			}
			else
			{
			h=(g*18.80)/100;
			cout<<"socialna osigurovka:"<<h<<endl;
	}
	i=g-h;
	cout<<"danachna osnova:"<<i<<endl;
	j=0.1*i;
	cout<<"DDFL:"<<j<<endl;
	k=g-(h+j);
	cout<<"netna zaplata:"<<k<<endl;
	system("pause");
	return 0;
}
