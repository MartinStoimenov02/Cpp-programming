#include<iostream>
#include<iomanip>
using namespace std;
int main(){
	int a,b;
	cout<<"Vavedi 1-vo chetiricifreno chislo: ";cin>>a;
	cout<<"Vavedi 2-ro chetiricifreno chislo: ";cin>>b;
	cout<<setw(15)<<a<<"x"<<b<<endl;
	cout<<setw(15)<<"-------------"<<endl;
	cout<<setw(15)<<(a%10)*b<<endl;
		cout<<setw(14)<<(a%100)*b<<endl;
			cout<<setw(13)<<(a%1000)*b<<endl;
				cout<<setw(12)<<(a%10000)*b<<endl;
				cout<<setw(15)<<"------------"<<endl;
				cout<<setw(15)<<a*b;
		return 0;
}
