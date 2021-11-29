#include <iostream>
#include <string.h>
using namespace std;
int main(int argc, char *argv[])
{
	char str[50], str1[50];
	int n;
	cout<<"Enter small letters:";
	cin.getline(str,50);
	n=strlen(str);
	for(int i=0; i<n; i++)
	
	{
		str[i]=str[i]-'a'+'A';
		cout<<str[i];
	}
	return 0;
}
