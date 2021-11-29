#include<iostream>
using namespace std; 
struct avtosalon 
{
	char marka[15]; 
	int godina; 
	char cviat[10];
	float cena;
};
int main ()
{
	int n, i; 
	cout<<"vavedi broq na kolite:";
	cin>>n; 
	avtosalon kola [n];
	for (i=0; i<n;i++)
	{
		cout<<"["<<i+1<<"]"<<endl; 
		cout<<"marka:";
		cin>>kola[i].marka;
		cout<<"godina na proizvodstvo:";
		cin>>kola[i].godina;
		cout<<"cviat:";
		cin>>kola[i].cviat;
		cout<<"cena:";
		cin>>kola[i].cena;
	}
	for(i=0; i<n;i++)
	{
		if(kola[i].godina>=2010)
		cout<<"["<<i+1<<"]"<<kola[i].marka<<";"<<kola[i].godina<<";"<<kola[i].cviat<<";"<<kola[i].cena<<endl;
	}
	return 0;
}
