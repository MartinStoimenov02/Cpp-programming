#include<iostream>
#include<fstream>
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
	ofstream f;
	f.open("avtosalon.txt", ios::app);
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
		cout<<"["<<i+1<<"]"<<kola[i].marka<<";"<<kola[i].godina<<";"<<kola[i].cviat<<";"<<kola[i].cena<<endl;
			f<<endl<<"["<<i+1<<"]"<<"marka:"<<kola[i].marka;
			f<<endl<<"godina na proizvodstvo:"<<kola[i].godina;
			f<<endl<<"cviat:"<<kola[i].cviat;
			f<<endl<<"cena:"<<kola[i].cena<<endl;
	}
	f.close();
	return 0;
}
