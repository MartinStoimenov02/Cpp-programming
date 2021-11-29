#include <iostream>
#include <string.h>
#include<limits> //used to get numeric limits
using namespace std;
int main()
{
	start:
	char str[500];
	int n, i, c;
	cout<<endl<<endl<<"your choice:"<<endl;
    cout<<"for 'word->code' press 1;"<<endl;
    cout<<"for 'code->word' press 2;"<<endl;
    cin>>c;
    if(c==1){
    cin.ignore (numeric_limits<streamsize>::max(), '\n'); //discard characters until newline is found
	cin.getline(str,500);
	n=strlen(str);
	for(i=0;i<n;i++) {
		str[i]=str[i]-'a'+ '1';
	}
	for(i=0;i<n;i++) {
		cout<<str[i];
	}
	}
	else if(c==2){
    cin.ignore (numeric_limits<streamsize>::max(), '\n'); //discard characters until newline is found
	cin.getline(str,500);
	n=strlen(str);
	for(i=0;i<n;i++) {
		str[i]=str[i]-'1'+ 'a';
	}
	for(i=0;i<n;i++) {
			cout<<str[i];
	}
	}
	else{
		cout<<"ERROR! Try again!"<<endl;
	}
	goto start;
	return 0;
}
