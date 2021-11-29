#include <iostream>
#include<string>
using namespace std;
int main()
{
	string name;
	int ny, age, by;
	cout<<"name:";
	cin>>name;
	cout<<"now year:";
	cin>>ny;
	cout<<"Age:";
	cin>>age;
	by=ny-age;
	cout<<"birth year:"<<by;
	return 0;
}
