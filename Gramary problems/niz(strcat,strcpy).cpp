#include <iostream>
#include <string.h>
using namespace std;
int main(int argc ,char *argv[])
{
	char str1[100], str2[100], str3[100], str[300];
	int strnum;
	cout<<"Enter str1:";			
	cin.getline(str1,100);
	cout<<"Enter str2:";				
	cin.getline(str2,100);
	cout<<"Enter str3:";			
	cin.getline(str3,100);
	strcat(str1," ");
	strcat(str1,str2);
	strcat(str1," ");				
	strcat(str1,str3);
	cout<<"str1:"<<str1<<endl;		
	strnum=strlen(str1);					
	cout<<"Str:"<<strnum;	
	return 0;
}
