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
	if(str[i]>='A' && str[i]<='Z')
	{
		str[i]=str[i]-'A'+'a';
	}
	str[0]=str[0]-'a'+'A';
	cout<<str[0];
	for(i=1;i<=n;i++)
	cout<<str[i];
	return 0;
}
