#include <iostream>
#include <stack>
using namespace std;
int main()
{
	stack <int> st;
	int x,max=0, min=0;
	cout<<"vavedi chislo:";
	while(cin>>x)
	{
		st.push(x);
		cout<<"vavedi chislo:";
	}
	max=st.top();
	min=st.top();
	while(!st.empty())
	{
		if(st.top()>max)
		{
			max=st.top();
		}
		if(st.top()<min)
		{
			min=st.top();
		}
		st.pop();
	}
	cout<<endl<<"min:"<<min<<endl;
	cout<<"max:"<<max<<endl;
	return 0;
}
