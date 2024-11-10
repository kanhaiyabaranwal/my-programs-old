#include<iostream>
#include<stack>
using namespace std;


int NextGreaterElement()
{
	int a[] = {6,3,2,5,4,1,8,9,4};
	stack<int> stk;
	stk.push(a[0]);
	int i=1;
	int n=sizeof(a)/sizeof(*a);
	
	while(i<n)
	{
		if(a[i]<stk.top())
			stk.push(a[i]);
		else
		{
			while(stk.size() && a[i]>stk.top())
			{	
				cout<<"Greater for "<<stk.top()<<" is "<<a[i]<<endl;
				stk.pop();
			}
			stk.push(a[i]);
		}
		
		
		i++;
	}
	while(stk.size())
	{
		cout<<"Greater for "<<stk.top()<<" is not found"<<endl;
		stk.pop();
	}
	return 0;
}

int main()
{
	NextGreaterElement();
	return 0;
}
