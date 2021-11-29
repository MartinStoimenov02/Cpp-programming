#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	double a,b,c,cosA,cosB,cosC, p,S,ha,hb,hc,ma,mb, mc,r,R,la,lb,lc;
	cout<<"a=";
	cin>>a;
	cout<<"b=";
	cin>>b;
	cout<<"c=";
	cin>>c;
	if(a>b&&a>c)
	{
	cosA=((b*b)+(c*c)-(a*a))/(2*b*c);
	cout<<"cosA:"<<cosA<<endl;
		if(cosA<0)
		cout<<"triugulnikut e tupoagalen"<<endl;
		if(cosA==0)
		cout<<"triugulnika e pravoygylen"<<endl;
		if(cosA>0)
		cout<<"triagalnika e ostroygylen"<<endl;
	}
	if(b>a&&b>c)
	{
		cosB=((a*a)+(c*c)-(b*b))/(2*a*c);
		cout<<"cosB:"<<cosB<<endl;
		if(cosB<0)
		cout<<"triugulnikut e tupoagalen"<<endl;
		if(cosB==0)
		cout<<"triugulnika e pravoygylen"<<endl;
		if(cosB>0)
		cout<<"triagalnika e ostroygylen"<<endl;
	}
	if(c>a&&c>b)
	{
		cosC=((a*a)+(b*b)-(c*c))/(2*a*b);
		cout<<"cosC:"<<cosC<<endl;
		if(cosC<0)
		cout<<"triugulnikut e tupoagalen"<<endl;
		if(cosC==0)
		cout<<"triugulnika e pravoygylen"<<endl;
		if(cosC>0)
		cout<<"triagalnika e ostroygylen"<<endl;
	}
	if(a==b&&b==c&&a==c)
	{
		cout<<"triygylnika e ostroygalen"<<endl;
	}
	p=(a+b+c)/2;
	cout<<"p="<<p<<endl;
	S=sqrt(p*(p-a)*(p-b)*(p-c));
	cout<<"S="<<S<<endl;
	ha=(2*S)/a;
	cout<<"ha="<<ha<<endl;
	hb=(2*S)/b;
	cout<<"hb="<<hb<<endl;
	hc=(2*S)/c;
	cout<<"hc="<<hc<<endl;
	cosA=((b*b)+(c*c)-(a*a))/(2*b*c);
	cout<<"cosA:"<<cosA<<endl;
	cosB=((a*a)+(c*c)-(b*b))/(2*a*c);
	cout<<"cosB:"<<cosB<<endl;
	cosC=((a*a)+(b*b)-(c*c))/(2*a*b);
	cout<<"cosC:"<<cosC<<endl;
	ma=sqrt((c*c)+((a*a)/4)-(a*c*cosB));
	cout<<"ma="<<ma<<endl;
	mb=sqrt((c*c)+((b*b)/4)-(c*b*cosA));
	cout<<"mb="<<mb<<endl;
	mc=sqrt(((c*c)/4)+(b*b)-(c*b*cosA));
	cout<<"mc="<<mc<<endl;
	r=S/p;
	cout<<"r="<<r<<endl;
	R=(a*b*c)/(4*S);
	cout<<"R="<<R<<endl;
	la=sqrt((c*c)+(((a*c)/(b+c))*((a*c)/(b+c)))-2*c*((a*c)/(b+c))*cosB);
	cout<<"la="<<la<<endl;
	lb=sqrt((((b*c)/(a+c))*((b*c)/(a+c)))+(c*c)-2*c*((b*c)/(a+c))*cosA);
	cout<<"lb="<<lb<<endl;
	lc=sqrt((((c*(b-a))/b)*((c*(b-a))/b))+(b*b)-2*b*((c*(b-a))/b)*cosA);
	cout<<"lc="<<lc<<endl;
	cout<<"blagodarq za vnimanieto!!!";
	system("PAUSE");
	return 0;
}
