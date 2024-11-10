#include<iostream>
#include<stack>
using namespace std;


void stock_span(int a[], int n)
{
	stack<int> stk;
	int r[7]={0};
	static int counter=0;
	
	for(int i=0;i<n;i++)
	{
		
		
		while(stk.size())
		{
			
			if(a[i] > a[stk.top()])
				stk.pop();
			else
				break;
			
		}
		
		if(stk.size())
			r[i]=i-stk.top();
		else
			r[i]=1;
		
		stk.push(i);
	}
	cout<<"result is: ";
	for(int i=0;i<n;i++)
		cout<<r[i]<<",";
	cout<<endl;
}

int main()
{
	int ar[]={100,80,60,70,60,75,85};
	stock_span(ar,7);
	return 0;
}
