#include <iostream>
#include<stack>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
double a, b, h, a1, h1, a2, h2, d, pr, vr, l1, l, S, c, c1, g;
int n, n1;
stack<double>shir;
stack<double>vis;
 cout << "dulzhina na staqta:";
    cin >>a;
    cout << "Shirina na staqta:";
    cin>>b;
    cout << "Visochina na staqta:";
    cin>>h;
    cout << "obem na edna kofa:";
    cin >>l1;
    cout << "edinichna cena za kofa:";
    cin >>c;
    cout<<"broq na prozorcite:";
    cin>>n;
    cout<<"broq na vratite:";
    cin>>n1;
    for(int i=1; i<=n; i++)
    {
    cout << "shirina na prozorec"<<"["<<i<<"]"<<":";
    cin >>a1;
    shir.push(a1);
    cout << "visochina na prozorec"<<"["<<i<<"]"<<":";
    cin>>h1;
    vis.push(h1);
	}
	while(!vis.empty())
	{
		d=shir.top()*vis.top();
		pr=d+pr;
		shir.pop();
		vis.pop();
	}
	d=0;
	for(int i=1; i<=n1; i++)
    {
    cout << "shirina na vrata"<<"["<<i<<"]"<<":";
    cin >>a2;
    shir.push(a2);
    cout << "visochina na vrata"<<"["<<i<<"]"<<":";
    cin>>h2;
    vis.push(h2);
	}
	while(!vis.empty())
	{
		d=shir.top()*vis.top();
		vr=d+vr;
		shir.pop();
		vis.pop();
	}
	S=((2*a*h)+(2*b*h))-(pr+vr);
	cout<<"Obshta kvadratura:"<<S<<endl;
    l=S*1;
    cout << "neobhodimi litri latex=" << l<<endl;
    g=l/l1;
    g=ceil(g);
    cout << "broi kofi=" << g <<endl;
    c1=c*g;
    cout << "obshta cena=" << c1<<endl;
    system ("pause");
    return 0;
}
