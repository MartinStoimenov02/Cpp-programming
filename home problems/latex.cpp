#include <iostream>
using namespace std;
int main()
{
double a; //shirina
double b; //dalzhina 
double h; //visochina 
double a1; //vrata shirina 
double h1; //vrata visochina 
double a2; //prozorec shirina 
double h2; //prozorec visochina 
double S; //lice
double l1;//kolko litra e edna kofa
double c;//edinichna cena na kofa
double c1;//krajna cena za potrbitelq
double l;//neobhodimi litri za boqdisvane na staqta
double g;//brojj kofi
 cout << "shirina na staqta:";
    cin >>a;
    cout << "dulzhina na staqta:";
    cin>>b;
    cout << "viso`ina na staqta:";
    cin>>h;
     cout << "shirina na vratata:";
    cin >>a1;
    cout << "visochina na vratata:";
    cin>>h1;
    cout << "shirina na prozoreca:";
    cin>>a2;
     cout << "visochina na prozoreca:";
    cin >>h2;
    cout << "obem na edna kofa:";
    cin >>l1;
    cout << "edinichna cena za kofa:";
    cin >>c;
    S=((2*a*h+2*b*h)+(a*b))-((a1*h1)+(a2*h2))
     ;cout << "S (lice)=" << S<<endl;
     l=S*1
     ;cout << "l(neobhodimi litri latex) =" << l<<endl;
     g=l/l1
     ;cout << "g(broi kofi)=" << g <<endl;
     c1=c*g;
     ;cout << "c1(obshta cena)=" << c1<<endl;
     system ("pause");
    ;return 0;
}

