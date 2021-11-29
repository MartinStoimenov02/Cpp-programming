#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	char str[500];
	int n,i;
	cin.getline(str,500);
	n=strlen(str);
	for(i=0;i<n;i++)
		str[i]=str[i]-'1'+ 'a';
	for(i=0;i<n;i++)
	cout<<str[i];
	
	return 0;
}
