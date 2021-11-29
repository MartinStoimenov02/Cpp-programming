#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main(int argc, char*argv[])
{
	char filename[30];
	
	int n;
ifstream fin;
label:
{
	cout<<"Choose:"<<endl;
	cout<<"1.Create new file"<<endl;
	cout<<"2.Read from file"<<endl;
	cin>>n;
	if(n==1)
	{
		cout<<"Enter file name:";
		cin>>filename;
		ofstream fout(filename);
		if(!fout)
		{
			cerr<<"ERROR!";
			goto label;
		}
		cout<<"You've just created a new file! :)"<<endl;
		 char text[1000000];
    while(cin.getline(text,sizeof(text)))
    {
        fout<<text;
    }
    
fout.close();
	}
	if(n==2)
	{
		cout<<"Enter file name:";
		cin>>filename;
		fin.open(filename,ios::in);
		if(!fin)
		{
			cerr<<"ERROR!";
			goto label;
		}
		char a;
		while(fin.eof()==false)
		{
			fin>>a;
			cout<<a<<" ";
		}
		fin.close();
	}

}
	system("pause");
	return 0;
}
