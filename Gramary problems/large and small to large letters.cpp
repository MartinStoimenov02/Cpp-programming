#include <iostream>
#include <string.h>
using namespace std;
int main(int argc ,char *argv[])
{
	char str[50];
	int n,i;
	cin.getline(str,20);
	n=strlen(str);
	for(i=0;i<n;i++)
	if(str[i]>='a' && str[i]<='z')
	{
		str[i]=str[i]-'a'+'A';
	}
	for(i=0;i<n;i++)
	cout<<str[i];
	return 0;
}
